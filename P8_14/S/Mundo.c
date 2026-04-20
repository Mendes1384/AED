/*
 * Mundo.c
 */

#include "Mundo.h"
// FAZER

#define QUAN_PAISES 200

struct Pais{
    Info info;
    string nome;
    string capital;
};

struct Mundo{
	Info info;
    Pais paises[QUAN_PAISES];
	// FAZER
};

Mundo criaMundo(void){
	Mundo m = malloc(sizeof(struct Mundo));
	if (m == NULL) semMemoria();
	m->info = criaInfo("Mundo", destroiMundo, destroiMundo, NULL, NULL, NULL);
	// FAZER
	return m;
}

void destroiMundo(Mundo m){
	destroiTudoDicionario(m->paises); // Nao ha' elementos a perservar... são so' strings.
	free(m);
}

void adicionaMundo(Mundo m, string pais, string capital){
	// FAZER
}

string qualCapitalMundo(Mundo m, string pais){
	// FAZER
	return "";
}

Iterador iteradorMundo(Mundo m){
	// FAZER
	return NULL;
}
