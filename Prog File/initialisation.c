#include "initialisation.h"

void initialisationCase(Case tab[N][N], int taille)
{
    printf("init\n");
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            tab[i][j].etatTomate = 20;
            tab[i][j].puc = NULL;
            tab[i][j].cocci = NULL;
        }
    }
}

void initTab(Puceron *tab[],int numbPuc)
{
    Puceron try;
    initPuc(&try);
    Coordonee coord={1,1};
    //placementPuc(&try,coord,tab);
    tab[0]=&try;
}

