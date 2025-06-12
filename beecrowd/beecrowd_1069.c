#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Item;

typedef struct pilha_enc pilha_enc;
typedef struct celula celula;

bool esvaziar(pilha_enc* P_enc);
pilha_enc* iniciar();
bool inserir(pilha_enc* P_enc, Item it);
pilha_enc* liberar(pilha_enc* P_enc);
bool remover(pilha_enc* P_enc);
int tamanho(pilha_enc* P_enc);
Item top(pilha_enc* P_enc);
bool vazia(pilha_enc* P_enc);

int main(){
    int n, indice, quant_dimas, mudanca = 1;
    char aux;
    pilha_enc* refino1 = iniciar();
    pilha_enc* refino2 = iniciar();
    scanf("%d", &n);
    char dimas[1000];
    for (int i = 0; i < n; i++)
    {
        quant_dimas = 0;
        indice = 0;
        scanf(" %s", dimas);
        while (dimas[indice] != '\0')
        {
            if (dimas[indice] == '<' || dimas[indice] == '>')
            {
                inserir(refino1, dimas[indice]);
            }
            indice++;
        }

        while (1)
        {
            if (mudanca == 0) // quando nao houver formacao de diamantes ele para o while
            {
                break;
            }
            mudanca = 0;
            while (!vazia(refino1)) // do refino1 para o refino2
            {
                aux = top(refino1);
                remover(refino1);
                inserir(refino2, aux);
                if (aux == '>')
                {
                    if (top(refino1) == '<')
                    {
                        remover(refino1);
                        remover(refino2);
                        quant_dimas++;
                        mudanca++;
                    }
                }
            }
            while (!vazia(refino2)) // para o refino2 para o refino1
            {
                aux = top(refino2);
                remover(refino2);
                inserir(refino1, aux);
                if (aux == '<')
                {
                    if (top(refino2) == '>')
                    {
                        remover(refino2);
                        remover(refino1);
                        quant_dimas++;
                        mudanca++;
                    }
                }
            }
        }
        printf("%d\n", quant_dimas);
        mudanca = 1;
        esvaziar(refino1);
        esvaziar(refino2);
        //printf("%c %c", top(refino1), top(refino2));
    }

    refino1 = liberar(refino1);
    refino2 = liberar(refino2);
    return 0;
}

struct pilha_enc
{
    celula* prim;
};

struct celula
{
    Item valor;
    celula* prox;
};

static celula* criar_celula(Item it){
    celula* nova = (celula*) calloc(1, sizeof(celula));
    if (nova == NULL)
    {
        return NULL;
    }
    nova->valor = it; 
    return nova;
}

bool esvaziar(pilha_enc* P_enc){
    if (P_enc == NULL || P_enc->prim == NULL)
    {
        return false;
    }
    
    while (P_enc->prim != NULL)
    {
        remover(P_enc);
    }
    return true;
}

pilha_enc* iniciar(){
    pilha_enc * P_enc = (pilha_enc*) calloc(1, sizeof(pilha_enc)); 
    if (P_enc == NULL)
    {
        return NULL;
    }
    return P_enc;
}

bool inserir(pilha_enc* P_enc, Item it){
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }
    nova_celula->prox = P_enc->prim;
    P_enc->prim = nova_celula;
    return true;
}

pilha_enc* liberar(pilha_enc* P_enc){
    if (P_enc == NULL)
    {
        return NULL;
    }
    
    esvaziar(P_enc);
    free(P_enc);
    return NULL;
}

bool remover(pilha_enc* P_enc){
    celula* aux = P_enc->prim;
    if (aux != NULL)
    {
        P_enc->prim = aux->prox;
        free(aux);
        return true;
    }
    return false;
}

int tamanho(pilha_enc* P_enc){
    if (P_enc == NULL || P_enc->prim == NULL)
    {
        return 0;
    }
    celula* cel_aux = P_enc->prim;
    int quant = 1;
    while (cel_aux->prox != NULL)
    {
        quant++;
        cel_aux = cel_aux->prox;
    }
    return quant;
}

Item top(pilha_enc* P_enc){
    if (P_enc == NULL)
    {
        //printf("Pilha nao iniciada.");
        return 'a';
    }
    if (P_enc->prim == NULL)
    {
        //printf("Pilha vazia.");
        return 'a';
    }
    return P_enc->prim->valor;
}

bool vazia(pilha_enc* P_enc){
    if (P_enc->prim == NULL) 
    {
        return true;
    }
    return false;
}