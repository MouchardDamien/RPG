#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

typedef enum { DEFENDER, ASSASSIN, WARRIOR, MAGE } T_Roles;

typedef struct{
	char name[30];
	T_Roles role;
	short hp;
	short att;
	short def;
	short crit_chance;
	short crit_dmg;
	short dodge;
	short speed;
} Player;

//initiate.c
void init_player(Player* p);

//menu.c
char welcome();
char main_menu();
void rules();
void quit();

//utility.c
void vide_buffer();
void ClearScreen();
int getch();
