#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <unistd.h>

#define MAX 100

//A
typedef struct
{
    char letras[MAX];
    int inicio;
    int fim;
} FilaA;
//B
typedef struct
{
    int num[MAX];
    int inicio;
    int fim;
    int cont;
}FilaB;

void enfileirarA(FilaA *f, char letra){
    if(f->fim == MAX){
        printf("Fila A está cheia!\n");
        return;
    }

    f->letras[f->fim] = letra;
    f->fim++;
}

char desenfileirarA (FilaA *f){
    if(f->fim == 0){
        printf("Fila A está vazia!\n");
        return '\0';
    }
    char removedChar = f->letras[f->inicio];

    printf(" [%c]\n", removedChar);

    for(int i = f->inicio;i<f->fim-1;i++){
        f->letras[i] = f->letras[i + 1];
    }
    f->fim--;
    return removedChar;
}

void enfileirarB(FilaB *f, int valor){
    if(f->cont == MAX){
        printf("Fila B está cheia!\n");
        return;
    }
    int valorTemp = valor - '0';
    f->num[f->fim] = valorTemp;
    f->fim = (f->fim + 1) % MAX;
    f->cont++;
}

int desenfileirarB (FilaB *f){
    if(f->cont == 0){
        printf("Fila B está vazia!\n");
        return 1;
    }
    int removedNum = f->num[f->inicio];
    printf(" [%d]", removedNum);
    f->inicio = (f->inicio + 1) % MAX;
    f->cont--;
    return removedNum;
}

void main(){
    setlocale(LC_ALL, "Portuguese");
    system("cls || clear");

    FilaA A;
    FilaB B;

    A.inicio=0;
    A.fim=0;
    B.inicio=0;
    B.fim=0;
    B.cont=0;
    int opc;

    char palavra[MAX];
    printf("Palavras: ");
    scanf("%[^\n]s", palavra);

    for(int i = 0; i < strlen(palavra); i++){
        char temp = palavra[i];
        if(isdigit(temp)){
            enfileirarB(&B, temp);
        } else if (isalpha(temp)){
            enfileirarA(&A, temp);
        }
    }

    do{
        printf("Escolha uma opção:\n");
        printf("1. Desenfileirar da Filas\n");
        printf("2. Sair\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            printf("Fila B: ");
            while(B.cont > 0){
                desenfileirarB(&B);
            }
            printf("\nFila A: ");
            while(A.fim > A.inicio){
                desenfileirarA(&A);
            }
            break;
        case 2:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }while(opc != 2);
}