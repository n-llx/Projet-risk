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
  
  
  
  
  char tour_du_joueur_n = 'A';

  while(sb_win_fun(information_territoires) == false){
    
    printf ("C'est au joueur %c de jouer !\n", tour_du_joueur_n);

    fonction_renfort(information_territoires);

    
    int desir_combat = desir_de_combat();
     
    if (desir_combat == 1){
      printf ("Qui voulez-vous attaquer ? Veuillez renseigner une lettre entre A et F sauf vous-même");
      char defenseur;
      scanf ("%c", &defenseur);
      fonction_combat(information_territoires[tour_du_joueur_n - 'A'], information_territoires[defenseur - 'A'], 0, matrice_adjacence, grille_jeu);
    }
    
    tour_du_joueur_n =+ 1;

    if (tour_du_joueur_n == 'G'){
      tour_du_joueur_n = 'A';
    }
  }
  
  return EXIT_SUCCESS;
}
