#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void affiche_matrice (int n, int m, char matrice[n][m]){
/* Comme son nom l'indique */
        for (int i = 0; i<n; i++){
            for (int j = 0; j<m; j++){
                printf ("%c", matrice[i][j]);
               
            }
            printf("\n");
        }
}

void multiplication_matrice (int n, int m, int mat1[n][m], int mat2[n][m], int mat_resultat[n][m]){
/* Comme son nom l'indique */  
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            
            mat_resultat[i][j]=0;
      
            for(int k = 0; k < m; k++) {
                mat_resultat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void affiche_de(int resulat){
/* On affiche donc un dé spécifique pour un résultat spécifique */
    if (resulat == 1){
        char des[3][7] = {{'/',' ',' ',' ',' ',' ','/'},{'/',' ',' ','.',' ',' ','/'},{'/',' ',' ',' ',' ',' ','/'}};
        affiche_matrice(3, 7, des);
      
    }
    if (resulat == 2){
        char des[3][7] = {{'/',' ',' ',' ',' ',' ','/'},{'/',' ','.',' ','.',' ','/'},{'/',' ',' ',' ',' ',' ','/'}};
        affiche_matrice(3, 7, des);
      
    }
    if (resulat == 3){
        char des[3][7] = {{'/',' ',' ','.',' ',' ','/'},{'/',' ',' ','.',' ',' ','/'},{'/',' ',' ','.',' ',' ','/'}};
        affiche_matrice(3, 7, des);
      
    }
    if (resulat == 4){
        char des[3][7] = {{'/',' ','.',' ','.',' ','/'},{'/',' ',' ',' ',' ',' ','/'},{'/',' ','.',' ','.',' ','/'}};
        affiche_matrice(3, 7, des);
      
    }
    if (resulat == 5){
        char des[3][7] = {{'/',' ','.',' ','.',' ','/'},{'/',' ',' ','.',' ',' ','/'},{'/',' ','.',' ','.',' ','/'}};
        affiche_matrice(3, 7, des);
      
    }
    if (resulat == 6){
        char des[3][7] = {{'/',' ','.',' ','.',' ','/'},{'/',' ','.',' ','.',' ','/'},{'/',' ','.',' ','.',' ','/'}};
        affiche_matrice(3, 7, des);
      
    }
   
}

void tri_resultat(int n, int tab[n]){
/* un simple tri de tableau */
    int denombrement[7] = {0};

    for (int i = 0; i<n; i++){
        denombrement[tab[i]] += 1;
    }
    
    int k = 0;
    for (int i = 0; i<7; i++){
        for (int j = k; j < (k + denombrement[i]); j++){
            tab[j] = i;
        }
        k += denombrement[i];
    }
}

int un_combat(int attaquant, int defenseur, int perte_troupe[2]){  
/* On effectue les lances de de, on les affichent puis ils sont enregistre dans un tableau que l'on va trie avec la fonction tri_resultat.*/

    // Fonction utilise : affiche_matrice, affiche_de, tris_resultat.
    
    srand(time( NULL ));

    int resulat_attaque[3] = {0};
    
    // Les cas : defeseur = 0, attaquant = 1 on ete filtre au prealable.
    
    if (attaquant >= 3){
                
        for (int i = 0; i<3; i++){
            
            int resulat = 0;
            while(resulat == 0){
                int nb_aleatoire = rand();
                resulat = nb_aleatoire%7;  
            }

            resulat_attaque[i] = resulat;

            affiche_de(resulat);
            printf("\n");
        }
    
        tri_resultat(3, resulat_attaque);
    }
    
    if (attaquant == 2){
                 
        for (int i = 0; i<2; i++){
            
            int resulat = 0;
            while(resulat == 0){
                int nb_aleatoire = rand();
                resulat = nb_aleatoire%7;  
            }

            resulat_attaque[i] = resulat;

            affiche_de(resulat);
            printf("\n");
        }
    
        tri_resultat(3, resulat_attaque);
    }

    int resulat_defense[2] = {0};
    
    if (defenseur >= 2){
                 
        for (int i = 0; i<2; i++){
            
            int resulat = 0;
            while(resulat == 0){
                int nb_aleatoire = rand();
                resulat = nb_aleatoire%7;  
            }

            resulat_defense[i] = resulat;

            affiche_de(resulat);
            printf("\n");
        }
    
        tri_resultat(2, resulat_defense);
    }

    if (defenseur == 1){
         
        for (int i = 0; i<1; i++){
            
            int resulat = 0;
            while(resulat == 0){
                int nb_aleatoire = rand();
                resulat = nb_aleatoire%7;  
            }

            resulat_defense[i] = resulat;

            affiche_de(resulat);
            printf("\n");
        }
    
        
        // Le cas a un seul defenseur est matcher ici pour eviter des complications par la suite.
        
        // h_r veut dire higher_results ie : le meilleur des resultats de chacun des joueurs.
        bool h_r = (resulat_attaque[2] <= resulat_defense[0]); // Les tableaux sont tries donc on prend l'element d'indice le plus haut.

        if (h_r){
            perte_troupe[0] -= 1;
        }
        else if (!h_r){
            perte_troupe[1] -= 1;
        }
        return EXIT_SUCCESS;
    }


/* Ainsi on match les resultats (le plus grand avec le plus grand, le deuxieme plus grand avec le deuxieme plus grand), 
   puis on met a jour le tableau perte_troupe en renseignant la perte de troupe de chaques joueurs */
    
    // h_r veut dire higher_results ie : le meilleur des resultats de chacun des joueurs.
    bool h_r = (resulat_attaque[2] <= resulat_defense[1]);
    bool second_h_r = (resulat_attaque[1] <= resulat_defense[0]); 

    // Pour eviter de reecrire deux fois la meme chose.
    bool tmp = h_r;
    for (int i = 1; i<=2; i++){

        if (tmp){
            perte_troupe[0] -= 1;
        }
        else if (!tmp){
            perte_troupe[1] -= 1;
        }
        
        tmp = second_h_r;
    }

    return EXIT_SUCCESS;
}

int autorise_combat (int n, int matrice_graphe[n][n], int position_attaquant, int position_defenseur, int nb_attaquant, int nb_defenseur){
/* On verifie que les sommets renseignés sont bien dans le graphe 
    if (position_attaquant || position_defenseur > n){
        return -1;
    }
*/
/* On verifie si les territoires sont adjacents */
    if (matrice_graphe[position_attaquant][position_defenseur] == 0){
        return -2;
    }
/* On verifie si défenseur différent de 0 */
    if (nb_defenseur == 0){
        return -3;
    }
/* On verifie si attaquant plus grand que 2 */
    if (nb_attaquant <= 2){
        return -4;
    }
/* Si tout est bon : 1 */
    return 1;
    
}

int informe_joueur(int info, int phase){
/* Informe le joueur de la situation (si il a la capacité d'attaquer, la porté etc..) */        
        if (info == -1){
            printf ("Ce territoire n'existe pas\nVeuillez renseigner un territoire valide\n");
            return 1;
        }
        if (info == -2){
            printf ("C'est territoire ne sont pas voisins\nVeuillez renseigner deux territoires voisins\n");
            return 1;
        }
        if ((info == -3) && (phase == 0)){
            printf ("Le terroire est vide\n");
            return 1;
        }
        if ((info == -3) && (phase == 1)){
            printf ("L'attaquant a gagné\n");
            return 1;
        }
        if (info == -4){
            printf ("Il n'y a pas assez d'attaquant\n");
            return 1;
        }
        if (info == 1){
            return 0;
        }
}

int oui_ou_non(char s[10]){
/* Fonction pour savoir si une chaine de caractères est "non" ou "oui" */   
    char oui[4] = {'o','u','i','\0'};
    char non[4] = {'n','o','n','\0'};

    bool est_oui = true;
    bool est_non = true;
    
    for (int i = 0; i<3; i++){
        
        if (s[i] != oui[i]){
            est_oui = false;
        }
        
        if (s[i] != non[i]){
            est_non = false;
        }
    }

    if (est_oui){
        return 1;
    }
    if (est_non){
        return 2;
    }
    else {
        return -1;
    }
}

int devenir_du_combat() {
/* Après chaque attaque, il s'agira de s'informer si l'attaquant continue */    
    char reponse[11];
    printf ("Voulez-vous continuez ?\nRépondez par oui ou par non\n");
    printf ("Votre réponse est limitée à 3 caractères\n");
    scanf ("%s", reponse);
    
    int est_oui_ou_non = oui_ou_non(reponse);

    if (est_oui_ou_non == 1){
        return 1;
    }
    if (est_oui_ou_non == 2){
        return -1;
    }
    if (est_oui_ou_non == -1){
        printf ("Sans fautes d'orthographes\n");
        return devenir_du_combat();
    }
    
}
int desir_de_combat() {
/* Après chaque attaque, il s'agira de s'informer si l'attaquant continue */    
    char reponse[11];
    printf ("Voulez-vous attaquer ?\nRépondez par oui ou par non\n");
    printf ("Votre réponse est limitée à 3 caractères\n");
    scanf ("%s", reponse);
    
    int est_oui_ou_non = oui_ou_non(reponse);

    if (est_oui_ou_non == 1){
        return 1;
    }
    if (est_oui_ou_non == 2){
        return -1;
    }
    if (est_oui_ou_non == -1){
        printf ("Sans fautes d'orthographes\n");
        return devenir_du_combat();
    }
    return 0;
    
}