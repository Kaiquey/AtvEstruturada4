/*Sequência de caracteres*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct{
    char letras[MAX];
    int inicio;
    int fim;

} Fila;

typedef struct{
    char letras[MAX];
    int topo;

} Pilha;
/*Enfileirar e desenfileirar*/

void enfileirar(Fila *f, char letra){
    if(f->fim == MAX){
        printf("Fila cheia!\n");
        return;
    }
    f->letras[f->fim] = letra;
    f->fim++;
}
char desenfileirar(Fila *f){
    if(f->fim ==0){
        printf("Fila vazia!\n");
        return '\0';
    }
    char letraTemp = f->letras[f->inicio];
    for(int i = f->inicio; i< f->fim - 1; i++){
        f->letras[i] = f->letras[i + 1];
    }
    f->fim--;
    return letraTemp;
}
/*Empilhar e desempilhar*/
void empilhar(Pilha *p, char letra){
    if(p->topo == MAX){
        printf("Pilha cheia!\n");
        return;
    }
    p->letras[p->topo] = letra;
    p->topo++;
}

char desempilhar(Pilha *p){
    if(p->topo == -1){
        printf("Pilha vazia!\n");
        return '\0';
    }
    p->topo--;
    return p->letras[p->topo];
}

void main(){
    Fila F;
    Pilha P;
    F.fim = 0;
    F.inicio = 0;
    P.topo = 0;
    char palavra[MAX];
    printf("Digite uma sequencia de palavras: ");
    scanf("%[^\n]", palavra);
    for(int i = 0; i < strlen(palavra); i++){
        if(isalpha(palavra[i])){
            palavra[i] = tolower(palavra[i]);
        }
        empilhar(&P, palavra[i]);
    }
    while(P.topo > 0){
        printf("%c", desempilhar(&P));
    }
} 