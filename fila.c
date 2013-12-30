#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//Lista com Sentinela
void TFila_Period_cria(TFila_Period *TFila) {
    TFila->pPrimeiro = malloc(sizeof(TCelula_Period_Hard));
    TFila->pUltimo = TFila->pPrimeiro;
    TFila->pPrimeiro->pProx = NULL;
    TFila->n_restricoes = 0;
}

int TFila_Period_vazio(TFila_Period *TFila) {
    if (TFila->pPrimeiro == TFila->pUltimo)
        return 0;
    return 1;
}

void TFila_Period_insere(TFila_Period *TFila, int a, int b) {
    TFila->pUltimo->pProx = (TCelula_Period_Hard *)malloc(sizeof(TCelula_Period_Hard));
    TFila->pUltimo = TFila->pUltimo->pProx;
    TFila->pUltimo->par.a = a;
    TFila->pUltimo->par.b = b;
    TFila->pUltimo->pProx = NULL;
    TFila->n_restricoes++;
}

void TFila_Period_Imprimi(TFila_Period *TFila) {
    TCelula_Period_Hard *aux;
    aux = TFila->pPrimeiro->pProx;
    while (aux != NULL) {
        printf("Par A: %d\tPar B: %d\n", aux->par.a, aux->par.b);
        aux=aux->pProx;
    }
}

Par_Ordenado TFila_Period_remove(TFila_Period *TFila) {
    Par_Ordenado saida;
    if (!TFila_Period_vazio(TFila)) {
        saida.a = saida.b =-1;
        return saida;
    }
    TCelula_Period_Hard *aux;
    aux = TFila->pPrimeiro->pProx;
    TFila->pPrimeiro->pProx = aux->pProx;
    saida = aux->par;
    free(aux);
    return saida;
}



