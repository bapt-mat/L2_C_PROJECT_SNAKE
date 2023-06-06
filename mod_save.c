#include "mod_save.h"

void sauvegarder(configuration *c, int indic){
    int i, j;
    FILE *f=NULL;

    /* Détermination du fichier à utiliser pour la sauvegarde et ouverture */

    switch(indic){
        case 1:

            if((f = fopen("saves/save1.txt", "w")) == NULL){ 
                printf("erreur ouverture");
                return;
            }
            break;

        case 2:

            if((f = fopen("saves/save2.txt", "w")) == NULL){ 
                printf("erreur ouverture");
                return;
            }
            break;

        case 3:

            if((f = fopen("saves/save3.txt", "w")) == NULL){ 
                printf("erreur ouverture");
                return;
            }
            break;

        default:

            if((f = fopen("saves/save1.txt", "w")) == NULL){ 
                printf("erreur ouverture");
                return;
            }           
    }

    /* --Ecriture de la taille de la matrice-- */

    fprintf(f, "%d\n", c->plateau.n);
    fprintf(f, "%d\n", c->plateau.m);

    /* --Ecriture des configurations du mode custom-- */

    fprintf(f, "%d\n", c->plateau.nb_murs_supp);
    fprintf(f, "%d\n", c->plateau.taille_murs_supp);

    /* --Ecriture du score-- */

    fprintf(f, "%d\n", c->score);

    /* --Ecriture du mode-- */

    fprintf(f, "%c\n", c->mode);

    /* --Ecriture de la vitesse-- */

    fprintf(f, "%d\n", c->serpent.vitesse);

    /* --Ecriture de la direction-- */

    fprintf(f, "%c\n", c->serpent.direction);

    /* --Ecriture du x de la pomme-- */

    fprintf(f, "%d\n", c->pomme.x);

    /* --Ecriture du y de la pomme-- */

    fprintf(f, "%d\n", c->pomme.y);

    /* --Ecriture du type de la pomme-- */

    fprintf(f, "%d\n", c->pomme.type_pomme);

    /* --Ecriture du nombre de pommes-- */

    fprintf(f,"%d\n", c->pomme.nb_pommes);

    /* --Ecriture de la taille du serpent-- */

    fprintf(f, "%d\n", c->serpent.taille);

    /* --Ecriture du tableau pos_x de serpent-- */

    for(i=0 ; i<c->serpent.taille ; i++){
        fputc(c->serpent.pos_x[i]+'0', f);
    }
    fputc('\n', f);

    /* --Ecriture du tableau pos_y de serpent-- */

    for(i=0 ; i<c->serpent.taille ; i++){
        fputc(c->serpent.pos_y[i]+'0', f);
    }
    fputc('\n', f);

    /* --Ecriture de la matrice correspondant au plateau-- */

    for(i=0 ; i<c->plateau.n ; i++){
        for(j=0 ; j<c->plateau.m ; j++){
            fputc(c->plateau.tab[i][j]+'0', f); /* +'0' pour avoir un bon affichage dans le fichier */
        }
        fputc('\n', f);
    }

    /* Fermeture */

    fclose(f);
}

char charger(configuration *c, int indic){
    int i, j, k;
    FILE *f;

    /* --Ouverture du fichier en fonction de la sauvegarde choisie-- */

    switch(indic){
        case 1:

            if((f = fopen("saves/save1.txt", "r")) == NULL){ 
                printf("erreur ouverture");
                return '0';
            }
            break;

        case 2:

            if((f = fopen("saves/save2.txt", "r")) == NULL){ 
                printf("erreur ouverture");
                return '0';
            }
            break;

        case 3:

            if((f = fopen("saves/save3.txt", "r")) == NULL){ 
                printf("erreur ouverture");
                return '0';
            }
            break;

        default:

            if((f = fopen("saves/save1.txt", "r")) == NULL){ 
                printf("erreur ouverture");
                return '0';
            }           
    }
    
    /* --Lecture des dimensions de la matrice-- */

    if(fscanf(f, "%d", &c->plateau.n)!=1){
        printf("Problem houston\n");
    }

    if(fscanf(f, "%d", &c->plateau.m)!=1){
        printf("Problem 2 houston\n");
    }

    /* --Ecriture des configurations du mode custom-- */
    
    if(fscanf(f, "%d", &c->plateau.nb_murs_supp)!=1){
        printf("nb_murs_supp pas la\n");
    }

    if(fscanf(f, "%d", &c->plateau.taille_murs_supp)!=1){
        printf("taille_murs_supp pas la\n");
    }

    /* --Lecture du score-- */

    if(fscanf(f, "%d", &c->score)!= 1){
        printf("Score pas là\n");
    }

    /* --Lecture du mode-- */

    c->mode=fgetc(f);

    if(fscanf(f, "%c", &c->mode)!=1){
        printf("mode pas là\n");
    }
 
    /* --Lecture de la vitesse-- */

    if(fscanf(f, "%d", &c->serpent.vitesse)!= 1){
        printf("vitesse pas là\n");
    }

    /* --Lecture de la direction-- */

    c->serpent.direction=fgetc(f);

    if (fscanf(f, "%c", &c->serpent.direction)!=1){
        printf("dir pas la \n");
    }

    /* --Lecture du x de la pomme-- */

    if(fscanf(f, "%d", &c->pomme.x)!=1){
        printf("pomme_x pas là\n");
    }

    /* --Lecture du y de la pomme-- */

    if(fscanf(f, "%d", &c->pomme.y)!=1){
        printf("pomme_y pas là\n");
    }

    /* --Lecture du type de la pomme-- */

    if(fscanf(f, "%d", &c->pomme.type_pomme)!=1){
        printf("pomme_type pas là\n");
    }

    /* --Lecture du nombre de pommes-- */

    if (fscanf(f, "%d", &c->pomme.nb_pommes)!=1){
        printf("nombre pommes pas la\n");
    }

    /* --Lecture de la taille du serpent-- */

    if(fscanf(f, "%d", &c->serpent.taille)!=1){
        printf("Taille serpent not here\n");
    }

    /* --Lecture du tableau pos_x de serpent-- */

    k=fgetc(f); /* On récupère un détritu */

    for(i=0 ; i<c->serpent.taille ; i++){
        if((k=fgetc(f))!='\n'){
            k -= '0';
            c->serpent.pos_x[i] = k;
        }
    }

    /* --Lecture du tableau pos_y de serpent-- */

    k=fgetc(f); /* Recup de caractères gênants */
    
    for(i=0 ; i<c->serpent.taille ; i++){
        if((k=fgetc(f))!='\n'){
            k -= '0';
            c->serpent.pos_y[i] = k;
        }
    }

    /* --Lecture de la matrice-- */

    k=fgetc(f); /* On récup des caractères gênants perdus */

    for(i=0 ; i<=c->plateau.n ; i++){
        for(j=0 ; j<=c->plateau.m ; j++){
            k=fgetc(f);
            if(k != '\n'){
                k -= '0';
                c->plateau.tab[i][j] = k;
            }
        }
    }

    /* --Fermeture-- */

    fclose(f);

    return c->serpent.direction;
}

void save_score(int score, char mode){
    int i, j, tmp;
    int scores[10];
    char mod[10];
    FILE *f;

    if(mode=='c'){
        return;
    }

    if((f = fopen("saves/scores.txt", "r+")) == NULL){ 
        printf("erreur ouverture");
        return;
    }

    for(i=0 ; i<10 ; i++){
        if(fscanf(f, "%d %c", &scores[i], &mod[i])!=2){
            printf("oups\n");
        }
    }

    if(score<scores[9]){
        return;
    }

    for(i=1 ; i<=10 ; i++){
        for(j=0 ; j<9 ; j++){
            if(scores[j]<scores[j+1]){
                tmp = scores[j];
                scores[j]=scores[j+1];
                scores[j+1]=tmp;
                tmp = mod[j];
                mod[j]=mod[j+1];
                mod[j+1]=tmp;
            }
        }
    }

    for(i=0 ; i<10 && scores[i]>score ; i++){
        ;
    }
    for(j=9 ; j>i ; j--){
        scores[j]=scores[j-1];
        mod[j]=mod[j-1];
    }
    if(scores[i]<score){
        scores[i]=score;
        mod[i]=mode;
    }

    fclose(f);

    if((f = fopen("saves/scores.txt", "w+")) == NULL){ 
        printf("erreur ouverture");
        return;
    }

    for(i=0 ; i<10 ; i++){
        fprintf(f, "%d ", scores[i]);
        fprintf(f, "%c\n", mod[i]);
    }

    fclose(f);

    return;

}

