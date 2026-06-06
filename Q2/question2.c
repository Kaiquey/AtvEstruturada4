#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

void limpeza(Pilha *topo){
    Pilha *aux;
    while(topo!=NULL){
        aux = topo;
        topo = topo->proximo;
        free(aux);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char frase[100];
    Pilha *topo = NULL; 
    int i=0;
    int flag = 1;
    printf("Digite a expressão matemática: ");
    scanf("%[^\n]", &frase);
        
    while(frase[i]!='\0'){
        if(frase[i]=='('){
            empilhar(&topo,'(');
        }else if(frase[i]==')'){
         if(topo==NULL)   {
             flag =0;
             break;
         }
         desempilhar(&topo);
        }
        i++;
    }
    
    if(topo!=NULL){
        flag = 0;
        limpeza(topo);
    }
    
    if(flag){
        printf("Correcto!\n");
        printf("O número de abrir e fechar parênteses é igual e eles estão bem posicionados!\n");
    }else{
        printf("Ai não... Erro na expressão\n");
        printf("Os parênteses estão errados ou não foi balanceado direito.\n");
    }
    
    return 0;
}