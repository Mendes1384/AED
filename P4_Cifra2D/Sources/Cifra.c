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
    string codigo;
    int tamanhoCodigo;
};

/*------------------------------------------*/
/* Funcoes privadas */

/*static int calcularCodigoReal(long long int c){
    long long int temp;
    
    temp = c / 26;
    c = c - 26 * temp;
    printf("%lld\n", c);

    return c;
}*/

static string contasCifra(CIFRA a){
    
    char temp[TAMANHO_MENSAGEM];
    int correcao;
    int i;
    int j = 0;
    int ch;

    for(i = 0; a->mensagem[i] != '\0'; i++){
        ch = a->mensagem[i];

        if(ch >= 'a' && ch <= 'z'){
            ch += (a->codigo[j] - 48);
            if(ch > 'z'){
                correcao = ch - 'z' - 1;
                ch = 'a' + correcao;
            }
        }
        /*else if(ch >= 'A' && ch <= 'Z'){
            ch += a->codigo;
            if(ch > 'Z'){
                correcao = ch - 'Z' - 1;
                ch = 'A' + correcao;
            }
        }*/
        j++;
        
        if(j == a->tamanhoCodigo)
            j = 0;
        temp[i] = ch;
    }
    temp[i] = '\0';

    return criaString(temp);
}

/*------------------------------------------*/
/* Funcoes publicas */

CIFRA criaCifra(string mensagem, string codigo, int tamanho){
    
    CIFRA a = malloc(sizeof(struct CIFRA));
    
    a->mensagem = criaString(mensagem);
    a->codigo = criaString(codigo);
    a->tamanhoCodigo = tamanho;
    a->MenCifrada = NULL;
    return a;
}

void destroiCifra(CIFRA a){
    destroiString(a->mensagem);
    destroiString(a->MenCifrada); 
    free(a);
}

void cifrar(CIFRA a){
    a->MenCifrada = contasCifra(a);
}

string getCifrada(CIFRA a){
    return a->MenCifrada;
}