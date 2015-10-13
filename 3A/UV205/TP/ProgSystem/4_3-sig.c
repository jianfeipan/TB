/* 
 * Auteur(s):
 */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int  message = 0;

void hdl_sys1(int n) {
  printf("hdl_sys1: Signal recu: message1\n");

}

void hdl_sys2(int n) {
  printf("hdl_sys2: Signal recu: message2\n");

}

void (*sig_avant)(int) = hdl_sys2;		/* pour la question 4.3 */

void change() {
  sig_avant = signal(SIGINT,sig_avant);
}


void travail() {
  /* Je travaille tres intensement !    */
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
  printf("PID: %d\n", getpid());
  /* Set up the structure to specify the new action. */
  signal(SIGINT,hdl_sys1);
  signal(SIGQUIT,change);

  
  travail();
}
