#include <stdio.h>
#include <math.h>

int main() {
    int num_pg = 3, soma_pg =0;

    for (int i=1; i<=7; i++){
        soma_pg += pow(num_pg,i);

        if (i==7) {
            int setimo_termo = pow(3,i); 
            printf("O Sétimo termo da Pg = %d\n",setimo_termo);
        }

    }

    printf("A soma total da PG = %d\n",soma_pg);
}