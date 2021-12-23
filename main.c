#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "color.h"
#include "fonction.h"


int main(void){
  srand(time(NULL));
  char grille_jeu[35][100] = {{'\0'}};
  char blank_grid[35][100] = {{'\0'}};
  grid_initialization(grille_jeu);
  create_colored_grid(grille_jeu, blank_grid);
  char colored_grid[35][100];
  initialize_grid_with_color(blank_grid, colored_grid);
//  Voisin cellule = color_of_neighbour(colored_grid, 20, 20);
//  printf("%c / %c / %c / %c - %d / %d / %d / %d\n", cellule.color_up, cellule.color_down, cellule.color_left, cellule.color_right, cellule.nbRed, cellule.nbBlue, cellule.nbGreen, cellule.nbYellow);
  print_colored_grid(colored_grid);
//  color("33");
//  printf("Test\n");
//  color("0");
  return EXIT_SUCCESS;
}
