/*Fila Sequencial Simples*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>

#define MAX 10

typedef struct Fila{
    int num[MAX];
    int inicio;
    int fim;

} Fila;

void enfileirar(Fila *f, int valor){
    if(f->fim == MAX){
        printf("Fila cheia!\n");
        return;
    }
    f->num[f->fim] = valor;
    f->fim++;
    printf("Número %d enfileirado com sucesso!\n", valor);
}
void desenfileirar(Fila *f){
    if(f->fim == 0){
        printf("Fila vazia!\n");
        return;
    }
    int numTemp = f->num[f->inicio];
    if(numTemp % 2 == 0){
        printf("Número %d é múltiplo de 2\n", numTemp);
    }
    for(int i = f->inicio; i < f->fim - 1; i++){
        f->num[i] = f->num[i + 1];
    }
    f->fim--;

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
    f.fim = 0;
    f.inicio = 0;
    int number;
    int op;
    do{
        system("cls");
        menu();
        scanf("%d", &op);
        switch (op){        
            case 1:
                printf("Digite um número para enfileirar: ");
                scanf("%d", &number);
                enfileirar(&f, number);
                break;
            case 2:
                desenfileirar(&f);
                break;
            case 3:
                printf("Saindo...\n");
                sleep(3);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                sleep(2);
                break;
        }
    }while(op != 3);
} 