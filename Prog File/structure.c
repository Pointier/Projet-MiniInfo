#include "structure.h"

struct Coordonee
{
    int x;
    int y;
};

struct Case
{
    struct Puceron *puc;
    struct Coccinelle *cocci;
    int etatTomate; // 
};

struct Puceron
{
    struct Coordonee coord;
    int age;
    int nourriConse; // Nombre de tours consécutifs où le puceron a mangé
    int indice;
};

struct Coccinelle
{
    struct Coordonee coord;
    int age;
    int puceronConso; // Nombre de pucerons mangés
    int indice;
};