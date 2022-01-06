#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "fonction.h"
#include "random.h"
#include <string.h>

char liste_couleur[4] = {'r','b','g','y'};





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

void print_grid_aux(Coords grid[26][200]){
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 200; j++){
      printf("{%d;%d} - ", grid[i][j].x, grid[i][j].y);
    }
    printf("\n");
  }
}
  

void grille_liste_territoire(char grid[35][100], Coords liste_territoire[26][200]){
  
  for(int i = 65; i <= 90; i++){
    char lettre_majuscule = i;
    for(int k = 0; k < 35; k++){
      for(int l = 0; l < 100; l++){
        if(grid[k][l] == lettre_majuscule){
          Coords coordonnes = {k, l};
          liste_territoire[i-65][0] = coordonnes;
        }
      }
    }
  }
  int compteur = 1;
  for(int i = 97; i <= 122; i++){
    compteur = 1;
    char lettre_minuscule = i;
    for(int k = 0; k < 35; k++){
      for(int l = 0; l < 100; l++){
        if(grid[k][l] == lettre_minuscule){
          Coords coordonnes = {k, l};
          liste_territoire[i-97][compteur] = coordonnes;
          compteur++;
        }
      }
    }
  }
}
