#include <stdio.h>

int main(void) {
    int num_primos[1500000] = {2,3,5,7};
    int u,j, i=4;


    int n;
    printf("Insira o valor limite do intervalo analisado: ");
    scanf("%d", &n);


    for (j =8; j<=n; j++){
        if ((j%2 !=0) && (j%3 != 0) && (j%5 != 0) && (j%7 !=0)) {
        num_primos[i] = j;
        i++;
           } 
    }


    for (u=0; u<=i-1; u++) {
        printf("%d, ", num_primos[u]);
   }

   printf("\n");
}