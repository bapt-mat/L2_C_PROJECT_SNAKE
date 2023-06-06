#include <time.h>
#include "mod_menu.h"
#define X 1600
#define Y 880

int main(){
  int suivant, x=0;
  MLV_Music *musique;
  srand(time(NULL));
  MLV_create_window("Snake", "Snake", X, Y);
  MLV_init_audio();
  musique = MLV_load_music("sound/main_theme.ogg");
  MLV_play_music(musique, 0.1, -1);
  while(x==0){
    suivant=menu_principal();
    switch(suivant){
    case 1:
      x=menu_new_game();
      break;
    case 2:
      x=menu_sauvegarde();
      break;
    case 3:
      x=menu_scores();
      break;
    case 4:
      MLV_stop_music();
      MLV_free_music(musique);
      MLV_free_audio();
      MLV_free_window();
      exit(EXIT_SUCCESS);
      break;
    default :
      x=0;
    }
  }
  MLV_free_window();
  exit(0);
}
