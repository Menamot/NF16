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
        } else{
            for (int j = 0; j < m.Ncolonnes; ++j) {
                if (now_node != NULL){
                    if(now_node->col!=j) { //中间出0
                        printf("0 ");
                    } else {
                        printf("%d ",now_node->val);
    //                    if((now_node->col==(m.Ncolonnes-2) && now_node->suivant == NULL)) { //一行结尾是0
    //                        printf("0 ");
    //                    }
                        now_node=now_node->suivant;
                    }
                } else {
                    printf("0 ");
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


void additionerMatrices(matrice_creuse m1, matrice_creuse m2) { // 用两个now_node分别代表两个矩阵的当前结点，理想情况将两个相同行和列的节点值相加即可
    // 根据矩阵相加规则和矩阵的数据结构可知，我们只需要对1矩阵中有零元素的情况进行讨论，2矩阵中有零元素不用考虑，因为1矩阵中的元素加上0还是原来的元素
    // 实际上，由于只有后驱指针，我们若想要实现1矩阵中第一行为(1, 0, 1)加上2矩阵(1, 1, 1)的情况，我们需要在1矩阵创建新的节点，并让这个节点的后驱指针指向相应的元素，因此我们只能通过对now_node.suivant进行操作
    for (int i = 0; i < m1.Nlignes; ++i) {
        liste_ligne now_node_1, now_node_2;
        now_node_1 = m1.tab_lignes[i];
        now_node_2 = m2.tab_lignes[i];
        // 为了对now_node.suivant进行操作，我们首先需要保证now_node不为空，也就是首先保证1矩阵的每一行的第一个节点不为空，一下三个if情况就是为了处理这种情况
        if(now_node_1!=NULL && now_node_2!=NULL && now_node_1->col>now_node_2->col) { // 对应1矩阵为(0, 1, 1)，2矩阵为（1，1，1）情况
           m1.tab_lignes[i]= creerElement(now_node_2->col,now_node_2->val);
           m1.tab_lignes[i]->suivant=now_node_1;
           now_node_1 = m1.tab_lignes[i];
        } else if(now_node_1 == NULL && now_node_2!=NULL){ // 1矩阵第一行行空，二矩阵当前节点有值，对应应1矩阵为(0, 0, 0)，2矩阵为（1，1，1）情况
            m1.tab_lignes[i]= creerElement(now_node_2->col,now_node_2->val);
            now_node_1 = m1.tab_lignes[i];
        } else if (now_node_1!=NULL && now_node_2!=NULL &&now_node_1->col==now_node_2->col){ //对应普通情况
            now_node_1->val=now_node_1->val+now_node_2->val;
        }
        // 下面对now_node.suivant进行操作，根据两个矩阵的now_node.suivant是否为空，一共有四种大情况
        for (int j = 0; j < m1.Ncolonnes; ++j) {
            if(now_node_1!=NULL && now_node_2!=NULL){ //防止两个矩阵的某一行都全为空的情况
                if(now_node_1->suivant!=NULL){
                    if(now_node_2->suivant!=NULL){
                        if(now_node_1->suivant->col==now_node_2->suivant->col){ // 最普通的两个结点的行列相同情况
                            now_node_1->suivant->val=now_node_1->suivant->val+now_node_2->suivant->val;
                            now_node_1=now_node_1->suivant;
                            now_node_2=now_node_2->suivant;
                        } else if(now_node_1->suivant->col>now_node_2->suivant->col){ // 1矩阵的now_node.suivant的col大于2矩阵的，意味着1矩阵中当前节点和下一节点存在空值，所以需要在该空值处填充2矩阵的的当前节点
                            liste_ligne temp=now_node_1->suivant;
                            now_node_1->suivant= creerElement(now_node_2->suivant->col,now_node_2->suivant->val);
                            now_node_1->suivant->suivant=temp;
                            now_node_1=now_node_1->suivant;
                            now_node_2=now_node_2->suivant;
                        } else if(now_node_1->suivant->col<now_node_2->suivant->col){ // 1矩阵的now_node.suivant的col小于2矩阵的，那么不用管，只让当前节点跳下一个
                            now_node_1=now_node_1->suivant;
                        }
                    } else if(now_node_2->suivant==NULL){ // 2矩阵的now_node.suivant为空，意味着到了行的末尾，或者行的后面都是0，这种情况直接break跳出这一行的循环，进行下一行
                        break;
                    }
                } else if(now_node_1->suivant==NULL){
                    if(now_node_2->suivant!=NULL){ //对应(1, 0, 0)加(1, 1, 1)情况
                        now_node_1->suivant= creerElement(now_node_2->suivant->col,now_node_2->suivant->val);
                        now_node_1=now_node_1->suivant;
                        now_node_2=now_node_2->suivant;
                    } else if(now_node_2->suivant==NULL){
                        break;
                    }
                }
            }
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
