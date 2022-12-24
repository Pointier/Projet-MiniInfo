#include "structure.h"
#include "affichage.h"
#include "initialisation.h"

int main()
{
    printf("start main\n");
    Case potager[N][N];

    initialisationCase(potager, N);

    EnsemblePuc testEnsP;
    creaEnsPuc(&testEnsP);
    Puceron pussy;
    initPuc(&pussy);
    Puceron fuzzy;
    initPuc(&fuzzy);

    ajoutPuc(&testEnsP, &pussy);
    ajoutPuc(&testEnsP, &fuzzy);
    printf("%d\n", testEnsP.tab[0]->age);
    vieillissementPuc(&pussy);
    printf("%d\n", testEnsP.tab[0]->age);
    // potager[5][5].puc=&pussy;
    printf("index fuzzy : %d\n", fuzzy.index);
    mortPuc(&testEnsP, &pussy);
    printf("index fuzzy : %d\n", fuzzy.index);
    afficher(potager, N);

    printf("end main\n");
    return 0;
}