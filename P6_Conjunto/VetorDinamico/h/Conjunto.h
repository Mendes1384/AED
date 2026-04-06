/*
 * Conjunto.h
 */

#ifndef CONJUNTO_H
#define CONJUNTO_H

#include "Iterador.h"

/***********************************************
	TAD Conjunto - Conjuntos genericos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Conjunto *Conjunto;
typedef Conjunto Set;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaConjunto - Cria um conjunto vazio.
Parametros: nada
Retorno: a conjunto criada
Precondicao: nada
***********************************************/
Conjunto criaConjunto(void);
Set createSet(void);

/***********************************************
destroiConjunto - Elimina um conjunto, mas nao os seus elementos.
Parametros: c - conjunto
Retorno: nada
Precondicao: c != NULL
***********************************************/
void destroiConjunto(Conjunto c);
void destroySet(Set c);

/***********************************************
destroiTudoConjunto - Elimina um conjunto, mais os seus elementos.
Parametros: c - conjunto
Retorno: nada
Precondicao: c != NULL
***********************************************/
void destroiTudoConjunto(Conjunto c);
void destroyAllSet(Set c);

/***********************************************
comparaConjunto - Compara dois comjuntos.
Parametros: a, b - conjuntos a comparar
Retorno: 0 se forem iguais; -1 se forem diferentes
Precondicao: a != NULL && b != NULL
***********************************************/
int comparaConjunto(Conjunto a, Conjunto b);
int compareSet(Set a, Set b);

/***********************************************
debugConjunto - Converte em string, para mostrar em situacoes de debug.
Parametros: c - conjunto
Retorno: a string criada
Precondicao: c != NULL
***********************************************/
string debugConjunto(Conjunto c);
string debugSet(Set c);

/***********************************************
vazioConjunto - Testa se o conjunto esta vazio.
Parametros: c - conjunto
Retorno: true - se conjunto vazio; false - caso contrario
Precondicao: c != NULL
***********************************************/
bool vazioConjunto(Conjunto c);
bool emptySet(Set c);

/***********************************************
tamanhoConjunto - Numero de elementos no conjunto.
Parametros: c - conjunto
Retorno: numero de elementos
Precondicao: c != NULL
***********************************************/
int tamanhoConjunto(Conjunto c);
int sizeSet(Set c);

/***********************************************
existeConjunto - Testa se elemento pertence ao conjunto.
Parametros:
	s - conjunto
	elem - elemento
Retorno: true - se pertence; false - caso contrario
Precondicao: s != NULL
***********************************************/
bool existeConjunto(Conjunto c, obj elem);
bool existsSet(Set c, obj elem);

/***********************************************
acrescentaConjunto - Acrescenta um elemento ao conjunto.
Parametros:
	c - conjunto
	elem - elemento
Retorno: nada
Precondicao: c != NULL && elem != NULL
***********************************************/
void acrescentaConjunto(Conjunto c, obj elem);
void addSet(Set c, obj elem);

/***********************************************
removeConjunto - Remove um elemento com conjunto
Parametros:
	c - conjunto
	elem - elemento a remover
Retorno: nada
Precondicao: c != NULL
***********************************************/
void removeConjunto(Conjunto c, obj elem);
void removeSet(Set c, obj elem);

/***********************************************
iteradorConjunto - Iterador para os elementos da conjunto.
Parametros: c - conjunto
Retorno: iterador dos elementos
Precondicao: c != NULL
***********************************************/
Iterador iteradorConjunto(Conjunto c);
Iterator iteratorSet(Set c);

/***********************************************
iteradorOrdenadoConjunto - Iterador ordenado para os elementos da conjunto.
Parametros: c - conjunto
Retorno: iterador dos elementos
Precondicao: c != NULL
***********************************************/
Iterador iteradorOrdenadoConjunto(Conjunto c);
Iterator sortedIteradorSet(Set c);

/***********************************************
subConjunto - Testa se um conjunto e' subconjunto de outro.
Parametros: a, b - conjuntos
Retorno: resultado booleano
Precondicao: a != NULL && b != NULL
***********************************************/
bool subConjunto(Conjunto a, Conjunto b);
bool subSet(Set a, Set b);

/***********************************************
uniaoConjunto - Uniao de conjuntos.
	Produz um conjunto novo e nao altera os argumentos.
Parametros: a, b - conjuntos
Retorno: novo conjunto
Precondicao: a != NULL && b != NULL
***********************************************/
Conjunto uniaoConjunto(Conjunto a, Conjunto b);
Set unionSet(Set a, Set b);

/***********************************************
intersecaoConjunto - Intersecao de conjuntos.
	Produz um conjunto novo e nao altera os argumentos.
Parametros: a, b - conjuntos
Retorno: novo conjunto
Precondicao: a != NULL && b != NULL
***********************************************/
Conjunto intersecaoConjunto(Conjunto a, Conjunto b);
Set intersectionSet(Set a, Set b);

/***********************************************
diferencaConjunto - Diferenca de conjuntos.
	Produz um conjunto novo e nao altera os argumentos.
Parametros: a, b - conjuntos
Retorno: novo conjunto
Precondicao: a != NULL && b != NULL
***********************************************/
Conjunto diferencaConjunto(Conjunto a, Conjunto b);
Set diferenceSet(Set a, Set b);

/***********************************************
testeConjunto - Alguns testes simples.
***********************************************/
void testeConjunto(void);
void testSet(void);

#endif /* CONJUNTO_H */