#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/********************************************************************
 * Fila de Restricoes de Periodo                                    /
 *******************************************************************/

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
    if (TFila_Period_vazio(TFila) == 0) {
        saida.a = saida.b = -1;
        return saida;
    }
    TCelula_Period_Hard *aux;
    aux = TFila->pPrimeiro->pProx;
    TFila->pPrimeiro->pProx = aux->pProx;
    saida = aux->par;
    free(aux);
    return saida;
}

/********************************************************************
 * Fila de estudantes em comum                                      /
 *******************************************************************/
void TFila_StudentCommon_cria (TFila_StudentCommon *fila) {
    fila->pPrimeiro = malloc(sizeof(TCelula_Period_common));
    fila->pPrimeiro->pProx = NULL;
    fila->pUltimo = fila->pPrimeiro;
    fila->n_periods = 0;
}

int TFila_StudentCommon_vazio (TFila_StudentCommon *fila) {
    if (fila->pPrimeiro == fila->pUltimo) return 0;
    return 1;
}

void TFila_StudentCommon_insere (TFila_StudentCommon *fila, int a, int b, int c) {
    fila->pUltimo->pProx = (TCelula_Period_common *) malloc(sizeof(TCelula_Period_common));
    fila->pUltimo = fila->pUltimo->pProx;
    fila->pUltimo->pProx = NULL;
    fila->pUltimo->period.p_a = a;
    fila->pUltimo->period.p_b = b;
    fila->pUltimo->period.n_p = c;
    fila->n_periods++;
}

Period_common TFila_StudentCommon_remove ( TFila_StudentCommon *fila) {
    Period_common saida;
    if (TFila_StudentCommon_vazio(fila) == 0) {
        saida.p_a = saida.n_p = saida.p_b = -1;
        return saida;
    }
    TCelula_Period_common *aux;
    aux = fila->pPrimeiro->pProx;
    fila->pPrimeiro->pProx = aux->pProx;
    saida = aux->period;
    free(aux);
    return saida;
}

void TFila_StudentCommon_Imprimi (TFila_StudentCommon *fila) {
    TCelula_Period_common *aux;
    aux = fila->pPrimeiro->pProx;
    while (aux != NULL) {
        printf("Exame A: %d\tExame B: %d\nEstudantes em Comum: %d\n\n", aux->period.p_a, aux->period.p_b, aux->period.n_p);
        aux=aux->pProx;
    }
}
