#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define MAX 10

typedef struct
{
    char num[MAX];
    int inicio;
    int fim;
} Fila;

void enfileirar(Fila *f, char valor){
    
    if (f->fim == MAX)    {
        printf("Fila cheia!\n");
        return;
    }
    f->num[f->fim] = valor;
    f->fim++;
}

int desenfileirar(Fila *f){
    if (f->fim == 0)    {
        printf("Fila vazia!\n");
        return 1;
    }
    int numTemp = f->num[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->fim--;
    return numTemp;
}

void menu(){
    printf("1. Enfileirar\n");
    printf("2. Desenfileirar\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
}

void main(){
    setlocale(LC_ALL, "Portuguese");
    Fila f;
    f.inicio = 0;
    f.fim = 0;

    int opc, num = 0;

    do{
        menu();
        scanf("%d", &opc);
        switch(opc){
            case 1:
                printf("Digite o número a ser enfileirado: ");
                scanf("%d", &num);
                if(num == 0){
                    printf("Número nulo! Não pode ser enfileirado!\n");
                    break;
                }
                enfileirar(&f, num);
                break;
            case 2:
                num = desenfileirar(&f);
                if(num != 1){
                    printf("Número desenfileirado: %d\n", num);
                }
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    }while(opc != 3);

}