/*
 * ConjuntoSequencia.c
 */

#include "Conjunto.h"
#include "Sequencia.h"
#include "Int.h"


/*------------------------------------------*/
/* Tipo privado */

struct Conjunto{
	Info info;
	Sequencia elems;
};

/*------------------------------------------*/
/* Funcoes privadas */

static int procuraConjunto(Conjunto c, obj elem){
	for (int i = 0; i < tamanhoSequencia(c->elems); i++)
		if (compara(elem, elementoSequencia(c->elems, i)) == 0)
			return i;
	return NAO_EXISTE;
}
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
/*------------------------------------------*/
/* Funcoes publicas */

Conjunto criaConjunto(void){
	Conjunto c = malloc(sizeof(struct Conjunto));
	if (c == NULL) semMemoria();
	c->info = criaInfo("Conjunto", destroiConjunto, destroiTudoConjunto,
							comparaConjunto, NULL, debugConjunto);
	c->elems = criaSequencia();
	return c;
}

/*Conjunto criaIntConjunto(int v[]){
	Conjunto c = criaConjunto();
	Sequencia s = criaSequencia(); 
	int tam = 0, i = 0;
	
	while(v[i] != -1){
		Int num = criaInt(v[i++]);
		acrescentaSequencia(s, num);
	}
	c->elems = s;

	return c;
}

void mostraConjunto(Conjunto c){
	int tam = tamanhoSequencia(c->elems);
	for(int i = 0; i < tam; i++)
		printf("%d ", elementoSequencia(c->elems, i));

	printf("\n");
}*/

Conjunto uniaoConjunto(Conjunto a, Conjunto b){
	vetor v = criaSequencia();
	int tam = tamanhoSequencia(a->elems);

	for(int i = 0; i < tam; i++){
		acrescentaSequencia(v, elementoSequencia(a->elems, i));
	}

	int tam2 = tamanhoSequencia(b->elems);

	for(int i = 0; i < tam2; i++){
		int elm = procuraConjunto(a, elementoSequencia(b->elems, i));
		if(elm == -1)
			acrescentaSequencia(v, elementoSequencia(b->elems, i));		
	}

	ordenaVetor(v, tamanhoSequencia(v));

	Conjunto c = criaIntConjunto(v);

	return c;
}


// COMPLETAR




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
         A  =  <0 1 2 3 4 5 6 7 8 9>
         B  =  <1 3 5 7 9 11 13 15 17 19>
     A + B  =  <0 1 2 3 4 5 6 7 8 9 11 13 15 17 19>
     A * B  =  <1 3 5 7 9>
     A - B  =  <0 2 4 6 8>
     B - A  =  <11 13 15 17 19>
     A < B  =  false
     B < A  =  false
   A < A+B  =  true
     A = B  =  false
 A+B = B+A  =  true
         A  =  <0 1 2 3 4 5 6 7 8 9>
   A-3-100  =  <0 1 2 4 5 6 7 8 9>
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
