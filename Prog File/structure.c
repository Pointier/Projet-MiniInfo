#include "structure.h"

struct Coordonnee
{
    int x;
    int y;
};

struct Case
{
    Puceron *puc = NULL;
    Coccinelle *cocci = NULL;
    int etatTomate = 5; // initialise la tomate comme mature
};

struct Puceron
{
    Coordonee coord;
    int age;
    int nourriConse; // Nombre de tours consécutifs où le puceron a mangé
    int indice;
};

struct Coccinelle
{
    Coordonee coord;
    int age;
    int puceronConso; // Nombre de pucerons mangés
    int indice;
};