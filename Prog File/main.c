#include "structure.h"
#include "affichage.h"
#include "initialisation.h"

int main()
{
    time_t t;
    /* Initializes random number generator*/
    srand((unsigned) time(&t));
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
    
    
    potager[5][5].puc=&pussy;
    Coordonee mil={5,5};
    placementPuc(&pussy,mil);

    printf("Posi pussy : %d %d \n",pussy.coord.x,pussy.coord.y);
    printf("Etat tomate : %d\n", potager[5][5].etatTomate);
    mangeTom(&pussy, potager);
    printf("Etat tomate : %d\n", potager[5][5].etatTomate);
    
    afficher(potager, N);

    printf("end main\n");
    return 0;
}