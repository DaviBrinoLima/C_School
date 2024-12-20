#include <stdio.h>


int main() {
    int vetor[6] = {1,4,6,5,8,2};
    int len_v = 6;

    int np = 0;
    int ni = 0;


    for (int i = 0; i<len_v; i++) {
        if ((vetor[i] % 2) == 0) {
            np += 1;
        } 

        else {
            ni += 1;
        }
    }


    printf("%d %d", np, ni);
    return 0;
}