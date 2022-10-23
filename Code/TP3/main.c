//
// Created by 陈文龙 on 2022/10/21.
//
#include <stdio.h>
#include "TP3.c"
int main() {
    matrice_creuse m[5];
    int input = 0,k=0,z=0,val;
    int N, M;
    while (1) {
        printf("enter function:\n");
        scanf("%d", &input);
        getchar();
        switch (input) {
            case 1:
                printf("you chosse remplirMatrice, enter the nomber of row\n");
                scanf("%d", &N);
                printf("you chosse remplirMatrice, enter the nomber of lignes\n");
                scanf("%d", &M);
                printf("you chosse remplirMatrice, enter the martrix\n");
                remplirMatrice(&m[k], N, M);
                printf("your enter matrix is:\n");
                afficherMatrice(m[k]);
                k++;
                break;
            case 2:
                printf("you chosse afficher matrix with table, enter the matrix you want to matrix\n");
                scanf("%d", &z);
                afficherMatrice(m[z-1]);
                break;
            case 3:
                printf("you chosse afficher matrix with list, enter the matrix you want to matrix\n");
                scanf("%d", &z);
                afficherMatriceListes(m[z-1]);
                break;
            case 4:
                printf("you chosse Donner la valeur, enter the matrix you want to matrix\n");
                scanf("%d", &z);
                printf("you chosse Donner la valeur, enter i and j\n");
                fflush(stdin);
                scanf("%d%d", &N,&M);
                printf("the number you find is : %d\n",rechercherValeur(m[z-1],N,M));
                break;
            case 5:
                printf("you chosse Affecter la valeur, enter the matrix you want to matrix\n");
                scanf("%d", &z);
                printf("you chosse Affecter la valeur, enter i and j\n");
                fflush(stdin);
                scanf("%d%d", &N,&M);
                printf("you chosse Affecter la valeur, enter the val\n");
                scanf("%d", &val);
                affecterValeur(m[z-1],N,M,val);
                printf("martrix change:\n");
                afficherMatrice(m[z-1]);
                break;
            case 8:
                return 0;
        }
        fflush(stdin);
    }
}
