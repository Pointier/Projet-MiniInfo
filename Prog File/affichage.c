#include "initialisation.h"
#include "structure.h"


void afficher(struct Case tab[][], int taille) // Prend une matrice carree et l'affiche
{
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (tab[i][j].puc==NULL && tab[i][j].cocci==NULL)
            {
                switch(tab[i][j].etatTomate)
                {
                    case 1:
                    printf(".");
                    break;

                    case 2:
                    case 3:
                    case 4:
                    printf("o");
                    break;
                    case 5:
                    print("O");
                }
                if (j+1==taille)
                printf('\n');
            }
        }
    }
}