#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFSIZE 512

int communication(struct sockaddr_un from, int sockfd) {
  int r;
  char buf[BUFSIZE];
  char *message = "Envoyez votre message : ";
  
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
  struct sockaddr_un s_un, from;
  
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
  memset(&s_un, 0, sizeof(s_un));
  s_un.sun_family = AF_UNIX;
  strcpy(s_un.sun_path, "server_socket");

  /* Creation de la socket */
  s = socket(AF_UNIX, SOCK_SEQPACKET, 0);
  if (s == -1) {
    perror("socket");
    exit(2);
  }

  /* Association d'un port a la socket */
  r = bind(s, (struct sockaddr *) &s_un, sizeof(s_un));
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
