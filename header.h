#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

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
} Player;

//initiate.c
void init_player(Player* p);

//utility.c
void vide_buffer();
void ClearScreen();
int getch();
