typedef struct _Par_Ordenado {
    int a, b;
} Par_Ordenado;

typedef struct TCelula_Period{
    struct TCelula_Period *pProx;
    Par_Ordenado par;
} TCelula_Period_Hard;

typedef struct _TFila_Period {
    TCelula_Period_Hard *pPrimeiro, *pUltimo;
    int n_restricoes;
} TFila_Period;

void TFila_Period_cria(TFila_Period *);
void TFila_Period_insere(TFila_Period *, int, int);
Par_Ordenado TFila_Period_remove(TFila_Period *);
int TFila_Period_vazio(TFila_Period *);
void TFila_Period_Imprimi(TFila_Period *);
