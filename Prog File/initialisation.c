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

void initEnsemblePuc(EnsemblePuc *ensP,int numPuc)
{
    for (int i = 0; i < numPuc; i++)
    {
        Puceron puc;
        initPuc(&puc);
        ajoutPuc(ensP,&puc);
    }
}

void initPlacInsecte(EnsemblePuc *ensP, Case tab[N][N])
{
    Coordonee tabCoord[ensP->card]; // Penser a rajouter le nombre de coccinelle;
    int c=0; // Compteur du nombre de coordonnée dans le tableau
    while (c<ensP->card)
    {
        bool nouvCoord=true; //
        Coordonee coordRand;
        coordRand.x = rand() % (N-1);
        coordRand.y = rand() % (N-1);
        for (int i=0;i<c;i++)
        {
            printf("Compteur test si rentre a 0 : %d\n",c);
            if (coordRand.x==tabCoord[i].x &&coordRand.y==tabCoord[i].y)
            nouvCoord=false;
        }
        if (nouvCoord)
        {
            tabCoord[c]=coordRand;
            c++;
        }

    }
    for(int i=0;i<ensP->card;i++)
    {
        ensP->tab[i]->coord=tabCoord[i];
        placementPuc(ensP->tab[i],tab);
    }

}
