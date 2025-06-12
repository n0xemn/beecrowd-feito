#include <stdio.h>
#include <stdlib.h>

void intervalo(double n){
    if (n < 0 || n > 100)
    {
        printf("Fora de intervalo\n");
        return;
    }
    if (n >= 0 && n <= 25)
    {
        printf("Intervalo [0,25]\n");
        return;
    }
    if (n > 25 && n <= 50)
    {
        printf("Intervalo (25,50]\n");
        return;
    }
    if (n > 50 && n <= 75)
    {
        printf("Intervalo (50,75]\n");
        return;
    }
    if (n > 75 && n <= 100)
    {
        printf("Intervalo (75,100]\n");
        return;
    }
}
int main(){
    double n;
    scanf("%lf", &n);
    intervalo(n);

    return 0;
}