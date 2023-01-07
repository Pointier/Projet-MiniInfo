#ifndef HEADER_INITIALISATION
#define HEADER_INITIALISATION
#include "structure.h"

void initialisationCase(Case tab[N][N], int taille); // Initialise l'ensemble de la grille avec des tomates mures et met le pointeur null
// pour indiquer l'absence de puceron et coccinnelle
void initEnsemblePuc(EnsemblePuc *ensP, int numPuc);     // Cree et initialise l'ensemble des puceron dans le tableau
void initPlacInsecte(EnsemblePuc *ensP, Case tab[N][N]); // Place tout les insectes sur la grille

#endif