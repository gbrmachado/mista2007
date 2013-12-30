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
    a->ex = malloc(a->num_ex * sizeof(exam));
    for (i = 0; i < a->num_ex; i++) {
        fgets(auxiliar, TAM_MAX, stdin);
        a->ex[i].num = countcomma(auxiliar);
        a->ex[i].student = malloc(a->ex[i].num * sizeof(int));
        aux_tok = strtok(auxiliar, ",");
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
    fgets(auxiliar, TAM_MAX, stdin);
    puts(auxiliar);
}
   
