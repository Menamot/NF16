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

// TD3
//int factorielle (int n){
//    int res;
//    if (n == 0) return res=1;
//    else {
//        res = n*factorielle(n-1);
//        return res;
//    }
//}

// E6.1-6.2
//int main (){
//    int i=5; int* j=&i;
//    printf("%x,%d\n",&i,i);
//    printf("%x,,%x,%d",&j,j,*j);
//    i++;
//}

// E7.1
//int main(){
//    int a[10];
//    for (int i = 0; i < 10; ++i) {
//        a[i]=7;
//    }
//}

// E7.2
//int main(){
//    int a[5]={4,3,2,1,0};
//}

// E7.3
//int main(){
//    int i=0;
//    char chaine[]="bonjour";
//    while (chaine[i]!='\0'){
//        printf("%c",chaine[i]);
//        i++;
//    }
//}

// E7.4
//int main(){
//    int a=0,b=0;
//    char chaine[10]={0};
//    scanf("%s",chaine);
//    for (int i = 0; i < 10; ++i) {
//        if (chaine[i]=='o'&& a<1) {
//            chaine[i] = 'a';
//            a++;
//        }
//        else if (chaine[i]=='n'&& b<1){
//            chaine[i] = 'd';
//            b++;
//        }
//    }
//    printf("%s",chaine);
//}

// E7.5-E7.6
//int main(){
//    int NMAX=5,sum=0,i=0,res=0;
//    int a[NMAX];
//    while (i<NMAX && a[i]!='\n') {
//        scanf("%d",&a[i]);
////        a[i] = getchar();
//        sum = sum + a[i];
//        i++;
//    }
//    res = sum/NMAX;
//    i=0;
//    while (i<NMAX && a[i]>=res) {
//        printf("%d",a[i]);
//        i++;
//    }
//    printf("%d",sum);
//}

// E7.7
//int main(){
//    int a[3][4]={12,13,14,15,16,17,18,19,20,21,22,23};
//}

// E8.1
//void swap(int* a, int* b){
//    int temp;
//    temp=*a;
//    *a=*b;
//    *b=temp;
//}
//int main(){
//    int a=2,b=10;
//    swap(&a,&b);
//    printf("%d,%d",a,b);
//}

// E8.2
//int my_isascii(char c){
//    if (c<=127 && c>=0) return 1;
//    else return 0;
//}
//int main(){
//    char c='[';
//    int a;
//    a = my_isascii(c);
//    printf("%c\n",c);
//    printf("%d",a);
//}

// E8.3
//int my_strlen(char c[]){
//    int i=0;
//    while(c[i]!='\0'){
//        i++;
//    }
//    return i;
//}
//int main(){
//    char c[]="chansksa";
//    int a;
//    a = my_strlen(c);
//    printf("%d",a);
//}

// E8.4
//int function(int n){
//    int MAX=10;
//    int a[MAX];
//    for (int i = 0; i < n; ++i) {
//        scanf("%d",&a[i]);
//    }
//    return n;
//}
//int main(){
//    int n;
//    scanf("%d",&n);
//    fflush(stdin);
//    int a= function(n);
//    printf("%d",a);
//}

// E8.5
//int min(int a[],int n){
//    int i=0,min=a[i];
//    while(i<n && a[i]<=min) {
//        min = a[i];
//        i++;
//    }
//    return min;
//}
//int main(){
//    int a[5]={5,4,3,2,2};
//    printf("%d", min(a,5));
//}

// E8.8
int main(int argc, char * argv[]){
    while(--argc>0) {
        printf("%s",*++argv);
        printf("\n");
    }
    printf("sadasda");
}

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

