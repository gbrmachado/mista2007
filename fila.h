/*-----------------------------------------------*
 * Estrutura para fila de Restricoes do periodo  *
 * ----------------------------------------------*/
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

/*************************************************
 * Estrutura para fila de periodos em comum      *
 * **********************************************/
typedef struct _Period_comum {
    int p_a,    //periodo A (numero do periodo)
        p_b,    //periodo B
        n_p;    //Numero de estudantes em comum entre os periodos A e B
} Period_common;

typedef struct _TCelula_Period_common {
    struct _TCelula_Period_common *pProx;
    Period_common period;
} TCelula_Period_common;

typedef struct _TFila_StudentCommon {
    TCelula_Period_common *pPrimeiro, *pUltimo;
    int n_periods;
} TFila_StudentCommon;

void TFila_StudentCommon_cria(TFila_StudentCommon *);
void TFila_StudentCommon_insere(TFila_StudentCommon *, int, int, int);
Period_common TFila_StudentCommon_remove(TFila_StudentCommon *);
int TFila_StudentCommon_vazio(TFila_StudentCommon *);
void TFila_StudentCommon_Imprimi(TFila_StudentCommon *);
