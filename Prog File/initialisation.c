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

void initEnsemblePuc(EnsemblePuc *ensP, int numPuc)
{
    for (int i = 0; i < numPuc; i++)
    {
        Puceron puc;
        initPuc(&puc);
        ajoutPuc(ensP, puc);
    }
}

void initPlacInsecte(EnsemblePuc *ensP, Case tab[N][N])
{
    Coordonnee tabCoord[ensP->card]; // Penser a rajouter le nombre de coccinelle;
    int c = 0;                      // Compteur du nombre de coordonnée dans le tableau
    while (c < ensP->card)
    {
        bool nouvCoord = true; //
        Coordonnee coordRand;
        coordRand.x = rand() % (N - 1);
        coordRand.y = rand() % (N - 1);
        for (int i = 0; i < c; i++)
        {
            if (coordRand.x == tabCoord[i].x && coordRand.y == tabCoord[i].y)
                nouvCoord = false;
        }
        if (nouvCoord)
        {
            printf("Coordonnee depart tableau : x=%d y=%d\n",coordRand.x,coordRand.y);
            tabCoord[c] = coordRand;
            c++;
        }
    }
    printf("Taille cardi %d\n",ensP->card);
    for (int i = 0; i < ensP->card; i++)
    {
        printf("Avant assi : x=%d y=%d\n",tabCoord[0].x,tabCoord[0].y);
        ensP->tab[i].coord = tabCoord[i];
        printf("Compteur placement puc %d\n", i);
        placementPuc(&ensP->tab[i], tab);
    }
}
