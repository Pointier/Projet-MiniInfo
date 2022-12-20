all : structure.o initialisation.o affichage.o main.o
	gcc main.o affichage.o initialisation.o structure.o -o jeu -Wall

structure.o : structure.c structure.h
	gcc -Wall -c structure.c

initialisation.o : initialisation.c initialisation.h	
	gcc -Wall -c initialisation.c

affichage.o : affichage.c affichage.h
	gcc -Wall -c affichage.c

main.o : main.c affichage.h structure.h
	gcc -Wall -c main.c
	
clean :
	rm -f *.o
