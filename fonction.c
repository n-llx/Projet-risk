#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "fonction.h"


int nb_Red(Voisin cell){
  int nb_red = 0;
  if(cell.color_up == 'r'){
    nb_red++;
  }else if(cell.color_down == 'r'){
    nb_red++;
  }else if(cell.color_left == 'r'){
    nb_red++;
  }else if(cell.color_left == 'r'){
    nb_red++;
  }
  return nb_red;
}

int nb_Blue(Voisin cell){
  int nb_blue = 0;
  if(cell.color_up == 'b'){
    nb_blue++;
  }else if(cell.color_down == 'b'){
    nb_blue++;
  }else if(cell.color_left == 'b'){
    nb_blue++;
  }else if(cell.color_left == 'b'){
    nb_blue++;
  }
  return nb_blue;
}

int nb_Green(Voisin cell){
  int nb_green = 0;
  if(cell.color_up == 'g'){
    nb_green++;
  }else if(cell.color_down == 'g'){
    nb_green++;
  }else if(cell.color_left == 'g'){
    nb_green++;
  }else if(cell.color_left == 'g'){
    nb_green++;
  }
  return nb_green;
}

int nb_Yellow(Voisin cell){
  int nb_yellow = 0;
  if(cell.color_up == 'y'){
    nb_yellow++;
  }else if(cell.color_down == 'y'){
    nb_yellow++;
  }else if(cell.color_left == 'y'){
    nb_yellow++;
  }else if(cell.color_left == 'y'){
    nb_yellow++;
  }
  return nb_yellow;
}

void create_colored_grid(char grid[35][100], char colored_grid[35][100]){
  // on remplace les caracteres par des couleurs.
  // le '*' est la couleur nulle. Au depart toutes les cases sont blanches/
  for(int i = 0; i < 35; i++){
    for(int j = 0; j < 100; j++){
      if(grid[i][j] == '/'){
        colored_grid[i][j] = '*';
      }else if(grid[i][j] == '@'){
        colored_grid[i][j] = 'w';
      }
    }
  }
}

Voisin color_of_neighbour(char colored_grid[35][100], int i, int j){
// Les 4 coins ne seront jamais pris en compte, il ne doit donc pas y avoir de terre
// Il est necessaire de prendre des coordonnes entre 1 et i - 1 et 1 et j - 1 pour eviter le depassement
  Voisin cell = {colored_grid[i - 1][j], colored_grid[i + 1][j], colored_grid[i][j - 1], colored_grid[i][j + 1], nb_Red(cell), nb_Blue(cell), nb_Green(cell), nb_Yellow(cell)};
  return cell;
}

void initialize_grid_with_color(char blank_grid[35][100], char nb_color[4]){
  //renvoie une grille coloree aleatoirement
}

void grid_initialization(char grid_result[35][100]){
//On suppose que la grille est exactement de taille 100
  for(int i = 0; i < 35; i++){
    for(int j = 0; j < 100; j++){
      char land;
      scanf("%c ", &land);
      grid_result[i][j] = land;
    }
  }
}

void print_grid(char grid[35][100]){
  for(int i = 0; i < 35; i++){
    for(int j = 0; j < 100; j++){
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}


