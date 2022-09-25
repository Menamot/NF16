#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14

//int main() {
//    int rayon=10; float surface;
//    surface = pow(rayon, 2) * PI;
//    printf("surface = %.2f", surface);
//    return 0;
//}

//int main() {
//    int x,y;
//    printf("enter x\n");
//    scanf("%d %d",&x,&y);
//    printf("x=%d,y=%d",x,y);
//}
//
//int main() {
//    char ch='7';
//    printf("%c\n",ch);
//    ch = 98;
//    printf("%c\n",ch);
//}


// E2
//int main() {
//    char enter;
//    printf("entrez un caractère\n");
//    scanf("%c", &enter);
//    printf("signe:%c\n code asccii décimal:%o\n code ascciihexadécimal:%x\n",enter,enter,enter);
//}

// E3
//int main(){
//    char enter;
//    printf("entrez un nombre entier\n");
//    scanf("%c", &enter);
//    if ('a' <= enter && enter <= 'z' || 'A' <= enter && enter <= 'Z') {
//        printf("1you entrez un nombre entier <10 & >0\n");
//    }
//    else {
//        printf("2you entrez un nombre entier >10 & <0\n");
//    }
//}

//int main() {
//    switch (getchar()) {
//        case 'o' :
//            printf("c’est un bon caractère");
//            break;
//        case 'O' :
//            printf("c’est un bon caractère");
//            break;
//        case 'n' :
//            printf("c’est un bon caractère");
//            break;
//        case 'N' :
//            printf("1c’est un bon caractère");
//            exit(0);
//        case '0' :
//            printf("c’est un bon caractère");
//            break;
//        default:
//            printf("21c’est un mauvais caractère");
//    }
//}

//int main() {
//    int annee;
//    scanf("%d",&annee);
//    if (2022-annee >130 || 2022-annee<50){
//        printf("age saisi invalide");
//        exit(0);
//    }
//    if (2022-annee < 50){
//        printf("Pour l’instant ?a va");
//    }
//    else {
//        printf("Vous êtes sur la mauvaise pente");
//    }
//}

//int main() {
//    int enter;
//    scanf("%d", &enter);
//    if (enter%2==0){
//        printf("pair");
//    }
//    else{
//        printf("impair");
//    }
//}


// E4
//int main() {
//    char a='a',A='A';
//    printf("%d",a-A);
//}

//int main(){
//    char enter;
//    scanf("%c",&enter);
//    if ('a'<= enter && enter <='z'){
//        enter -= 32;
//        printf("%c",enter);
//    }
//    else{
//        printf("%c",enter);
//    }
//}

//int main(){
//    float enter=30.21321312;
//    printf("%05.1f",enter);
//}


// E5
//int main(){
//    int i =0;
//    for (i = 0; i < 10; ++i) {
//        printf("%d ",i);
//    }
//    i = 0;
//    do {
//        printf("%d",i);
//        i++;
//    } while (i<10);
//}

//int main() {
//    char enter; int i=0;
//    while(1){
//        scanf("%c",&enter);
//        getchar(); //由于系统会将回车键也当成输入\n，需要使用getchar()来进行隔断
//        switch (enter) {
//            case 'o' :
//                printf("c’est un bon caractère\n");
//                break;
//            case 'O' :
//                printf("c’est un bon caractère\n");
//                break;
//            case 'n' :
//                printf("c’est un bon caractère\n");
//                break;
//            case 'N' :
//                printf("c’est un bon caractère\n");
//                exit(0);
//            case '0' :
//                printf("c’est un bon caractère\n");
//                break;
//            default:
//                printf("c’est un mauvais caractère%d\n",i);
//        }
//        i++;
//    }
//}


// TP
//int main (){
//    float a,b;
//    scanf("%f %f",&a,&b);
//    a = a + b;
//    printf("%f",a);
//}

//int main(){
//    int i;
//    while (1) {
//        scanf("%d",&i);
//        getchar();
//        if (i<=0) {exit(0);}
//    }
//}

//int main(){
//    char i;
//    while (1){
//        printf("quelle table");
//        scanf("%c",&i);
//        getchar();
//        if (i=='0') exit(0);
//        if (i<'1'|| i>'9') printf("not right");
//        i = i-'0';
//        for (int j = i; j <= 9; ++j) {
//            printf("%d*%d ",i,j);
//        }
//    }
//}

//int main(){
//    int a[10];
//    for (int j = 0; j < 10; ++j) {
//        a[j]=0;
//        printf("%d ",a[j]);
//    }
//}

//int main(){
//    int a[3][4],z=12;
//    for (int i = 0; i <=2 ; ++i) {
//        for (int j = 0; j <=3 ; ++j) {
//            a[i][j]=z;
//            printf("%d ",a[i][j]);
//            z++;
//        }
//        printf("\n");
//    }
//}

//void echanger(int* a, int* b){
//    int temp;
//    temp = *a;
//    *a = *b;
//    *b = temp;
//}
//int main(){
//    int a=1,b=2;
//    echanger(&a,&b);
//    printf("%d %d",a,b);
//}

//int main(){
//    int i; int* j=&i;
//    *j++;
//    printf("%d %x",i,j);
//    j++;
//    printf("%d %x",i,j);
//}

//int main(){
//    int a[3][4],z=12;
//    int (*b)[4]=a;
//    for (int i = 0; i <=2 ; ++i) {
//        for (int j = 0; j <=3 ; ++j) {
//            *(*(b+i)+j)=z; //等于*(a[i]+j)
//            printf("%d ",a[i][j]);
//            z++;
//        }
//        printf("\n");
//    }
//}

//int main(){
//    int Nb=3;
//    int list[Nb];
//    for (int i = 0; i < Nb; ++i) {
//        scanf("%d",&list[i]);
//    }
//}