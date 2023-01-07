all : structure.o initialisation.o tour.o main.o
	gcc -Wall -o jeu structure.o initialisation.o tour.o main.o 

structure.o :  structure.c structure.h
	gcc -Wall -c structure.c 

initialisation.o :  initialisation.c  initialisation.h
	gcc -Wall -c initialisation.c 

tour.o : tour.c tour.h
	gcc -Wall -c tour.c

main.o : main.c
	gcc -Wall -c main.c
	
clean :
	rm -f *.o
