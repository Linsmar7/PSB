#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//CONVERSÃO DOS DECIMAIS
void convDtoB (int n) { //conversor de decimal para binario
    int vetorDtoB[50];
    int i = 0;
    while (n > 0){
        vetorDtoB[i] = n%2;
        n = n/2;
        i++;
    }
    for (int j = i-1; j >=0; j--) {
        printf("%d", vetorDtoB[j]);
    }
    printf("\n");
}

void convDtoO (int n){ //conversor de decimal para octal
    int vetorDtoO[50];
    int i = 0;
    while (n > 0){
        vetorDtoO[i] = n%8;
        n = n/8;
        i++;
    }
    for (int j = i-1; j >=0; j--) {
        printf("%d", vetorDtoO[j]);
    }
    printf("\n");
}

void convDtoH (int n){ //conversor de decimal para hexadecimal
    char vetorDtoH[50];
    int i = 0;
    int aux = 0;
    while (n > 0){
        aux = n%16;
        switch (aux){  //meu deus que switch grande
        case 1:
            vetorDtoH[i] = '1';
            break;
        case 2:
            vetorDtoH[i] = '2';
            break;
        case 3:
            vetorDtoH[i] = '3';
            break;
        case 4:
            vetorDtoH[i] = '4';
            break;
        case 5:
            vetorDtoH[i] = '5';
            break;
        case 6:
            vetorDtoH[i] = '6';
            break;
        case 7:
            vetorDtoH[i] = '7';
            break;
        case 8:
            vetorDtoH[i] = '8';
            break;
        case 9:
            vetorDtoH[i] = '9';
            break;
        case 10:
            vetorDtoH[i] = 'A';
            break;
        case 11:
            vetorDtoH[i] = 'B';
            break;
        case 12:
            vetorDtoH[i] = 'C';
            break;
        case 13:
            vetorDtoH[i] = 'D';
            break;
        case 14:
            vetorDtoH[i] = 'E';
            break;
        case 15:
            vetorDtoH[i] = 'F';
            break;
        }
        n = n/16;
        i++;
    }
    for (int j = i-1; j >=0; j--) {
        printf("%c", vetorDtoH[j]);
    }
    printf("\n");
}

//CONVERSORES DOS BINÁRIOS
int convBtoD (long long int n){ //conversor de binario para decimal
    long long int binario = n;
    int decimal = 0;
    for (int i = 0; binario > 0; i++) {
        decimal += (pow(2, i)) * (binario%10);
        binario = binario/10;
    }
    return decimal;
}

void convBtoO (long long int n){ //conversor de binario para octal
    long long int binario = n;
    int decimal = convBtoD(binario); //transformo o número binario em decimal
    convDtoO(decimal); //transformo o decimal em octal
}

void convBtoH (long long int n){ //conversor de binario para hexadecimal
    long long int binario = n;
    int decimal = convBtoD(binario); //transformo o número binario em decimal
    convDtoH(decimal); //transformo o decimal em hexadecimal
}

//CONVERSORES DOS OCTAIS
int convOtoD (int n){ //conversor de octal para decimal
    long long int octal = n;
    int decimal = 0;
    for (int i = 0; octal > 0; i++) {
        decimal += (pow(8, i)) * (octal%10);
        octal = octal/10;
    }
    return decimal;
}

void convOtoB (int n){ //conversor de octal para binario
    int octal = n;
    int decimal = convOtoD(octal);
    convDtoB(decimal);
}

void convOtoH (int n){ //conversor de octal para hexadecimal
    int octal = n;
    int decimal = convOtoD(octal);
    convDtoH(decimal);
}

//CONVERSORES DOS HEXADECIMAIS
void convHtoB (int n){ //conversor de hexadecimal para binario
    convDtoB(n);
}

void convHtoO (int n){ //conversor de hexadecimal para octal
    convDtoO(n);
}


int main() {
    int select;
    long long int numero;
    int aux;
    scanf("%d", &select);
    switch (select){
        case 0:
            scanf("%d", &numero);
            convBtoO(numero);

            aux = convBtoD(numero);
            printf("%d\n", aux);

            convBtoH(numero);
            break;
        case 1:
            scanf("%d", &numero);
            convOtoB(numero);

            aux = convOtoD(numero);
            printf("%d\n", aux);

            convOtoH(numero);
            break;
        case 2:
            scanf("%d", &numero);
            convDtoB(numero);
            convDtoO(numero);
            convDtoH(numero);
            break;
        case 3:
            scanf("%X", &numero); //pega numero em hexa e transforma em decimal
            convHtoB(numero);
            convHtoO(numero);
            printf("%d", numero);
            break;
    }
    return 0;
}