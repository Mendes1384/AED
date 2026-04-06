/*
 * Cifra.c
 */

#include "Cifra.h"

/*------------------------------------------*/
/* Constantes privadas */

    #define TAMANHO_MENSAGEM 256

/*------------------------------------------*/
/* Tipo privado */

struct CIFRA {

    string mensagem;
    string MenCifrada;
    int codigo;

};

/*------------------------------------------*/
/* Funcoes privadas */

static int calcularCodigoReal(int c){
    int temp;

    temp = c / 26;
    c = c - 26 * temp;

    return c;
}

static string contasCifra(CIFRA a){
    
    char temp[TAMANHO_MENSAGEM];
    int correcao;
    int i;
    int ch;

    for(i = 0; a->mensagem[i] != '\0'; i++){
        ch = a->mensagem[i];
        if(ch >= 'a' && ch <= 'z'){
            ch += a->codigo;
            if(ch > 'z'){
                correcao = ch - 'z' - 1;
                ch = 'a' + correcao;
            }
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch += a->codigo;
            if(ch > 'Z'){
                correcao = ch - 'Z' - 1;
                ch = 'A' + correcao;
            }
        }
        temp[i] = ch;
    }
    temp[i] = '\0';

    return criaString(temp);
}

/*------------------------------------------*/
/* Funcoes publicas */

CIFRA criaCifra(string m, int c){
    
    CIFRA a = malloc(sizeof(struct CIFRA));
    
    a->mensagem = criaString(m);
    a->codigo = calcularCodigoReal(c);
    return a;
}

void destroiCifra(CIFRA a){
    free(a);
}

void cifrar(CIFRA a){
    a->MenCifrada = contasCifra(a);
}

string getCifrada(CIFRA a){
    return a->MenCifrada;
}