#ifndef HEADER_STRUCTURE
#define HEADER_STRUCTURE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 30
#define NB_PUC 900
#define NB_COCCI 900

typedef struct // Structure stockant des coordonnees en 2D
{
    int x;
    int y;
} Coordonnee;

typedef struct // Structure définissant un puceron
{
    Coordonnee coord;     // Position dans le tableau 2D de case
    Coordonnee direction; // Indique la direction du puceron
    bool mortPuc;
    int age;         // Si atteint 10, le puceron meurt
    int nourriConse; // Nombre de tours consécutifs où le puceron a mangé
    int index;       // Indique la position du puceron dans la structure ...
} Puceron;

void initPuc(Puceron *puc); // Fonction permettant d'initier un puceron avec des parametre de base et avec des coordonnées en dehors de la matrice.

typedef struct // Structure contenant les pucerons et l'index permettant de savoir combien il y a de puceron.
{
    Puceron tab[NB_PUC];
    int card; // Indique le nombre de puceron dans le tableau
} EnsemblePuc;

void creaEnsPuc(EnsemblePuc *ensP);            // Initialise le cardinal
void ajoutPuc(EnsemblePuc *ensP, Puceron puc); // Rajoute un puceron dans l'ensemble puceron

typedef struct // Structure Coccinelle
{
    Coordonnee coord; // Position dans le tableau 2D de case
    int age;          // Si atteint 20, la coccinelle meurt
    int puceronConso; // Nombre de pucerons mangés
    int index;        // Indique la position de la coccinelle dans la structure ...
} Coccinelle;

typedef struct // Structure contenant les coccinelles et l'index permettant de savoir combien il y a de coccinelles.
{
    Coccinelle tab[NB_COCCI];
    int card; // Indique le nombre de puceron dans le tableau
} EnsembleCocci;

typedef struct // Structure permettant de simuler un potager, contient un pointeur vers coccinelle ou puceron pour savoir ou il sont.
// Contient aussi un int pour simuler une tomate.
{
    Puceron *puc;
    Coccinelle *cocci;
    int etatTomate;
} Case;

void vieillissementPuc(EnsemblePuc *ensP, Puceron *puc, Case tab[N][N]); // Fonction qui vieillit les pucerons et appelle la fonction mortPuc si trop vieux
void mortPuc(EnsemblePuc *ensP, Puceron puc, Case tab[N][N]);            // Tue les puceron et les enleve de la grille.
Coordonnee caseVideRandPuc(Coordonnee coord, Case tab[N][N]);            // Selectionne une case vide autour des pucerons et si pas possible renvoie la position actuelle du puceron.
void mangeTom(Puceron *puc, Case tab[N][N]);                             // Fait manger la tomate au puceron si possible
void placementPuc(Puceron *puc, Case tab[N][N]);                         // Place le puceron sur la case indiqué
void deplacementPuc(Puceron *puc, Case tab[N][N]);                       // Deplace le puceron soit selon direction precedente soit Tomate random autour si possible.
void directionPuc(Puceron *puc, Case tab[N][N]);                         // Permet de connaitre la direction du puceron.
bool presenceTom(Coordonnee coord, Case tab[N][N]);                      // Permet de savoir si tomate mangeable sur la case.
Coordonnee selectRandTom(Coordonnee coord, Case tab[N][N]);              // Selection une tomate mure random autour du puceron
void suppPucCase(Coordonnee coord, Case tab[N][N]);                      // Supprime le pointeur puceron de la case.
void reproPuc(Puceron puc, Case tab[N][N], EnsemblePuc *ensP);           // Permet la reproduction d'un nouveau puceron.
void checkCoord(Coordonnee *coord);                                      // Permet de supprimer les bordure
void setCoordPuc(Puceron *puc, Coordonnee coord);                        // Permet de modifier les coordonnees d'un puceron.
#endif