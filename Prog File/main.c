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
    
    
   
    Coordonee mil={4,4};
    placementPuc(&pussy,mil,potager);
    Puceron *array[10];
    initTab(array,10);
    Coordonee mil1={1,1};
    placementPuc(array[0],mil1,potager);
    Coordonee mil2={0,0};
    placementPuc(array[1],mil2,potager);


    printf("Posi pussy : %d %d \n",pussy.coord.x,pussy.coord.y);
    printf("Etat tomate : %d\n", potager[5][5].etatTomate);
    mangeTom(&pussy, potager);
    printf("Etat tomate : %d\n", potager[5][5].etatTomate);
    //potager[4][4].etatTomate=1;
    Coordonee pres=selectRandTom(&pussy,potager);
    printf("X= %d et Y= %d\n",pres.x,pres.y);
    
    afficher(potager, N);

    printf("end main\n");
    return 0;
}