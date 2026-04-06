/*
 * MainAutomovel.c
 */

#include "Automovel.h"

#define MAX_MAT		20	// tamanho maximo da matricula

void lerMatricula(string mat){
    printf("Matricula: ");
    scanf(" %s", mat);
}

void lerEntrada(int *h, int *m){
    printf("Entrada (hh:mm): ");
    scanf(" %d:%d", h, m);
}

void lerSaida(int *h, int *m){
    printf("Saida (hh:mm): ");
    scanf(" %d:%d", h, m);
}

void apresentaEstadia(Automovel t){
    //int m, e;
    //m = getMatricula(t);
    //e = getEstadia(t);
    printf("O automovel com matricula %s teve uma estadia de %d horas\n", getMatricula(t), getEstadia(t));
}

int main(void) {
	char matricula[MAX_MAT];
	lerMatricula(matricula);
	Automovel meuAutomovel = criaAutomovel(matricula);

	int hora, minutos;
	lerEntrada(&hora, &minutos);
	registaEntradaAutomovel(meuAutomovel, hora, minutos);

	lerSaida(&hora, &minutos);
	registaSaidaAutomovel(meuAutomovel, hora, minutos);

	apresentaEstadia(meuAutomovel);

	destroiAutomovel(meuAutomovel);
	return 0;
}
