#include <stdio.h>

// Permet d'afficher un texte en couleur
void color(char parametre[]){
  printf("\033[%sm", parametre);
}
