#include "structure.h"
#include "affichage.h"
#include "initialisation.h"

int main()
{
    printf("start main\n");
    time_t t;
    srand((unsigned)time(&t)); // Initialise time pour les seed de la fonction random

    Case potager[N][N];             // Cree le potager
    initialisationCase(potager, N); // initialise le potager

    EnsemblePuc ensP;  // Cree l'ensemble contenant les puceron
    creaEnsPuc(&ensP); // Initialise l'ensemble contenant les pucerons
    int numPucIni = 1;
    initEnsemblePuc(&ensP, numPucIni); // Crre et ajoute 20 pucerons à l'ensemble

    initPlacInsecte(&ensP, potager); // Place les insectes dans le potager.

    tour(50, &ensP, potager); // Gestion des tours

    printf("end main\n");
    return 0;
}