#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void fin(int n){
	wait(NULL);
	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
	int pipe_fd[2];
	int pid;
        char buffer;

	//pipe for tubes
	if(pipe(pipe_fd)==-1){
		printf("piple error\n");	
	}else{
		printf("fd_read : %d , fd_write : %d ", pipe_fd[0],pipe_fd[1]);
	}


	if((pid = fork())<0){
		printf("fork error\n");
		exit(EXIT_FAILURE);
  	}
	
	if(pid > 0){//father
 		signal(SIGCHLD,fin);
		printf("child pid : %d\n", pid); 
		close(STDOUT_FILENO);          
		dup(pipe_fd[1]); 
		close(pipe_fd[1]);              
	}else{//child
		close(STDIN_FILENO);
		dup(pipe_fd[0]);
		close(pipe_fd[0]);
	}

	while(read(STDIN_FILENO, &buffer,1) > 0){
		write(STDOUT_FILENO,&buffer,1);
	}
	exit(EXIT_SUCCESS);
}
