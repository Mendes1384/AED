/*
 * MainAntesDepoisLista.c
 */

#include "Lista.h"

/***********************************************
existeLista - Testa se objeto ocorre na lista.
Parametros: l - lista; a - objeto
Retorno: true - se ocorre; false - se nao
Precondicao: a != NULL
***********************************************/
bool existeLista(lista l, obj a){
	// FAZER
	return false;
}

/***********************************************
depoisLista - Acrescenta b depois de cada ocorrencia de a.
Parametros: l - lista; a, b - objetos
Retorno: lista modificada
Precondicao: a != NULL && b != NULL
***********************************************/
lista depoisLista(lista l, obj a, obj b){
	lista res = l;
	// FAZER
	return res;
}

/***********************************************
antesLista - Acrescenta a antes de cada ocorrencia de b.
Parametros: l - lista; a, b - objetos
Retorno: lista modificada
Precondicao: a != NULL && b != NULL
***********************************************/
lista antesLista(lista l, obj a, obj b){
	lista res = l;
	// FAZER
	return res;
}


#include <Int.h>

static lista criaIntervalo(int a, int b){
	if (a > b)	// intervalo vazio
		return NULL;
	lista l = criaNo(criaInt(a), NULL), ult = l;	// cria 1. no' fora do ciclo, com ult a apontar para o 1. no'
	for (int i = a + 1 ; i <= b ; i++){
		lista novo = criaNo(criaInt(i), NULL);	// novo no', com o valor correto
		ult->seg = novo;	// acrescenta no final (a seguir a ult)
		ult = novo;		// o novo no' passa a ser o ultimo
	}
	return l;
}

void teste(void){
	lista l = criaIntervalo(2, 12);

	printf("l = %s\n", textoLista(l));

	printf("\n");

	printf("existe(l,5) = %d\n", existeLista(l, criaInt(5)));
	printf("existe(l,0) = %d\n", existeLista(l, criaInt(0)));

	printf("\n");

	printf("depois(l,5,55) = ");
	l = depoisLista(l, criaInt(5), criaInt(55));
	printf("%s\n", textoLista(l));

	printf("depois(l,5,55) = ");
	l = depoisLista(l, criaInt(5), criaInt(55));
	printf("%s\n", textoLista(l));

	printf("depois(l,55,55) = ");
	l = depoisLista(l, criaInt(55), criaInt(55));
	printf("%s\n", textoLista(l));

	printf("depois(l,12,13) = ");
	l = depoisLista(l, criaInt(12), criaInt(13));
	printf("%s\n", textoLista(l));

	printf("\n");

	printf("antes(l,77,7) = ");
	l = antesLista(l, criaInt(77), criaInt(7));
	printf("%s\n", textoLista(l));

	printf("antes(l,77,7) = ");
	l = antesLista(l, criaInt(77), criaInt(7));
	printf("%s\n", textoLista(l));

	printf("antes(l,77,77) = ");
	l = antesLista(l, criaInt(77), criaInt(77));
	printf("%s\n", textoLista(l));

	printf("antes(l,22,2) = ");
	l = antesLista(l, criaInt(22), criaInt(2));
	printf("%s\n", textoLista(l));
}

/* OUTPUT ESPERADO:

l = <2 3 4 5 6 7 8 9 10 11 12>

existe(l,5) = 1
existe(l,0) = 0

depois(l,5,55) = <2 3 4 5 55 6 7 8 9 10 11 12>
depois(l,5,55) = <2 3 4 5 55 55 6 7 8 9 10 11 12>
depois(l,55,55) = <2 3 4 5 55 55 55 55 6 7 8 9 10 11 12>
depois(l,12,13) = <2 3 4 5 55 55 55 55 6 7 8 9 10 11 12 13>

antes(l,77,7) = <2 3 4 5 55 55 55 55 6 77 7 8 9 10 11 12 13>
antes(l,77,7) = <2 3 4 5 55 55 55 55 6 77 77 7 8 9 10 11 12 13>
antes(l,77,77) = <2 3 4 5 55 55 55 55 6 77 77 77 77 7 8 9 10 11 12 13>
antes(l,22,2) = <22 2 3 4 5 55 55 55 55 6 77 77 77 77 7 8 9 10 11 12 13>
*/

int main(void){
	teste();
	return 0;
}