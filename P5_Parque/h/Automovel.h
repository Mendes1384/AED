/*
 * Automovel.h
 */

#ifndef AUTOMOVEL_H_
#define AUTOMOVEL_H_

#include "Util.h"
#include "Info.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct Automovel *Automovel;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaAutomovel - Cria um automovel.
Parametros:
	mat - matricula do automovel
Retorno: o automovel criado
Precondicao: mat != NULL
***********************************************/
Automovel criaAutomovel(string mat);

/***********************************************
destroiAutomovel - Elimina um automovel.
Parametros: a - automovel a eliminar
Retorno: nada
Precondicao: a != NULL
***********************************************/
void destroiAutomovel(Automovel a);

/***********************************************
registaEntradaAutomovel - Regista hora e minuto de entrada.
Parametros:
	a - automovel
	h - hora de entrada
	m - minuto de entrada
Retorno: nada
Precondicao: a != NULL && 0 <= h <= 24 && 0 <= m <= 60
***********************************************/
void registaEntradaAutomovel(Automovel a, int h, int m);

/***********************************************
registaSaidaAutomovel - Regista hora e minuto de saida.
Parametros:
	a - automovel
	h - hora de saida
	m - minuto de saida
Retorno: nada
Precondicao: a != NULL && 0 <= h <= 24 && 0 <= m <= 60
***********************************************/
void registaSaidaAutomovel(Automovel a, int h, int m);

/***********************************************
getMatricula - Retorna a matricula
Parametros:
    a - automovel
Returno: Matricula (string)
Precondição: a != NULL
***********************************************/

string getMatricula(Automovel a);

/***********************************************
getEstadia - Retorna o tempo de estadia
Parametros:
    a - automovel
Returno: Estadia (int)
Precondição: a != NULL
***********************************************/

int getEstadia(Automovel a);

/***********************************************
getMat - Retorna a matricula
Parametros:
    a - automovel
Returno: Matricula (string)
Precondição: a != NULL
***********************************************/

string getMat(Automovel a);

#endif /* AUTOMOVEL_H_ */
