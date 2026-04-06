/*
 *  Maratona.h
 */

#ifndef MARATONA_H_ 
#define MARATONA_H_

#include "Atleta.h"
#include "Sequencia.h"
#include "Iterador.h"

/*------------------------------------------*/
/* Tipo publico */

typedef struct Maratona *Maratona;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaMaratona - Cria uma Maratona.
Parametros:
    designacao - nome de maratona
Retorno: A matatona criada
Precondicao: designacao != NULL 
***********************************************/
Maratona criaMaratona(string designacao);


void registaAtletaMaratona(Maratona m, Atleta a);

int quantosRecordistasMaratona(Maratona m);

Atleta vencedorMasculinoMaratona(Maratona m);

#endif /* MARATONA_H_ */