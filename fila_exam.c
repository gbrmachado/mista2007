#include <stdio.h>
#include <stdlib.h>
#include "fila_exam.h"

void TFila_Exam_cria(TFila_Exam *TFila) {
    TFila->pPrimeiro = malloc(sizeof(TCelula_Exam));
    TFila->pUltimo = TFila->pPrimeiro;
    TFila->pPrimeiro->pProx = NULL;
    TFila->n = 0;
}

int TFila_Exam_vazio(TFila_Exam *TFila) {
    if (TFila->pPrimeiro == TFila->pUltimo)
        return 0;
    return 1;
}

void TFila_Exam_insere(TFila_Exam *TFila, exam a) {
    TFila->pUltimo->pProx = (TCelula_Exam *)malloc(sizeof(TCelula_Exam));
    TFila->pUltimo = TFila->pUltimo->pProx;
    TFila->pUltimo->ex = a;
    TFila->pUltimo->pProx = NULL;
    TFila->n++;
}

void TFila_Exam_Imprimi(TFila_Exam *TFila) {
    TCelula_Exam *aux;
    aux = TFila->pPrimeiro->pProx;
    while (aux != NULL) {
        printf("Num: %d\tDur: %d\n", aux->ex.num, aux->ex.dur);
        aux=aux->pProx;
    }
}

exam TFila_Exam_remove(TFila_Exam *TFila) {
    exam saida;
    if (TFila_Exam_vazio(TFila) == 0) {
        saida.num = saida.dur = -1;
        return saida;
    }
    TCelula_Exam *aux;
    aux = TFila->pPrimeiro->pProx;
    TFila->pPrimeiro->pProx = aux->pProx;
    saida = aux->ex;
    free(aux);
    return saida;
}

