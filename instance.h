#include "fila.h"
typedef struct {
    int dur,
        num,
        *student,
        exclusive;   //1 se exclusivo, 0 se nao   
} exam;

typedef struct {
    int day,
        month,
        year,
        hour,
        min, 
        sec,
        penalty,
        duration;
} period;

typedef struct {
    int capacity,
        penalty,
        peso;

} room;

typedef struct {
    exam *ex;       //conjunto de exames
    period *per;    //conjunto de peridos
    room *r;        //conjunto de salas
    int num_ex,     //numero de exames
        num_per,    //numero de periodos
        num_room;   //numero de salas
//Conjunto de restricoes de periodo
    TFila_Period period_exclusion,  //conjunto de exames q n podem ser alocados no mesmo periodo 
                 period_after,      //conjunto d exames q devem ser alocados em sequencia
                 period_coincidence;  //conjunto de exames q devem ser alocados no mesmo periodo
//Conjunto de Institucional Constraints

    int twoinarow,     //Dois exames em seguda
        twoinaday,     //Dois exames em um dia
        periodspread,  //
        nonmixed,      //Salas e periodos com com duracoes mistas
        frontload[3];  //exames mais tarde
} timetabling;




int countcomma(char s[]); 
int next_comma(char s[], int f_pos) ;
void leitura(timetabling *);
