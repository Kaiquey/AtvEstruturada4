#include <stdlib.h>
#include <stdio.h>

#define MAX 50

typedef struct Pilha {
    int num;
    struct Pilha *proximo;
} Pilha;

void empilhar(Pilha **topo, int v) {
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        exit(1);
    }
    novo->num = v;
    novo->proximo = *topo; 
    *topo = novo;          
}

int desempilhar(Pilha **topo) {
    if (*topo == NULL) {
        printf("Erro: Mal formada essa parada ai, falta numero para operar");
        exit(1);
    }
    Pilha *aux = *topo;
    int value = aux->num;
    *topo = aux->proximo; 
    free(aux);            
    return value;
}

void main()
{
    char frase[MAX];
    int i =0;
    Pilha *topo = NULL;
    
    printf("Fale a expressao em notacao polonesa reversa (ex: 23+5*): ");
    scanf("%[^\n]", &frase);
    
    while(frase[i]!='\0'){
        if(frase[i] >= '0' && frase[i] <='9'){
            empilhar(&topo,frase[i] -'0');
        }
        else if(frase[i] =='+' ||frase[i] =='-' || frase[i] =='*'|| frase[i] =='/'){
            int direita = desempilhar(&topo);
            int esquerda = desempilhar(&topo);
            int result;
            
            switch(frase[i]){
                case '+':
                result = esquerda + esquerda;
                break;
                case '-':
                result = esquerda - direita;
                break;
                case '*':
                result = esquerda * direita;
                break;
                case '/':
                    if(direita == 0){
                        printf("Erro na divisao. Zero detectado para dividir\n");
                        exit(1);
                    }
                    result = esquerda / direita;
                    break;
            }
            empilhar(&topo, result);
        }else{
                printf("ERROR: Caractere nao valido '%c' na frase.\n", frase[i]);
                exit(1);
        }
        i++;
    }
    int resultado = desempilhar(&topo);
    if(topo != NULL){
        printf("Erro: Tem numeros sobrando pae\n");
        while(topo!=NULL){
            desempilhar(&topo);
        }
    }else{
        printf("O resultado final: %d\n", resultado);
    }
}
