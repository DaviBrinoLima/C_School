#include <stdio.h>


int main() {
    int v[6] = {11,22,33,44,55,66};
    int len_v = 6;


    int r[6] = {};
    int aux = 5;


    for (int i=0; i<len_v; i++) {
        r[i] = v[aux];
        aux -= 1;

        printf("%d ", r[i]);
    }


    return 0;
}