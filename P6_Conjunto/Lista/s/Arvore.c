/*
 * Arvore.c
 */

#include "Arvore.h"

/*------------------------------------------*/
/* Funcoes privadas */

static void debugArvoreAux(arvore a, string str, int tab){
	if (!vaziaArvore(a)){
		sprintf(str, "%*s", tab * 2, ""); str += strlen(str);
		sprintf(str, "%s\n", debug(a->elem)); str += strlen(str);
		debugArvoreAux(a->esq, str, tab+1); str += strlen(str);
		debugArvoreAux(a->dir, str, tab+1);
	}
}


static int vetorArvoreAux(arvore a, vetor v, int i){
	if (vaziaArvore(a))
		return i;
	else {
		v[i] = a->elem;
		int j = vetorArvoreAux(a->esq, v, i+1);
		return vetorArvoreAux(a->dir, v, j);
	}
}

static vetor vetorArvore(arvore a, int *n){
	*n = tamanhoArvore(a);
	vetor v = malloc(sizeof(obj) * *n);
	if (v == NULL) semMemoria();
	vetorArvoreAux(a, v, 0);
	return v;
}

/*------------------------------------------*/
/* Funcoes publicas */

arvore criaNoArvore(obj elem, arvore esq, arvore dir){
	arvore n = malloc(sizeof(struct noArvore));
	if (n == NULL) semMemoria();
	n->elem = elem;
	n->esq = esq;
	n->dir = dir;
	return n;
}

void destroiNoArvore(arvore a){
	free(a); // apenas o no' apontado
}

void destroiArvore(arvore a){
	destroiArvore(a->esq);
	destroiArvore(a->dir);
	destroiNoArvore(a);
}

void destroiTudoArvore(arvore a){
	destroiArvore(a->esq);
	destroiArvore(a->dir);
	destroiTudo(a->elem);
	destroiNoArvore(a);
}

string debugArvore(arvore a){
	string str = criaStringN(10000);
	debugArvoreAux(a, str, 1);
	return recriaString(str);
}

bool vaziaArvore(arvore a){
	return a == NULL;
}

int tamanhoArvore(arvore a){
	if (a == NULL)
		return 0;
	else
		return 1 + tamanhoArvore(a->esq) + tamanhoArvore(a->dir);
}

Iterador iteradorArvore(arvore a){
	int n;
	vetor v = vetorArvore(a, &n);
	Iterador it = criaIterador(v, n);
	destroiVetor(v);
	return it;
}

Iterador iteradorOrdenadoArvore(arvore a){
	int n;
	vetor v = vetorArvore(a, &n);
	Iterador it = criaOrdenadoIterador(v, n);
	destroiVetor(v);
	return it;
}



#include "Int.h"

static arvore criaIntsArvore(int n){
	if (n == 0)
		return NULL;
	else
		return criaNoArvore(criaInt(n), criaIntsArvore(n-1), criaIntsArvore(n-1));
}

void testeArvore(void){
	arvore a = criaIntsArvore(3);
	printf("tamanho %d\n", tamanhoArvore(a));
	printf("%s\n", debugArvore(a));
	int n;
	vetor v = vetorArvore(a, &n);
	printf("%s\n", debugVetor(v, n));
}

/*
tamanho 7
  3
    2
      1
      1
    2
      1
      1

[3 2 1 1 2 1 1]
*/

/* ENGLISH */

tree createNodeTree(obj elem, tree left, tree right){ return criaNoArvore(elem, left, right); }
void destroyNodeTree(tree t){ destroiNoArvore(t); }
void destroyTree(tree t){ destroiArvore(t); }
void destroyAllTree(tree t){ destroiTudoArvore(t); }
string debugTree(tree t){ return debugArvore(t); }
bool emptyTree(tree t){ return vaziaArvore(t); }
int sizeTree(tree t){ return tamanhoArvore(t); }
Iterator iteratorTree(tree t) { return iteradorArvore(t); }
Iterator sortedIteratorTree(tree t) { return iteradorOrdenadoArvore(t); }
void testTree(void){ testeArvore(); }
