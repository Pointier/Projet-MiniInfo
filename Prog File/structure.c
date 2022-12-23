#include "structure.h"



struct Coordonee
{
    int x;
    int y;
};

struct Case
{
    Puceron *puc;
    Coccinelle *cocci;
    int etatTomate; // Indique
};

struct Puceron
{
    Coordonee coord; // Position dans le tableau 2D de case
    int age;         // Si atteint 10, le puceron meurt
    int nourriConse; // Nombre de tours consécutifs où le puceron a mangé
    int index;       // Indique la position du puceron dans la structure ...
};

void creationPuc(Puceron *puc)
{
    puc->coord.x = -1;
    puc->coord.y = -1;
    puc->age = 0;
    puc->nourriConse = 0;
    puc->index = -1;
}

void vieillissementPuc(Puceron *puc)
{
    puc->age++;
}

struct EnsemblePuc
{
    Puceron *tab[N];
    int card; // Indique le nombre de puceron dans le tableau
};

void creaEnsPuc(EnsemblePuc *EnsP)
{
    EnsP->card=0;
}

void ajoutPuc(EnsemblePuc *EnsP, Puceron *puc)
{
    EnsP->tab[EnsP->card] = puc;
    EnsP->card++;
}

struct Coccinelle
{
    Coordonee coord;  // Position dans le tableau 2D de case
    int age;          // Si atteint 20, la coccinelle meurt
    int puceronConso; // Nombre de pucerons mangés
    int index;        // Indique la position de la coccinelle dans la structure ...
};