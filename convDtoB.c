#include <stdio.h>
#include <stdlib.h>
int main () {
    float decimal;
    int bin[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //vetor de 16 posições
                                                                    //todas as posições iniciam com 0
    scanf("%f", &decimal); //entrada do número fracionário na base decimal
    if (decimal == 1) printf("1.000000000000000");
    else {
        int cont = 0;
        while (cont <= 15){ //o while só vai 16 vezes
            cont++;
            decimal *= 2;
            if (decimal >= 1){
                bin[cont] = 1;
                decimal -= 1;
                if (decimal == 0) break;
            }
            else bin[cont] = 0;
        }
        printf("0."); //Já printo o "0." aqui já que sempre vai ser assim pra números fracionários
        for (int i = 1; i < 16; i++) {
            printf("%d", bin[i]);
        }
        printf("\n");
    }

return 0;
}