#include <stdio.h>


int main() {
    int v[8] = {9,6,2,4,8,5,1,3};
    int len_v = 8;


    if ((len_v % 2) == 0) {
        for (int i = 0; i <len_v; i += 2) {
            printf("%d %d\n", v[i], v[i+1]);
        }
    }


    return 0;
}