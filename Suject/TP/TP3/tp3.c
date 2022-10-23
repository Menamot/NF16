#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


// Fonction qui permet de créer un élement d'une liste chaînée
// Params : indice de colonne (int), valeur de l'élement (int)
// Return : pointeur vers le nouvele élement créé
element *creerElement(int colonne, int valeur) {
    element *nouvelElement = malloc(sizeof(element));
    nouvelElement->col = colonne;
    nouvelElement->val = valeur;
    nouvelElement->suivant = NULL;
    return nouvelElement;
}


void remplirMatrice(matrice_creuse *m, int N, int M) {

  /*Ecrire ici le code de cette fonction*/

}


void afficherMatrice(matrice_creuse m){

  /*Ecrire ici le code de cette fonction*/

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

