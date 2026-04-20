/*
 * MainMundo.c
 */

#include "Mundo.h"
#include "Str.h"

#define MAX_LINHA 80

void mostra(string pais, string capital){
	printf("%s -> %s\n", pais, capital);
}

void interroga(Mundo m, string pais){
	char linha[MAX_LINHA];
	char capital[MAX_LINHA];
	printf("Nao conheço a capital de %s. Por favor, ensine-me: ", pais);
	if (fgets(linha, MAX_LINHA, stdin) == NULL
	|| sscanf(linha, "%s", capital) != 1) {
		printf("Capital invalida\n");
	}
	else {
		adicionaMundo(m, pais, capital);
		printf("Obrigado!\n");
	}
}

void cmdLista(Mundo m, string args){
	// FAZER
}

void cmdMenu(Mundo m, string args){
	printf("Menu:\n");
	printf("  C - capital\n");
	printf("  L - lista ordenada\n");
	printf("  ? - menu\n");
	printf("  T - terminar\n");
}

void cmdCapitalDe(Mundo m, string args){
	char pais[MAX_LINHA];
	if (sscanf(args,"%s",pais) != 1){
		printf("Dados invalidos\n");
		return;
	}
	string capital = qualCapitalMundo(m, pais);
	if (capital == NULL) {  // nao sabe!
		interroga(m, pais);
	}
	else {
		mostra(pais, capital);
	}
}

void inicializaMundo(Mundo m){
	adicionaMundo(m, "Portugal", "Lisboa");
	adicionaMundo(m, "Espanha", "Madrid");
	adicionaMundo(m, "Franca", "Paris");
}


char lerComando(string linha) {
	printf("> ");
	if (fgets(linha, MAX_LINHA, stdin) == NULL)
		linha[0] = 'T';
	return toupper(linha[0]);
}

void interpretador(Mundo m){
	char linha[MAX_LINHA], cmd;
	string args = linha + 2;
	do {
		cmd = lerComando(linha);
		switch (cmd){
			case 'L': cmdLista(m, args); break;
			case '?': cmdMenu(m, args); break;
			case 'C': cmdCapitalDe(m, args); break;
			case 'T': break;
			case '\n': break;
			default: printf("Comando invalido\n"); break;
		}
	} while (cmd != 'T');
	printf ("Volte sempre!\n");
}

int main(void){
	Mundo m = criaMundo();
	inicializaMundo(m);
	interpretador(m);
	destroiMundo(m);
	return 0;
}