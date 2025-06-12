#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Item;

typedef struct lista_enc lista_enc;
typedef struct celula celula;

int busca_por_valor(lista_enc* L_enc, Item it);
Item busca_por_posicao(lista_enc* L_enc, int posi);
bool esvaziar(lista_enc* L_enc);
void exibir(lista_enc* L_enc);
lista_enc* iniciar();
bool inserir_fim(lista_enc* L_enc, Item it);
bool inserir_inicio(lista_enc* L_enc, Item it);
bool inserir_meio(lista_enc* L_enc, Item it, int posicao);
lista_enc* liberar(lista_enc* L_enc);
void ordenar(lista_enc* L_enc);
bool remover_comeco(lista_enc* L_enc);
bool remover_meio(lista_enc* L_enc, int posicao);
bool remover_fim(lista_enc* L_enc);
int tamanho(lista_enc* L_enc);
bool vazia(lista_enc* L_enc);

int main(){
    int N, iguais = 0, indice = 0, brindes = 0;
    char letraux;
    lista_enc* letras = iniciar();
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        indice += 4;
        for (int j = 0; j < 4; j++)
        {
            if (tamanho(letras) == 0)
            {
                inserir_fim(letras, 'F');
                inserir_fim(letras, 'A');
                inserir_fim(letras, 'C');
                inserir_fim(letras, 'E');
                //exibir(letras);
                indice = 4;
            }
            
            scanf(" %c", &letraux);
            if (letraux == busca_por_posicao(letras, indice))
            {
                iguais++;
            }
            inserir_fim(letras, letraux);
            //exibir(letras);
            indice--;
        }
        //exibir(letras);
        if (iguais == 4)
        {
            brindes++;
            indice -= 4;
            iguais = 0;
            for (int K = 0; K < 8; K++)
            {
                remover_fim(letras);
                //exibir(letras);
            }
        }
        else
        {
            indice += 4;
            iguais = 0;
        }
    }
    printf("%d\n", brindes);

    liberar(letras);
    return 0;
}

struct lista_enc
{
    int qtde;
    celula* prim;
};

struct celula
{
    Item valor;
    celula* prox;
};

int busca_por_valor(lista_enc* L_enc, Item it){
    if (L_enc ==NULL)
    {
        return 0;
    }
    
    int i = 1;
    celula* cel_aux = L_enc->prim;
    while (cel_aux != NULL)
    {
        if (cel_aux->valor == it)
        {
            return i;
        }
        cel_aux = cel_aux->prox;
        i++;
    }
    return 0;
}

Item busca_por_posicao(lista_enc* L_enc, int posi){
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        return 0;
    }
    
    int i = 1;
    celula* cel_aux = L_enc->prim;
    while (cel_aux != NULL)
    {
        if (i == posi)
        {
            return cel_aux->valor;
        }
        cel_aux = cel_aux->prox;
        i++;
    }
    return 0;
}

static celula* criar_celula(Item it){
    celula* nova = (celula*) calloc(1, sizeof(celula));
    if (nova == NULL)
    {
        return NULL;
    }
    nova->valor = it; 
    return nova;
}

bool esvaziar(lista_enc* L_enc){
    if (L_enc == NULL || L_enc->qtde == 0)
    {
        return false;
    }
    
    while (L_enc->qtde != 0)
    {
        remover_comeco(L_enc);
    }
    return true;
}

void exibir(lista_enc* L_enc){
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        return;
    }
    
    celula* aux = L_enc->prim;
    while (aux != NULL)
    {
        printf("%C ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

lista_enc* iniciar(){
    lista_enc * L_enc = (lista_enc*) calloc(1, sizeof(lista_enc));
    if (L_enc == NULL)
    {
        return NULL;
    }
    return L_enc;
}

bool inserir_fim(lista_enc* L_enc, Item it){
    if (L_enc == NULL)
    {
        return false;
    }
                     
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }
    
    celula* celula_auxiliar = L_enc->prim;
    for (int i = 1; i <= L_enc->qtde; i++)
    {
        if (celula_auxiliar->prox == NULL)
        {
            celula_auxiliar->prox = nova_celula;
            L_enc->qtde++;
            return true;
        }
        celula_auxiliar = celula_auxiliar->prox;
    }
    L_enc->prim = nova_celula;
    L_enc->qtde++;
    return true;
}

bool inserir_inicio(lista_enc* L_enc, Item it){
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }
    nova_celula->prox = L_enc->prim;
    L_enc->prim = nova_celula;
    L_enc->qtde++;
    return true;
}

bool inserir_meio(lista_enc* L_enc, Item it, int posicao){
    if (L_enc || !vazia(L_enc) || posicao <= L_enc->qtde || posicao > 0)
    {
        celula* aux_prox = L_enc->prim;
        celula* aux_ant;
        celula* cel_aux = criar_celula(it);
        if (cel_aux == NULL)
        {
            return false;
        }
        
        if (posicao > 1)
        {
            for (int i = 1; i < posicao; i++)
            {
                aux_ant = aux_prox;
                aux_prox = aux_prox->prox;
            }
            cel_aux->prox = aux_prox;
            aux_ant->prox = cel_aux;
            L_enc->qtde++;
            return true;
        } 
        cel_aux->prox = L_enc->prim;
        L_enc->prim = cel_aux;
        L_enc->qtde++;
        return true;
    }
    return false;
}

lista_enc* liberar(lista_enc* L_enc){
    if (L_enc == NULL)
    {
        return NULL;
    }
    
    esvaziar(L_enc);
    free(L_enc);
    return NULL;
}

void ordenar(lista_enc* L_enc){
    if (L_enc == NULL)
    {
        return;
    }
    
    for (int i = 1; i < L_enc->qtde; i++)
    {
        celula* cel_aux = L_enc->prim;

        for (int j = 1; j < L_enc->qtde + 1 - i; j++)
        {
            Item valor_aux = cel_aux->valor;
            if (valor_aux > cel_aux->prox->valor)
            {
                cel_aux->valor = cel_aux->prox->valor;
                cel_aux->prox->valor = valor_aux;
            }
            cel_aux = cel_aux->prox;
        }
    }
}

bool remover_comeco(lista_enc* L_enc){
    celula* aux = L_enc->prim;
    if (aux != NULL)
    {
        L_enc->prim = aux->prox; 
        L_enc->qtde--;
        free(aux);
        return true;
    }
    return false;
}

bool remover_meio(lista_enc* L_enc, int posicao){
    if (L_enc || !vazia(L_enc) || posicao <= L_enc->qtde || posicao > 0)
    {
        celula* aux_prox = L_enc->prim;
        celula* aux_ant;
        if (posicao > 1)
        {
            for (int i = 1; i < posicao; i++)
            {
                aux_ant = aux_prox;
                aux_prox = aux_prox->prox;
            }
            aux_ant->prox = aux_prox->prox;
            free(aux_prox);
            L_enc->qtde--;
            return true;
        }
        L_enc->prim = aux_prox->prox;
        free(aux_prox);
        L_enc->qtde--;
        return true;
    }
    return false;
}

bool remover_fim(lista_enc* L_enc) 
{
    if(L_enc == NULL || L_enc->prim == NULL)
        return false;

    celula *ant = L_enc->prim;
    if(ant->prox == NULL) 
    {
        L_enc->prim = NULL;
        free(ant);
    } 
    else 
    {
        celula* prox = ant->prox;
        while(prox->prox != NULL) 
        {
            ant = prox;
            prox = prox->prox;
        }
        ant->prox = NULL;
        free(prox);
    }

    L_enc->qtde--;

    return false;
}

int tamanho(lista_enc* L_enc){
    if (L_enc == NULL)
    {
        return 0;
    }
    return L_enc->qtde;
}

bool vazia(lista_enc* L_enc){
    if (L_enc->qtde == 0)
    {
        return true;
    }
    return false;
}