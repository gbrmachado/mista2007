#include<stdio.h>
#include<stdlib.h>
#include "fila.h"
int main() {
    TFila_Period fila;
    int menu, a, b;
    Par_Ordenado par;
    TFila_Period_cria(&fila);
    do {
        printf("1:Adiciona\n2:Remove\n3Imprimi\n");
        scanf("%d", &menu);
        if (menu == 0)
            return 0;
        switch (menu) {
            case 1:
                printf("Digite os pares ordenados: ");
                scanf("%d %d", &a, &b);
                TFila_Period_insere(&fila, a, b);
                break;
            case 2:
                par = TFila_Period_remove(&fila);
                printf("%d %d\n", par.a, par.b);
                break;
            case 3:
                TFila_Period_Imprimi(&fila);
                break;
            }
    } while(1);
    return 0;
}

