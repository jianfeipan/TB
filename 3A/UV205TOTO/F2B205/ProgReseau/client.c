#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 512

int s;
char buf[BUFSIZE];
char URGENT[] = "z";

void urgent_signal(int n) {
  printf("Sending urgent signal!\n");
  strcpy(buf, URGENT);
  write(s, buf, strlen(buf));
}

int main(int argc, char **argv) {
  int port, r;
  struct sockaddr_in sin;
  struct hostent *hp;
  char *pt;

  if (argc != 3) {
    printf("Usage : %s nom_machine_distante port_serveur\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[2]);
  if (port == 0) {
    printf("Mauvais numero de port\n");
    exit(1);
  }

  /* Obtention de l'adresse IP du distant, a partir de son nom par
   * consultation du fichier /etc/hosts ou de la base hosts des NIS ou du
   * DNS (Domain Name Service) */
  hp = gethostbyname(argv[1]);
  if (hp == NULL) {
    fprintf(stderr, "Erreur gethostbyaddr\n");
    exit(2);
  }

  /* Construction de la structure d'adresse du distant */
  memset(&sin, 0, sizeof(sin));
  memcpy(&sin.sin_addr, hp->h_addr, hp->h_length);
  sin.sin_family = hp->h_addrtype;
  sin.sin_port = htons(port);

  /* Dans ce qui suit, n'oubliez pas de tester le code de retour des
   * fonctions utilisees et d'emettre un message d'erreur avec perror(),
   * puis de sortir avec exit(). */

  /* Ouverture de la socket */
  s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (s == -1) {
    perror("socket");
    exit(3);
  }
  
  /* Connexion au distant */
  r = connect(s, (struct sockaddr *) &sin, sizeof(sin));
  if (r < 0) {
    perror("Connexion refusee");
    exit(1);
  }
  
  signal(SIGQUIT, urgent_signal);

  /* Boucle de communication */
  for (;;) {
    /* Lecture socket */
    r = read(s, buf, BUFSIZE);
    if (r <= 0) {
      printf("Connexion rompue\n");
      exit(0);
    }
    buf[r] = '\0';
    /* Affichage ecran du message lu sur la socket */
    printf("%s", buf);

    /* Lecture clavier. Si on tape <Control-D>, gets() rend NULL 
     * <Control-D> symbolise la fin de fichier, ici la terminaison
     * du client */
    pt = fgets(buf, BUFSIZE, stdin);
    if (pt == NULL) {
      printf("Sortie du client\n");
      exit(0);
    }
    r = write(s, buf, strlen(buf));
  }
}
