/*
 * Automovel.c
 */

#include "Automovel.h"

/*------------------------------------------*/
/* Constantes privadas */

#define HORAS_NUM_MINUTO	60

/*------------------------------------------*/
/* Tipo privado */

struct Automovel{
    string matricula;
    int minutosEntrada;
    int minutosSaida;
    int horasEstadia;
	// decidir o que colocar aqui
};

/*------------------------------------------*/
/* Funcoes privadas */
    static void calculaEstadia(Automovel a){
        a->horasEstadia = (a->minutosSaida - a->minutosEntrada)/HORAS_NUM_MINUTO;
        if((a->minutosSaida - a->minutosEntrada)%HORAS_NUM_MINUTO > 0){
            a->horasEstadia = a->horasEstadia + 1;
        }
    }

/*------------------------------------------*/
/* Funcoes publicas */

Automovel criaAutomovel(string mat){
    Automovel a = malloc(sizeof(struct Automovel));
    if (a == NULL){
        semMemoria();
    }

    a->matricula = criaString(mat);
    a->minutosEntrada = NAO_EXISTE;
    a->minutosSaida = NAO_EXISTE;
    a->horasEstadia = NAO_EXISTE;

    return a;
}

void destroiAutomovel(Automovel a) {
    free(a);
}

void registaEntradaAutomovel(Automovel a, int h, int m){
    a->minutosEntrada = h * HORAS_NUM_MINUTO + m;
}

void registaSaidaAutomovel(Automovel a, int h, int m){
    a->minutosSaida = h * HORAS_NUM_MINUTO + m;
}

string getMatricula(Automovel a){
    return (a->matricula);
}

int getEstadia(Automovel a){
    calculaEstadia(a);
    return a->horasEstadia;
}
