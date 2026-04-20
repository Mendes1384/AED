/*
 * Mundo.h
 */

#ifndef MUNDO_H_
#define MUNDO_H_

#include "Iterador.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct Mundo *Mundo;

/*	Um objeto de tipo Mundo representa uma
	base de dados com correspondencias entre
	paises e capitais.
*/

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaMundo - Cria um mundo.
Parametros: nada
Retorno: o mundo criado
Precondicao: nada
***********************************************/
Mundo criaMundo(void);

/***********************************************
destroiMundo - Elimina um mundo.
Parametros: m - mundo
Retorno: nada
Precondicao: m != NULL
***********************************************/
void destroiMundo(Mundo m);

/***********************************************
adicionaMundo - Adiciona a um mundo uma correspondencia entre pais e capital.
Parametros: m - mundo; pais - pais; capital - capital
Retorno: nada
Precondicao: m != NULL && pais != NULL && capital != NULL
		&& qualCapitalMundo(m, pais) == NULL
***********************************************/
void adicionaMundo(Mundo m, string pais, string capital);

/***********************************************
qualCapitalMundo - Determina a capital dum pais.
Parametros: m - mundo; pais - pais
Retorno: capital - se pais conhecido; NULL - caso contrario
Precondicao: m != NULL && pais != NULL
***********************************************/
string qualCapitalMundo(Mundo m, string pais);

/***********************************************
iteradorMundo - Iterador de paises.
Parametros: m - mundo
Retorno: iterador de paises
Precondicao: m != NULL
***********************************************/
Iterador iteradorMundo(Mundo m);

#endif /* MUNDO_H_ */