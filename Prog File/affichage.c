#include "affichage.h"

void afficher(Case tab[N][N], int taille) // Prend une matrice carree et l'affiche
{
    printf("Affichage\n");
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (tab[i][j].puc == NULL && tab[i][j].cocci == NULL)
            {
                printf("\033[1;37m");

                if(tab[i][j].etatTomate>=1 && tab[i][j].etatTomate<=4)
                printf(".");
                else if (tab[i][j].etatTomate>=5 && tab[i][j].etatTomate<=19)
                printf("o");
                else if (tab[i][j].etatTomate==20)
                printf("O");
            }
            else if (tab[i][j].puc != NULL || tab[i][j].cocci != NULL)
            {
                if (tab[i][j].cocci != NULL)
                {
                    printf("\033[0;31m");
                }
                else
                {
                    printf("\033[0;32m");
                    printf("∧");
                }
            }
            if (j + 1 == taille)
                printf("\n");
        }
    }
}