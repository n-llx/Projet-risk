#include <stdio.h>
#include <stdlib.h>
#include "fonction_auxiliaire_combat.c"
// #include "matrice_du_graphe.c"
// #include "information_territores.c"

int fonction_combat(int tab_attaquant[], int tab_defenseur[], int phase, int matrice_du_graphe[4][4]){
    
    // La phase 0 correspond à la toute première attaque du tour
    if (phase == 0){
    
        int info = autorise_combat(4, matrice_du_graphe, tab_attaquant[1], tab_defenseur[1], tab_attaquant[0], tab_defenseur[0]);

        if (informe_joueur(info, 0) == 1) {
            return -1;
        }
    }
    
    int tab_perte_troupe[2] = {0,0};
    un_combat(tab_attaquant[0], tab_defenseur[0], tab_perte_troupe);

    tab_attaquant[0] += tab_perte_troupe[0];
    tab_defenseur[0] += tab_perte_troupe[1];

    printf ("Perte en troupe de l'attaquant : %d\n", tab_perte_troupe[0]);
    printf ("Perte en troupe du défenseur : %d\n", tab_perte_troupe[1]);

    int info_2 = autorise_combat(4, matrice_du_graphe, tab_attaquant[1], tab_defenseur[1], tab_attaquant[0], tab_defenseur[0]);

    if (informe_joueur(info_2, 1) == 1) {
        return -1;
    }
    

    int desision = devenir_du_combat();

    if (desision == 1){
        fonction_combat(tab_attaquant, tab_defenseur, 1, matrice_du_graphe);
    }
    else {
        return -2;
    }    
    return 1;
}

