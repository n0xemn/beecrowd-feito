#include <stdio.h>
#include <stdlib.h>

void notas(int n){
    int cem = 0, cinq = 0, vinte = 0, dez = 0, cinc = 0, dois = 0, um = 0;
    while (n > 0)
    {
        if (n >= 100)
        {
            cem++;
            n -= 100;
            continue;
        }
        if (n < 100 && n >= 50)
        {
            cinq++;
            n -= 50;
            continue;
        }
        if (n < 50 && n >= 20)
        {
            vinte++;
            n -= 20;
            continue;
        }
        if (n < 20 && n >= 10)
        {
            dez++;
            n -= 10;
            continue;
        }
        if (n < 10 && n >= 5)
        {
            cinc++;
            n -= 5;
            continue;
        }
        if (n < 5 && n >= 2)
        {
            dois++;
            n -= 2;
            continue;
        }
        else
        {
            um++;
            break;
        }
    }
    printf("\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", cem, cinq, vinte, dez, cinc, dois, um);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", n);
    notas(n);

    return 0;
}