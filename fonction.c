#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "fonction.h"
#include "random.h"
#include <string.h>

char liste_couleur[4] = {'r','b','g','y'};

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
      }else if(grid[i][j] == 'X'){
        colored_grid[i][j] = 'X';
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

void paint_around_X(int i, int j,char grid_to_color[35][100]){
  char couleur = random_pick(liste_couleur, 4);//Faire attention a regarder plus tard le nb de joueurs
  for(int k = i - 4; k <= i + 4; k++){
    for(int l = j - 4; l <= j + 4; l++){
      if(grid_to_color[k][l] == 'w'){
        grid_to_color[k][l] = couleur;
      }
    }
  }
}

void initialize_grid_with_color(char grid_to_color[35][100], char colored_grid[35][100]){
  for(int i = 0; i < 35; i++){
    for(int j = 0; j < 100; j++){
      char cell = grid_to_color[i][j];
      if(cell == 'X'){
        paint_around_X(i,j,grid_to_color);
      }
    }
  }
  for(int i = 0; i < 35; i++){
    for(int j = 0; j < 100; j++){
      colored_grid[i][j] = grid_to_color[i][j];
    }
  }
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

void from_char_to_number(char lettre, char couleur[5]){
  if(lettre == 'w'){
    strcpy(couleur, "0;37");
  }else if(lettre == 'r'){
    strcpy(couleur, "0;31");;
  }else if(lettre == 'b'){
    strcpy(couleur, "0;34");
  }else if(lettre == 'g'){
    strcpy(couleur, "0;92");
  }else if(lettre == 'y'){
    strcpy(couleur, "0;93");
  }else if(lettre == '*'){
    strcpy(couleur, "0;90");
  }
}

void print_colored_grid(char colored_grid[35][100]){
  for(int i = 0; i < 35; i++){
    for(int j = 0; j < 100; j++){
      char couleur[5] = {'\0'};
      from_char_to_number(colored_grid[i][j], couleur);
      color(couleur);
      printf("%c", colored_grid[i][j]);
      color("0");
    }
    printf("\n");
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


