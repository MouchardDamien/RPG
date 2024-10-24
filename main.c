#include "header.h"


int main(void){

	srand(time(NULL));
	
	Player* p1 = malloc(sizeof(Player));
	
	if(p1 == NULL){
		printf("Error of allocation in main !\n\n");
	}
	
	ClearScreen();
	init_player(p1);

	return 0;
}
	
	

