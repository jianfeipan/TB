/*
 * Auteur: Botu Sun
 *
 * Cet programme refait ce que fait la commande "ls". Il donne des
 * informnations sur les caracteristiques de fichiers dont le nom est passe
 * en parametre.
 *
 * Utilisation de la primitive stat(2) et de la fonction getpwuid(3).
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>

/* Petite fonction qui se charge d'envoyer les messages d'erreur
   et qui ensuite "suicide" le processus. */

void erreur_grave(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

/* Fonction principale (fournie avec erreur(s?)) */

int main(int argc, char **argv) {
  // Error code:
  // struct stat status, *buffer;
  // Correct code:
  struct stat status;
  struct stat* buffer = &status;
  int r;

  r = stat(argv[1], buffer);
  if (r < 0)
    erreur_grave("Stat");
    
  struct passwd* user = getpwuid(buffer->st_uid);
  if (!user)
    erreur_grave("Getpwuid");
  
  struct passwd* user_fake = getpwuid(1000);
  if (!user_fake)
    erreur_grave("Getpwuid fake");

  printf("Fichier %s:  mode: %X  Taille: %ld  Proprietaire: %s\n",
	argv[1], buffer->st_mode, buffer->st_size, user->pw_name);

  exit(EXIT_SUCCESS);
}
