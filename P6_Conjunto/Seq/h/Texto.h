/*
 * Texto.h
 */

#ifndef TEXTO_H
#define TEXTO_H

#include "Util.h"

/***********************************************
	TAD Textoing - Textoings representadas por objetos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Texto *Texto;
typedef Texto Text;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaTexto - Cria um objeto que representa um pedaço de texto (uma string).
Parametros: valor - o texto a representar
Retorno: o objeto criado
Precondicao: valor != NULL
***********************************************/
Texto criaTexto(string valor);
Texto createText(string value);

/***********************************************
destroiTexto - Elimina um objeto de tipo Texto.
Parametros: texto - objeto texto
Retorno: nada
Precondicao: texto != NULL
***********************************************/
void destroiTexto(Texto texto);
void destroyText(Text text);

/***********************************************
comparaTexto - Compara dois textos.
Parametros: texto1, text2 - objetos texto
Retorno: negativo, zero ou positivo
Precondicao: texto1 != NULL && text2 != NULL
***********************************************/
int comparaTexto(Texto texto1, Texto texto2);
int compareText(Text text1, Texto text2);

/***********************************************
dispersaoTexto - Funcao de dispersao dos textos.
Parametros: texto - objeto texto; dim - dimensao da tabela
Retorno: valor de dispersao
Precondicao: texto != NULL && dim > 0
***********************************************/
int dispersaoTexto(Texto texto, int dim);
int hashText(Texto text, int dim);

/***********************************************
debugTexto - Converte em string, para mostrar em situacoes de debug.
Parametros: texto - objeto texto
Retorno: a string criada
Precondicao: texto != NULL
***********************************************/
string debugTexto(Texto texto);
string debugText(Text text);

/***********************************************
valorTexto - Extrai a string guardada num objeto texto.
Parametros: texto - objeto texto
Retorno: a string guardada no objeto
Precondicao: texto != NULL
**********************************************/
string valorTexto(Texto texto);
string valueText(Text text);

/***********************************************
testeTexto - Alguns testes simples.
***********************************************/
void testeTexto(void);
void testText(void);

#endif /* TEXTO_H */
