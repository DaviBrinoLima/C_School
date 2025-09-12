#include <stdio.h>

int main() {
    int soma = 0;

    for (int i = 1; i <= 10; i+=1){
        printf("%d ", i);

        if (i % 2 == 0) {
            soma += i;
        }
    }

    printf("\n O resultado é = %d", soma);
}