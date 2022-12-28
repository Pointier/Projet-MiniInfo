#include "structure.h"

void initPuc(Puceron *puc)
{
    puc->coord.x = -1;
    puc->coord.y = -1;
    puc->age = 0;
    puc->nourriConse = 0;
    puc->index = -1;
}


void mangeTom(Puceron *puc, Case tab[N][N])
{
    
    if (tab[puc->coord.x][puc->coord.y].etatTomate==5)
    {
        tab[puc->coord.x][puc->coord.y].etatTomate=1;
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