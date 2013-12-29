#include<stdio.h>
#include<stdlib.h>
#include "instance.h"
#include "solution.h"

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
    b->nsc = malloc(a.num_ex * sizeof(int *));  //alocacao dinamica
    for ( i=0; (i< a.num_ex) ; i++ ) 
        b->nsc[i] = malloc( a.num_ex * a.num_ex * sizeof(int) );
    for (i=0 ; (i < a.num_ex) ; i++) 
        for (j=0 ; (j < a.num_ex) ; j++)
            b->nsc[i][j] = common_student_ex(a.ex[i], a.ex[j]);
}

void imprimi(solution b) {
    int i,j;
    for (i=0 ; (i < b.tam) ; i++) {
        for (j=0 ; (j < b.tam) ; j++) {
            if (i!=j)
                printf("%2d ", b.nsc[i][j]);
        }
        printf("\n");
    }
}
