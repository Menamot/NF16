//
// Created by 陈文龙 on 2022/10/21.
//
#include <stdio.h>
#include "TP3.h"
int main() {
    matrice_creuse m[5];
    int input = 0,k=0,z=0,z2=0,val;//k是为了当前输入的第几个矩阵，z是存储用户输入的矩阵
    int N, M;
    printf("-----------------------------------------\n");
    printf("1. Remplir une matrice creuse\n"
           "2. Afficher une matrice creuse sous forme de tableau\n"
           "3. Afficher une matrice creuse sous forme de listes\n"
           "4. Donner la valeur d’un élément d’une matrice creuse\n"
           "5. Affecter une valeur à un élément d’une matrice creuse\n"
           "6. Additionner deux matrices creuses\n"
           "7. Calculer le gain en espace en utilisant cette représentation pour une matrice donnée\n"
           "8. Quitter\n");
    while (1) {
        printf("-----------------------------------------\n");
        if( k!=0) {
            printf("You now have %d matrix :\n",k);
            for (int i = 0; i < k; ++i) {
                printf("matrix %d: %d * %d\n",i+1,m[i].Ncolonnes,m[i].Nlignes);
            }
        }
        printf("Enter the function you want to choose:\n");
        scanf("%d", &input);
        getchar();
        switch (input) {
            case 1:
                printf("You choose remplirMatrice, enter the number of row and list\n");
                scanf("%d %d", &N,&M);
                if(N==0 || M == 0){ printf("incorrect enter !\n"); break;}
                printf("Enter the values of the matrix\n");
                remplirMatrice(&m[k], N, M);
                printf("Your matrix %d is:\n",k+1);
                afficherMatrice(m[k]);
                k++;
                break;
            case 2:
                if(k==0) {
                    printf("You haven't enter a matrix !\n");
                    break;
                }
                else {
                    printf("You choose afficher matrix with table, enter the matrix you want to matrix\n");
                    scanf("%d", &z);
                    if(z<0 || z>k) { printf("There is no matrix %d\n",z); break;}
                    afficherMatrice(m[z - 1]);
                    break;
                }
            case 3:
                printf("You choose afficher matrix with list, enter the matrix you want to matrix\n");
                scanf("%d", &z);
                if(z<0 || z>k) { printf("There is no matrix %d\n",z); break;}
                afficherMatriceListes(m[z-1]);
                break;
            case 4:
                printf("You choose Donner la valeur, enter the matrix you want to change\n");
                scanf("%d", &z);
                if(z<0 || z>k) { printf("There is no matrix %d\n",z); break;}
                printf("Enter the numbers of row and list\n");
                fflush(stdin);
                scanf("%d %d", &N,&M);
                if (N>m[z-1].Nlignes || M>m[z-1].Ncolonnes){ printf("Your enter incorrect !\n"); break;}
                printf("The number you find is : %d\n", rechercherValeur(m[z-1],N,M));
                break;
            case 5:
                printf("You choose Affecter la valeur, enter the matrix you want to matrix\n");
                scanf("%d", &z);
                if(z<0 || z>k) { printf("There is no matrix %d\n",z); break;}
                printf("Enter the numbers of row and list\n");
                fflush(stdin);
                scanf("%d%d", &N,&M);
                if (N>m[z-1].Nlignes || M>m[z-1].Ncolonnes){ printf("Your enter incorrect !\n"); break;}
                printf("Enter the value you want to give\n");
                scanf("%d", &val);
                affecterValeur(m[z-1],N,M,val);
                printf("matrix %d change:\n",z-1);
                afficherMatrice(m[z-1]);
                break;
            case 6:
                printf("You choose add two matrix, enter the two matrixs you want to add\n");
                scanf("%d%d",&z,&z2);
                additionerMatrices(m[z-1],m[z2-1]);
                printf("Matrix %d change ! Result:\n",z);
                afficherMatrice(m[z-1]);
                break;
            case 7:
                printf("enter the matrix you want to calculate, I print the number of bytes saved\n");
                scanf("%d",&z);
                printf("we saved %d bytes\n",nombreOctetsGagnes(m[z-1]));
                break;
            case 8:
                for(int i=0;i<=k;i++)
                    destroy(&m[z-1]);
                return 0;
        }
        fflush(stdin);
    }
}
