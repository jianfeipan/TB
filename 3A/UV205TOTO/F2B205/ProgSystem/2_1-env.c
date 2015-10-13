/*
 * Auteur: Botu Sun
 *
 * Cet programme permet de rechercher une variable d'environnement dans
 * le systeme.
 *
 * Utilisation de la fonction getenv(3).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare external var.
extern char **environ;

/* Petite fonction qui se charge d'envoyer les messages d'erreur
   et qui ensuite "suicide" le processus. */

void erreur_grave(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

/* Fonction principale (fournie avec erreur(s?)) */

int main(int argc, char **argv) {
  if (argc != 2) {
    erreur_grave("This program will accept exact 1 argument!");
  }
  
  // Methode 1:
  printf("Methode 1:\n");
  int i = 0;
  char *iter;
  for (iter = *(environ + i); iter; iter = *(environ + ++i)) {
    // If the current env var starts with request var.
    if (strstr(iter, argv[1]) == iter) {
      // Print out.(omit "REQUEST_VAR=")
      printf("Environment variable %s=%s\n", 
             argv[1], iter + strlen(argv[1]) + 1);
      break;
    }
  }
  // If iter ends with NULL, then not find!
  if (!iter) {
    printf("Environment variable %s is not found!\n", argv[1]);
  }
  
  // Methode 2:
  printf("Methode 2:\n");
  char* result = getenv(argv[1]);
  if(!result) {
    printf("Environment variable %s is not found!\n", argv[1]);
  } else {
    printf("Environment variable %s=%s\n", argv[1], result);
  }
  
  exit(0);
}
