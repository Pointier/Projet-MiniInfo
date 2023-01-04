#include "structure.h"
#include "affichage.h"
#include "initialisation.h"


int main()
{
    printf("start main\n");

    Case potager[N][N];

    initialisationCase(potager, N);
    

    EnsemblePuc ensP;
    creaEnsPuc(&ensP);
    int numPucIni=20;
    initEnsemblePuc(&ensP, numPucIni);
    initPlacInsecte(&ensP,potager);
    afficher(potager,N);
      
    
   


    printf("end main\n");
    return 0;
}