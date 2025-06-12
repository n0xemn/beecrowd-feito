#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void media(float(*mat)[12]){
    double result = 0.0;
    double quant = 0.0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //scanf("%lf", &mat[i][j]);
            mat[i][j] = rand()%21;
            if (j > i && j < 11 -i)
            {
                result += mat[i][j];
                quant++;
            }
        }
    }
    printf("%.1lf\n", (result)/(quant));
}
void soma(float(*mat)[12]){
    double result = 0.0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //scanf("%lf", &mat[i][j]);
            mat[i][j] = rand()%21;
            if (j > i && j < 11 - i)
            {
                result += mat[i][j];
            }
        }
    }
    printf("%.1lf\n", result);
}
int main(){
    srand(time(NULL));
    char escolha;
    double mat[12][12];
    scanf("%c", &escolha);
    switch (escolha)
    {
    case 'S':
        soma(mat);
        break;

    case 'M':
        media(mat);
        break;
    
    default:
        break;
    }

    return 0;
}