#include <stdio.h>


int main()  {
    int vetor[4] = {4,2,7,5};
    int len_v = 4;


    for (int i=0; i<len_v; i++) {
        if (vetor[i] == 5) {
            printf("o valor 5 está presente");
        }
    }


    return 0;
}