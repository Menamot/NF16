//
// Created by 陈文龙 on 2022/10/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"
element *creerElement(int colonne, int valeur) {
    element *nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne;
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}


void remplirMatrice(matrice_creuse *m, int N, int M) {
    //使用此函数时必须传入的是一个实例对象的地址，不能是指针本身！！
    m->tab_lignes=(liste_ligne *)malloc(M*sizeof(liste_ligne));
    m->Ncolonnes=M;
    m->Nlignes=N;
    for(int i=0;i<N;i++)
    {
        //m->list[]
        liste_ligne* temp=&(m->tab_lignes[i]);
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
                *temp=(element *)malloc(sizeof(element));
                (*temp)->val=input;
                (*temp)->col=j;
                temp=&(*temp)->suivant;
                (*temp)=NULL;
            }
        }
    }

}


void afficherMatrice(matrice_creuse m){

    for (int i = 0; i < m.Nlignes; ++i) {
        liste_ligne now_node;
        now_node = m.tab_lignes[i];
        for (int j = 0; j < m.Ncolonnes; ++j) {
            if (now_node != NULL){
                printf("%d",now_node->val);
                now_node=now_node->suivant;
            }
        }
    }

}

void afficherMatriceListes(matrice_creuse m) {

    /*Ecrire ici le code de cette fonction*/

}


int rechercherValeur(matrice_creuse m, int i, int j) {

    /*Ecrire ici le code de cette fonction*/

}


void affecterValeur(matrice_creuse m, int i, int j, int val) {

    /*Ecrire ici le code de cette fonction*/

}


void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {

    /*Ecrire ici le code de cette fonction*/

}


int nombreOctetsGagnes(matrice_creuse m) {

    /*Ecrire ici le code de cette fonction*/

}
