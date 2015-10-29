#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/un.h>

#define BUFSIZE 512
void myExit(int n){
    wait(NULL);
}


void communication(int ns, struct sockaddr_un from, socklen_t fromlen){
	int s;
  	char buf[BUFSIZE];
  	ssize_t nread, nwrite;
	char host[NI_MAXHOST];
  	char *message = "I am server : Message a envoyer: ";
	s = getnameinfo((struct sockaddr *)&from, fromlen,
			host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
	if (s == 0)
	  printf("Debut avec client '%s'\n", host);
	else
	  fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));

	for (;;) {
		nwrite = write(ns, message, strlen(message));
		if (nwrite < 0) {
			perror("write");
			close(ns);
			break;
		}
		nread = read(ns, buf, BUFSIZE);
		if (nread == 0) {
			printf("Fin avec client '%s'\n", host);
			close(ns);
			break;
		} else if (nread < 0) {
			perror("read");
			close(ns);
			break;
		}
		buf[nread] = '\0';
		printf("Message recu '%s'\n", buf);
	}
}






int main(int argc, char **argv) {
  int sfd, b, ns, pid;
  struct sockaddr_un addrlocal;
  struct sockaddr_un from;
  socklen_t fromlen;

  if (argc != 2) {
    printf("Usage: %s  file name\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  sfd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
  if(sfd<0){
    perror("socket");
	exit(0);
  } 

  memset(&addrlocal, 0, sizeof(struct sockaddr_un));
  addrlocal.sun_family = AF_UNIX;
  snprintf(addrlocal.sun_path, 108, argv[1]);
  //strncpy(addrlocal.sun_path, argv[1], strlen(argv[1]));
  unlink(argv[1]);
  b = bind(sfd, (struct sockaddr *)&addrlocal,sizeof(addrlocal));
  if(b<0){
	perror("bind");
	exit(0);
  }

  listen(sfd,1);
  memset(&from, 0, sizeof(struct sockaddr_un));
  fromlen = sizeof(from);
  for (;;) {
    ns = accept(sfd,(struct sockaddr *)&from,&fromlen);
    if (ns == -1) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

	if((pid=fork())==-1){
	  perror("fork");
      exit(EXIT_FAILURE);
	}
	
	//child
	if(pid == 0){
		close(sfd);
		communication(ns,from,fromlen);
		exit(EXIT_SUCCESS);
	}
	//parent
	else{
		signal(SIGCHLD,myExit);
		close(ns);
	}
  }
  exit(EXIT_SUCCESS);
}
