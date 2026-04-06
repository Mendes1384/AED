/*
 * Vetor.h
 */

#ifndef VETOR_H
#define VETOR_H

#include "Util.h"
#include "Info.h"

/***********************************************
	Modulo Vector - Vetores genericos (nao e' TAD)

Este modulo oferece algumas funcoes uteis
para vetores de objetos. Podia incluir mais
funcoes uteis como,'criaVetor', 'destroiVetor',
'cresceVetor', etc. Contudo essas funcoes nao foram
criadas para os alunos serem obrigados a treinar a
manipulacao direta de vetores, nomeadamente usando
diretamente 'malloc' e 'realloc'.
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef obj *vetor;
typedef vetor vector;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
copiaVetor - Duplica um vetor de objetos.
Parametros:
	v - vetor a copiar
	n - numero de objetos no vetor
Retorno: copia do vetor
Precondicao: v != NULL && n >= 0
***********************************************/
vetor copiaVetor(vetor v, int n);
vetor copyVector(vector v, int n);

/***********************************************
destroiVetor - Elimina um vetor de objetos.
Parametros: v - vetor a eliminar
Retorno: nada
Precondicao: v != NULL
***********************************************/
void destroiVetor(vetor v);
void destroyVetor(vector v);

/***********************************************
ordenadoVetor - Testa se vetor de objetos esta' ordenado.
Parametros:
	v - vetor a testar
	n - numero de objetos no vetor
Retorno: true - se estiver ordenado; false - caso contrário
Precondicao: v != NULL && n >= 0
***********************************************/
bool ordenadoVetor(vetor v, int n);
bool sortedVector(vector v, int n);

/***********************************************
ordenaVetor - Ordena um vetor de objetos.
Parametros:
	v - vetor a ordenar
	n - numero de objetos no vetor
Retorno: nada
Precondicao: v != NULL && n >= 0
***********************************************/
void ordenaVetor(vetor v, int n);
void sortVector(vector v, int n);

/***********************************************
homogeneoVetor - Testa se todos os objetos no vetor sao do mesmo tipo.
Parametros:
	v - vetor a testar
	n - numero de objetos no vetor
Retorno: true - se homogeneo; false - caso contrario
Precondicao: v != NULL && n >= 0
***********************************************/
bool homogeneoVetor(vetor v, int n);
bool homogeneousVector(vector v, int n);

/***********************************************
debugVetor - Converte em string, para mostrar em situacoes de debug.
Parametros:
	v - vetor a mostrar
	n - numero de objetos no vetor
Retorno: a string criada
Precondicao: v != NULL && n >= 0
***********************************************/
string debugVetor(vetor v, int n);
string debugVector(vector v, int n);

#endif /* VETOR */
