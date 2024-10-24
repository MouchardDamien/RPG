all: exec clean 

main.o: main.c header.h 
	gcc -c main.c -o main.o 
	
initiate.o: initiate.c header.h 
	gcc -c initiate.c -o initiate.o
	
utility.o: utility.c header.h 
	gcc -c utility.c -o utility.o

exec: main.o utility.o initiate.o
	gcc main.o utility.o initiate.o -o exec 

clean: 
	rm *.o
