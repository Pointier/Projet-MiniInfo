#ifndef HEADER_STRUCTURE
#define HEADER_STRUCTURE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 8
#define NB_PUC 100
#define NB_COCCI 100

typedef struct // Structure stockant des coordonnees en 2D
{
    int x;
    int y;
} Coordonnee;

typedef struct  // Structure définissant un puceron
{
    Coordonnee coord; // Position dans le tableau 2D de case
    Coordonnee direction; // Indique la direction du puceron
    bool directionChanger;
    int age;         // Si atteint 10, le puceron meurt
    int nourriConse; // Nombre de tours consécutifs où le puceron a mangé
    int index;       // Indique la position du puceron dans la structure ...
} Puceron;



void initPuc(Puceron *puc); // Fonction permettant d'initier un puceron avec des parametre de base et avec des coordonnées en dehors de la matrice.


typedef struct
{
    Puceron tab[NB_PUC];
    int card; // Indique le nombre de puceron dans le tableau
} EnsemblePuc;



void creaEnsPuc(EnsemblePuc *ensP);
void ajoutPuc(EnsemblePuc *ensP, Puceron puc);

typedef struct
{
    Coordonnee coord;  // Position dans le tableau 2D de case
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

void vieillissementPuc(EnsemblePuc *ensP, Puceron *puc, Case tab[N][N]); // Fonction qui vieillit les pucerons et appelle la fonction mort si trop vieux
void mortPuc(EnsemblePuc *ensP, Puceron *puc, Case tab[N][N]); // Tue les puceron et les enleve de la grille.
Coordonnee caseVideRandPuc(Coordonnee coord,Case tab[N][N]); // Selectionne une case vide autour des pucerons et si pas possible renvoie la position actuelle du puceron.
void mangeTom(Puceron *puc, Case tab[N][N]); // Fait manger la tomate au puceron si possible
void placementPuc(Puceron *puc, Case tab[N][N]); // Place le puceron sur la case indiqué
void deplacementPuc(Puceron *puc, Case tab[N][N]); // Deplace le puceron soit selon direction precedente soit Tomate random autour si possible.
void directionPuc(Puceron *puc,Case tab[N][N]); // Permet de connaitre la direction du puceron.
bool presenceTom(Coordonnee coord, Case tab[N][N]); // Permet de savoir si tomate mangeable sur la case.
Coordonnee selectRandTom(Coordonnee coord, Case tab[N][N]); // attention ne renvoie que qunad pres tomate pour l'instant
void suppPucCase(Coordonnee coord, Case tab[N][N]); // Supprime le pointeur puceron de la case.
void reproPuc(Puceron *puc, Case tab[N][N], EnsemblePuc *ensP); // Permet la reproduction d'un nouveau puceron.
void checkCoord(Coordonnee *coord); // Permet de passer de changer de bord.
int generationDirection();
void setCoordPuc(Puceron *puc,Coordonnee coord);
Coordonnee decodageDirection(int n);
#endif