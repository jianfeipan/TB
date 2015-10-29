#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/un.h>


#define BUFSIZE 512

int main(int argc, char **argv) {
  int sfd, c;
  struct sockaddr_un addrlocal;
  char buf[BUFSIZE], *pt;
  ssize_t nread, nwrite;

  if (argc != 2) {
    printf("Usage: %s file path\n", argv[0]);
    exit(EXIT_FAILURE);
  }

 
  	sfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	if(sfd<0){
		perror("socket");
		exit(0);
	} 
	
    memset(&addrlocal, 0, sizeof(struct sockaddr_un));
  	addrlocal.sun_family = AF_UNIX;
	//strncpy(addrlocal.sun_path, argv[1], strlen(argv[1]));
	snprintf(addrlocal.sun_path, 108, argv[1]);
	c = connect(sfd, (struct sockaddr *)&addrlocal,sizeof(addrlocal));
    if(c<0){
		perror("bind");
		exit(0);
    }


  for (;;) {
    nread = read(sfd, buf, BUFSIZE);
    if (nread == 0) {
      printf("Connexion rompue\n");
      exit(EXIT_SUCCESS);
    } else if (nread < 0) {
      perror("read");
      exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("Message recu '%s'", buf);

    pt = fgets(buf, BUFSIZE, stdin);
    if (pt == NULL) {
      printf("Sortie du client\n");
      exit(EXIT_SUCCESS);
    }
    nwrite = write(sfd, buf, strlen(buf));
    if (nwrite < 0) {
      perror("write");
      exit(EXIT_FAILURE);
    }
  }
}
