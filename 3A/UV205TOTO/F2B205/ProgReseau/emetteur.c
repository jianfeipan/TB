#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 100000

int main(int argc, char **argv) {
  int s, port, r, volume, enabled;
  struct sockaddr_in sin;
  struct hostent *hp;
  char buf[BUFSIZE];

  if (argc != 4) {
    printf("Usage : %s adresse_service port_serveur volume\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[2]);
  if (port == 0) {
    fprintf(stderr, "Mauvais numero de port\n");
    exit(1);
  }

  volume = atoi(argv[3]);
  if (volume == 0 || volume > BUFSIZE) {
    fprintf(stderr, "Donnez un volume inferieur a %d octets\n", BUFSIZE);
    exit(1);
  }

  /* Initialisation du buffer */
  for (r = 0; r < BUFSIZE; r++)
    buf[r] = 'a';

  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  hp = gethostbyname(argv[1]);
  if (hp == NULL) {
    fprintf(stderr, "Erreur gethostbyaddr\n");
    exit(2);
  } else {
    memcpy(&sin.sin_addr, hp->h_addr, hp->h_length);
  }
  sin.sin_port = htons(port);
  
  // Broadcast:
  inet_pton(AF_INET, "10.29.231.255", &sin.sin_addr);
  
  /* Ouverture socket */
  s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (s == -1) {
    perror("socket");
    exit(2);  
  }
  enabled = 1;
  setsockopt(s, SOL_SOCKET, SO_BROADCAST, &enabled, sizeof(enabled));

  /* Envoi donnees */
  r = sendto(s, buf, volume, 0, (struct sockaddr *) &sin, sizeof(struct sockaddr_in));
  if (r < 0) {
    perror("Probleme sendto");
  }
  exit(0);
}
