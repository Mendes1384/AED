/*
 * Vetor.c
 */

#include "Vetor.h"

/*------------------------------------------*/
/* Funcoes privadas */

static void troca(obj *ob1, obj *ob2){
	obj aux = *ob1;
	*ob1 = *ob2;
	*ob2 = aux;
}

/*------------------------------------------*/
/* Funcoes publicas */

vetor copiaVetor(vetor v, int n){
	vetor original = v;
	vetor copia = malloc(sizeof(obj) * n);
	for (int i = 0 ; i < n ; i++){
		copia[i] = original[i];
	}
	return copia;
}

void destroiVetor(vetor v){
	free(v);
}

bool ordenadoVetor(vetor v, int n){
	for (int i = 0; i < n-1; i++){
		if (v[i] > v[i+1])
			return false;
	}
	return true;
}

// ordenacao por selecao (selection sort)
void ordenaVetor(vetor v, int n){
	for (int i=0; i < n-1; i++){
		int minIdx = i;	// regista indice do minimo ate' ao momento
		for (int j=i+1; j < n; j++){ // procura minimo em [i, n-1]
			if (compara(v[j], v[minIdx]) < 0)
				minIdx = j;
		}
		troca(&v[i], &v[minIdx]);
	}
}

bool homogeneoVetor(vetor v, int n){
	for (int i = 1 ; i < n ; i++){
		if (!mesmoTipo(v[0], v[i]))
			return false;
	}
	return true;
}

string debugVetor(vetor v, int n){
	string str = criaStringN(10000);
	strcat(str, "[") ;
	for (int i = 0; i < n; i++){
		strcat(str, debug(v[i]));
		if (i < n-1)
			strcat(str, " ");
	}
	strcat(str, "]");
	return recriaString(str);
}

/* ENGLISH */

vetor copyVector(vector v, int n){ return copiaVetor(v, n); }
void destroyVetor(vector v){ destroiVetor(v); }
bool sortedVector(vector v, int n){ return ordenadoVetor(v, n); }
void sortVector(vector v, int n){ return ordenaVetor(v, n); }
bool homogeneousVector(vector v, int n){ return homogeneoVetor(v, n); }
string debugVector(vector v, int n){ return debugVetor(v, n); }
