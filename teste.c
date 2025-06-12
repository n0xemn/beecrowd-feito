#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char te[10];
    scanf(" %s", te);
    if (strcmp(te, "ar") == 0)
    {
        printf("deu certo");
    }
    else
    {
        printf("n deu certo");
    }
    return 0; 
}