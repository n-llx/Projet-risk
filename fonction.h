struct Coords
{
  int x;
  int y;
};
typedef struct Coords Coords;

struct InfoCase
{
  char nom_de_la_case;
  int nombre_de_troupe;
  char couleur_de_la_case;
};
typedef struct InfoCase InfoCase;

void initialisation_jeu(int nombre_joueurs, int nb_territoire, char map[35][100], Coords liste_territoire[30][200], char map_colored[35][100], InfoCase info_territoire[6]);
bool est_dans_la_liste (char element, char liste[6]);
void grid_initialization(char grid_result[35][100]);
void from_char_to_number(char lettre, char couleur[5]);
void print_colored_grid(char colored_grid[35][100]);
void print_grid(char grid[35][100]);
void print_grid_aux(Coords grid[30][200]);
void grille_liste_territoire(char grid[35][100], Coords liste_territoire[30][200]);


