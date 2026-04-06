/*
 * ConjuntoLista.c
 */

#include "Conjunto.h"
#include "Lista.h"

/*------------------------------------------*/
/* Tipo privado */

struct Conjunto{
	Info info;
	lista elems;
};

/*------------------------------------------*/
/* Funcoes privadas */

// retorna no' com o elemento procurado, e tambem retorna o no' previo
static lista procuraConjunto(Conjunto c, obj elem, lista *prev){
	*prev = NULL;
	for (lista l = c->elems; l != NULL ; *prev = l, l = l->seg){
		if (compara(l->elem, elem) == 0)
			return l;
	}
	return NULL;
}

/*------------------------------------------*/
/* Funcoes publicas */

Conjunto criaConjunto(void){
	Conjunto c = malloc(sizeof(struct Conjunto));
	if (c == NULL) semMemoria();
	c->info = criaInfo("Conjunto", destroiConjunto, destroiTudoConjunto,
							comparaConjunto, NULL, debugConjunto);
	c->elems = criaLista();
	return c;
}


// COMPLETAR


#include "Int.h"

static Conjunto criaIntConjunto(int v[]){
	Conjunto c = criaConjunto();
	for (int i = 0; v[i] != -1; i++)
		acrescentaConjunto(c, criaInt(v[i]));
	return c;
}

static void mostraConjunto(string nome, Conjunto c){
	printf("%10s  =  %s\n", nome, debugConjunto(c));
}

static void mostraBool(string nome, bool b){
	printf("%10s  =  %s\n", nome, b?"true":"false");
}

void testeConjunto(void){
	printf("Testando Conjunto:\n");

	int va[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, -1};
	Conjunto a = criaIntConjunto(va);

	int vb[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, -1};
	Conjunto b = criaIntConjunto(vb);

	mostraConjunto("A", a);
	mostraConjunto("B", b);

	mostraConjunto("A + B", uniaoConjunto(a, b));
	mostraConjunto("A * B", intersecaoConjunto(a, b));
	mostraConjunto("A - B", diferencaConjunto(a, b));
	mostraConjunto("B - A", diferencaConjunto(b, a));

	mostraBool("A < B", subConjunto(a, b));
	mostraBool("B < A", subConjunto(a, b));
	mostraBool("A < A+B", subConjunto(a, uniaoConjunto(a, b)));
	mostraBool("A = B", comparaConjunto(a, b) == 0);
	mostraBool("A+B = B+A", comparaConjunto(uniaoConjunto(a, b), uniaoConjunto(b, a)) == 0);

	mostraConjunto("A", a);
	removeConjunto(a, criaInt(3));
	removeConjunto(a, criaInt(100));
	mostraConjunto("A-3-100", a);
}

/*
Testando Conjunto:
         A  =  <9 8 7 6 5 4 3 2 1 0>
         B  =  <19 17 15 13 11 9 7 5 3 1>
     A + B  =  <11 13 15 17 19 0 1 2 3 4 5 6 7 8 9>
     A * B  =  <1 3 5 7 9>
     A - B  =  <0 2 4 6 8>
     B - A  =  <11 13 15 17 19>
     A < B  =  false
     B < A  =  false
   A < A+B  =  true
     A = B  =  false
 A+B = B+A  =  true
         A  =  <9 8 7 6 5 4 3 2 1 0>
   A-3-100  =  <9 8 7 6 5 4 2 1 0>
*/

/* ENGLISH */

Set createSet(void) { return criaConjunto(); }
void destroySet(Set c) { destroiConjunto(c); }
void destroyAllSet(Set c) { destroiTudoConjunto(c); }
int compareSet(Set a, Set b) { return comparaConjunto(a, b); }
string debugSet(Set c) { return debugConjunto(c); }
bool emptySet(Set c) { return vazioConjunto(c); }
int sizeSet(Set c) { return tamanhoConjunto(c); }
bool existsSet(Set c, obj elem) { return existeConjunto(c, elem); }
void addSet(Set c, obj elem) { acrescentaConjunto(c, elem); }
void removeSet(Set c, obj elem) { removeConjunto(c, elem); }
Iterator iteratorSet(Set c) { return iteradorConjunto(c); }
Iterator sortedIteradorSet(Set c) { return iteradorOrdenadoConjunto(c); }
bool subSet(Set a, Set b) { return subConjunto(a, b); }
Set unionSet(Set a, Set b) { return uniaoConjunto(a, b); }
Set intersectionSet(Set a, Set b) { return intersecaoConjunto(a, b); }
Set diferenceSet(Set a, Set b) { return diferencaConjunto(a, b); }
void testSet(void) { testeConjunto(); }
