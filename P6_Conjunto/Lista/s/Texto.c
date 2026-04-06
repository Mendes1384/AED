/*
 * Texto.c
 */

#include "Texto.h"
#include "Info.h"

/*------------------------------------------*/
/* Tipo privado */

struct Texto {
	Info info;
	string valor;
};

/*------------------------------------------*/
/* Funcoes publicas */

Texto criaTexto(string valor){
	Texto texto = malloc(sizeof(struct Texto));
	if (texto == NULL) semMemoria();
	texto->info = criaInfo("Texto", destroiTexto, destroiTexto,
				comparaTexto, dispersaoTexto, debugTexto);
	texto->valor = criaString(valor);
	return texto;
}

void destroiTexto(Texto texto){
	destroiString(texto->valor);
	free(texto);
}

int comparaTexto(Texto texto1, Texto texto2){
	string s1 = valorTexto(texto1);
	string s2 = valorTexto(texto2);
	return strcmp(s1, s2);
}

/* djb2 function by dan bernstein */
int dispersaoTexto(Texto texto, int dim){
	string s = valorTexto(texto);
	unsigned long hash = 5381;
	int c;
	while ((c = (unsigned int)*s++) != '\0')
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash % dim;
}

string debugTexto(Texto texto){
	return texto->valor;
}

string valorTexto(Texto texto){
	return texto->valor;
}

void testeTexto(void){
	printf("Testando Texto:\n");
	Texto texto0 = criaTexto("05");
	for (int i = 0 ; i < 10 ; i++){
		char a[100];
		sprintf(a, "%02d", i);
		Texto texto = criaTexto(a);
		printf("(%s,%d,%d)\n",
			debugTexto(texto),
			comparaTexto(texto, texto0),
			dispersaoTexto(texto, 100)
		);
		destroiTexto(texto);
	}
	destroiTexto(texto0);
	printf("\n");
}

/*
Testando Texto:
(00,-5,41)
(01,-4,42)
(02,-3,43)
(03,-2,44)
(04,-1,45)
(05,0,46)
(06,1,47)
(07,2,48)
(08,3,49)
(09,4,50)
*/

/* ENGLISH */

Texto createText(string value){ return criaTexto(value); }
void destroyText(Text text){ destroiTexto(text); }
int compareText(Text text1, Texto text2){ return comparaTexto(text1, text2); }
int hashText(Texto text, int dim){ return dispersaoTexto(text, dim); }
string debugText(Text text){ return debugTexto(text); }
string valueText(Text text){ return valorTexto(text); }
void testText(void){ testeTexto(); }
