//
// Created by 陈文龙 on 2022/10/21.
//

#ifndef NF16_TP3_H
#define NF16_TP3_H
#include <stdlib.h>
#include <stdio.h>
typedef struct element
{
    int valeur;
    int colonne;
    struct element* ptr_next_element;
}Element,*liste_ligne;

typedef struct matrice_creuse
{
    int nligne;
    int ncolonne;
    liste_ligne *list;
}matrice_creuse;

void remplirMatrice(matrice_creuse *m, int N, int M)
{
    m=(matrice_creuse *)malloc(sizeof(matrice_creuse));
    m->list=(liste_ligne *)malloc(M*sizeof(liste_ligne));
    m->ncolonne=M;
    m->nligne=N;
    for(int i=0;i<N;i++)
    {
        //m->list[]
        liste_ligne temp=m->list[i];
        for(int j=0;j<M;j++)
        {
            int input;
            printf("Please enter %d line %d colonne data",i,j);
            scanf("%d",&input);
            if(input==0)
            {
                temp=NULL;
                continue;
            }
            else if(input!=0)
            {
                temp=(Element *)malloc(sizeof(Element));
                temp->valeur=input;
                temp->colonne=j;
                temp->ptr_next_element=NULL;
            }
        }
    }
}
#endif //NF16_TP3_H
