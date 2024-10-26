all: exec clean 

main.o: main.c header.h 
	gcc -c main.c -o main.o 
	
initiate.o: initiate.c header.h 
	gcc -c initiate.c -o initiate.o
	
utility.o: utility.c header.h 
	gcc -c utility.c -o utility.o

menu.o: menu.c header.h 
	gcc -c menu.c -o menu.o

exec: main.o utility.o initiate.o menu.o
	gcc main.o utility.o initiate.o menu.o -o exec 

clean: 
	rm *.o
