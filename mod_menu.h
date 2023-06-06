#ifndef __MOD_MENU__
#define __MOD_MENU__

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <string.h>
#include "types.h"

#define RES_X 1600
#define RES_Y 880
#define N 20
#define M 20

void afficher_menu_principal();
int menu_principal();
void afficher_menu_sauvegarde();
int menu_sauvegarde();
void afficher_meilleurs_scores();
int menu_scores();
void afficher_new_game();
int menu_new_game();
void afficher_menu_custom(char *texte1, char * texte2, char *texte3, char *texte4, char *texte5);
int menu_custom();
void bouton_retour();
void afficher_save();
int sauvegarde(configuration *c);
void afficher_menu_pause();
char menu_pause(configuration *c);
void afficher_menu_lose(int score, int indic);
char menu_lose(configuration *c);

#endif
