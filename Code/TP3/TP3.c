//
// Created by 陈文龙 on 2022/10/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP3.h"
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
            scanf("%d",&input);
            if(input==0)
            {
                *temp=NULL;
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


void afficherMatrice(matrice_creuse m){ //复杂度O(N*M)
    for (int i = 0; i < m.Nlignes; ++i) {
        liste_ligne now_node;
        now_node = m.tab_lignes[i];
        if (now_node == NULL) { //一行全为0
            for (int j = 0; j < m.Ncolonnes; ++j) {
                printf("0 ");
            }
        }
        for (int j = 0; j < m.Ncolonnes; ++j) {
            if (now_node != NULL){
                if(now_node->col!=j) { //中间出0
                    printf("0 ");
                }
                else {
                    printf("%d ",now_node->val);
                    if((now_node->col==(m.Ncolonnes-2) && now_node->suivant == NULL)) { //一行结尾是0
                        printf("0 ");
                    }
                    now_node=now_node->suivant;
                }
            }

        }
        printf("\n");
    }
}

void afficherMatriceListes(matrice_creuse m) { //复杂度O(N*M)
    for (int i = 0; i < m.Nlignes; ++i) {
        liste_ligne now_node;
        now_node = m.tab_lignes[i];
        for (int j = 0; j < m.Ncolonnes; ++j) {
            if (now_node != NULL){
                    printf("%d/%d ",now_node->val,now_node->col+1); //前者代表值，后者为indice
                    now_node=now_node->suivant;
            }
        }
        printf("\n");
    }
}


int rechercherValeur(matrice_creuse m, int i, int j) { //复杂度O(j)
    liste_ligne now_node;
    now_node = m.tab_lignes[i-1];
    while (1) {
        if (now_node->col==(j-1)) {return now_node->val;}
        if (now_node->col>(j-1) || (now_node->col== (j-2) && now_node->suivant== NULL)) {return 0;}
        now_node = now_node->suivant;
    }
}


void affecterValeur(matrice_creuse m, int i, int j, int val) { //复杂度O(j)
    liste_ligne now_node;
    now_node = m.tab_lignes[i-1];
    for(int k=0;k<j;k++) {
        if (now_node== NULL && k==0) { //一行全为0
            m.tab_lignes[i-1] = creerElement(j-1,val);
            break;
        }
        if (now_node->col==(j-1)) {
            now_node->val=val;
            break;
        }
        if (now_node->suivant== NULL && now_node->col==(j-2)) { //一行结尾为0
            now_node->suivant = creerElement(j-1,val);
            break;
        }
        if(val==0 && rechercherValeur(m,i,j)!=0 &&now_node->col==(j-2)) {
            if(now_node->suivant->suivant!=NULL){now_node->suivant==now_node->suivant->suivant;}
            else{now_node->suivant=NULL;}
            break;
        }
        if (now_node != NULL) {now_node = now_node->suivant;}
    }
}


void additionerMatrices(matrice_creuse m1, matrice_creuse m2) {
    for (int i = 0; i < m1.Nlignes; ++i) {
        liste_ligne now_node_1, now_node_2;
        now_node_1 = m1.tab_lignes[i];
        now_node_2 = m2.tab_lignes[i];
        for (int j = 0; j < m1.Ncolonnes; ++j) {
            if(now_node_1!=NULL && now_node_2!=NULL) { // 普通都有值情况
                now_node_1->val = now_node_1->val + now_node_2->val;
            }
            if(now_node_1 == NULL && now_node_2!=NULL){ // 1矩阵一行空，二矩阵当前节点有值
                now_node_1= creerElement(now_node_2->col,now_node_2->val);
            }
            now_node_1=now_node_1->suivant;
            now_node_2=now_node_2->suivant;
        }
    }

}


int nombreOctetsGagnes(matrice_creuse m) {
    //这个函数在计算3x3矩阵时有问题，全0矩阵和有一个元素的矩阵节省空间数居然相同
    /*Ecrire ici le code de cette fonction*/
    //Calculer l'espace occupe par une matrice creuse
    int resul=0;
    int i=0;
    for(liste_ligne temp1=m.tab_lignes[i];i<m.Nlignes;i++)
    {
        int NomDeEle=0;
        for(liste_ligne temp2=temp1;temp2!=NULL;temp2=temp2->suivant)
            NomDeEle++;
        resul+=(int)(NomDeEle*sizeof(element));
    }
    resul=m.Nlignes*m.Ncolonnes*sizeof(int)-resul-sizeof(m.tab_lignes);
    return resul;
}
void destroy(matrice_creuse *m)
{
    for(int i=0;i<m->Nlignes;i++)
    {
        liste_ligne temphead=(m->tab_lignes[i]);
        liste_ligne temp=NULL;
        for(liste_ligne temp2=temphead;temp2!=NULL;temp2=temp)
        {
            temp=temp2->suivant;
            free(temp2);
        }

        m->tab_lignes[i]=NULL;
    }
    free(m->tab_lignes);
    m->Nlignes=0;
    m->Ncolonnes=0;
}
