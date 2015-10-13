#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFSIZE 512

int communication(struct sockaddr_in from, int sockfd) {
  int r;
  struct hostent *hp;
  char buf[BUFSIZE];
  char *message = "Envoyez votre message : ";
  
  /* Reconnaissance de la machine cliente */
  hp = gethostbyaddr(&from.sin_addr, sizeof(struct in_addr),
         from.sin_family);
  if (hp == NULL) {
    fprintf(stderr, "Erreurs gethostbyaddr\n");
    shutdown(sockfd, 2);
    return -1;
  } else
    printf("Machine appellante: %s\n", hp->h_name);

  for (;;) {
    r = write(sockfd, message, strlen(message));
    r = read(sockfd, buf, BUFSIZE);
    if (r <= 0) {
      printf("fin client\n");
      break;
    }
    buf[r] = '\0';
    printf("%s\n", buf);
  }
  return 0;
}

int main(int argc, char **argv) {
  int s, ns, r, port;
  pid_t pid;
  socklen_t fromlen;
  struct sockaddr_in sin, from;
  
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
      communication(from, ns);
      exit(0);
    }
  }
}
