#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void media(float (*mat)[12]){
    float result = 0, quant = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //scanf("%f", &mat[i][j]);
            mat[i][j] = rand()%21;
            if (i > 0 && j < i)
            {
                result += mat[i][j];
                quant++;
            }
        }
    }
    printf("%.1lf\n", result/quant);
}
void soma(float (*mat)[12]){
    float result = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            //scanf("%f", &mat[i][j]);
            mat[i][j] = rand()%21;
            if (i > 0 && j < i)
            {
                result += mat[i][j];
            }
        }
    }
    printf("%.1f\n", result);
}
int main(){
    srand(time(NULL));
    char escolha;
    float mat[12][12];
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