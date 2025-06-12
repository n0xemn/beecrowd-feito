#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int main(){
    //srand(time(NULL));
    int vet[100];
    int maior = -1, posic;
    for (int i = 0; i < 100; i++)
    {
        scanf("%d", &vet[i]);
        //vet[i] = rand();
        if (vet[i] > maior)
        {
            maior = vet[i];
            posic = i + 1;
        }
    }
    printf("%d\n%d\n", maior, posic);

    return 0;
}