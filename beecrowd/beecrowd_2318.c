#include <stdio.h>
#include <stdlib.h>
// quadrado 3x3 onde a soma de uma linha e igual a soma de uma coluna e diagonal

void soma_mat(int* quadrado[3], int linha, int* zero, int* soma);
void subs(int* quadrado[3]);

int main(){
    int quadrado[3][3], aux = 1, soma = 0, fixo, linha = 0 , zero = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &quadrado[i][j]);
            //printf("%d ", quadrado[i][j]);
        } 
        //printf("\n");
    }

    while (zero)
    {
        soma_mat(quadrado, linha, &zero, &soma);
        if (linha < 3)
        {
            /* code */
        }
        
        linha++;
    }
    fixo = soma;

    return 0;
}

void subs(int* quadrado[3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; 3++)
        {
            
        }
        
    }
    
}

void soma_mat(int* quadrado[3], int linha, int* zero, int* soma){
    int aux = 1;
    for (int i = 0; i < 3; i++)
    {
        *soma += quadrado[linha][i];
        aux = quadrado[linha][i];
        if (aux == 0)
        {
            *soma = 0;
            *zero = 1;
            return;
        }
        else
        {
            *zero = 0;
        }

    }
}