#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void sent_danc(char* str);

int main(){
    char str[51];
    while (fgets(str, 51, stdin))
    {
        str[strcspn(str, "\n")] = '\0';
        sent_danc(str);
        printf("%s", str);
    }
    printf("\n");
    return 0;
}

void sent_danc(char* str){
    int j = strlen(str), aux = 0; // essa funca eh da biblioteca string e serve pra retornar o numero de elementos da string

    for (int i = 0; i < j; i++, aux ++)
    {
        if (str[i] == ' ')
        {
            aux++;
        }
        else if (str[i] != ' ')
        {
            if (str[i] >= 97 && aux%2 == 0)
            {
                str[i] = toupper(str[i]);
            }
            else if (str[i] <= 96 && aux%2 ==1)
            {
                str[i] = tolower(str[i]);
            }
        }
    }
    str[j] = '\0';
}