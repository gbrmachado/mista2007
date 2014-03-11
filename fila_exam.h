#include "instance.h"

typedef struct _fila_exam_t {
    exam ex;
    struct _fila_exam_t *pProx;
} TCelula_Exam;

typedef struct {
    TCelula_Exam *pPrimeiro, *pUltimo;
    int n;
} TFila_Exam;

void TFila_Exam_cria(TFila_Exam *);
void TFila_Exam_insere(TFila_Exam *, exam);
exam TFila_Exam_remove(TFila_Exam *);
int TFila_Exam_vazio(TFila_Exam *);
void TFila_Exam_Imprimi(TFila_Exam *);

