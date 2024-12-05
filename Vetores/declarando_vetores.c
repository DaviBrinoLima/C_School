#include <stdio.h>


int main () 
{
    float u[10] = {1,2,3,4,5,6,7,8,9,10};
    int len_u = 10;


    for (int i = 0; i < len_u; i += 1) 
    {
    printf("%f \n", u[i]);
    }


    return 0;
}