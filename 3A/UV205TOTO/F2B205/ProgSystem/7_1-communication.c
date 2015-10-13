/* 
 * Auteur: Botu Sun
 */

#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int fd[2];
  char buf;
  if (pipe(fd) != 0) {
    perror("Error creating pipe!");
  }
  pid_t pid;
  if ((pid = fork()) == -1) {
    perror("Error forking!");
  }
  
  if (pid == 0) {
    // Child  
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
  } else {
    // Father
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
  }
  
  while (read(STDIN_FILENO, &buf, 1) > 0) {
    write(STDOUT_FILENO, &buf, 1);
  }
  
  if (pid == 0) {
    // Child  
    close(fd[0]);
  } else {
    // Father
    close(fd[1]);
  }
}
