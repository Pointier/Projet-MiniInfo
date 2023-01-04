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
void setCoordPuc(Puceron *puc, Coordonee coord)
{
    puc->coord.x = coord.x;
    puc->coord.y = coord.y;
}

void placementPuc(Puceron *puc, Case tab[N][N])
{

    tab[puc->coord.x][puc->coord.y].puc = puc;
}

Coordonee directionPuc(Puceron *puc)
{
    Coordonee dir;
    dir.x = puc->coord.x - puc->precCoord.x;
    dir.y = puc->coord.y - puc->precCoord.y;
    return dir;
}

bool presenceTom(Coordonee coord, Case tab[N][N])
{
    if (tab[coord.x][coord.y].etatTomate >= 5 && tab[coord.x][coord.y].cocci == NULL && tab[coord.x][coord.y].puc == NULL)
        return true;
    else
        return false;
}

Coordonee caseVideRandPuc(Puceron *puc, Case tab[N][N])
{
    Coordonee caseVide[8];
    int cVide = 0; // Compteur pour nombre de Coord dans le tableu de case vide
    Coordonee autourPuc;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (!(j == 0 && i == 0))
            {
                autourPuc.x = puc->coord.x + i;
                autourPuc.y = puc->coord.y + j;

                if (tab[autourPuc.x][autourPuc.y].cocci == NULL && tab[autourPuc.x][autourPuc.y].puc == NULL)
                {
                    caseVide[cVide] = autourPuc;
                    cVide++;
                }
            }
        }
    }
    if (cVide != 0)
    {
        int n = rand() % cVide;
        return caseVide[n];
    }
    else // si toutes les cases sont occupés le puceron ne bouge pas
    {
        autourPuc.x = 0;
        autourPuc.y = 0;
        return autourPuc;
    }
}

Coordonee selectRandTom(Puceron *puc, Case tab[N][N])
{
    time_t t;
    /* Initializes random number generator*/
    srand((unsigned)time(&t));
    Coordonee caseTom[8];

    Coordonee autourPuc;
    bool test;
    int cTom = 0; // Compteur pour nombre de Coord dans le tableau de tomate mure

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (!(j == 0 && i == 0))
            {
                autourPuc.x = puc->coord.x + i;
                autourPuc.y = puc->coord.y + j;
                test = presenceTom(autourPuc, tab);

                if (test)
                {
                    caseTom[cTom] = autourPuc;
                    cTom++;
                }
            }
        }
    }
    if (cTom != 0)
    {
        int n = rand() % cTom;

        return caseTom[n];
    }
    else // Si il n'y as pas de tomate autour du puceron choisit une case vide autour du puceron
        return caseVideRandPuc(puc, tab);
}

void deplacementPuc(Puceron *puc, Case tab[N][N])
{
    Coordonee dir;
    dir = directionPuc(puc);
    dir.x = dir.x + puc->coord.x;
    dir.y = dir.y + puc->coord.y;
    if (presenceTom(dir, tab))
        placementPuc(puc, tab);
}

void mangeTom(Puceron *puc, Case tab[N][N])
{
    printf("Etat tomate fct : %d\n", tab[puc->coord.x][puc->coord.y].etatTomate);
    if (tab[puc->coord.x][puc->coord.y].etatTomate >= 5)
    {
        tab[puc->coord.x][puc->coord.y].etatTomate = 1;
        printf("Etat tomate fct : %d\n", tab[puc->coord.x][puc->coord.y].etatTomate);
        puc->nourriConse++;
    }
}

void vieillissementPuc(EnsemblePuc *ensP, Puceron *puc)
{
    puc->age++;
    if (puc->age >= 10)
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
}

void reproPuc(Puceron *puc, Case tab[N][N], EnsemblePuc *ensP)
{
    Puceron nPuceron; // Nouveau puceron a a ajouté dans Ensemble Puceron
    initPuc(&nPuceron);
    Coordonee emplaNvPuc = caseVideRandPuc(puc, tab);
    if (!(emplaNvPuc.x == 0 && emplaNvPuc.y == 0)) // Ne cree pas un nouveau puceron si pas d'emplacement vide autour du puceron
    {
        ajoutPuc(ensP, &nPuceron);
        setCoordPuc(&nPuceron,emplaNvPuc);
        placementPuc(&nPuceron,tab);
    }
}