#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char escolha;
    scanf("%c", &escolha);
    double valor = 0.0;
    double soma = 0.0;
    double quant = 0.0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //scanf("%lf", &valor);
            valor = rand()%21;
            if (j < i && j < 11 - i)
            {
                soma += valor;
                quant++;
            }
            valor = 0;
        }
    }
    if (escolha == 'S')
    {
        printf("%.1lf\n", soma);
    }
    else
    {
        printf("%.1lf\n", soma/quant);
    }
    
    return 0;
}