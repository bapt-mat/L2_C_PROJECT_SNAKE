#ifndef __MOD_PLATEAU__
#define __MOD_PLATEAU__

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include "types.h"

#define RESO_X 1600
#define RESO_Y 880
#define MAXI 600 

void creer_plateau(configuration *c,int n, int m);
int est_legal_mur(configuration *c, int x, int y);
void creer_mur_supp(configuration *c, int nb_murs, int taille_mur);
int est_legal_pomme(configuration *c);
void creer_pomme(configuration *c, int nb_pommes);
void effacer_pomme(configuration *c);
void creer_serpent(configuration *c);

#endif