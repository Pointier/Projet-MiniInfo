#include "structure.h"
#include "affichage.h"
#include "initialisation.h"





int main()
{
    printf("start main\n");
    Case potager[N][N];
   
    initialisationCase(potager, N);
    
    afficher(potager, N);
    
    EnsemblePuc testEnsP;
    creaEnsPuc(&testEnsP);
    Puceron pussy;
    ajoutPuc(&testEnsP,&pussy);
    printf("%d\n",testEnsP.tab[0]->age);
    vieillissementPuc(&pussy);
    printf("%d\n",testEnsP.tab[0]->age);

    printf("end main\n");
    return 0;
}