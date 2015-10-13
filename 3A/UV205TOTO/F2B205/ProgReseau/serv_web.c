#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>

#define BUFSIZE 512
enum TypeFichier { NORMAL, REPERTOIRE, ERREUR };

const char* OK200 = "HTTP/1.1 200 OK\r\n\r\n";
const char* ERROR403 = "HTTP/1.1 403 Forbidden\r\n\r\nAccess denied\r\n";
const char* ERROR404 = "HTTP/1.1 404 Not Found\r\n\r\nFile or directory not found\r\n";
const char* HTMLEND = "</body></html>";

/* Fonction typeFichier()
 * argument : le nom du fichier
 * rend une valeur de type enumeration delaree en tete du fichier
 * NORMAL, ou REPERTOIRE ou ERRREUR
 */
enum TypeFichier typeFichier(char *fichier) {
  struct stat status;
  int r;

  r = stat(fichier, &status);
  if (r < 0)
    return ERREUR;
  if (S_ISREG(status.st_mode))
    return NORMAL;
  if (S_ISDIR(status.st_mode))
    return REPERTOIRE;
  /* si autre type, on envoie ERREUR (a fixer plus tard) */
  return ERREUR;
}


/* envoiFichier()
 * Arguments : le nom du fichier, la socket
 * valeur renvoyee : 0 si OK, -1 si erreur
 */
#define BUSIZE 1048;
int envoiFichier(char *fichier, int soc) {
  int fd, r;
  char buf[BUFSIZE];

  /* A completer.
   * On peut se poser la question de savoir si le fichier est
   * accessible avec l'appel systeme access();
   * Si oui, envoie l'entete OK 200 puis le contenu du fichier
   * Si non, envoie l'entete ERROR 403
   */
  if (access(fichier, F_OK | R_OK) == -1) {
    write(soc, ERROR403, strlen(ERROR403));
    return -1;
  } else {
    write(soc, OK200, strlen(OK200));
    fd = open(fichier, O_RDONLY);
    write(soc, buf, strlen(buf));
    do {
      r = read(fd, buf, BUFSIZE);
      if (r == -1) {
        perror("Error");
      } else if (r == 0) {
        break;
      }
      write(soc, buf, r);
    } while (1);
    write(soc, "\n\r", 2);
    return 0;
  }
}


/* envoiRep()
 * Arguments : le nom du repertoire, la socket
 * valeur renvoyee : 0 si OK, -1 si erreur
 */
int envoiRep(char *rep, int soc) {
  DIR *dp;
  struct dirent *pdi;
  char buf[1024], nom[1024];

  dp = opendir(rep);
  if (dp == NULL)
    return -1;

  write(soc, OK200, strlen(OK200));
  sprintf(buf, "<html><title>Repertoire %s</title><body>", rep);
  write(soc, buf, strlen(buf));

  while ((pdi = readdir(dp)) != NULL) {
    /* A completer
     * Le nom de chaque element contenu dans le repertoire est retrouvable a
     * l'adresse pdi->d_name. Faites man readdir pour vous en convaincre.
     * Dans un premier temps, on se contentera de la liste simple.
     * Dans une petite amelioration on poura prefixer chaque element avec
     * l'icone folder ou generic en fonction du type du fichier.
     * (Tester le nom de l'element avec le chemin complet.) */
     sprintf(nom, "%s", pdi->d_name);
     strcat(nom, "<br>");
     write(soc, nom, strlen(nom));
  }
  write(soc, HTMLEND, strlen(HTMLEND));
  write(soc, "\n\r", 2);
  return 0;
}


void communication(int soc, struct sockaddr_in from) {
  struct hostent *hp;
  char buf[BUFSIZE];
  int r;
  char *pf;
  enum op { GET, PUT } operation;
  enum TypeFichier file_type;

  /* Eventuellement, inserer ici le code pour la reconnaissance de la 
   * machine appelante */
  
  hp = gethostbyaddr(&from.sin_addr, sizeof(struct in_addr),
         from.sin_family);
  if (hp == NULL) {
    fprintf(stderr, "Erreurs gethostbyaddr\n");
    fprintf(stderr, "Errno: %d\n", h_errno);
    shutdown(soc, 2);
    return;
  } else
    printf("Machine appellante: %s\n", hp->h_name);
  
  /* Reconnaissance de la requete */
  r = read(soc, buf, BUFSIZE);
  if (r > 0) {
    if (strncmp(buf, "GET", 3) == 0)
      operation = GET;
  } else {
    perror("Erreur lecture socket\n");
    return;
  }

  switch (operation) {
    case GET:
      pf = strtok(buf + 4, " ");
      /* On pointe alors sur le / de "GET /xxx HTTP...
       * strtok() rend l'adresse du premier caractere
       * apres l'espace et termine le mot par '\0'
       */
      pf++; /* pour pointer apres le slash */
      /* pf pointe sur le nom du fichier suivant le / de la requete.
       * Si la requete etait "GET /index.html ...", alors pf pointe sur 
       * le "i" de "index.html"
       */
      /* si le fichier est un fichier ordinaire, on l'envoie avec la fonction
       * envoiFichier().
       * Si c'est un repertoire, on envoie son listing avec la fonction
       * envoiRep().
       * Vous pouvez utiliser la fonction typeFichier() ci-dessous pour tester
       * le type du fichier.
       */
      file_type = typeFichier(pf);
      switch (file_type) {
        case NORMAL:
          envoiFichier(pf, soc);
          break;
        case REPERTOIRE:
          envoiRep(pf, soc);
          break;
        default:
          write(soc, ERROR404, strlen(ERROR404));
          break;
      }
      break;
    case PUT:
      perror("Service not implemented!");
      exit(-1);
  }
  close(soc);
}


int main(int argc, char **argv) {
  int s, ns, r, port;
  pid_t pid;
  struct sockaddr_in sin, from;
  socklen_t fromlen;
  char cwd[512];
  
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    perror("getcwd() error");
    exit(1);
  }
  
  /*
   * The host resolution in communication() requires access to some 
   * system call which it can no longer find in under this repersitory.
   * So this cannot coexist with the resolution above we need DNS.
   */
  if (chroot(cwd) != 0) {
    fprintf(stderr, "chroot(%s) failed\n", cwd);
    exit(1);
  }

  signal(SIGCHLD, SIG_IGN);
  
  if (argc != 2) {
    printf("Usage : %s  port_serveur\n", argv[0]);
    exit(1);
  }
  
  port = atoi(argv[1]);
  if (port < 5000) {
    printf("donnez un numero de port superieur a 5000\n");
    exit(1);
  }

  /* Construction de l'adresse locale (pour bind) */
  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = INADDR_ANY;
  sin.sin_port = htons(port);

  /* Creation de la socket */
  s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (s == -1) {
    perror("socket");
    exit(2);
  }

  /* Association d'un port a la socket */
  r = bind(s, (struct sockaddr *) &sin, sizeof(sin));
  if (r == -1) {
    perror("bind");
    exit(3);
  }

  /* Mise en etat d'attente de connexions */
  if (listen(s, 5) < 0) {
    perror("listen");
    exit(4);
  }
  
  fromlen = sizeof(from);
  for (;;) {
    /* Acceptation de connexions */
    ns = accept(s, (struct sockaddr *) &from, &fromlen);
    if (ns == -1) {
      perror("accept");
      exit(1);
    }
    pid = fork();
    if (pid == -1) {
      perror("Error forking!");
      exit(5);
    }
    if (pid == 0) {
      // Child:
      communication(ns, from);
      return 0;
    } else {
      // Father:
      close(ns);
    }
  }
}
