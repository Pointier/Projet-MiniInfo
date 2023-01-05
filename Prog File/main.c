#include "structure.h"
#include "affichage.h"
#include "initialisation.h"

int main()
{
    printf("start main\n");

    Case potager[N][N];
    // printf("Potager Done\n");
    // initialisationCase(potager, N);
    // printf("Init Case done\n");
    EnsemblePuc ensP;
    // printf("Ensemble puc done\n");

    creaEnsPuc(&ensP);
    // printf("CreaEnsPuc done\n");
    int numPucIni = 20;
    initEnsemblePuc(&ensP, numPucIni);
    initPlacInsecte(&ensP, potager);
    // printf("Init Ensemble Puc done\n");
    printf("Coord puc 0: %d y: %d\n", ensP.tab[0]->coord.x, ensP.tab[0]->coord.y);
    printf("Coord puc 1: %d y: %d\n", ensP.tab[1]->coord.x, ensP.tab[1]->coord.y);
    printf("Essai avec un puceron hors tableau\n");
    Puceron try;
    initPuc(&try);
    try.coord.x = 2;
    try.coord.y = 3;
    deplacementPuc(&try, potager);
    
    ensP.tab[0]->coord.x = 5;
    ensP.tab[0]->coord.y = 10;
    placementPuc(ensP.tab[0], potager);
    printf("Coord puc x: %d y: %d\n", ensP.tab[0]->coord.x, ensP.tab[0]->coord.y);
    printf("Adresse puc dans main : %p\n",ensP.tab[0]);
    deplacementPuc(ensP.tab[0], potager);

    initPlacInsecte(&ensP, potager);
    printf("Init Plac Insecte done\n");

    tour(5, &ensP, potager);

    // afficher(potager,N);
    // printf("Affichage Done\n");

    printf("end main\n");
    return 0;
}