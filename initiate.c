#include "header.h"

void choose_name(char name[30]){
	printf("Choose the name of your character (30 letters max !) : \n\n");
  	scanf("%s",name);
  	vide_buffer();
	ClearScreen();  	
  	
  	char critic_name = rand()%2;
  	
  	if(critic_name == 0){
  		printf("Ok ! '%s' is a beautifull name ! \n\n", name);
  	} else {
  		printf("Hum... ok. '%s' is an... hum... original name. \n\n", name);
  	}
  	
  	sleep(5);
  	ClearScreen();
}

T_Roles choose_role(){
	char choice = 1;
	int verif;
	T_Roles role;
	
	printf("Choose your class :\n\n 1. TANK \n 2. ASSASSIN \n 3. WARRIOR \n 4. MAGE \n\n");
	
	while (choice){
    		verif = scanf("%d",&role);
    		vide_buffer();
    		switch(role){
    		
    			case 0 || 1 || 2 || 3:
    				choice = 0;
    				break;
    
    			default:
    				ClearScreen();
    				printf("Choose your class :\n\n 1. TANK \n 2. ASSASSIN \n 3. WARRIOR \n 4. MAGE \n\n");
    				break;
    		}
  	}
  	
 	return role;
}

void init_player(Player* p){
	
	if(p == NULL){
		printf("Error of allocation in init_player !\n\n");
	}
	
	char p_name[30];
	
	choose_name(p_name);
	
	strcpy(p->name,p_name);
	p->role = choose_role();
	
}




