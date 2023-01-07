#ifndef HEADER_AFFICHAGE
#define HEADER_AFFICHAGE
#include "initialisation.h"

void afficher(Case tab[N][N], int taille); // Prend une matrice carree et l'affiche
void pousseTomate(Case tab[N][N]);
void deplacementEnsPuc(EnsemblePuc *ensP, Case tab[N][N]);
void actionPuc(EnsemblePuc *ensP, Case tab[N][N]);
void tour(int nbtour, EnsemblePuc *ensP, Case tab[N][N]);
#endif
