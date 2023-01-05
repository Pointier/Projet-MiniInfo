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
    coord=checkCoord(coord);
    puc->coord.x = coord.x;
    puc->coord.y = coord.y;
}

Coordonee checkCoord(Coordonee coord) // Permet de passer de changer de bord.
{
    if (coord.x==-1)
    coord.x=N-1;
    if(coord.x==N)
    coord.x=0;
    if (coord.y==-1)
    coord.y=N-1;
    if(coord.y==N)
    coord.y=0;
    return coord;
}

void placementPuc(Puceron *puc, Case tab[N][N]) // Place le puceron sur la case indiqué
{
    
    printf("Coord puc in pla x: %d y: %d\n",puc->coord.x,puc->coord.y);
    tab[puc->coord.x][puc->coord.y].puc = puc;
}

void deplacementPuc(Puceron *puc, Case tab[N][N]) // Deplace le puceron soit selon direction precedente soit Tomate random autour si possible.
{
    printf("Coord puc in depla x: %d y: %d\n",puc->coord.x,puc->coord.y);
    printf("Adresse puc dans depla : %p\n",puc);
    Coordonee dir;
    /*dir = directionPuc(puc);
    
    dir.x = dir.x + puc->coord.x;
    dir.y = dir.y + puc->coord.y;
    dir=checkCoord(dir);
    if (presenceTom(dir, tab))
    {
        suppPucCase(puc,tab);
        setCoordPuc(puc,dir);
        placementPuc(puc, tab); 
    }
        
    else
    {*/
        suppPucCase(puc,tab);
        
        dir=selectRandTom(puc,tab);
        setCoordPuc(puc,dir);
        placementPuc(puc, tab); 
   // }
    
}

void suppPucCase(Puceron *puc, Case tab[N][N]) // Supprime le pointeur puceron de la case.
{
    //printf("Ok2\n");
    printf("Adresse puc dans suppPucCase : %p\n",puc);
    printf("Coord puc in suppPuceCase x: %d y: %d\n",puc->coord.x,puc->coord.y);
    tab[puc->coord.x][puc->coord.y].puc = NULL;
    
}
Coordonee directionPuc(Puceron *puc) // Permet de connaitre la direction du puceron.
{
    Coordonee dir;
    dir.x = puc->coord.x - puc->precCoord.x;
    dir.y = puc->coord.y - puc->precCoord.y;
    dir=checkCoord(dir);
    return dir;
}

bool presenceTom(Coordonee coord, Case tab[N][N]) // Permet de savoir si tomate mangeable sur la case.
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
                autourPuc=checkCoord(autourPuc);

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

Coordonee selectRandTom(Puceron *puc, Case tab[N][N]) // Selectionne une case vide autour des pucerons et si pas possible renvoie la position actuelle du puceron.
{
    
    printf("Rand x: %d y: %d\n",puc->coord.x,puc->coord.y);
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
                autourPuc=checkCoord(autourPuc);
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



void mangeTom(Puceron *puc, Case tab[N][N]) // Fait manger la tomate au puceron si possible
{
    
    if (tab[puc->coord.x][puc->coord.y].etatTomate >= 5)
    {
        tab[puc->coord.x][puc->coord.y].etatTomate = 1;
        
        puc->nourriConse++;
    }
}

void vieillissementPuc(EnsemblePuc *ensP, Puceron *puc, Case tab[N][N]) // Fonction qui vieillit les pucerons et appelle la fonction mort si trop vieux
{
    puc->age++;
    if (puc->age >= 10)
        mortPuc(ensP, puc,tab);
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
void mortPuc(EnsemblePuc *ensP, Puceron *puc, Case tab[N][N]) // Tue les puceron et les enleve de la grille.
{
    if (ensP->card > 1)
    {
        ensP->tab[puc->index] = ensP->tab[ensP->card - 1]; // On remplace la puce morte par le dernier puceron du tableau
        ensP->tab[ensP->card - 1]->index = puc->index;     // On met a jour l'index du puceron déplacé
        ensP->card = ensP->card - 1;                       // On met a jour le cardinal
    }
    puc->index = -1;
    suppPucCase(puc,tab);
}

void reproPuc(Puceron *puc, Case tab[N][N], EnsemblePuc *ensP) // Permet la reproduction d'un nouveau puceron.
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