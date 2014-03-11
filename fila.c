#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/********************************************************************
 * Fila de Duplas                                                   /
 *******************************************************************/

//Lista com Sentinela
void TFila_Dupla_cria(TFila_Dupla *TFila) {
    TFila->pPrimeiro = malloc(sizeof(TCelula_Dupla));
    TFila->pUltimo = TFila->pPrimeiro;
    TFila->pPrimeiro->pProx = NULL;
    TFila->n = 0;
}

int TFila_Dupla_vazio(TFila_Dupla *TFila) {
    if (TFila->pPrimeiro == TFila->pUltimo)
        return 0;
    return 1;
}

void TFila_Dupla_insere(TFila_Dupla *TFila, int a, int b) {
    TFila->pUltimo->pProx = (TCelula_Dupla *)malloc(sizeof(TCelula_Dupla));
    TFila->pUltimo = TFila->pUltimo->pProx;
    TFila->pUltimo->par.a = a;
    TFila->pUltimo->par.b = b;
    TFila->pUltimo->pProx = NULL;
    TFila->n++;
}

void TFila_Dupla_Imprimi(TFila_Dupla *TFila) {
    TCelula_Dupla *aux;
    aux = TFila->pPrimeiro->pProx;
    while (aux != NULL) {
        printf("Par A: %d\tPar B: %d\n", aux->par.a, aux->par.b);
        aux=aux->pProx;
    }
}

TDupla TFila_Dupla_remove(TFila_Dupla *TFila) {
    TDupla saida;
    if (TFila_Dupla_vazio(TFila) == 0) {
        saida.a = saida.b = -1;
        return saida;
    }
    TCelula_Dupla *aux;
    aux = TFila->pPrimeiro->pProx;
    TFila->pPrimeiro->pProx = aux->pProx;
    saida = aux->par;
    free(aux);
    return saida;
}

/********************************************************************
 * Fila de Triplas                                                  /
 *******************************************************************/
void TFila_Tripla_cria (TFila_Tripla *fila) {
    fila->pPrimeiro = malloc(sizeof(TCelula_Tripla));
    fila->pPrimeiro->pProx = NULL;
    fila->pUltimo = fila->pPrimeiro;
    fila->n = 0;
}

int TFila_Tripla_vazio (TFila_Tripla *fila) {
    if (fila->pPrimeiro == fila->pUltimo) return 0;
    return 1;
}

void TFila_Tripla_insere (TFila_Tripla *fila, int a, int b, int c) {
    fila->pUltimo->pProx = (TCelula_Tripla *) malloc(sizeof(TCelula_Tripla));
    fila->pUltimo = fila->pUltimo->pProx;
    fila->pUltimo->pProx = NULL;
    fila->pUltimo->tripla.a = a;
    fila->pUltimo->tripla.b = b;
    fila->pUltimo->tripla.c = c;
    fila->n++;
}

TTripla TFila_Tripla_remove ( TFila_Tripla *fila) {
    TTripla saida;
    if (TFila_Tripla_vazio(fila) == 0) {
        saida.a = saida.b = saida.c = -1;
        return saida;
    }
    TCelula_Tripla *aux;
    aux = fila->pPrimeiro->pProx;
    fila->pPrimeiro->pProx = aux->pProx;
    saida = aux->tripla;
    free(aux);
    return saida;
}

void TFila_Tripla_Imprimi (TFila_Tripla *fila) {
    TCelula_Tripla *aux;
    aux = fila->pPrimeiro->pProx;
    while (aux != NULL) {
        printf("Exame A: %d\tExame B: %d\nEstudantes em Comum: %d\n\n", aux->tripla.a, aux->tripla.b, aux->tripla.c);
        aux=aux->pProx;
    }
}
