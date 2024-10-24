#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef enum { DEFENDER, ASSASSIN, WARRIOR, MAGE } T_Roles;

typedef struct{
	char name[30];
	T_Roles role;
	short attack;
	short defense;
	short crit_chance;
	short crit_damage;
	short dodge;
} Player;

//initiate.c
void init_player(Player* p);

//utility.c
void vide_buffer();
void ClearScreen();
