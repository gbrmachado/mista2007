#include<stdio.h>
#include<stdlib.h>
#include "instance.h"
#include "solution.h"

void room_period(timetabling a, solution *b) {
    int i;
    b->roomxperiod = malloc(a.num_per * sizeof(int));
    for (i = 0; i < a.num_per; i++) 
        b->roomxperiod[i] = malloc(a.num_room * sizeof(int));

}    

int common_student_ex(exam a, exam b) {
    int i, j, count = 0;
    for (i=0 ; (i < a.num) ; i++ ) 
        for (j=0 ; (j < b.num) ; j++) 
            if ( a.student[i] == b.student[j])
                    count++;
    return count;
}
       

void gera_sol(timetabling a, solution *b) {
    int i,j;
    b->tam = a.num_ex;
    b->nsc = malloc(a.num_ex * sizeof(student_common *));  //alocacao dinamica
    TFila_Period_cria(&b->Fila_estudantes_comum); //cria fila de estudantes
    for ( i=0; (i< a.num_ex) ; i++ ) 
        b->nsc[i] = malloc( a.num_ex * a.num_ex * sizeof(student_common) );
    for (i=0 ; (i < a.num_ex) ; i++) 
        for (j=0 ; (j < a.num_ex) ; j++) {
            b->nsc[i][j].n_estudents = common_student_ex(a.ex[i], a.ex[j]);
            if (b->nsc[i][j].n_estudents > 0) 
                TFila_Period_insere(&b->Fila_estudantes_comum,i,j);
        }

}

void imprimi(solution b) {
    int i,j;
    for (i=0 ; (i < b.tam) ; i++) {
        for (j=0 ; (j < b.tam) ; j++) {
            if (i!=j)
                printf("%2d ", b.nsc[i][j].n_estudents);
        }
        printf("\n");
    }
}
