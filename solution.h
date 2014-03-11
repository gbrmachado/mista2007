#include "fila_exam.h"
typedef struct _student_common {
    int n_estudents,      //numero de estudantes em comum entre 2 exames
        alocado;          //0 nao alocado, 1 alocado
} student_common;

typedef struct {
    student_common **nsc;

    int tam,   //tamanho do vetor
        **roomxperiod,  //Vetor de sala x periodos alocando um exame 
        *exam_conflit;  //vetor contendo o numero de conflitos de cada exame
    TFila_Exam Fila_aloca; //fila de exames na ordem de alocacao 
} solution;
void cria_solution(timetabling, solution *);
void room_period(timetabling, solution *);
void gera_sol(timetabling, solution *) ;
void imprimi(solution) ;
