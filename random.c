#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

bool random(int une_chance_sur){
  int a = rand();
  int random = a % une_chance_sur;
  return (random == 0);
}

char random_pick(char liste[], int taille_liste){
  return(liste[rand() % taille_liste ]);
}

