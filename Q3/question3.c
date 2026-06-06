#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct Pilha {
    char letra;
    struct Pilha *proximo;
} Pilha;

void empilhar(Pilha **topo, char l) {
    Pilha *novo = (Pilha*) malloc(sizeof(Pilha));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória!\n");
        exit(1);
    }
    novo->letra = l;
    novo->proximo = *topo; 
    *topo = novo;          
}

char desempilhar(Pilha **topo) {
    if (*topo == NULL) {
        return '\0';
    }
    Pilha *aux = *topo;
    char chr = aux->letra;
    *topo = aux->proximo; 
    free(aux);            
    return chr;
}

void main()
{
    char frase[40];
    
    Pilha *topo = NULL;
    int palindromo = 1;
    
    printf("Digite uma palavra ai:");
    scanf("%[^\n]", &frase);
    
    int tamanho = strlen(frase);
    int meio = tamanho / 2;
    
    for(int i=0;i<meio;i++){
        empilhar(&topo, tolower(frase[i]));
    }
    
    int init_second_middle;
    if(tamanho%2==0){
        init_second_middle = meio;
    }else{
        init_second_middle = meio+1;
    }
    
    for(int i = init_second_middle; i<tamanho;i++){
        char desempilha_Letra = desempilhar(&topo);
        if(tolower(frase[i]) !=desempilha_Letra){
            palindromo = 0;
            break;
        }
    }
    
    while(topo !=NULL){
        desempilhar(&topo);
    }
    
    if(palindromo){
        printf("A palavra \"%s\" eh palindromo\n", frase);
    } else printf("A palavra \"%s\" nao eh palindromo\n ", frase);

    
}
