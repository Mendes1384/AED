/*
 * Parque.h
 */

#ifndef PARQUE_H_
#define PARQUE_H_

#include "Automovel.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct Parque *Parque;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaParque - Cria um parque.
Parametros: nada
Retorno: o parque criado
Precondicao: nada
***********************************************/
Parque criaParque(void);

/***********************************************
destroiParque - Elimina um parque, mas nao os automoveis.
Parametros: p - parque a apagar
Retorno: nada
Precondicao: t != NULL
***********************************************/
void destroiParque(Parque p);

/***********************************************
destroiTudoParque - Elimina um parque incluindo os automoveis.
Parametros: p - parque a apagar
Retorno: nada
Precondicao: t != NULL
***********************************************/
void destroiTudoParque(Parque p);

/***********************************************
existeAutomovelParque - Verifica se uma matricula ocorre no parque.
Parametros:
	p - parque
	mat - matricula
Retorno: true - se matricula ocorre; false - caso contrario
Precondicao: p != NULL && mat != NULL
***********************************************/
bool existeAutomovelParque(Parque p, string mat);

/***********************************************
entradaAutomovelParque - Adiciona um novo automovel ao parque.
Parametros:
	p - parque
	mat - matricula
	horas, minutos - tempo de entrada
Retorno: true - se entrada com sucesso; false - caso contrario
Precondicao: p != NULL && mat != NULL
		&& 0 <= horas < 24 && 0 <= minutos < 60
***********************************************/
bool entradaAutomovelParque(Parque p, string mat, int horas, int minutos);

/***********************************************
saidaAutomovelParque - Determina o preco a pagar e destroi o automovel.
Parametros:
	p - parque
	mat - matricula do automovel a sair
	horas, minutos  - tempo de saida
Retorno: valor a pagar
Precondicao: p != NULL && mat != NULL
		&& 0 <= horas < 24 && 0 <= minutos < 60
		&& existeAutomovelParque(p, mat)
***********************************************/
double saidaAutomovelParque(Parque p, string mat, int horas, int minutos);

/***********************************************
ocupacaoParque - Numero de automoveis no saidaAutomovelParque(Parque p, string mat, int horas, int minutos);parque.
Parametros: p - parque
Retorno: numero de tickets
Precondicao: p != NULL
***********************************************/
int ocupacaoParque(Parque p);

/***********************************************
caixaParque - Valor em caixa no parque.
Parametros: p -  parque
Retorno: dinheiro em caixa
Precondicao: p != NULL
***********************************************/
double caixaParque(Parque p);

/***********************************************
posParque - Permite percorrer todos os automoveis do parque atraves dum indice.
	No futuro, usaremos um iterador para cumprir o mesmo objetivo.
Parametros:
	p - parque
	idx - indice
Retorno: um automovel
Precondicao: p != NULL && 0 <= i < ocupacaoParque(p)
***********************************************/
Automovel posParque(Parque p, int idx);

/***********************************************
getAuto - Retorna um automovel de indice i.
Parametros:
	p - parque
	i - indice
Retorno: um automovel
Precondicao: p != NULL && 0 <= i < ocupacaoParque(p)
***********************************************/
Automovel getAuto(Parque p, int i);

/***********************************************
getAuto - Retorna a ocupacao.
Parametros: NULL
Retorno: NULL
Precondicao: Nenhuma.
***********************************************/
int getOcupacao(Parque p);

#endif /* PARQUE_H_ */