/*
 * ConjuntoVetor.c
 */

#include "Conjunto.h"

/*------------------------------------------*/
/* Constantes privadas */

#define CAPACIDADE_INICIAL	4

/*------------------------------------------*/
/* Tipo privado */

struct Conjunto{
	Info info;
	vetor elems;	  // vetor dinamico
	int numElems;
	int capacidade;
};

/*------------------------------------------*/
/* Funcoes privadas */

static void asseguraCapacidade(Conjunto c){
	if (tamanhoConjunto(c) == c->capacidade){ // se conjunto cheio...
		int novaCapacidade = c->capacidade * 2; // ... entao duplica a capacidade
		c->elems = realloc(c->elems, sizeof(obj) * novaCapacidade);
		c->capacidade = novaCapacidade;
	}
}

/* Procura elemento elem e indica a sua posicao */
static int procuraConjunto(Conjunto c, obj elem){
	for (int i = 0; i < c->numElems; i++)
		if (compara(elem, c->elems[i]) == 0)
			return i;
	return NAO_EXISTE;
}

/*------------------------------------------*/
/* Funcoes publicas */

Conjunto criaConjunto(void){
	int cap = CAPACIDADE_INICIAL;
	Conjunto c = malloc(sizeof(struct Conjunto));
	if (c == NULL) semMemoria();
	c->info = criaInfo("Conjunto", destroiConjunto, destroiTudoConjunto,
							comparaConjunto, NULL, debugConjunto);
	c->elems = malloc(sizeof(obj) * cap);
	if (c->elems == NULL) semMemoria();
	c->numElems = 0;
	c->capacidade = cap;
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
         A  =  [0 1 2 3 4 5 6 7 8 9]
         B  =  [1 3 5 7 9 11 13 15 17 19]
     A + B  =  [0 1 2 3 4 5 6 7 8 9 11 13 15 17 19]
     A * B  =  [1 3 5 7 9]
     A - B  =  [0 2 4 6 8]
     B - A  =  [11 13 15 17 19]
     A < B  =  false
     B < A  =  false
   A < A+B  =  true
     A = B  =  false
 A+B = B+A  =  true
         A  =  [0 1 2 3 4 5 6 7 8 9]
   A-3-100  =  [0 1 2 9 4 5 6 7 8]
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
