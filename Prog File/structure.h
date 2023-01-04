#ifndef HEADER_STRUCTURE
#define HEADER_STRUCTURE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10
#define NB_PUC 100
#define NB_COCCI 100

typedef struct // Structure stockant des coordonnees en 2D
{
    int x;
    int y;
} Coordonee;

typedef struct  // Structure définissant un puceron
{
    Coordonee coord; // Position dans le tableau 2D de case
    Coordonee precCoord; // Indique les coordonnées du tour précédent
    int age;         // Si atteint 10, le puceron meurt
    int nourriConse; // Nombre de tours consécutifs où le puceron a mangé
    int index;       // Indique la position du puceron dans la structure ...
    bool aMange; // Permet de savoir si le puceron a mange de façon consecutive
} Puceron;

void initPuc(Puceron *puc); // Fonction permettant d'initier un puceron avec des parametre de base et avec des coordonnées en dehors de la matrice.


typedef struct
{
    Puceron *tab[NB_PUC];
    int card; // Indique le nombre de puceron dans le tableau
} EnsemblePuc;

void creaEnsPuc(EnsemblePuc *ensP);
void ajoutPuc(EnsemblePuc *ensP, Puceron *puc);
void vieillissementPuc(EnsemblePuc *ensP, Puceron *puc);
void mortPuc(EnsemblePuc *ensP, Puceron *puc);

typedef struct
{
    Coordonee coord;  // Position dans le tableau 2D de case
    int age;          // Si atteint 20, la coccinelle meurt
    int puceronConso; // Nombre de pucerons mangés
    int index;        // Indique la position de la coccinelle dans la structure ...
} Coccinelle;

typedef struct
{

} EnsembleCocci;

typedef struct
{
    Puceron *puc;
    Coccinelle *cocci;
    int etatTomate; // Indique
} Case;

Coordonee caseVideRandPuc(Puceron *puc,Case tab[N][N]);
void mangeTom(Puceron *puc, Case tab[N][N]);
void setCoordPuc(Puceron *puc, Coordonee coord);
void placementPuc(Puceron *puc, Case tab[N][N]);
void deplacementPuc(Puceron *puc, Case tab[N][N]);
Coordonee directionPuc(Puceron *puc);
bool presenceTom(Coordonee coord, Case tab[N][N]);
Coordonee selectRandTom(Puceron *puc, Case tab[N][N]); // attention ne renvoie que qunad pres tomate pour l'instant
void reproPuc(Puceron *puc, Case tab[N][N], EnsemblePuc *ensP);

#endif