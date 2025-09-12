#include <stdio.h>

int main(void) {
    int num_primos[20] = {2,3,5,7};
    int i,u,j;


    for (i=4; i<=19; i++) {
        for (j= (num_primos[i-1]+1); j<=300; j++){
           if ((j%2 !=0) && (j%3 != 0) && (j%5 != 0) && (j%7 !=0)) {
            break;
           } 
        }
        num_primos[i] = j;
    }


   for (u=0; u<=19; u++) {
        printf("%d, ", num_primos[u]);
   }

   printf("\n");
}