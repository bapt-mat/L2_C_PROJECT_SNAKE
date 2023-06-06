#include "mod_plateau.h"
#include "mod_menu.h"
#include "mod_save.h"

/*PLATEAU*/

void creer_plateau (configuration *c,int n, int m){
  int i,j;
  for(i=0; i<n ; i++){
    for(j=0; j<m ; j++){
      if ((j==0) || (j==n-1) || (i==0) || (i==m-1)){
        c->plateau.tab[i][j]=3; /*creation des murs*/
      }
      else {
        c->plateau.tab[i][j]=0; /*creation du "vide"*/
      }
      
    }
  }
  c->plateau.n=n;
  c->plateau.m=m;
}

int est_legal_mur(configuration *c, int x, int y){
  if ((c->plateau.tab[x][y])!=0 || x==c->plateau.n/2){
    return 0;
  }
  else{
    return 1;
  }
}

void creer_mur_supp(configuration *c, int nb_murs, int taille_mur){
  int i, cnt_nb_murs=0, dir_mur_x, dir_mur_y;
  int x = rand()%((c->plateau.n)-1)+1; /*coor aleatoire du mur*/
  int y = rand()%((c->plateau.m)-1)+1;
  
  while(cnt_nb_murs<nb_murs){

    while (!est_legal_mur(c,x,y)){ /*verif des coor*/
      x = rand()%((c->plateau.n)-1)+1; /*nouvelles coor si elles ne sont pas ok*/
      y = rand()%((c->plateau.m)-1)+1;
    }

    if (taille_mur == 0){ /*taille aléatoire si la taille passé en param est 0*/
      taille_mur = rand()%(6-2)+2; 
    }

    dir_mur_x = rand()%(3)+1; /*direction aleatoire du mur*/
    switch (dir_mur_x){
      case 1 : 
        dir_mur_x=1;
        break;
      case 2 :
        dir_mur_x=-1;
        break;
      case 3 :
        dir_mur_x=0;
        break;
    }

    dir_mur_y = rand()%(3-1+1)+1;
    switch (dir_mur_y){
      case 1 : 
        dir_mur_y=1;
        break;
      case 2 :
        dir_mur_y=-1;
        break;
      case 3 :
        dir_mur_y=0;
        break;

    }

    for (i=0; i<taille_mur; i++){ /*creation du mur*/
      c->plateau.tab[x][y]=3;
      x+=dir_mur_x;
      y+=dir_mur_y;
      if (!est_legal_mur(c,x,y)){ /*on sort de la boucle si une coor du mur n'est pas légal*/
        i=taille_mur;
      }
    }

    x = rand()%((c->plateau.n)-1)+1; /*nouvelles coor pour le prochain mur*/
    y = rand()%((c->plateau.m)-1)+1;
    cnt_nb_murs++;
  }
}

/*POMME*/

int est_legal_pomme(configuration *c){
  if (c->plateau.tab[c->pomme.x][c->pomme.y]!=0){
    return 0;
  }
  else{
    return 1;
  }
}

void creer_pomme(configuration *c, int nb_pommes){
  /*creation de la pomme*/
  int n=c->plateau.n;
  int m=c->plateau.m;
  int type_pomme;
  int i;

  for (i=0;i<nb_pommes;i++){
    
    c->pomme.x=(rand()%(n));
    c->pomme.y=(rand()%(m));
    while (!est_legal_pomme(c)){
      c->pomme.x=(rand()%(n));
      c->pomme.y=(rand()%(m));
    }
  
  /*type pomme*/

    type_pomme=rand()%100;

    if (type_pomme<=10){
      c->plateau.tab[c->pomme.x][c->pomme.y]=4; /*pomme +2 -> 10% de chance*/
      c->pomme.type_pomme=4;
    }
    else {
      if (type_pomme<=20){
          c->plateau.tab[c->pomme.x][c->pomme.y]=5; /*pomme -1 -> 10% de chance*/
          c->pomme.type_pomme=5;
      }
      else {
	if (type_pomme<=25){  
	  c->plateau.tab[c->pomme.x][c->pomme.y]=6; /*pomme accélération -> 5% de chance*/
          c->pomme.type_pomme=6;

	    }
	else { 
          c->plateau.tab[c->pomme.x][c->pomme.y]=2; /*pomme +1 -> 75% de chance*/
          c->pomme.type_pomme=2;
	}
      }
    }
  }
}

void effacer_pomme(configuration *c){
  int i, j;
  for (i=0; i<c->plateau.n; i++){
    for (j=0; j<c->plateau.m; j++){
      if (c->plateau.tab[i][j]==4 || c->plateau.tab[i][j]==5 || c->plateau.tab[i][j]==2 || c->plateau.tab[i][j]==6){
        c->plateau.tab[i][j]=0;
      }
    }
  }
}

/*SERPENT*/

void creer_serpent(configuration *c){
  int i,pos_x,pos_y;
  pos_x=c->plateau.n/2;
  pos_y=c->plateau.m/2;
  c->serpent.taille = 3;
  for (i=0; i<c->serpent.taille ; i++){
    c->plateau.tab[pos_x][pos_y]=1;
    c->serpent.pos_x[i]=pos_x;
    c->serpent.pos_y[i]=pos_y;
    pos_y--;
  }
}

