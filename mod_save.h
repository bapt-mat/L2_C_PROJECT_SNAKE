#ifndef __MOD_SAVE__
#define __MOD_SAVE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

void sauvegarder(configuration *c, int indic);
char charger(configuration *c, int indic);
void save_score(int score, char mode);

#endif