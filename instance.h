typedef struct {
    int dur,
        num,
        *student;
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
        peso;       //

} room;

typedef struct {
    exam *ex;       //conjunto de exames
    period *per;    //conjunto de peridos
    room *r;        //conjunto de salas
    int num_ex,     //numero de exames
        num_per,    //numero de periodos
        num_room;   //numero de salas
} timetabling;

int countcomma(char s[]); 
int next_comma(char s[], int f_pos) ;
void leitura(timetabling *);
