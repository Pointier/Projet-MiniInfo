#include "affichage.h"

void afficher(Case tab[N][N], int taille) // Prend une matrice carree et l'affiche
{
    printf("Affichage\n");
    for (int i = 0; i < taille; i++)
    {
        for (int j = 0; j < taille; j++)
        {
            if (tab[i][j].puc == NULL && tab[i][j].cocci == NULL)
            {
                printf("\033[1;37m");

                if (tab[i][j].etatTomate >= 1 && tab[i][j].etatTomate <= 4)
                    printf(".");
                else if (tab[i][j].etatTomate >= 5 && tab[i][j].etatTomate <= 19)
                    printf("o");
                else if (tab[i][j].etatTomate == 20)
                    printf("O");
            }
            else if (tab[i][j].puc != NULL || tab[i][j].cocci != NULL)
            {
                if (tab[i][j].cocci != NULL)
                {
                    printf("\033[0;31m");
                }
                else
                {
                    printf("\033[0;32m");
                    if ((tab[i][j].puc->direction.x==-1&&tab[i][j].puc->direction.y==-1)||(tab[i][j].puc->direction.x==-1&&tab[i][j].puc->direction.y==-1))
                    {
                        printf("\\");
                    }
                    else if((tab[i][j].puc->direction.x==-1&&tab[i][j].puc->direction.y==1)||(tab[i][j].puc->direction.x==1&&tab[i][j].puc->direction.y==-1))
                    {
                        printf("/");
                    }
                    else if (tab[i][j].puc->direction.x==-1&&tab[i][j].puc->direction.y==0)
                    {
                        printf("Ʌ");
                    }
                    else if (tab[i][j].puc->direction.x==1&&tab[i][j].puc->direction.y==0)
                    {
                        printf("V");
                    }
                    else if (tab[i][j].puc->direction.x==0&&tab[i][j].puc->direction.y==1)
                    {
                        printf(">");
                    }
                    else if (tab[i][j].puc->direction.x==0&&tab[i][j].puc->direction.y==-1)
                    {
                        printf("<");
                    }
                }
            }
            if (j + 1 == taille)
                printf("\n");
        }
    }
}
void pousseTomate(Case tab[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tab[i][j].etatTomate<20)
            tab[i][j].etatTomate++;
        }
    }
}

void deplacementEnsPuc(EnsemblePuc *ensP, Case tab[N][N])
{
    printf("Start depla ensemble puc\n");
    for (int i = 0; i < ensP->card; i++)
    {
        deplacementPuc(&ensP->tab[i], tab);
    }
}

void actionPuc(EnsemblePuc *ensP, Case tab[N][N])
{
    for (int i = 0; i < ensP->card; i++)
    {
        mangeTom(&ensP->tab[i], tab);
        if (ensP->tab[i].nourriConse == 5)
            reproPuc(&ensP->tab[i], tab, ensP);
        vieillissementPuc(ensP, &ensP->tab[i],tab);
        directionPuc(&ensP->tab[i],tab);
    }
}

void tour(int nbtour,EnsemblePuc *ensP, Case tab [N][N])
{
    for(int i=0;i<nbtour;i++)
    {
        printf("Tour %d :\n",i);
        printf("Ok1\n");
        pousseTomate(tab);
        if(i!=0)
        {
            deplacementEnsPuc(ensP, tab);
        }
        
        printf("Deplacement Ensemble Puc done\n");
        actionPuc(ensP,tab);
        printf("Action Puc done\n");
        printf("Direction puceron %d x %d y %d\n",i,ensP->tab[0].direction.x,ensP->tab[0].direction.y);
        afficher(tab,N);
        printf("Fin tour\n");
    }
}