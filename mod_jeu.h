#ifndef __MOD_JEU__
#define __MOD_JEU__

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include "types.h"

#define RES_X 1600
#define RES_Y 880
#define MAXIM 600 

void bouton_pause();
void affichage_configuration(configuration *c);
char deplacement_serp(configuration *c, char dir_actuelle, MLV_Keyboard_button touche, int pomme_mur);
configuration creer_configuration(int n, int m, int vitesse, int nb_murs_supp, int taille_murs_supp, char dir, int nb_pommes, char mode);
int jeu(configuration config);
int reprendre_jeu(configuration config);

#endif
