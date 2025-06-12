#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// logica pra calcular operacoes: letra que vai virar menos a letra atual.

int main(){
    int casos, i = 0, opera = 0;
    scanf("%d", &casos);

    char A[101];
    char B[101];
    while (i < casos)
    {
        scanf(" %s", A);
        scanf(" %s", B);
        for (int j = 0; A[j] != '\0'; j++)
        {
            if (B[j] > A[j])
            {
                opera += (B[j] - A[j]);
                //printf("%d\n", opera);
            }
            if (B[j] < A[j])
            {
                opera += (A[j] - B[j] - 26) * (-1);
            }
        }
        printf("%d\n", opera);
        opera = 0;
        i++;
    }

    return 0;
}