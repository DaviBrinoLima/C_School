#include <stdio.h>


int main() {
    int v[5] = {1,2,3,4,5};
    int v_reverse[5] = {};

    int len_v = 5;
    int aux = 4;


    for (int i = 0; i <len_v; i++) {
        v_reverse[i] = v[aux]; 
        aux = aux - 1;

        printf("%d\n", v_reverse[i]);
    }
}