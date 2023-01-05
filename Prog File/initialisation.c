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
        ajoutPuc(ensP, &puc);
    }
}

void initPlacInsecte(EnsemblePuc *ensP, Case tab[N][N])
{
    Coordonee tabCoord[ensP->card]; // Penser a rajouter le nombre de coccinelle;
    int c = 0;                      // Compteur du nombre de coordonnée dans le tableau
    while (c < ensP->card)
    {
        bool nouvCoord = true; //
        Coordonee coordRand;
        coordRand.x = rand() % (N - 1);
        coordRand.y = rand() % (N - 1);
        for (int i = 0; i < c; i++)
        {
            if (coordRand.x == tabCoord[i].x && coordRand.y == tabCoord[i].y)
                nouvCoord = false;
        }
        if (nouvCoord)
        {
            tabCoord[c] = coordRand;
            c++;
        }
    }
    for (int i = 0; i < ensP->card; i++)
    {
        ensP->tab[i]->coord = tabCoord[i];
        printf("Coord puc %d x %d y %d\n", i, ensP->tab[i]->coord.x, ensP->tab[i]->coord.y);
        placementPuc(ensP->tab[i], tab);
    }
    for (int i = 0; i < ensP->card; i++)
    {
        printf("Coord puc %d adresse %p\n", i, ensP->tab[i]);
        printf("Coord puc %d x %d y %d\n", i, ensP->tab[i]->coord.x, ensP->tab[i]->coord.y);
    }
}
