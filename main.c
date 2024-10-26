#include "header.h"

int main(void) {

  ClearScreen();
  
  srand(time(NULL));
  char choice_menu = -1;

  Player *p1 = malloc(sizeof(Player));

  if (p1 == NULL) {
    printf("Error of allocation in main !\n\n");
  }

  choice_menu = welcome();

  char active = 1;

  while(active){
    switch(choice_menu){
      case '1':
        init_player(p1);
        break;
    
      case '2':
        rules();
        choice_menu = main_menu();
        break;
    
      case '3':
        quit();
        active = 0;
        break;
    
      default:
        break;
    }
  }
  
  return 0;
}
