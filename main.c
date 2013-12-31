#include<stdio.h>
#include<stdlib.h>
#include "instance.h"
#include "solution.h"
int main() {
    timetabling a;
    solution sol;
    int i,j;
    leitura(&a);
    gera_sol(a, &sol);
//    imprimi(sol);
    return 0;
}
