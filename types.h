#ifndef __TYPES__
#define __TYPES__
#define MAX 40
#define MA 1600

typedef struct{
  int n, m;
  int tab[MAX][MAX];
  int nb_murs_supp;
  int taille_murs_supp;
}plateau;

typedef struct{
  int x;
  int y;
  int type_pomme;
  int nb_pommes;
}pomme;

typedef struct{
  int pos_x[MA];
  int pos_y[MA];
  int taille;
  int vitesse;
  char direction;
}serpent;

typedef struct{
  plateau plateau;
  pomme pomme;
  serpent serpent;
  int score;
  char mode;
}configuration;

#endif