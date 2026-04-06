/*
* Cifra.h
*/

#ifndef CIFRA_H
#define CIFRA_H

#include "Util.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct CIFRA *CIFRA;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

CIFRA criaCifra(string mensagem, string codigo, int tamanho);

void destroiCifra(CIFRA a);

void cifrar(CIFRA a);

string getCifrada(CIFRA a);

#endif /* CIFRA_H */