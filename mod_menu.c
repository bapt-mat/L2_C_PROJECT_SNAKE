#include "mod_menu.h"
#include "mod_jeu.h"
#include "mod_save.h"

void afficher_menu_principal(){

  MLV_Image *fond;
  MLV_Image *titre;

  /* --Background du menu-- */

  MLV_clear_window(MLV_COLOR_GREY);
  fond = MLV_load_image("Images/fond.jpg");
  titre = MLV_load_image("Images/titre.png");
  MLV_resize_image(fond,1600,880);
  MLV_resize_image_with_proportions(titre, 400, 260);

  MLV_draw_image(fond,0,0);
  MLV_draw_image(titre, 615,20);


  /* --Cases du menu-- */
  
  MLV_draw_filled_rectangle(610,220,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,210,400,130,MLV_COLOR_DEEP_PINK);
  
  MLV_draw_filled_rectangle(610,370,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,360,400,130,MLV_COLOR_DEEP_PINK);

  MLV_draw_filled_rectangle(610,520,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,510,400,130,MLV_COLOR_DEEP_PINK);

  MLV_draw_filled_rectangle(610,670,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,660,400,130,MLV_COLOR_DEEP_PINK);


  /* --Ecriture dans les cases-- */

  MLV_draw_text(725,265,"NOUVELLE PARTIE", MLV_COLOR_BLACK);
  MLV_draw_text(730,415,"CHARGER PARTIE", MLV_COLOR_BLACK);
  MLV_draw_text(725,565,"MEILLEURS SCORES", MLV_COLOR_BLACK);
  MLV_draw_text(760,715,"QUITTER",MLV_COLOR_BLACK);

  MLV_actualise_window();
  MLV_free_image(fond);
  MLV_free_image(titre);
}

int menu_principal(){

  int retour=0, x, y;

  /* --Affichage-- */

  afficher_menu_principal();

  /* --Récupération du clic et renvoie de la valeur pour le suivant-- */

  MLV_wait_mouse(&x, &y);

  if((x>600 && x<1010)&&(y>210 && y<350)){
    retour=1;
  }
  if((x>600 && x<1010)&&(y>360 && y<500)){
    retour=2;
  }
  if((x>600 && x<1010)&&(y>510 && y<650)){
    retour=3;
  }
  if((x>600 && x<1010)&&(y>660 && y<800)){
    retour=4;
  }

  return retour;
}

void afficher_menu_sauvegarde(){

  MLV_Image *fond;
  /* --Background du Menu-- */

  MLV_clear_window(MLV_COLOR_BLACK);

  fond = MLV_load_image("Images/fond.jpg");
  MLV_resize_image(fond,1600,880);
  MLV_draw_image(fond,0,0);

  /* --Cases des sauvegardes-- */

  MLV_draw_filled_rectangle(610,220,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,210,400,130,MLV_COLOR_DEEP_PINK);

  MLV_draw_filled_rectangle(610,390,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,380,400,130,MLV_COLOR_DEEP_PINK);

  MLV_draw_filled_rectangle(610,560,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,550,400,130,MLV_COLOR_DEEP_PINK);

  /* --Ecriture dans les cases-- */

  MLV_draw_text(740,265,"SAUVEGARDE 1",MLV_COLOR_BLACK);
  MLV_draw_text(740,435,"SAUVEGARDE 2",MLV_COLOR_BLACK);
  MLV_draw_text(740,605,"SAUVEGARDE 3",MLV_COLOR_BLACK);

  /* --Bouton Retour-- */

  bouton_retour();

  MLV_actualise_window();
  MLV_free_image(fond);
}

int menu_sauvegarde(){
  int retour=0, x, y, cnt=0, v;
  configuration c;
  while(cnt==0){
    afficher_menu_sauvegarde();
    MLV_wait_mouse(&x, &y);

    /* --Charger la sauvegarde 1-- */

    if((x>600 && x<1010) && (y>210 && y<350)){
      c.serpent.direction = charger(&c, 1);
      v=jeu(c);
      if(v==3){
       menu_scores();
       cnt=1;
      }
      if(v==2){
       cnt=1;
      }
      if(v==1){
        menu_new_game();
        cnt=1;
      }
    }

    /* --Charger la sauvegarde 2-- */

    if((x>600 && x<1010)&&(y>380 && y<520)){
      c.serpent.direction = charger(&c, 2);
      v=jeu(c);
      if(v==3){
       menu_scores();
       cnt=1;
      }
      if(v==2){
       cnt=1;
      }
      if(v==1){
        menu_new_game();
        cnt=1;
      }
    }

    /* --Charger la sauvegarde 3-- */

    if((x>600 && x<1010)&&(y>550 && y<690)){
      c.serpent.direction = charger(&c, 3);
      v=jeu(c);
      if(v==3){
       menu_scores();
       cnt=1;
      }
      if(v==2){
       cnt=1;
      }
      if(v==1){
        menu_new_game();
        cnt=1;
      }
    }

    /* --Retour-- */

    if((x>1400 && x<1560)&&(y>105 && y<215)){
      cnt =1;
    }
  }

  return retour;
}

void afficher_meilleurs_scores(){
  MLV_Image *fond;
  MLV_Image *titre;
  FILE *f;
  int i;
  int tab[10];
  char mode[10];
  char mod[20];
  char p[10];
  char cla[25];

  /* --Récupération des scores et du mode-- */

  if((f = fopen("saves/scores.txt", "r+")) == NULL){ 
    printf("erreur ouverture");
  }

  for(i=0 ; i<10 ; i++){
    if(fscanf(f, "%d %c", &tab[i], &mode[i])!=2){
      printf("oups\n");
    }
  }

  fclose(f);

  /* --Background du Menu-- */

  MLV_clear_window(MLV_COLOR_GREY);

  fond = MLV_load_image("Images/fond.jpg");
  titre = MLV_load_image("Images/meilleurs_scores.png");
  MLV_resize_image(fond,1600,880);
  MLV_resize_image(titre, 450, 250);
  MLV_draw_image(fond,0,0);
  MLV_draw_image(titre, 580, 0);
  

  /* --Bouton Retour-- */

  bouton_retour();


  MLV_draw_filled_rectangle(610,220,400,500,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,210,400,500,MLV_COLOR_PURPLE4);

  /* --Attribution du mode-- */

  strcpy(mod, ""); /*Pour être sûr de pas avoir de débris dedans*/

  switch(mode[0]){
  case 'e':
    strcat(mod, "EASY");
    break;
  case 'm':
    strcat(mod, "MEDIUM");
    break;
  case 'd':
    strcat(mod, "HARD");
    break;
  case 'h':
    strcat(mod, "HELL");
    break;
  default:
    strcat(mod, "EASY");
  }

  /* --Affichage du premier-- */
  i=1;
  sprintf(cla, "%d - %s", i, mod);
  sprintf(p, "%d", tab[i-1]);
  MLV_draw_text(650,240, cla, MLV_COLOR_YELLOW);   
  MLV_draw_text(900,240,p,MLV_COLOR_GOLD);

  /* --Affichage des autres-- */

  for(i=1 ; i<10 ; i++){
    strcpy(mod, "");  /*réinitialiser mod à chaque fois*/

    switch(mode[i]){
    case 'e':
      strcat(mod, "EASY");
      break;
    case 'm':
      strcat(mod, "MEDIUM");
      break;
    case 'd':
      strcat(mod, "HARD");
      break;
    case 'h':
      strcat(mod, "HELL");
      break;
    default:
      printf("shit\n");
    }

    sprintf(cla, "%d - %s", i+1, mod);
    sprintf(p, "%d", tab[i]);
    if(mode[i]=='h'){
      MLV_draw_text(650, 240+i*49, cla, MLV_COLOR_FIREBRICK2);
      MLV_draw_text(900, 240+i*49, p, MLV_COLOR_FIREBRICK2);
    }
    else{
      MLV_draw_text(650, 240+i*49, cla, MLV_COLOR_WHITE);
      MLV_draw_text(900, 240+i*49, p, MLV_COLOR_WHITE);
    }

  }

  MLV_actualise_window();
  MLV_free_image(fond);
  MLV_free_image(titre);
}

int menu_scores(){
  int retour=0, x, y, cnt=0;

  /* --Affichage-- */

  afficher_meilleurs_scores();

  while(cnt==0){
    MLV_wait_mouse(&x, &y);
    if((x>1400 && x<1560)&&(y>105 && y<215)){
      cnt = 1;
    }
  }
  return retour;
}

void afficher_new_game(){

  MLV_Image *fond;

  /* --Background du menu-- */

  MLV_clear_window(MLV_COLOR_GREY);

  fond = MLV_load_image("Images/fond.jpg");
  MLV_resize_image(fond,1600,880);
  MLV_draw_image(fond,0,0); 

  /* --Cases-- */

  MLV_draw_filled_rectangle(610,100,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,90,400,130,MLV_COLOR_LIGHT_BLUE);
  
  MLV_draw_filled_rectangle(610,250,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,240,400,130,MLV_COLOR_YELLOW);

  MLV_draw_filled_rectangle(610,400,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,390,400,130,MLV_COLOR_ORANGERED);

  MLV_draw_filled_rectangle(610,550,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,540,400,130,MLV_COLOR_FIREBRICK4);
  
  MLV_draw_filled_rectangle(610,700,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,690,400,130,MLV_COLOR_DEEP_PINK);


  /* --Text-- */

  MLV_draw_text(775,145,"EASY", MLV_COLOR_BLACK);
  MLV_draw_text(775,295,"MEDIUM", MLV_COLOR_BLACK);
  MLV_draw_text(775,445,"HARD", MLV_COLOR_BLACK);
  MLV_draw_text(775,600,"HELL",MLV_COLOR_BLACK);
  MLV_draw_text(775,745,"CUSTOM",MLV_COLOR_BLACK);

  /* --Bouton retour-- */

  bouton_retour();

  MLV_actualise_window();
  MLV_free_image(fond);
}

int menu_new_game(){
  configuration config;
  int retour=0, x, y, cnt=0, v;
  while(cnt==0){

    /* --Affichage-- */

    afficher_new_game();

    /* --Attente du clic-- */
 
    MLV_wait_mouse(&x, &y);

    if((x>600 && x<1010)&&(y>90 && y<220)){ /*mode facile*/
    config=creer_configuration(N, M, 7, 0, 0, 'd', 1, 'e');
     v=jeu(config);
     if(v==3){
       menu_scores();
       cnt=1;
     }
     if(v==2){
       cnt=1;
     }
}
   if((x>600 && x<1010)&&(y>240 && y<370)){ /*mode medium*/
     config=creer_configuration(N, M, 10, 0, 0, 'd', 1, 'm');
     v=jeu(config);
     if(v==3){
       menu_scores();
       cnt=1;
     }
     if(v==2){
       cnt=1;
     }
   }
   if((x>600 && x<1010)&&(y>390 && y<520)){ /*mode hard*/
     config=creer_configuration(N, M, 15, 0, 0, 'd', 1, 'd');
     v=jeu(config);
     if(v==3){
       menu_scores();
       cnt=1;
     }
     if(v==2){
       cnt=1;
     }
   }
   if((x>600 && x<1010)&&(y>540 && y<670)){ /*mode hell*/
     config=creer_configuration(N+10, M+10, 16, 25, 1, 'd', 1, 'h');
     v=jeu(config);
     if(v==3){
       menu_scores();
       cnt=1;
     }
     if(v==2){
       cnt=1;
     }
   }

    /* --Mode Customisable-- */

    if((x>600 && x<1010)&&(y>690 && y<820)){
 
      menu_custom();

    }

    /* --Retour-- */

    if((x>1400 && x<1550)&&(y>105 && y<205)){
      cnt=1;
    }
  }
 
  return retour;
}

void afficher_menu_custom(char *texte1, char * texte2, char * texte3, char * texte4, char * texte5){

  MLV_Image *fond;

  /* --Background du menu-- */

  MLV_clear_window(MLV_COLOR_GREY);

  fond = MLV_load_image("Images/fond.jpg");
  MLV_resize_image(fond,1600,880);
  MLV_draw_image(fond,0,0);

  /* --Caractéristiques du Plateau-- */

  MLV_draw_adapted_text_box(225,135,"Entrez les caractéristiques de votre plateau de jeu :",9,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_COLOR_PURPLE4,MLV_TEXT_CENTER);

  MLV_draw_filled_rectangle(676,177,27,22,MLV_COLOR_RED);
  MLV_draw_rectangle(676,177,27,22,MLV_COLOR_BLACK);
  MLV_draw_text(680,180,texte1,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(826,177,27,22,MLV_COLOR_RED);
  MLV_draw_rectangle(826,177,27,22,MLV_COLOR_BLACK);
  MLV_draw_text(830,180,texte2,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(976,177,27,22,MLV_COLOR_RED);
  MLV_draw_rectangle(976,177,27,22,MLV_COLOR_BLACK);
  MLV_draw_text(980,180,texte3,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(1126,177,27,22,MLV_COLOR_RED);
  MLV_draw_rectangle(1126,177,27,22,MLV_COLOR_BLACK);
  MLV_draw_text(1130,180,texte4,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(1276,177,27,22,MLV_COLOR_RED);
  MLV_draw_rectangle(1276,177,27,22,MLV_COLOR_BLACK);
  MLV_draw_text(1278,180,texte5,MLV_COLOR_BLACK);


  MLV_draw_all_input_boxes();

  MLV_draw_adapted_text_box(680,85,"REMPLIR ICI",9,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_COLOR_PURPLE4,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(935,85,"METTRE 0 SI AUCUN MUR",9,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_COLOR_PURPLE4,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(750,235,"----ENSUITE----",9,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_COLOR_PURPLE4,MLV_TEXT_CENTER);
  MLV_draw_adapted_text_box(1200,235,"ALEATOIRE",9,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_DEEPPINK,MLV_TEXT_CENTER);

  /* --Vitesse de jeu-- */

  MLV_draw_adapted_text_box(680,285,"CHOISIR LA VITESSE DU SERPENT :",9,MLV_COLOR_BLACK,MLV_COLOR_WHITE,MLV_COLOR_PURPLE4,MLV_TEXT_CENTER);

  MLV_draw_filled_rectangle(670,345,300,115,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(660,335,300,115,MLV_COLOR_DEEP_PINK);
  MLV_draw_text(790,385,"LENT",MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(670,480,300,115,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(660,470,300,115,MLV_COLOR_DEEP_PINK);
  MLV_draw_text(790,520,"MOYEN",MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(670,615,300,115,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(660,605,300,115,MLV_COLOR_DEEP_PINK);
  MLV_draw_text(790,655,"RAPIDE",MLV_COLOR_BLACK);


  /* --Bouton Retour-- */

  bouton_retour();

  MLV_actualise_window();
  MLV_free_image(fond);

}

int menu_custom(){
  configuration config;
  int retour=0, x, y, cnt=0,vitesse;
  int n, m, v, nb_murs, taille_murs, nb_pommes;
  char* texte, *texte1, *texte2, *texte3, *texte4, *texte5;
  MLV_Input_box *input_box, *input_box_1, *input_box_2, *input_box_3, *input_box_4, *input_box_5;
  MLV_Event event;
  MLV_Button_state etat=MLV_RELEASED;

  /* --Création de la première boîte de saisie-- */

  input_box_1 = MLV_create_input_box(
				     620,135,
				     110,30,
				     MLV_COLOR_BLACK,MLV_COLOR_BLACK,
				     MLV_COLOR_DEEP_PINK,"Longueur : "
				     );
  texte1 = (char*) malloc( 1*sizeof(char) ); *texte1 = '\0';

  /* --Création de la deuxième boîte de saisie-- */

  input_box_2 = MLV_create_input_box(
				     750,135,
				     100,30,
				     MLV_COLOR_BLACK,MLV_COLOR_BLACK,
				     MLV_COLOR_DEEP_PINK,"Largeur : "
				     );
  texte2 = (char*) malloc( 1*sizeof(char) ); *texte2 = '\0';

  /* --Création de la troisième boîte de saisie-- */

  input_box_3 = MLV_create_input_box(
				     890,135,
				     130,30,
				     MLV_COLOR_BLACK,MLV_COLOR_BLACK,
				     MLV_COLOR_DEEP_PINK,"Nombre_murs : "
				     );
  texte3 = (char*) malloc( 1*sizeof(char) ); *texte3 = '\0';

  /* --Création de la quatrième boîte de saisie-- */

  input_box_4 = MLV_create_input_box(
				     1040,135,
				     120,30,
				     MLV_COLOR_BLACK,MLV_COLOR_BLACK,
				     MLV_COLOR_DEEP_PINK,"Taille_murs : "
				     );
  texte4 = (char*) malloc( 1*sizeof(char) ); *texte4 = '\0';

  /* --Création de la cinquième boîte de saisie-- */

  input_box_5 = MLV_create_input_box(
				     1180,135,
				     155,30,
				     MLV_COLOR_BLACK,MLV_COLOR_BLACK,
				     MLV_COLOR_DEEP_PINK,"Nombre_pommes : "
				     );
  texte5 = (char*) malloc( 1*sizeof(char) ); *texte5 = '\0';

  /* --Récupération des dimensions dans les 'input_boxes' ou de clicks-- */
  
  do{

    event = MLV_NONE;

    /* --Récupération d'event 'input box' ou de clicks-- */

    event = MLV_get_event(NULL,NULL,NULL,&texte,&input_box,&x,&y,NULL,&etat);

    switch(event){

    case MLV_NONE : 
      break;
    case MLV_KEY :
      break;
    case MLV_MOUSE_MOTION :
      break;

    case MLV_INPUT_BOX :

      if(input_box==input_box_1){
        free(texte1);
        texte1=texte;
      }
      if(input_box==input_box_2){
        free(texte2);
        texte2=texte;
      }
      if(input_box==input_box_3){
        free(texte3);
        texte3=texte;
      }
      if(input_box==input_box_4){
        free(texte4);
        texte4=texte;
      }
      if(input_box==input_box_5){
        free(texte5);
        texte5=texte;
      }
      break;
      
    case MLV_MOUSE_BUTTON :

      if((x>660 && x<970)&&(y>335 && y<460)&& etat==MLV_PRESSED){
        /* Lancer Partie en mode lent */
        if(sscanf(texte1, "%d", &n)!=1 || sscanf(texte2, "%d", &m)!=1 || sscanf(texte3, "%d", &nb_murs)!=1 || sscanf(texte4, "%d", &taille_murs)!=1 || sscanf(texte5, "%d", &nb_pommes)!=1){ /*on recupere les valeurs des input box*/
          break;
        }
        if (n>40 || m>40 || nb_pommes>500){ /*sécurité sur la taille de la matrice et le nb_pommes*/
          n=40;
          m=40;
	  nb_pommes=200;
        }
	if ((n<30 || m<30) && nb_pommes>300){
	  nb_pommes=100;
	}
	if((n<20 || m<20) && nb_pommes>100){
	  nb_pommes=50;
	}
        
        config=creer_configuration(n, m, 7, nb_murs, taille_murs, 'd', nb_pommes, 'c'); /*on crée la configuration avec les valeurs récupérées*/
	      v=jeu(config); /*on lance le jeu avec la config qu'on vient de créer*/
	      if(v==3){
	        menu_scores();
	        cnt=1;
	      }
	      if(v==2){
	        cnt=1;
	      }
      }
      if((x>660 && x<970)&&(y>470 && y<595)&& etat==MLV_PRESSED){
        /*Lancer Partie en mode moyen */
	      if(sscanf(texte1, "%d", &n)!=1 || sscanf(texte2, "%d", &m)!=1 || sscanf(texte3, "%d", &nb_murs)!=1 || sscanf(texte4, "%d", &taille_murs)!=1 || sscanf(texte5, "%d", &nb_pommes)!=1){
          break;
        }
        if (n>40 || m>40 || nb_pommes>500){ /*sécurité sur la taille de la matrice et le nb_pommes*/
          n=40;
          m=40;
	  nb_pommes=200;
        }
	if ((n<30 || m<30) && nb_pommes>300){
	  nb_pommes=100;
	}
	if((n<20 || m<20) && nb_pommes>100){
	  nb_pommes=50;
	}
	      config=creer_configuration(n, m, 10, nb_murs, taille_murs, 'd', nb_pommes, 'c');
	      v=jeu(config);
        if(v==3){
	        menu_scores();
	        cnt=1;
	      }
	      if(v==2){
	        cnt=1;
	      }
      }
      if((x>660 && x<970)&&(y>605 && y<730)&& etat==MLV_PRESSED){
        /* Lancer Partie en mode Rapide */
	      if(sscanf(texte1, "%d", &n)!=1 || sscanf(texte2, "%d", &m)!=1 || sscanf(texte3, "%d", &nb_murs)!=1 || sscanf(texte4, "%d", &taille_murs)!=1 || sscanf(texte5, "%d", &nb_pommes)!=1){
          break;
        }
        if (n>40 || m>40 || nb_pommes>500){ /*sécurité sur la taille de la matrice et le nb_pommes*/
          n=40;
          m=40;
	  nb_pommes=200;
        }
	if ((n<30 || m<30) && nb_pommes>300){
	  nb_pommes=100;
	}
	if((n<20 || m<20) && nb_pommes>100){
	  nb_pommes=50;
	}
	      config=creer_configuration(n, m, 15, nb_murs, taille_murs, 'd', nb_pommes, 'c');
	      v=jeu(config);
        if(v==3){
	        menu_scores();
	        cnt=1;
	      }
	      if(v==2){
	        cnt=1;
	      }
      }
      if ((x>1200 && x<1280)&&(y>235 && y<275)){
        n=rand()%(40-20)+20;
        m=n;
        vitesse=rand()%(15-7)+7;
        nb_murs=rand()%(20-1)+1;
        taille_murs=rand()%(5-1)+1;
        nb_pommes=rand()%(50-1)+1;

        config=creer_configuration(n, m, vitesse, nb_murs, taille_murs, 'd', nb_pommes, 'c');
	      v=jeu(config);
        if(v==3){
	        menu_scores();
	        cnt=1;
	      }
	      if(v==2){
	        cnt=1;
	      }
      }
      if((x>1400 && x<1550)&&(y>105 && y<205)){
        cnt=1;
      }
      break;
      
    default :
      break;  
    }

        /* --Affichage du menu-- */
    afficher_menu_custom(texte1, texte2, texte3, texte4, texte5);
  }while(! cnt);


  /* --Libération de la mémoire utilisée par texte1, texte2, texte3 et texte4-- */

  free(texte1);
  free(texte2);
  free(texte3);
  free(texte4);
  free(texte5);

  /* --Fermeture des boîtes de saisies-- */

  MLV_free_input_box(input_box_1);
  MLV_free_input_box(input_box_2);
  MLV_free_input_box(input_box_3);
  MLV_free_input_box(input_box_4);
  MLV_free_input_box(input_box_5);
  return retour;
}
void bouton_retour(){
  MLV_draw_filled_rectangle(1410,115,150,100,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(1400,105,150,100,MLV_COLOR_DEEP_PINK);
  MLV_draw_text(1445,145,"RETOUR",MLV_COLOR_BLACK);
}

void afficher_save(){

  MLV_Image *fond;
  /* --Background du Menu-- */

  MLV_clear_window(MLV_COLOR_BLACK);

  fond = MLV_load_image("Images/fond.jpg");
  MLV_resize_image(fond,1600,880);
  MLV_draw_image(fond,0,0);

  /* --Cases des sauvegardes-- */

  MLV_draw_filled_rectangle(610,220,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,210,400,130,MLV_COLOR_DEEP_PINK);

  MLV_draw_filled_rectangle(610,390,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,380,400,130,MLV_COLOR_DEEP_PINK);

  MLV_draw_filled_rectangle(610,560,400,130,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(600,550,400,130,MLV_COLOR_DEEP_PINK);
 


  /* --Ecriture dans les cases-- */

  MLV_draw_text(740,265,"SAUVEGARDE 1",MLV_COLOR_BLACK);
  MLV_draw_text(740,435,"SAUVEGARDE 2",MLV_COLOR_BLACK);
  MLV_draw_text(740,605,"SAUVEGARDE 3",MLV_COLOR_BLACK);

  /* --Bouton Retour-- */

  bouton_retour();

  MLV_actualise_window();
  MLV_free_image(fond);
}

int sauvegarde(configuration *c){
  int retour=0, cnt=0, x, y;
  while(cnt==0){

    afficher_save();
    MLV_wait_mouse(&x, &y);

    if((x>600 && x<1010)&&(y>210 && y<350)){
      /* sauver sur save1*/
      sauvegarder(c, 1);
      cnt=1;
    }

    if((x>600 && x<1010)&&(y>380 && y<520)){
      /* sauver sur save2 */
      sauvegarder(c, 2);
      cnt=1;
    }

    if((x>600 && x<1010)&&(y>550 && y<690)){
      /* sauver sur save3 */
      sauvegarder(c, 3);
      cnt=1;
    }

    if((x>1400 && x<1560)&&(y>105 && y<215)){
      retour=1;
      cnt =1;
    }
  }

  return retour;
}

void afficher_menu_pause(){

  /* --Cases du menu-- */
  
  MLV_draw_filled_rectangle(650,245,300,113,MLV_COLOR_DEEP_PINK);
  MLV_draw_rectangle(650,245,300,113,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(650,368,300,112,MLV_COLOR_DEEP_PINK);
  MLV_draw_rectangle(650,368,300,112,MLV_COLOR_BLACK);

  MLV_draw_filled_rectangle(650,490,300,113,MLV_COLOR_DEEP_PINK);
  MLV_draw_rectangle(650,490,300,113,MLV_COLOR_BLACK);

  /* --Ecriture dans les cases-- */

  MLV_draw_text(735,290,"REPRENDRE PARTIE", MLV_COLOR_BLACK);
  MLV_draw_text(735,413,"SAUVEGARDER PARTIE", MLV_COLOR_BLACK);
  MLV_draw_text(760,530,"QUITTER",MLV_COLOR_BLACK);

  MLV_actualise_window();
}

char menu_pause(configuration *c){
  int x, y, cnt=1;
  char retour='0';

  while(cnt==1){

    afficher_menu_pause();

    MLV_wait_mouse(&x, &y);

    if((x>650 && x<950)&&(y>245 && y<358)){
      /* --Reprise de la Partie-- */
      cnt=0;
      retour='0';
    }
    if((x>650 && x<950)&&(y>368 && y<480)){
      /* --Sauvegarder Partie-- */
      cnt=sauvegarde(c);
      retour='2';
    }
      /* --Quitter la partie-- */
    if((x>650 && x<950)&&(y>490 && y<603)){
      retour='2';
      cnt=0;
    }
  }
  return retour;
}

void afficher_menu_lose(int score, int indic){

  MLV_Image *fond;

  /* --Message de fin et score-- */

  char message[100]="Dommage ! Vous avez obtenu le score de : ";
  char message2[100]="Félicitations ! Vous avez rempli le plateau de jeu ! votre score : ";
  char l[9]="";
  sprintf(l, "%d", score);

  /* Background du menu */

  MLV_clear_window(MLV_COLOR_GREY);
  fond = MLV_load_image("Images/fond.jpg");
  MLV_resize_image(fond,1600,880);
  MLV_draw_image(fond, 0, 0);

  /* Message */

  if(indic == 0){
    strcat(message, l);
    MLV_draw_adapted_text_box(645, 225,message,9,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_DEEP_PINK,MLV_TEXT_CENTER);
  }
  else{
    strcat(message2, l);
    MLV_draw_adapted_text_box(600, 225,message2,9,MLV_COLOR_BLACK,MLV_COLOR_BLACK,MLV_COLOR_DEEP_PINK,MLV_TEXT_CENTER);
  }


  /* Recommencer une partie */

  MLV_draw_filled_rectangle(660,345,300,112,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(650,335,300,112,MLV_COLOR_DEEP_PINK);
  MLV_draw_text(735,380,"RECOMMENCER", MLV_COLOR_BLACK);

  /* Meilleurs Scores */

  MLV_draw_filled_rectangle(660,478,300,112,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(650,468,300,112,MLV_COLOR_DEEP_PINK);
  MLV_draw_text(735,513,"MEILLEURS SCORES", MLV_COLOR_BLACK);

  /* Quitter */

  MLV_draw_filled_rectangle(660,610,300,112,MLV_COLOR_BLACK);
  MLV_draw_filled_rectangle(650,600,300,112,MLV_COLOR_DEEP_PINK);
  MLV_draw_text(760,645,"QUITTER", MLV_COLOR_BLACK);

  MLV_actualise_window();
  MLV_free_image(fond);

}

char menu_lose(configuration *c){
  int x, y, cnt=1, ind=1, i, j;
  char retour='0';

  /* --Affichage-- */

  for(i=0 ; i<c->plateau.n ; i++){

    for(j=0 ; j<c->plateau.m ; j++){

      if(c->plateau.tab[i][j] == 0){

        afficher_menu_lose(c->score, 0);
        ind=0;
        break;
      }
    }

    if(ind==0){

      break;
    }
  }
  
  if(ind == 1){
    afficher_menu_lose(c->score, 1);
  }

  /* --Sauvegarde du score et du mode-- */

  save_score(c->score, c->mode);

  while(cnt==1){

    MLV_wait_mouse(&x, &y);

    /* --Retour au menu de choix de partie-- */

    if((x>725 && x<1025)&&(y>335 && y<448)){

      retour='1';
      cnt=0;

    }

    /* --Menu des meilleurs scores-- */

    if((x>725 && x<1025)&&(y>458 && y<570)){

      cnt=menu_scores();
      retour='3';

    }

    /* --Retour au menu principal-- */

    if((x>725 && x<1025)&&(y>580 && y<692)){

      cnt=0;
      retour='2';

    }
  }
  
  return retour;
}

