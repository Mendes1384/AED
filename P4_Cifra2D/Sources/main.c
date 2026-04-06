#include <stdio.h>
#include "Cifra.h"

#define MAX_MENSAGEM 256

void receberParametros(string codigo, int *linhas);
void receberMensagem(string mensagem, int linhas);
void enviarMensagem(CIFRA cifra);
void cifrarMensagem(CIFRA cifra);

int main(void){

    char codigo[MAX_MENSAGEM];
    char mensagem[MAX_MENSAGEM];
    int linhas;
    int tamanho;
    
    //do{

        receberParametros(codigo, &linhas);
        tamanho = strlen(codigo);
        //printf("%d\n", tamanho);

        receberMensagem(mensagem, linhas);

        CIFRA cifra = criaCifra(mensagem, codigo, tamanho);

        cifrarMensagem(cifra);

        enviarMensagem(cifra);
        destroiCifra(cifra);
    //}while(codigo != (-1));

    return 0;
}

void receberParametros(string codigo, int *linhas){
    printf("Codigo: ");
    scanf(" %s", codigo);
    printf("Linhas: ");
    scanf(" %d", linhas);
}

void receberMensagem(string mensagem, int linhas){
    
    int i;
    char tmp[MAX_MENSAGEM];
    string tmp2;
    
    printf("Texto: \n");
    
    for(i = 0; i < linhas; i++){
        getchar();
        scanf("%255[^\n]", tmp);
        
        tmp2 = tmp;
        while(*tmp2 != '\0'){
            *mensagem++ = *tmp2++;
        }
    }

    *mensagem = '\0';
}
void enviarMensagem(CIFRA cifra){
    printf("Texto cifrado: %s\n", getCifrada(cifra));
}

void cifrarMensagem(CIFRA cifra){
    cifrar(cifra);
}