typedef struct {
    int **nsc, //numero de estudantes em comum    
        tam;
} solution;

void gera_sol(timetabling a, solution *b) ;
void imprimi(solution b) ;
