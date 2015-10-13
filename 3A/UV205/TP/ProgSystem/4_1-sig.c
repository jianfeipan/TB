/* 
 * Auteur(s):
 */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int  message = 0;
void (*sig_avant)(int);		/* pour la question 4.3 */

void hdl_sys1() {
  printf("hdl_sys1: Signal recu: message%d\n", message+1);

}

void hdl_sys2() {
  message = (message+1)%2;
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
  signal(SIGINT,hdl_sys1);
  signal(SIGQUIT,hdl_sys2);
  /* ? ? ? ? ? ? */
  
  travail();
}
