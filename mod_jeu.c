
#include "mod_jeu.h"
#include "mod_plateau.h"
#include "mod_menu.h"


configuration creer_configuration(int n, int m, int vitesse, int nb_murs_supp, int taille_murs_supp, char dir, int nb_pommes, char mode){
	configuration config;
	config.score=0;
	creer_plateau(&config,n,m);
	creer_serpent(&config);
	config.pomme.nb_pommes=nb_pommes;
	creer_pomme(&config, nb_pommes);
	config.serpent.vitesse=vitesse;
	config.plateau.nb_murs_supp=nb_murs_supp;
	config.plateau.taille_murs_supp=taille_murs_supp;
	config.serpent.direction=dir;
	config.mode=mode;
	return config;
}

void indication(){

  /* Initialisation des coordonnées pour dessiner les flèches */

  int coord_x[7]={1420, 1450, 1435, 1435, 1405, 1405, 1390};
  int coord_y[7]={245, 290, 290, 320, 320, 290, 290};
  int coord_x1[7]={1381, 1426, 1426, 1456, 1456, 1426, 1426};
  int coord_y1[7]={363, 333, 348, 348, 378, 378, 393};
  int coord_x2[7]={1420, 1390, 1405, 1405, 1435, 1435, 1450};
  int coord_y2[7]={508, 463, 463, 433, 433, 463, 463};
  int coord_x3[7]={1381, 1381, 1411, 1411, 1456, 1411, 1411};
  int coord_y3[7]={550, 580, 580, 595, 565, 535, 550};

  /* --Fond-- */

  MLV_draw_filled_rectangle(1200,125,320,700,MLV_COLOR_DEEP_PINK);

  /* --Bouton ECHAP-- */

  MLV_draw_filled_rectangle(1215,145,80,80,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1210,140,80,80,MLV_COLOR_WHITE);
  MLV_draw_text(1225,165,"ECHAP",MLV_COLOR_BLACK);

  /* -- Flèche-- */

  MLV_draw_text(1313, 165,"==>",MLV_COLOR_BLACK);

  /* --Indication-- */

  MLV_draw_filled_rectangle(1386,145,80,80,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1381,140,80,80,MLV_COLOR_WHITE); 
  MLV_draw_text(1396,165,"PAUSE",MLV_COLOR_BLACK);

  /* --Déplacement-- */

  MLV_draw_filled_rectangle(1215,240,80,80,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1210,235,80,80,MLV_COLOR_WHITE);
  MLV_draw_text(1245,265,"Z",MLV_COLOR_BLACK);
  MLV_draw_text(1313, 265,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_polygon(coord_x, coord_y, 7, MLV_COLOR_WHITE);
  MLV_draw_polygon(coord_x, coord_y, 7, MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(1215,335,80,80,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1210,330,80,80,MLV_COLOR_WHITE);
  MLV_draw_text(1245,365,"Q",MLV_COLOR_BLACK);
  MLV_draw_text(1313,365,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_polygon(coord_x1, coord_y1, 7, MLV_COLOR_WHITE);
  MLV_draw_polygon(coord_x1, coord_y1, 7, MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(1215,435,80,80,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1210,430,80,80,MLV_COLOR_WHITE);
  MLV_draw_text(1245,465,"S",MLV_COLOR_BLACK);
  MLV_draw_text(1313,465,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_polygon(coord_x2, coord_y2, 7, MLV_COLOR_WHITE);
  MLV_draw_polygon(coord_x2, coord_y2, 7, MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(1215,535,80,80,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1210,530,80,80,MLV_COLOR_WHITE);
  MLV_draw_text(1245,565,"D",MLV_COLOR_BLACK);
  MLV_draw_text(1313,565,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_polygon(coord_x3, coord_y3, 7, MLV_COLOR_WHITE);
  MLV_draw_polygon(coord_x3, coord_y3, 7, MLV_COLOR_BLACK);

  /* --Pommes-- */

  /* -Pomme classique-*/

  MLV_draw_filled_circle(1250, 645, 15, MLV_COLOR_RED);
  MLV_draw_circle(1250, 645, 15, MLV_COLOR_BLACK);
  MLV_draw_filled_ellipse(1250,627,3,7,MLV_COLOR_GREEN);
  MLV_draw_text(1313,635,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1386,630,80,30,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1381,625,80,30,MLV_COLOR_WHITE);
  MLV_draw_text(1386, 633,"TAILLE +1", MLV_COLOR_BLACK);

  /* -Pomme +2- */

  MLV_draw_filled_circle(1250, 695, 15, MLV_COLOR_CHOCOLATE4);
  MLV_draw_circle(1250, 695, 15, MLV_COLOR_BLACK);
  MLV_draw_filled_ellipse(1250,677,3,7,MLV_COLOR_GREEN);
  MLV_draw_text(1313,685,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1386,680,80,30,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1381,675,80,30,MLV_COLOR_WHITE);
  MLV_draw_text(1386, 683,"TAILLE +2", MLV_COLOR_BLACK);

  /* -Pomme -1-*/

  MLV_draw_filled_circle(1250, 745, 15, MLV_COLOR_GOLD);
  MLV_draw_circle(1250, 745, 15, MLV_COLOR_BLACK);
  MLV_draw_filled_ellipse(1250,727,3,7,MLV_COLOR_GREEN);
  MLV_draw_text(1313,735,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1386,730,80,30,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1381,725,80,30,MLV_COLOR_WHITE);
  MLV_draw_text(1386, 733,"TAILLE -1", MLV_COLOR_BLACK);

  /* -Pomme Accélération- */

  MLV_draw_filled_circle(1250, 795, 15, MLV_COLOR_LIGHT_BLUE);
  MLV_draw_circle(1250, 795, 15, MLV_COLOR_BLACK);
  MLV_draw_filled_ellipse(1250,777,3,7,MLV_COLOR_GREEN);
  MLV_draw_text(1313,785,"==>",MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1384,780,86,30,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1379,775,86,30,MLV_COLOR_WHITE);
  MLV_draw_text(1381, 783,"VITESSE +1", MLV_COLOR_BLACK);  

}

void affichage_configuration(configuration *c){
	int i,j, cnt1=0, cnt2=0;
	int n=c->plateau.n;
	int m=c->plateau.m;
	char message[50]="VOTRE SCORE : ";
	char l[10];

	sprintf(l, "%d", c->score);
	strcat(message, l);

	MLV_clear_window(MLV_COLOR_BLACK);

	c->plateau.tab[0][0]=3;

    for(i=0 ; i<n ; i++){ /*relation matrice et plateau visuel*/
		for(j=0 ; j<m ; j++){

			if(c->plateau.tab[i][j]==0){ /*vide*/
				if (i%2==0){
					if (j%2==0){
						MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
						MLV_draw_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
						cnt1=cnt1+20;
					}
					else {
						MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE4);
						MLV_draw_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE4);
						cnt1=cnt1+20;
					}
				}
				else{
					if(j%2==0){
						MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE4);
						MLV_draw_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE4);
						cnt1=cnt1+20;
					}
					else {
						MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
						MLV_draw_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
						cnt1=cnt1+20;
					}
				}
			}

			if(c->plateau.tab[i][j]==3){ /*mur*/
				MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_DARK_BLUE);
				cnt1=cnt1+20;
			}

			if(c->plateau.tab[i][j]==2){ /*pomme normale*/
                MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
                MLV_draw_filled_circle((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2,8, MLV_COLOR_RED);
				MLV_draw_filled_ellipse((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2-12,2,4, MLV_COLOR_GREEN);
                cnt1=cnt1+20;
            }
            if(c->plateau.tab[i][j]==1){ /*serpent*/
                MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_DEEPPINK);
                cnt1=cnt1+20;
            }
            if(c->plateau.tab[i][j]==4){ /*pomme +2*/
                MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
                MLV_draw_filled_circle((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2,8, MLV_COLOR_CHOCOLATE4);
				MLV_draw_filled_ellipse((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2-12,2,4, MLV_COLOR_GREEN);
                cnt1=cnt1+20;
            }
            if(c->plateau.tab[i][j]==5){ /*pomme -1*/
                MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
                MLV_draw_filled_circle((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2,8, MLV_COLOR_GOLD);
				MLV_draw_filled_ellipse((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2-12,2,4, MLV_COLOR_GREEN);
                cnt1=cnt1+20;
            }
	    if(c->plateau.tab[i][j]==6){ /*pomme -1*/
                MLV_draw_filled_rectangle((RES_X/2-n/2*20)+cnt1,(RES_Y/2-m/2*20)+cnt2,20,20,MLV_COLOR_PURPLE);
                MLV_draw_filled_circle((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2,8, MLV_COLOR_LIGHT_BLUE);
				MLV_draw_filled_ellipse((RES_X/2-n/2*20+10)+cnt1,(RES_Y/2-m/2*20+10)+cnt2-12,2,4, MLV_COLOR_GREEN);
                cnt1=cnt1+20;
            }
		}
        cnt2=cnt2+20;
        cnt1=0;
    }

	indication();

	/* --Affichage du score-- */

	MLV_draw_filled_rectangle(05,180,137,32,MLV_COLOR_BLACK);
	MLV_draw_adapted_text_box(200,175,message,9,MLV_COLOR_DEEP_PINK,MLV_COLOR_BLACK,MLV_COLOR_DEEP_PINK,MLV_TEXT_CENTER);

	MLV_actualise_window();
}

char deplacement_serp(configuration *c, char dir_actuelle, MLV_Keyboard_button touche, int pomme_mur){
	int i, j, tmp_x[MAXIM], tmp_y[MAXIM], dir_x=0, dir_y=0;
	int eff_queue=c->serpent.taille-1;	
	char retour='m';

	/* --Détermination de la direction-- */

	switch(touche){

	case MLV_KEYBOARD_z :
		if(dir_actuelle=='s'){
			return dir_actuelle;
		}
		dir_actuelle='z';
		break;

	case MLV_KEYBOARD_q :
		if(dir_actuelle=='d'){
			return dir_actuelle;
		}
		dir_actuelle='q';
		break;

	case MLV_KEYBOARD_s :
		if(dir_actuelle=='z'){
			return dir_actuelle;
		}
		dir_actuelle='s';
		break;

	case MLV_KEYBOARD_d :
		if(dir_actuelle=='q'){
			return dir_actuelle;
		}
		dir_actuelle='d';
		break;

	case MLV_KEYBOARD_ESCAPE :
		c->serpent.direction=dir_actuelle;
		retour = menu_pause(c);
		break;

	default :
		break;
	}
	
	if(retour =='2'){
		return retour;
	}


	switch(dir_actuelle){
	case 'z' :
		dir_x=-1;
		dir_y=0;
		break; 

	case 'q' :
		dir_x=0;
		dir_y=-1;
		break; 

	case 's' :
		dir_x=1;
		dir_y=0;
		break;

	case 'd' :
		dir_x=0;
		dir_y=1;
		break;

	default :
		break;

	}

	/* Tableau temporaire des coordonnées du serpent */

	for(j=0; j<c->serpent.taille;j++){
    	tmp_x[j]=c->serpent.pos_x[j];  
    	tmp_y[j]=c->serpent.pos_y[j];		
	}

	/* Déplacement de la tête dans la direction voulue */

	c->serpent.pos_x[0]=c->serpent.pos_x[0]+dir_x;
	c->serpent.pos_y[0]=c->serpent.pos_y[0]+dir_y;

	/* Rencontre avec Pommes ou Murs */

	switch(c->plateau.tab[c->serpent.pos_x[0]][c->serpent.pos_y[0]]){

	case 1 :
		retour = menu_lose(c);
		break;


	case 2 :
		effacer_pomme(c);
		eff_queue=c->serpent.taille-1;
		c->serpent.taille += 1;
		c->score += 1;
		creer_pomme(c, c->pomme.nb_pommes);
		creer_mur_supp(c, pomme_mur, pomme_mur);
		break;

	case 3 :
		retour = menu_lose(c);
		break;

	case 4 :
		effacer_pomme(c);
		eff_queue=c->serpent.taille;
		tmp_x[c->serpent.taille]=tmp_x[0];
		tmp_y[c->serpent.taille]=tmp_y[0];
		tmp_x[c->serpent.taille+1]=tmp_x[0];
		tmp_y[c->serpent.taille+1]=tmp_y[0];
		c->serpent.taille += 2;
		c->score += 1;
		creer_pomme(c, c->pomme.nb_pommes);
		creer_mur_supp(c, pomme_mur, pomme_mur);
		break;

	case 5 :
		effacer_pomme(c);
		eff_queue=c->serpent.taille-2;
		c->serpent.taille -= 1;
		c->plateau.tab[tmp_x[c->serpent.taille]][tmp_y[c->serpent.taille]]=0;
		c->score += 1;
		creer_pomme(c, c->pomme.nb_pommes);
		creer_mur_supp(c, pomme_mur, pomme_mur);
		break;


	case 6 :
	    effacer_pomme(c);
		eff_queue=c->serpent.taille-1;
		c->serpent.taille += 1;
		c->score += 1;
		creer_pomme(c, c->pomme.nb_pommes);
		creer_mur_supp(c, pomme_mur, pomme_mur);
		c->serpent.vitesse++;
		MLV_change_frame_rate(c->serpent.vitesse);
		break;
		
	}

	if(retour=='1'){
		return retour;
	}

	if(retour=='2'){
		return retour;
	}

	if(retour=='3'){
		return retour;
	}

	/* Efface la queue */

	c->plateau.tab[tmp_x[eff_queue]][tmp_y[eff_queue]]=0;

	/* déplacement du serpent entier */

	for(i=1; i<c->serpent.taille; i++){
	  c->plateau.tab[c->serpent.pos_x[0]][c->serpent.pos_y[0]]=1;
	  c->serpent.pos_x[i]=tmp_x[i-1];
	  c->serpent.pos_y[i]=tmp_y[i-1];
	  c->plateau.tab[c->serpent.pos_x[i]][c->serpent.pos_y[i]]=1;		
	}
	MLV_flush_event_queue();
	return dir_actuelle;
}

int jeu(configuration config){

	int retour=0;
	int pomme_mur=0;
	MLV_Keyboard_button touche=MLV_KEYBOARD_NONE;
	MLV_Button_state etat=MLV_RELEASED;

	if (config.plateau.nb_murs_supp !=1 || config.plateau.taille_murs_supp !=1){
		creer_mur_supp(&config, config.plateau.nb_murs_supp, config.plateau.taille_murs_supp);
	}
	else {
		pomme_mur=1;
	}
	
	MLV_change_frame_rate(config.serpent.vitesse);
	/* --Debut du jeu-- */
	
	do{
		touche=MLV_KEYBOARD_NONE;
		etat=MLV_RELEASED;

		MLV_get_event(&touche,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&etat);
		
		if (etat==MLV_PRESSED){
			config.serpent.direction = deplacement_serp(&config, config.serpent.direction, touche, pomme_mur);
		}
		else{
			touche=MLV_KEYBOARD_NONE;
			config.serpent.direction = deplacement_serp(&config, config.serpent.direction, touche, pomme_mur);
		}
		
		if(config.serpent.direction=='1'){
			retour = 1;
			break;
		}
		if(config.serpent.direction=='2'){
			retour = 2;
			break;
		}
		if(config.serpent.direction=='3'){
			retour = 3;
			break;
		}

		affichage_configuration(&config);	
		MLV_delay_according_to_frame_rate();

			
	}while(1);

	return retour;
}

