#include <stdio.h>


int main() {
    int vetor[6] = {5,4,6,3,2,1};
    int len_v = 6;


    for (int i = 0; i < len_v; i++) {
        vetor[i] += 1;
        printf("%d ", vetor[i]);
    }


    return 0;
}