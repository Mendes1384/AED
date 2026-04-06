/*
 * Atleta.h
 */

#ifndef ATLETA_H_
#define ATLETA_H_

#include "Info.h"
#include "Util.h"
#include <stdbool.h>

#define NAO_TERMINOU -1
#define MASC false
#define FEM true
#define NUMERO_INICIAL 1001

/*------------------------------------------*/
/* Tipo publico */

typedef struct Atleta *Atleta;
typedef bool genero;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaAtleta - Cria um atleta.
Parametros:
    nAtleta - Numero do Atleta
Retorno: O atleta criado
Precondicao: nome != NULL && pais != NULL && recorde > 0 && gen == (MASC || FEM)
***********************************************/
Atleta criaAtleta(string nome, string pais, int recorde, genero gen);

/***********************************************
destroiAtleta - Destroi um atleta.
Parametros:
    a - O Atleta a destruir
Retorno: NULL
Precondicao: Atleta != NULL
***********************************************/
void destroiAtleta(Atleta a);

/***********************************************
atribuiTempoAtleta - Atribui um tempo ao atleta.
Parametros:
    a - O Atleta
    tempo - O tempo a atribuir
Retorno: -
Precondicao: a != NULL
***********************************************/
void atribuiTempoAtleta(Atleta a, int tempo);

/***********************************************
numeroAtleta - Retorna o numero do atleta.
Parametros:
    a - O Atleta
Retorno: O numero do atleta
Precondicao: a != NULL
***********************************************/
int numeroAtleta(Atleta a);

/***********************************************
nomeAtleta - Retorna o nome do atleta.
Parametros:
    a - O Atleta
Retorno: O nome do atleta
Precondicao: a != NULL
***********************************************/
string nomeAtleta(Atleta a);

/***********************************************
paisAtleta - Retorna o pais do atleta.
Parametros:
    a - O Atleta
Retorno: O pais do atleta
Precondicao: a != NULL
***********************************************/
string paisAtleta(Atleta a);

/***********************************************
generoAtleta - Retorna o genero do atleta.
Parametros:
    a - O Atleta
Retorno: O genero do atleta
Precondicao: a != NULL
***********************************************/
genero generoAtleta(Atleta a);

/***********************************************
tempoAtleta - Retorna o tempo do atleta.
Parametros:
    a - O Atleta
Retorno: O tempo do atleta na maratona
Precondicao: a != NULL
***********************************************/
int tempoAtleta(Atleta a);

/***********************************************
recordeAtleta - Retorna o recorde do atleta.
Parametros:
    a - O Atleta
Retorno: O recorde do atleta
Precondicao: a != NULL
***********************************************/
int recordeAtleta(Atleta a);

/***********************************************
terminouAtleta - Verifica se o atleta terminou.
Parametros:
    a - O Atleta
Retorno: true se terminou, false caso contrario
Precondicao: a != NULL
***********************************************/
bool terminouAtleta(Atleta a);

#endif /* ATLETA_H_ */