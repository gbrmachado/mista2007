typedef struct _student_common {
    int n_estudents,      //numero de estudantes em comum entre 2 exames
        alocado;          //0 nao alocado, 1 alocado
} student_common;

typedef struct {
    student_common **nsc;

    int tam,   //tamanho do vetor
        **roomxperiod;  //Vetor de sala x periodos alocando um exame 
    TFila_Period Fila_estudantes_comum; //fila de estudantes em comum
} solution;

void room_period(timetabling, solution *);
void gera_sol(timetabling, solution *) ;
void imprimi(solution) ;
