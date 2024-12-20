#include <stdio.h>


int main() {
    int v[5] = {4,1,5,8,6};
    int len_v = 5;


    int maior = v[0]; 
    int menor = v[0];


    for (int i = 0; i<len_v; i += 1) {
        if (v[i] < menor) {
            menor = v[i];
        }

        if (v[i] > maior) {
            maior = v[i];
        }
    }


    printf("Menor: %d \nMaior: %d \n", menor,maior);
    return 0;
}