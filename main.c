#include<stdio.h>
#include<stdlib.h>
#include "instance.h"
#include "solution.h"
int main() {
    timetabling a;
    solution sol;
    int i,j;
    leitura(&a);
    cria_solution(a, &sol);
    imprimi(sol);
    gera_sol(a,&sol);
    return 0;
}
