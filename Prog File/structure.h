#ifndef HEADER_STRUCTURE
#define HEADER_STRUCTURE
#include <stdio.h>
#define N 10

typedef struct Coordonee Coordonee;

typedef struct Case Case;

typedef struct Puceron Puceron;
void creationPuc(Puceron *puc);
void vieillissementPuc(Puceron *puc);

typedef struct EnsemblePuc EnsemblePuc;
void creaEnsPuc(EnsemblePuc *ensP);
void ajoutPuc(EnsemblePuc *ensP, Puceron *puc);

typedef struct Coccinelle Coccinelle;

typedef struct EnsembleCocci EnsembleCocci;

#endif