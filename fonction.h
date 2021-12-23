struct Voisin
{
  char color_up;
  char color_down;
  char color_left;
  char color_right;
  int nbRed;
  int nbBlue;
  int nbGreen;
  int nbYellow;
};
typedef struct Voisin Voisin;

int nb_Red(Voisin cell);
int nb_Blue(Voisin cell);
int nb_Green(Voisin cell);
int nb_Yellow(Voisin cell);
void create_colored_grid(char grid[35][100], char colored_grid[35][100]);
Voisin color_of_neighbour(char colored_grid[35][100], int i, int j);
void initialize_grid_with_color(char grid_to_color[35][100], char colored_grid[35][100]);
void grid_initialization(char grid_result[35][100]);
void from_char_to_number(char lettre, char couleur[5]);
void print_colored_grid(char colored_grid[35][100]);
void print_grid(char grid[35][100]);
