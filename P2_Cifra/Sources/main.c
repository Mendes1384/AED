#include <stdio.h>
#include "Cifra.h"

#define MAX_MENSAGEM 256

void receberCodigo(int *codigo);
void receberMensagem(string mensagem);
void enviarMensagem(CIFRA cifra);
void cifrarMensagem(CIFRA cifra);

int main(void){

    int codigo;
    char mensagem[MAX_MENSAGEM];
    
    while(1){

        receberCodigo(&codigo);
        receberMensagem(mensagem);

        CIFRA cifra = criaCifra(mensagem, codigo);

        cifrarMensagem(cifra);

        enviarMensagem(cifra);
        destroiCifra(cifra);
    }

    return 0;
}

void receberCodigo(int *codigo){
    printf("Codigo: ");
    scanf(" %d", codigo);
}

void receberMensagem(string mensagem){
    printf("Texto: ");
    scanf(" %s", mensagem);
}

void enviarMensagem(CIFRA cifra){
    printf("Texto cifrado: %s\n", getCifrada(cifra));
}

void cifrarMensagem(CIFRA cifra){
    cifrar(cifra);
}