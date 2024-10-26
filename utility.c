#include "header.h"

void vide_buffer(){
	while(getchar()!='\n'){
	}
}

void ClearScreen() {
	#ifdef _WIN32
		system("cls");  // Commande pour Windows
	#else
		system("clear"); // Commande pour Linux/macOS
	#endif
}

int getch(void) { 
	struct termios oldattr, newattr; 
	int ch; 
	tcgetattr(STDIN_FILENO, &oldattr); 
	newattr = oldattr; 
	newattr.c_lflag &= ~(ICANON | ECHO); 
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr); 
	ch = getchar(); 
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); 
	return ch; 
}
