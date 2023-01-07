#include "initialisation.h"

void initialisationCase(Case tab[N][N], int taille)
// Initialise l'ensemble de la grille avec des tomates mures et met
// le pointeur null pour indiquer l'absence de puceron et coccinelle
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
// Cree et initialise l'ensemble des puceron dans le tableau
{
    for (int i = 0; i < numPuc; i++)
    {
        Puceron puc;
        initPuc(&puc);
        ajoutPuc(ensP, puc);
    }
}

void initPlacInsecte(EnsemblePuc *ensP, Case tab[N][N])
// Place tout les insectes sur la grille
{
    // On aurais rajouté les coccinelles dans le tableau de coordonnee (pour la taille) mais comme on ne les a pas implementés.
    Coordonnee tabCoord[ensP->card]; // Cree un tableau de coordonnees contenant le nombre de puceron et coccinelle
    int c = 0;                       // Compteur du nombre de coordonnée dans le tableau
    while (c < ensP->card)           // Boucle while permettant de generer un ensemble de coordonnee differentes
    {
        bool nouvCoord = true; //
        Coordonnee coordRand;
        coordRand.x = rand() % (N - 1);
        coordRand.y = rand() % (N - 1);
        for (int i = 0; i < c; i++) // Parcourt le tableau pour verifier que les coordonnees nouvellement creer sont bien differentes des autres
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

    for (int i = 0; i < ensP->card; i++) // Assigne a chaque insecte une coordonnee
    {
        ensP->tab[i].coord = tabCoord[i];
        placementPuc(&ensP->tab[i], tab);
    }
    // On aurais rajoute une boucle pour assigner les positions aux coccinelles.
}
