#include "structure.h"
#include "affichage.h"
#include "initialisation.h"

int main()
{
    printf("start main\n");
    //printf("Taille N : %d \n",N);
    time_t t;
    srand((unsigned) time(&t));
    Case potager[N][N];
    // printf("Potager Done\n");
    initialisationCase(potager, N);
    //printf("Init Case done\n");
    EnsemblePuc ensP;
    //printf("Ensemble puc done\n");
    creaEnsPuc(&ensP);
    //printf("CreaEnsPuc done\n");
    int numPucIni = 1;
    initEnsemblePuc(&ensP, numPucIni);
    //printf("Init Ensemble Puc done\n");
    initPlacInsecte(&ensP, potager);
    //printf("Init Plac Insecte done\n");

    tour(50, &ensP, potager);

    //afficher(potager,N);
    //printf("Affichage Done\n");

    printf("end main\n");
    return 0;
}