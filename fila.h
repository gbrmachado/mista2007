/*-----------------------------------------------*
 * Estrutura para fila de Restricoes do periodo  *
 * ----------------------------------------------*/
typedef struct {
    int a,
        b;
} TDupla;

typedef struct _TCelula_Dupla{
    struct _TCelula_Dupla *pProx;
    TDupla par;
} TCelula_Dupla;

typedef struct _TFila_Dupla {
    TCelula_Dupla *pPrimeiro, *pUltimo;
    int n;     //Numero de elementos
} TFila_Dupla;

void TFila_Dupla_cria(TFila_Dupla *);
void TFila_Dupla_insere(TFila_Dupla *, int, int);
TDupla TFila_Dupla_remove(TFila_Dupla *);
int TFila_Dupla_vazio(TFila_Dupla *);
void TFila_Dupla_Imprimi(TFila_Dupla *);

/*************************************************
 * Estrutura para fila de periodos em comum      *
 * **********************************************/
typedef struct {
    int a,    //periodo A (numero do periodo)
        b,    //periodo B
        c;    //Numero de estudantes em comum entre os periodos A e B
} TTripla;

typedef struct _TCelula_Tripla {
    struct _TCelula_Tripla *pProx;
    TTripla tripla;
} TCelula_Tripla;

typedef struct {
    TCelula_Tripla *pPrimeiro, *pUltimo;
    int n;
} TFila_Tripla;

void TFila_Tripla_cria(TFila_Tripla *);
void TFila_Tripla_insere(TFila_Tripla *, int, int, int);
TTripla  TFila_Tripla_remove(TFila_Tripla *);
int TFila_Tripla_vazio(TFila_Tripla *);
void TFila_Tripla_Imprimi(TFila_Tripla *);
void TFila_Tripla_ordena(TFila_Tripla *);
