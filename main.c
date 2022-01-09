#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "color.h"
#include "fonction.h"


int main(void){
  srand(time(NULL));
  char grille_jeu[35][100] = {{'\0'}};
  grid_initialization(grille_jeu);
  Coords liste_territoire[30][200];
  grille_liste_territoire(grille_jeu, liste_territoire);

  InfoCase information_territoires[6];
  initialisation_jeu(3, 6, grille_jeu, liste_territoire, grille_jeu, information_territoires);
  return EXIT_SUCCESS;
}
