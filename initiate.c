#include "header.h"

void choose_name(char name[30]) {
  printf("Choose the name of your character (30 letters max !) : \n\n");
  scanf("%s", name);
  vide_buffer();
  ClearScreen();

  char critic_name = rand() % 2;

  if (critic_name == 0) {
    printf("Ok ! '%s' is a beautifull name ! \n\n", name);
  } else {
    printf("Hum... ok. '%s' is an... hum... original name. \n\n", name);
  }

  sleep(4);
  ClearScreen();
}


T_Roles choose_role() {
  char choice = 1;
  char choice2 = 1;
  char change = 1;
  char choice3;
  int verif;
  T_Roles role;

  while(change){

    choice2 = 1;

    printf("Choose your class :\n\n 1. TANK \n 2. ASSASSIN \n 3. WARRIOR \n 4. "
         "MAGE \n\n");

    while (choice) {
      verif = scanf("%d", &role);
      role--;
      vide_buffer();
      switch (role) {

        case 0 : 
        case 1 :
        case 2 :
        case 3 :
          choice = 0;
          break;

        default:
          ClearScreen();
          printf("Please choose a valid role (type 1, 2, 3 or 4) ! \n\n");
          sleep(3);
          ClearScreen();
          printf("Choose your class :\n\n 1. TANK \n 2. ASSASSIN \n 3. WARRIOR \n 4. MAGE \n\n");
          break;
      }
    }
    ClearScreen();
    switch(role){
      case 0:
        printf("You are now a Tank !\nTank have a high defense and hp but low attack and crit chance !\n\n");
        sleep(7);
        break;
      case 1:
        printf("You are now an Assassin !\nAssassin have a high crit chance and attack chance but low defense and hp !\n\n");
        sleep(8);
        break;
      case 2:
        printf("You are now a Warrior !\nWarrior is an very equilibrate class !\n\n");
        sleep(5);
        break;
      case 3:
        printf("You are now a Mage !\nMage have a high attack and hp but low defense !\n\n");
        sleep(6);
        break;
    }
    ClearScreen();
    
    printf("Do you want to change your class ? (Y/N)\n\n");

    while (choice2) {
      verif = scanf("%c", &choice3);
      vide_buffer();
      switch (choice3) {

        case 'Y':
        case 'y':
          choice2 = 0;
          choice = 1;
          ClearScreen();
          break;
        
        case 'N' :
        case 'n' :
          ClearScreen();
          choice2 = 0;
          change = 0;
          printf("Ok ! Perfect !\n\n");
          sleep(2);
          ClearScreen();
          break;

        default:
          ClearScreen();
          printf("Please type a valid choice (Y or N ) ! \n\n");
          sleep(3);
          ClearScreen();
          printf("Do you want to change your class ? (Y/N)\n\n");
          break;
      }
    }
  }

  return role;
}

  
void init_player(Player *p){

  if (p == NULL) {
    printf("Error of allocation in init_player !\n\n");
  }

  char p_name[30];

  choose_name(p_name);

  strcpy(p->name, p_name);
  p->role = choose_role();

  switch(p->role){
    case 0:
      p->hp = 120;
      p->att = 20;
      p->def = 15;
      p->crit_chance = 10;
      p->crit_dmg = 50;
      p->dodge = 5;
      break;
    
    case 1:
      p->hp = 80;
      p->att = 35;
      p->def = 5;
      p->crit_chance = 40;
      p->crit_dmg = 50;
      p->dodge = 15;
      break;
    
    case 2:
      p->hp = 100;
      p->att = 25;
      p->def = 10;
      p->crit_chance = 15;
      p->crit_dmg = 50;
      p->dodge = 10;
      break;
    
    case 3:
      p->hp = 110;
      p->att = 35;
      p->def = 5;
      p->crit_chance = 15;
      p->crit_dmg = 50;
      p->dodge = 10;
      break;
    
    default:
      printf("Error in init_player !\n\n");
      break;
  }

  printf("Do you want to see your stats ? (Y/N)\n\n");

  char choice = 1;
  char choice2;
  int verif;

  while(choice){
    verif = scanf("%c", &choice2);
    vide_buffer();
    switch (choice2) {

      case 'Y':
      case 'y':
        ClearScreen();
        printf("Ok ! I let you 12 secondes to see them... \n\n");
        printf(" HP : %d \n Attack : %d\n Defense : %d\n Crit chance : %d %%\n Crit damage : %d %%\n Dodge chance : %d %%\n ", p->hp, p->att, p->def, p->crit_chance, p->crit_dmg, p->dodge);
        sleep(12);
        ClearScreen();
        printf("Do you want to see again your stats ? (Y/N)\n\n");
        break;
      
      case 'N':
      case 'n':
        ClearScreen();
        choice = 0;
        printf("Ok ! \n\n");
        sleep(2);
        ClearScreen();
        break;

      default:
        ClearScreen();
        printf("Please type a valid choice (Y or N ) ! \n\n");
        sleep(3);
        ClearScreen();
        printf("Do you want to see your stats ? (Y/N)\n\n");
        break;
    }
    
  }
}




