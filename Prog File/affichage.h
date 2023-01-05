#ifndef HEADER_AFFICHAGE
#define HEADER_AFFICHAGE
#include "initialisation.h"

void tour(int nbtour,EnsemblePuc *ensP, Case tab [N][N]);
void afficher(Case tab[N][N], int taille);
void pousseTomate(Case tab[N][N]);
void deplacementEnsPuc(EnsemblePuc *ensP, Case tab[N][N]);
void actionPuc(EnsemblePuc *ensP, Case tab [N][N]);

#endif
