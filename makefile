all : main.o affichage.o initialisation.o structure.o
	gcc main.o affichage.o initialisation.o structure.o -o jeu -Wall

main.o : main.c affichage.h structure.h
	gcc -Wall -c main.c
affichage.o : affichage.c affichage.h
	gcc -Wall -c affichage.c

initialisation.o : initialisation.c initialisation.h	
	gcc -Wall -c initialisation.c
	
structure.o : structure.c structure.h
	gcc -Wall -c structure.c	
clean :
	rm -f *.o
