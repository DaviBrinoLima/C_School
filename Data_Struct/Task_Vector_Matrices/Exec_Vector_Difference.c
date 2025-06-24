#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void) {
    srand(time(NULL));
    int len;
    int i,j,k = 0;
    int aux_1, aux_2;
    int flag =1;


    while (flag) {
        printf("Insira o tamanho desejado para os vetores 1 e 2 [Tamanho Máximo = 50]: ");
        scanf("%d", &len);

        if (len > 50) {
            printf("Tamanho máximo excedido. Insira novamente o tamanho desejado para os vetores 1 e 2 [Tamanho Máximo = 50]: ");
            scanf("%d", &len);  
        }

        else {
            flag = 0;
        }
    }
    
    

    int vetor_1[len], vetor_2[len], vetor_diferenca[len];


    for (int y=0; y<=(len-1); y++) {
        vetor_1[y] = (rand()%50) + 1;
        vetor_2[y] = (rand()%50) + 1;

        for (int z=0; z<y; z++) {
            if ((vetor_1[y] == vetor_1[z]) || (vetor_2[y] == vetor_2[z])) {
                y--;
                break;
            }
        }
    }

        
    for (i=0; i<=(len-1); i++) {
        for (j=0; j<=(len-1); j++) {
            if (vetor_1[i] == vetor_2[j]) {
                break;
            }
        }
            
        if (vetor_1[i] != vetor_2[j]){
            vetor_diferenca[k] = vetor_1[i];
            k += 1;
        }   
    }


    printf("Vetor Diferença = "); 
    
    for (int u = 0; u<=(k-1); u++) {
        printf("%d, ", vetor_diferenca[u]);
    }

    printf("\n");
}
