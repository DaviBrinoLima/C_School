#include <stdio.h>


int main() {
    int a = 8;
    int v[4] = {6,2,8,1};

    int len_v = 4;
    int indice = 0;

    
    for (int i = 0; i<len_v; i++) {
        if (v[i] == a) {
            printf("%d\n", indice);
        }

        indice += 1;
    }


    return 0;
}