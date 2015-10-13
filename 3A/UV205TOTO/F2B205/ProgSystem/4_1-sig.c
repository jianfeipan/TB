/* 
 * Auteur(s): Botu Sun
 */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void (*sig_avant)(int);		/* pour la question 4.3 */

int message_id = 1;

void hdl_sys1(int n) {
  printf("hdl_sys1: Signal recu: %d\n", n);
}

void print_message(int n) {
  printf("Message %d\n", message_id);
}

void toggle_message(int n) {
  if (message_id == 1) {
    message_id = 2;
  } else {
    message_id = 1;
  }
}

void travail() {
  /* Je travail tres intensement !    */
  /* Ne cherchez pas a comprendre ;-) */
  /* Il n'y a rien a modifier ici     */
  const char msg[] = "-\\|/";
  const int sz = strlen(msg);
  int i = 0;

  for (;;) {
    write(STDOUT_FILENO, "\r", 1);
    usleep(100000);
    write(STDOUT_FILENO, " => ", 4);
    write(STDOUT_FILENO, &msg[i++], 1);
    if (i == sz) i = 0;
  }
}
void travail() __attribute__((noreturn));
/* Petit raffinement pour le compilateur: cette fonction ne termine pas */

int main() {
  // Register a handler for SIGILL.
  if (signal(SIGILL, hdl_sys1) == SIG_ERR) {
    fprintf(stderr, "Cannot register handler for SIGILL");
  }
  // Register a handler for SIGINT and SIGQUIT.
  if (signal(SIGINT, print_message) == SIG_ERR) {
    fprintf(stderr, "Cannot register handler for SIGINT");
  }
  if (signal(SIGQUIT, toggle_message) == SIG_ERR) {
    fprintf(stderr, "Cannot register handler for SIGQUIT");
  }
  
  printf("PID: %d\n", getpid());
  
  travail();
}
