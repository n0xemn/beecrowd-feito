#include <stdio.h>
#include <stdlib.h>

int main(){
    float n;
    int aux = 0;
    for (int i = 1; i <= 6; i++)
    {
        scanf("%f", &n);
        if (n > 0)
        {
            aux++;
        }
    }
    printf("%d valores positivos\n", aux);

    return 0;
}