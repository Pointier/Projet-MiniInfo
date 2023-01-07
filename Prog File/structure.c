#include "structure.h"

void initPuc(Puceron *puc) // Fonction permettant d'initier un puceron avec des parametre de base et avec des coordonnées en dehors de la matrice.
{
    puc->coord.x = -1;
    puc->coord.y = -1;
    puc->direction.x = 0;
    puc->direction.y = 0;
    puc->age = 0;
    puc->nourriConse = 0;
    puc->index = -1;
    puc->mortPuc = false;
}

void setCoordPuc(Puceron *puc, Coordonnee coord) // Permet de modifier les coordonnees d'un puceron.
{

    checkCoord(&coord); // Verifie que les coordonnees ne sont pas hors grille
    puc->coord.x = coord.x;
    puc->coord.y = coord.y;
}

void checkCoord(Coordonnee *coord) // Permet de supprimer les bordures
// Si les coordonnees sont superieur a la limite de la grille , les coordonnes sont mise a 0
//  ou si inferieur a la grille mise au maximum pour simuler une grille sans bord.
{
    if (coord->x <= -1)
        coord->x = N - 1;
    if (coord->x >= N)
        coord->x = 0;
    if (coord->y <= -1)
        coord->y = N - 1;
    if (coord->y >= N)
        coord->y = 0;
}

void placementPuc(Puceron *puc, Case tab[N][N]) // Place le puceron sur la case indiqué
// Prends les coordonnees du puceron et assigne sont adresse a la case.
{
    checkCoord(&puc->coord);
    tab[puc->coord.x][puc->coord.y].puc = puc;
}

void deplacementPuc(Puceron *puc, Case tab[N][N]) // Deplace le puceron soit selon direction precedente soit Tomate random autour si possible.
{
    if (presenceTom(puc->direction, tab)) // Si presence tomate et pas d'obstacle dans la direction du puceron il se deplace sur cette case.
    {
        suppPucCase(puc->coord, tab);
        puc->coord.x = puc->coord.x + puc->direction.x;
        puc->coord.y = puc->coord.y + puc->direction.y;
        placementPuc(puc, tab);
    }
    else // Sinon reassigne une direction aleatoire
    {
        directionPuc(puc, tab);
        suppPucCase(puc->coord, tab);
        puc->coord.x = puc->coord.x + puc->direction.x;
        puc->coord.y = puc->coord.y + puc->direction.y;
        placementPuc(puc, tab);
    }
}

void suppPucCase(Coordonnee coord, Case tab[N][N]) // Supprime le pointeur puceron de la case.
{
    tab[coord.x][coord.y].puc = NULL;
}

void directionPuc(Puceron *puc, Case tab[N][N]) // Permet d'assigner une direction a un puceron.
{
    Coordonnee prochaineCase;
    prochaineCase.x = puc->coord.x + puc->direction.x;
    prochaineCase.y = puc->coord.y + puc->direction.y;
    if ((puc->direction.x == 0 && puc->direction.y == 0) || !(presenceTom(prochaineCase, tab)))
    {
        puc->direction = selectRandTom(puc->direction, tab);
    }
}

bool presenceTom(Coordonnee coord, Case tab[N][N]) // Permet de savoir si tomate mangeable sur la case.
{
    checkCoord(&coord);
    if (tab[coord.x][coord.y].etatTomate >= 5 && tab[coord.x][coord.y].cocci == NULL && tab[coord.x][coord.y].puc == NULL) // Si tomate a plus de 5 et pas d'obstacle renvoie que la case est correcte.
    {
        return true;
    }

    else
    {
        return false;
    }
}

Coordonnee caseVideRandPuc(Coordonnee coord, Case tab[N][N]) // Selectionne une case vide autour des pucerons et si pas possible renvoie la position actuelle du puceron.
{
    Coordonnee caseVide[8];
    int cVide = 0; // Compteur pour nombre de Coord dans le tableu de case vide
    Coordonnee autourPuc;
    Coordonnee dir;
    for (int i = -1; i < 2; i++) // Permet de regarder toutes les cases autour du puceron et si vide les ajoutent dans un tableau de coordonnees
    {
        for (int j = -1; j < 2; j++)
        {
            if (!(j == 0 && i == 0))
            {
                autourPuc.x = coord.x + i;
                autourPuc.y = coord.y + j;

                if (tab[autourPuc.x][autourPuc.y].cocci == NULL && tab[autourPuc.x][autourPuc.y].puc == NULL)
                {
                    dir.x = i;
                    dir.y = j;
                    caseVide[cVide] = dir;
                    cVide++;
                }
            }
        }
    }
    if (cVide != 0) // Si il y a des case dans le tableau en choisit une aleatoirement.
    {
        int n = rand() % cVide;
        return caseVide[n];
    }
    else // si toutes les cases sont occupés le puceron ne bouge pas
    {
        dir.x = 0;
        dir.y = 0;
        return autourPuc;
    }
}

Coordonnee selectRandTom(Coordonnee coord, Case tab[N][N]) // Selectionne une case vide autour des pucerons et si pas possible renvoie la position actuelle du puceron.
{

    Coordonnee caseTom[8];
    Coordonnee autourPuc;
    Coordonnee dir;
    bool test;
    int cTom = 0; // Compteur pour nombre de Coord dans le tableau de tomate mure

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (!(j == 0 && i == 0))
            {
                autourPuc.x = coord.x + i;
                autourPuc.y = coord.y + j;
                test = presenceTom(autourPuc, tab);

                if (test)
                {
                    dir.x = i;
                    dir.y = j;
                    caseTom[cTom] = dir;
                    cTom++;
                }
            }
        }
    }
    if (cTom != 0) // Si le tableau n'est pas vide, choisit une case contenant une tomate mangeable
    {
        int n = rand() % cTom;

        return caseTom[n];
    }
    else // Si il n'y as pas de tomate autour du puceron choisit une case vide autour du puceron
        return caseVideRandPuc(autourPuc, tab);
}

void mangeTom(Puceron *puc, Case tab[N][N]) // Fait manger la tomate au puceron si possible
{

    if (tab[puc->coord.x][puc->coord.y].etatTomate >= 5)
    {
        tab[puc->coord.x][puc->coord.y].etatTomate = 1;

        puc->nourriConse++;
    }
    else
        puc->nourriConse = 0; // Remet le compteur de nourriture conse a 0
}

void vieillissementPuc(EnsemblePuc *ensP, Puceron *puc, Case tab[N][N]) // Fonction qui vieillit les pucerons et appelle la fonction mort si trop vieux
{
    puc->age++;
    if (puc->age >= 10)
    {
        mortPuc(ensP, *puc, tab);
    }
}

void creaEnsPuc(EnsemblePuc *ensP) // Initialise le cardinal
{
    ensP->card = 0;
}

void ajoutPuc(EnsemblePuc *ensP, Puceron puc) // Rajoute un puceron dans l'ensemble puceron
{
    ensP->tab[ensP->card] = puc;
    puc.index = ensP->card;
    ensP->card++;
}
void mortPuc(EnsemblePuc *ensP, Puceron puc, Case tab[N][N]) // Tue les puceron et les enleve de la grille.
{

    suppPucCase(puc.coord, tab);

    ensP->tab[puc.index] = ensP->tab[ensP->card - 1]; // On remplace la puce morte par le dernier puceron du tableau
    ensP->tab[ensP->card - 1].index = puc.index;      // On met a jour l'index du puceron déplacé
    ensP->card = ensP->card - 1;                      // On met a jour le cardinal
}

void reproPuc(Puceron puc, Case tab[N][N], EnsemblePuc *ensP) // Permet la reproduction d'un nouveau puceron.
{
    Coordonnee emplaNvPuc = caseVideRandPuc(puc.coord, tab); // Verifie et choisit une case vide autour du puceron(parent);
    if (!(emplaNvPuc.x == 0 && emplaNvPuc.y == 0)) // Ne cree pas un nouveau puceron si pas d'emplacement vide autour du puceron
    {
        if (ensP->card < NB_PUC) // Si le tableau de puceron n'est pas plein ajoute un puceron
        {
            Puceron nPuceron; // Nouveau puceron a a ajouté dans Ensemble Puceron
            initPuc(&nPuceron);
            emplaNvPuc.x = emplaNvPuc.x + puc.coord.x;
            emplaNvPuc.y = emplaNvPuc.y + puc.coord.y;
            ajoutPuc(ensP, nPuceron);
            setCoordPuc(&ensP->tab[ensP->card], emplaNvPuc);
            placementPuc(&ensP->tab[ensP->card], tab);
        }
    }
}
