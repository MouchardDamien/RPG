#include "header.h"

void choose_name(char name[30]) {
  printf("Choose the name of your character (30 letters max !) : \n\n\n");
  scanf("%s", name);
  vide_buffer();
  ClearScreen();

  char critic_name = rand() % 2;

  if (critic_name == 0) {
    printf("Oh ! It's a beautifull name ! \n\n");
  } else {
    printf("Hum... ok. It's an... original name. \n\n");
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
  char role;

  while(change){

    choice2 = 1;

    printf("\nChoose your class :\n\n 1. TANK \n 2. ASSASSIN \n 3. WARRIOR \n 4. MAGE \n\n");
    
    while (choice) {
      role = getch();

      switch(role){

        case '1':
          choice = 0;
          ClearScreen();
          printf("You are now a Tank !\nTank have a high defense and hp but low attack and crit chance and speed !\n\n");
          sleep(7);
          ClearScreen();
          break;

        case '2':
          choice = 0;
          ClearScreen();
          printf("You are now an Assassin !\nAssassin have a high crit chance, speed and attack chance but low defense and hp !\n\n");
          sleep(8);
          ClearScreen();
          break;

        case '3':
          choice = 0;
          ClearScreen();
          printf("You are now a Warrior !\nWarrior is a very equilibrate class !\n\n");
          sleep(5);
          ClearScreen();
          break;

        case '4':
          choice = 0;
          ClearScreen();
          printf("You are now a Mage !\nMage have a high attack and hp but low defense !\n\n");
          sleep(6);
          ClearScreen();
          break;

        default:
          ClearScreen();
          printf("\nChoose your class :\n\n 1. TANK \n 2. ASSASSIN \n 3. WARRIOR \n 4. MAGE \n\n");
          break;
      }
    }

    role = role - '0';
    role--;
    
    printf("Do you want to change your class ? (Y/N)\n\n");

    while (choice2) {
      choice3 = getch();
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

  printf("First, create your character !\n\n");
  sleep(3);
  ClearScreen();
  
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
      p->speed = 80;
      break;
    
    case 1:
      p->hp = 80;
      p->att = 35;
      p->def = 5;
      p->crit_chance = 40;
      p->crit_dmg = 50;
      p->dodge = 15;
      p->speed = 120;
      break;
    
    case 2:
      p->hp = 100;
      p->att = 25;
      p->def = 10;
      p->crit_chance = 15;
      p->crit_dmg = 50;
      p->dodge = 10;
      p->speed = 100;
      break;
    
    case 3:
      p->hp = 110;
      p->att = 35;
      p->def = 5;
      p->crit_chance = 15;
      p->crit_dmg = 50;
      p->dodge = 10;
      p->speed = 100;
      break;
    
    default:
      printf("Error in init_player !\n\n");
      break;
  }

  printf("Do you want to see your stats ? (Y/N)\n\n");

  char choice = 1;
  char choice2 = 1;
  char verif;

  while(choice){
    choice2 = getch();
    switch (choice2) {

      case 'Y':
      case 'y':
        choice = 0;
        verif = -1;
        while(verif != ' '){
          ClearScreen();
          printf("Ok ! There is : \n\n");
          printf(" HP : %d \n  Attack : %d\n  Defense : %d\n  Crit chance : %d %%\n  Crit damage : %d %%\n  Dodge chance : %d %%\n  Speed : %d\n\nPress space to quit...\n\n ", p->hp, p->att, p->def, p->crit_chance, p->crit_dmg, p->dodge,p->speed);
          verif = getch();
        }
        ClearScreen();
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
        break;
    }
  }
}
