#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char Item;

typedef struct fila_enc fila_enc;
typedef struct celula celula;

bool esvaziar(fila_enc* L_enc);
Item front(fila_enc* L_enc);
fila_enc* iniciar();
bool inserir(fila_enc* L_enc, Item it);
fila_enc* liberar(fila_enc* L_enc);
bool remover(fila_enc* L_enc);
int tamanho(fila_enc* L_enc);
bool vazia(fila_enc* L_enc);

int main(){
    char expre[1001], quant = 0, aux = 1;
    fila_enc* paren = iniciar();
    while (scanf(" %s", expre) != EOF)
    {
        for (int i = 0; expre[i] != '\0'; i++)
        {
            if (expre[i] == '(' || expre[i] == ')')
            {
                inserir(paren, expre[i]);
            } 
        }
        int aux2 = tamanho(paren);
        for (int i = 0; i < aux2; i++)
        {
            if (tamanho(paren) == 1 && front(paren) == '(')
            {
                quant = 1;
                break;
            }
    
            if (aux == 1 && front(paren) == ')')
            {
                quant = 1;
                break;
            }
            
            else if (front(paren) == '(')
            {
                remover(paren);
                quant++;
                aux++;
            }
            else if (front(paren) == ')')
            {
                remover(paren);
                quant--;
            } 
        }
        
        if (quant == 0)
        {
            printf("correct\n");
        }
        else
        {
            printf("incorrect\n");
        }
        esvaziar(paren);
        aux = 1;
        quant = 0;
    }

    liberar(paren);
    return 0;
}

struct fila_enc
{
    celula* prim;
};

struct celula
{
    Item valor;
    celula* prox;
};

static celula* criar_celula(Item it){ // certo/pronto
    celula* nova = (celula*) calloc(1, sizeof(celula));
    if (nova == NULL)
    {
        return NULL;
    }

    nova->valor = it; 
    return nova;
}

bool esvaziar(fila_enc* L_enc){ // certo/pronto 
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        return false;
    }
    
    while (L_enc->prim != NULL)
    {
        remover(L_enc);
    }
    return true;
}

Item front(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        printf("Sem elemento a ser exibido");
        return 'a';
    }
    celula* aux = L_enc->prim;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    return aux->valor;
}

fila_enc* iniciar(){ // certo/pronto
    fila_enc* L_enc = (fila_enc*) malloc(sizeof(fila_enc));
    if (L_enc == NULL)
    {
        return NULL;
    }
    L_enc->prim = NULL;

    return L_enc;
}

bool inserir(fila_enc* L_enc, Item it){ // certo/pronto
    celula* nova_celula = criar_celula(it);
    if (nova_celula == NULL)
    {
        return false;
    }

    nova_celula->prox = L_enc->prim;
    L_enc->prim = nova_celula;
    return true;
}

fila_enc* liberar(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL)
    {
        return NULL;
    }
    
    esvaziar(L_enc);
    
    free(L_enc);
    return NULL;
}

bool remover(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL || L_enc->prim == NULL)
    {
        return false;
    }
    
    celula* aux_ant = L_enc->prim;
    if (aux_ant->prox == NULL)
    {
        L_enc->prim = NULL;
        free(aux_ant);
        return true;
    }
    celula* aux_pro = L_enc->prim->prox;
    while (aux_pro->prox != NULL)
    {
        aux_ant = aux_pro;
        aux_pro = aux_pro->prox;
    }
    aux_ant->prox = NULL;
    free(aux_pro);
    return true;
}

int tamanho(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL)
    {
        printf("Fila nao inciada.");
        return 0;
    }
    int quant = 0;
    celula* aux = L_enc->prim;
    while (aux != NULL)
    {
        quant++;
        aux = aux->prox;
    }
    return quant;
}

bool vazia(fila_enc* L_enc){ // certo/pronto
    if (L_enc == NULL)
    {
        printf("Fila, nao iniciada.");
        return false;
    }
    
    if (L_enc->prim == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}