int nombre_territoire = 6;
int matrice_adjacence[6][6] =
{
{0, 1, 0, 0, 0, 0},
{1, 0, 1, 0, 0, 0},
{0, 1, 0, 1, 0, 0},
{0, 0, 1, 0, 1, 0},
{0, 0, 0, 1, 0, 1},
{0, 0, 0, 0, 1, 0},
};

char liste_couleur[4] = {'r','b','g','y'};



#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "color.h"
#include "fonction.h"
#include "random.h"
#include <string.h>



void initialisation_jeu(int nombre_joueurs, int nb_territoire, char map[35][100], Coords liste_territoire[30][200], char map_colored[35][100], InfoCase info_territoire[6]){
  printf("\033[1;1H\033[2J");
  print_grid(map);
  char liste_territoires_deja_choisis[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};
  for(int i = 0; i < nb_territoire; i++){
    printf("Joueur %c, sur quel territoire voulez vous installer vos troupes ? \n", liste_couleur[i%nombre_joueurs]);
    char territoire_choisi = '\0';
    scanf(" %c", &territoire_choisi);
    printf("Le territoire choisi est le territoire %c\n", territoire_choisi);
    if (est_dans_la_liste(territoire_choisi, liste_territoires_deja_choisis)){
      printf("Territoire invalide ! On recommence tout ! \n");
      printf("\033[1;1H\033[2J");
      initialisation_jeu(nombre_joueurs, nb_territoire, map, liste_territoire, map_colored, info_territoire);
    }else if(liste_territoire[65 - territoire_choisi][0].x != 0){
      liste_territoires_deja_choisis[65 - territoire_choisi] = territoire_choisi;
      InfoCase info_one_territory = {territoire_choisi, 0, liste_couleur[i%4]};
      printf("Combien de troupes voulez vous deposer ? \n");
      int nb_troupe = 0;
      scanf("%d", &nb_troupe);
      info_one_territory.nombre_de_troupe = nb_troupe;
      info_territoire[65 - territoire_choisi] = info_one_territory;
    }else{
      printf("Territoire invalide ! On recommence tout ! \n");
      printf("\033[1;1H\033[2J");
      initialisation_jeu(nombre_joueurs, nb_territoire, map, liste_territoire, map_colored, info_territoire);
    }
  }
}

bool est_dans_la_liste (char element, char liste[6]){
  for(int i = 0; i < 6; i++){
    if(liste[i] == element){
      return true;
    }
  }
  return false;
}

void grid_initialization(char grid_result[35][100]){
//On suppose que la grille est exactement de taille 100
  for(int i = 0; i < 35; i++){
    for(int j = 0; j < 100; j++){
      char land;
      scanf(" %c", &land);
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

void print_grid_aux(Coords grid[30][200]){
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 200; j++){
      printf("{%d;%d} - ", grid[i][j].x, grid[i][j].y);
    }
    printf("\n");
  }
}
  

void grille_liste_territoire(char grid[35][100], Coords liste_territoire[30][200]){
  
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

bool sb_win_fun (InfoCase info_territoire[6]){
    
    bool territorie_a= true;
    bool territorie_b= true;
    bool territorie_c= true;
    bool territorie_d= true;
    bool territorie_e= true;
    bool territorie_f= true;

    for (int i = 0; i<6; i++){
        if (info_territoire[i].nom_de_la_case == 'A'){
            territorie_b= false;
            territorie_c= false;
            territorie_d= false;
            territorie_e= false;
            territorie_f= false;
        }
        if (info_territoire[i].nom_de_la_case == 'B'){
            territorie_a= false;
            territorie_c= false;
            territorie_d= false;
            territorie_e= false;
            territorie_f= false;
        }
        if (info_territoire[i].nom_de_la_case == 'C'){
            territorie_b= false;
            territorie_a= false;
            territorie_d= false;
            territorie_e= false;
            territorie_f= false;
        }
        if (info_territoire[i].nom_de_la_case == 'D'){
            territorie_b= false;
            territorie_c= false;
            territorie_a= false;
            territorie_e= false;
            territorie_f= false;
        }
        if (info_territoire[i].nom_de_la_case == 'E'){
            territorie_b= false;
            territorie_c= false;
            territorie_d= false;
            territorie_a= false;
            territorie_f= false;
        }
        if (info_territoire[i].nom_de_la_case == 'F'){
            territorie_b= false;
            territorie_c= false;
            territorie_d= false;
            territorie_e= false;
            territorie_a= false;
        }
    }
    if (territorie_a){
        return true;
    }
    if (territorie_b){
        return true;
    }
    if (territorie_c){
        return true;
    }
    if (territorie_d){
        return true;
    }
    if (territorie_e){
        return true;
    }
    if (territorie_f){
        return true;
    }
    return false;
  }


void fonction_renfort(InfoCase info_territoire[6]){
  
  int nb_de_soldat = 5;
  
  printf("Vous avez 5 soldats de plus !\n");
  printf ("Ou voulez-vous les mettres ?");
  
  
  while ((nb_de_soldat =! 0)){
    printf ("Renseigner le territoire puis suivi d'un espace le nombre de troupe à y placer\n");
    char territoire;
    int nb_troupe = 0;
    scanf ("%c %d ", &territoire, &nb_troupe);

    info_territoire[territoire - 'A'].nombre_de_troupe += nb_troupe;

    nb_de_soldat -= nb_troupe;
  }

}

