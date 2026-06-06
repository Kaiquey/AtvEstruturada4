#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Pilha {
    int bit;
    struct Pilha *proximo;
} Pilha;


void empilhar(Pilha **topo, int bit) {
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        exit(1);
    }
    novo->bit = bit;
    novo->proximo = *topo; 
    *topo = novo;          
}

int desempilhar(Pilha **topo) {
    if (*topo == NULL) {
        return -1;
    }
    Pilha *aux = *topo;
    int bit_desempilhado = aux->bit;
    *topo = aux->proximo; 
    free(aux);            
    return bit_desempilhado;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int num, original, resto;
    Pilha *topo = NULL; 
    do {
        printf("Digite um número inteiro maior que zero: ");
        scanf("%d", &num);
        
        if (num<= 0) {
            printf("Erro: O número digitado deve ser estritamente maior que zero!\n\n");
        }
    } while (num <= 0);

    original = num; 

    while (num > 0) {
        resto = num % 2;
        empilhar(&topo, resto);
        num = num / 2;
    }

    printf("O número %d convertido para binário é: ", original);
    
    while (topo != NULL) {
        printf("%d", desempilhar(&topo));
    }
    printf("\n");

    return 0;
}