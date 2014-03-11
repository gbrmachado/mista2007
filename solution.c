#include<stdio.h>
#include<stdlib.h>
#include "instance.h"
#include "solution.h"
/* Numero de estudantes em comum entre 2 exames */
int common_student_ex(exam a, exam b) {
    int i, j, count = 0;
    for (i=0 ; (i < a.num) ; i++ ) 
        for (j=0 ; (j < b.num) ; j++) 
            if ( a.student[i] == b.student[j])
                    count++;
    return count;
}


//função para preparação inicial da variavel do tipo solution
void cria_solution(timetabling a, solution *b) {
    int i, j;
//variaveis iniciais
    b->tam = a.num_ex;

/**************** NSC - Number Student Common ******************************
 * Matriz Bidimensional de tamanho exam x exam, em que cada posição nsc[i][j]
 * contém o numero de conflitos entre exam[i] e exam[j]
 ***************************************************************************/

//ALOCACAO DINAMICA
    b->nsc = malloc(a.num_ex * sizeof(student_common *));  //alocacao dinamica
    for ( i=0; (i< a.num_ex) ; i++ ) 
        b->nsc[i] = malloc( a.num_ex * sizeof(student_common) );
// Preenchimento de nsc
    for (i=0 ; (i < a.num_ex) ; i++) { 
        for (j=0 ; (j < a.num_ex) ; j++) {
            if (i != j) {
                b->nsc[i][j].n_estudents = common_student_ex(a.ex[i], a.ex[j]);
            }
        }
    }
/*********************** Exam Conflit **********************************
 * Vetor Unidimensional de tamanho n_exam, contendo o numero total de
 * conflitos que cada exame possui.
 ***********************************************************************/
    b->exam_conflit = malloc(a.num_ex * sizeof(int)); //alocacao d
    for (i = 0; i < a.num_ex; i++) {
        b->exam_conflit[i] = 0;  //inicio do contador
//Preenchimento de exam_conflit com o somatório do numero de conflitos
//de cada exame
        for (j = 0; j < a.num_ex; j++) 
            b->exam_conflit[i] += b->nsc[j][i].n_estudents;
        
    }
/******************* ROOM x Period *************************************
 * Matriz Bidimensional contendo 
 * Cria Matriz Bidimensional room x period 
 ***********************************************************************/
    b->roomxperiod = malloc(a.num_per * sizeof(int));
    for (i = 0; i < a.num_per; i++) 
        b->roomxperiod[i] = malloc(a.num_room * sizeof(int));
/**************** Fila_Aloca ******************************************
 * Fila encadeada de exames.
 * Contem os exames em ordem de alocação
 **********************************************************************/
    TFila_Exam_cria(&b->Fila_aloca);  //Cria Fila
}    
/***********************************************************************
 * Função Auxiliar para gerar solução
 * Encontra o maior elemento de exam_conflit, e depois o transforma em -1
 ***********************************************************************/
int pos_max(solution *b) {
    int i, pos_max = 0;
    for (i = 0; i < b->tam; i++) {
        if (b->exam_conflit[i] >= b->exam_conflit[pos_max])
            pos_max = i;
    }
    b->exam_conflit[pos_max] = -1;
    return pos_max;
}

void gera_sol(timetabling a, solution *b) {
    int i,j, pos_aux = 0;
    for (i = 0; i < a.num_ex; i++) {
        pos_aux = pos_max(b);
        TFila_Exam_insere(&b->Fila_aloca, a.ex[pos_aux]);
    }
    TFila_Exam_Imprimi(&b->Fila_aloca);
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
