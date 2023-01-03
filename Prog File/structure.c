#include "structure.h"

void initPuc(Puceron *puc)
{
    puc->coord.x = -1;
    puc->coord.y = -1;
    puc->precCoord.x = -1;
    puc->precCoord.y = -1;
    puc->age = 0;
    puc->nourriConse = 0;
    puc->index = -1;
}

void placementPuc(Puceron *puc, Coordonee coord)
{
    puc->coord.x=coord.x;
    puc->coord.y=coord.y;
}

Coordonee directionPuc(Puceron *puc)
{
    Coordonee dir;
    dir.x=puc->coord.x-puc->precCoord.x;
    dir.y=puc->coord.y-puc->precCoord.y;
    return dir;
}

bool presenceTom(Coordonee coord, Case tab[N][N])
{
    if (tab[coord.x][coord.y].etatTomate>=5)
    return true;
    else
    return false;
}

Coordonee selectRandTom(Puceron *puc, Case tab[N][N])
{
    Coordonee array[9];
    int c=0; // Compteur pour nombre de Coord dans le tableau
    for(int i=0;i<2;i++)
    {
        for (int j=0;j<2;j++)
        {
            
        }
    }
}

void deplacementPuc(Puceron *puc, Case tab[N][N])
{
    Coordonee dir;
    dir=directionPuc(&puc);
    dir.x=dir.x+puc->coord.x;
    dir.y=dir.y+puc->coord.y;
    if(presenceTom(dir,tab))
    placementPuc(&puc, dir);
    


}

void mangeTom(Puceron *puc, Case tab[N][N])
{
    printf("Etat tomate fct : %d\n", tab[puc->coord.x][puc->coord.y].etatTomate);
    if (tab[puc->coord.x][puc->coord.y].etatTomate>=5)
    {
        tab[puc->coord.x][puc->coord.y].etatTomate=1;
        printf("Etat tomate fct : %d\n", tab[puc->coord.x][puc->coord.y].etatTomate);
        puc->nourriConse++;
    }
}

void vieillissementPuc(EnsemblePuc *ensP, Puceron *puc)
{
    puc->age++;
    if(puc->age>=10)
    mortPuc(ensP, puc);

}

void creaEnsPuc(EnsemblePuc *ensP)
{
    ensP->card = 0;
}

void ajoutPuc(EnsemblePuc *ensP, Puceron *puc)
{
    ensP->tab[ensP->card] = puc;
    puc->index = ensP->card;
    ensP->card++;
}
void mortPuc(EnsemblePuc *ensP, Puceron *puc)
{
    if (ensP->card > 1)
    {
        ensP->tab[puc->index] = ensP->tab[ensP->card - 1]; // On remplace la puce morte par le dernier puceron du tableau
        ensP->tab[ensP->card - 1]->index = puc->index;     // On met a jour l'index du puceron déplacé
        ensP->card = ensP->card - 1;                       // On met a jour le cardinal
    }
    puc->index = -1;
    puc->coord.x = -1; // On supprime le puceron de la grille
    puc->coord.y = -1;
}