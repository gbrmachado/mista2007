#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "instance.h"

#define TAM_MAX 100000

int countcomma(char s[]) {
    int count = 0, i;
    for (i=0;s[i]!='\0';i++) if (s[i] == ',') count++;
    return count;  
}

void leitura(timetabling *a) {
    char auxiliar[TAM_MAX], *aux_tok;
    int i, j;
    fgets(auxiliar, TAM_MAX, stdin);
    // Leitura de exames
    sscanf(auxiliar, "[Exams:%d]\n", &a->num_ex);     
    a->ex = malloc(a->num_ex * sizeof(exam));         //alocacao dinamica
    for (i = 0; i < a->num_ex; i++) {
        fgets(auxiliar, TAM_MAX, stdin);
        a->ex[i].num = countcomma(auxiliar);          //numero de exames eh dado pelo numero de virgulas 
        a->ex[i].student = malloc(a->ex[i].num * sizeof(int));   //aloca vetor de estudantes fazendo exame
        aux_tok = strtok(auxiliar, ",");              //divide o auxiliar
        a->ex[i].dur = atoi(aux_tok);
        j=0;
        aux_tok = strtok(NULL, ",");
        while(aux_tok != NULL) {
            a->ex[i].student[j++] = atoi(aux_tok);
            aux_tok = strtok(NULL, ",");
        }
    }
    /*  Leitura de Periodos  */
    fgets(auxiliar, TAM_MAX, stdin);
    sscanf(auxiliar, "[Periods:%d]", &a->num_per);
    a->per = malloc(a->num_per * sizeof(period));
    for(i=0; i< a->num_per; i++) {
        fgets(auxiliar, TAM_MAX, stdin);
        sscanf(auxiliar, "%d:%d:%d, %d:%d:%d, %d, %d", &a->per[i].day, &a->per[i].month, &a->per[i].year, &a->per[i].hour, &a->per[i].min, &a->per[i].sec, &a->per[i].duration, &a->per[i].penalty);
    }
    /*  Leitura de salas  */
    fgets(auxiliar, TAM_MAX, stdin);
    sscanf(auxiliar,"[Rooms:%d]\n", &a->num_room);
    a->r = malloc(a->num_room * sizeof(room));
    for (i=0; i<a->num_room; i++) 
        scanf("%d, %d\n", &a->r[i].penalty, &a->r[i].capacity);
    /* Leitura de Period Hard Constraints */
    fgets(auxiliar,TAM_MAX, stdin);  //leitura auxiliar
    TFila_Period_cria(&a->period_exclusion);   //cria as filas
    TFila_Period_cria(&a->period_coincidence);
    TFila_Period_cria(&a->period_after);
    while (1) {
        fgets(auxiliar,TAM_MAX, stdin);  //leitura auxiliar
        if (strcmp(auxiliar, "[RoomHardConstraints]\n") == 0) break;
        int par1, par2, men = 0;                             //variaveis para guardar os
        par1 = atoi(auxiliar);
        aux_tok = strtok(auxiliar, ",");           //separacao da primeira virgula
        aux_tok = strtok(NULL, ", ");
        if (strcmp(aux_tok, "EXAM_COINCIDENCE") == 0) 
            men = 1;                                  //se exam coincidence, men = 1
        
        else if (strcmp(aux_tok, "EXCLUSION") == 0) 
            men = 2;                                  //se exclusion, men = 2
        else if (strcmp(aux_tok, "AFTER") == 0) 
            men = 3;                                  //se after, men = 3;
        aux_tok = strtok(NULL, ", ");              //separacao da segunda virgula
        par2 = atoi(aux_tok);
        switch (men) {
            case 1:
                TFila_Period_insere (&a->period_coincidence, par1, par2);
                break;
            case 2:
                TFila_Period_insere(&a->period_exclusion, par1, par2);
                break;
            case 3:
                TFila_Period_insere(&a->period_after,par1,par2);
                break;
        }
        printf("Period Coincidence: \n");
        TFila_Period_Imprimi(&a->period_coincidence);
        printf("Period After: \n");
        TFila_Period_Imprimi(&a->period_after);
        printf("Period Exclusion: \n");
        TFila_Period_Imprimi( &a->period_exclusion);
//        printf("MEN: %d\nA:%d\t\tB:%d\n", men, par1, par2);
    }
}
   
