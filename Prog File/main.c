#include "structure.h"
#include "affichage.h"
#include "initialisation.h"


int main()
{
    printf("start main\n");

    Case potager[N][N];
    printf("Potager Done\n");
    initialisationCase(potager, N);
    printf("Init Case done\n");
    EnsemblePuc ensP;
    printf("Ensemble puc done\n");

    creaEnsPuc(&ensP);
    printf("CreaEnsPuc done\n");
    int numPucIni=20;
    initEnsemblePuc(&ensP, numPucIni);
    printf("Init Ensemble Puc done\n");

    initPlacInsecte(&ensP,potager);
    printf("Init Plac Insecte done\n");
    
    placementPuc(ensP.tab[0],potager);
    printf("Coord puc x: %d y: %d\n",ensP.tab[0]->coord.x,ensP.tab[0]->coord.y);
    aa(ensP.tab[0],potager);
    Puceron fuck;
    fuck.coord.x=5;
    fuck.coord.y=5;
    aa(&fuck,potager);

    tour(5,&ensP,potager);

   // afficher(potager,N);
    //printf("Affichage Done\n");
    
   


    printf("end main\n");
    return 0;
}