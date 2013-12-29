#include<stdio.h>
#include<stdlib.h>
#include "instance.h"
int countcomma(char s[]) {
    int count = 0, i;
    for (i=0;s[i]!='\0';i++) if (s[i] == ',') count++;
    return count;  
}

int next_comma(char s[], int f_pos) {
    int i = 0;
    for (i=f_pos ; s[i]!='\0' ; i++) {
        if (s[i] == ',') 
            return ++i;
    }
    return -1;
}

void leitura(timetabling *a) {
    char auxiliar[1000], *aux;
    int i, j;
    scanf("[Exams:%d]\n", &a->num_ex);
    a->ex = malloc(a->num_ex * sizeof(exam));
    /*  Leitura de exames  */
    for(i=0; i < a->num_ex ; i++) {
        int ini,j;
        fgets(auxiliar,1000,stdin);
        a->ex[i].dur = atoi(auxiliar);
        a->ex[i].num = countcomma(auxiliar);
        a->ex[i].student = malloc(a->ex[i].num * sizeof(int));
        ini = next_comma(auxiliar,0);
        j = 0;
        while(ini != -1) {
            a->ex[i].student[j] = atoi(auxiliar + ini);
            j++;
            ini = next_comma(auxiliar,ini);
        }
    }
/*  Leitura de Periodos  */
    scanf("[Periods:%d]\n", &a->num_per);
    a->per = malloc(a->num_per * sizeof(period));
    for(i=0; i< a->num_per; i++) 
        scanf("%d:%d:%d, %d:%d:%d, %d, %d", &a->per[i].day, &a->per[i].month, &a->per[i].year, &a->per[i].hour, &a->per[i].min, &a->per[i].sec, &a->per[i].duration, &a->per[i].penalty);
    /*  Leitura de salas  */ 
    scanf("[Rooms:%d]\n", &a->num_room);
    a->r = malloc(a->num_room * sizeof(room));
    for (i=0; i<a->num_room; i++) 
        scanf("%d, %d", &a->r[i].penalty, &a->r[i].capacity);

}
   
