#include <stdio.h>


int main () {
    int a = 0; 
    int b = 0;
    int c = 0;


    printf("Insira um valor para a: \n");
    scanf("%d", &a);

    printf("Insira um valor para b: \n");
    scanf("%d", &b);

    printf("Insira um valor para c: \n");
    scanf("%d", &c);


    if (a==b && b==c) {
        printf("Os números têm que ser distintos");
    }

    else {
        if (a < b && b < c) {
            printf("%d %d %d", a, b, c);
        }

        else if (a<c && c<b) {
            printf("%d %d %d", a, c, b);
        }

        else if (b <a && a<c) {
            printf("%d %d %d", b, a, c);
        }

        else if (b<c && c<a) {
            printf("%d %d %d", b, c, a);
        }

        else if (c<a && a<b) {
            printf("%d %d %d", c, a, b);
        }

        else {
            printf("%d %d %d", c, b, a);
        }
    }


    return 0;
}