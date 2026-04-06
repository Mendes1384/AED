/*
 * Parque.c
 */

#include <string.h>
#include "Parque.h"

#define MAX_OCUPACAO 256
#define NAO_EXISTE (-1)

/*------------------------------------------*/
/* Constantes privadas */

/*------------------------------------------*/
/* Tipo privado */

struct Parque {
    Automovel *a;
    int ocupacaoReal;
    int ocupacao;
    double caixa;
    int capacidade;
	// decidir o que colocar aqui
};

/*------------------------------------------*/
/* Funcoes privadas */

static int getI(Parque p, string mat){
    int i;
    
    for(i = 0; i < p->ocupacao; i++){
        if(strcmp(mat, getMat(p->a[i])) == 0){
            return i;
        }
    }

    return (-1);
}

static void obterOcupacaoReal(Parque p){
    int i;

    p->ocupacaoReal = p->ocupacao;

    for(i = 0; i < p->ocupacao; i++){
        if(strcmp("NAO_EXISTE", getMat(p->a[i])) == 0){
            p->ocupacaoReal--;
        }
    }
}

static double calculaPreco(int estadia){
    double preco;

    if(estadia <= 1){
        preco = 1.5;
    }
    else if(estadia <= 3){
        preco = 1.5 + 1 * (estadia - 1);
    }
    else{
        preco = 1.5 + 1 + 1 + 0.75*(estadia - 3);
    }

    return preco;
}

static void aumentarCapacidade(Parque p) {
    int i;
    p->capacidade *= 2;
    Automovel *novo = malloc(p->capacidade * sizeof(Automovel));

    if (novo == NULL)
        semMemoria();

    for (i = 0; i < p->ocupacao; i++)
        novo[i] = p->a[i];

    free(p->a);
    p->a = novo;
}
 
/*------------------------------------------*/
/* Funcoes publicas */

Parque criaParque (void){

    Parque p = malloc(sizeof(struct Parque));

    if(p == NULL){
        semMemoria();
    }

    p->a = malloc(MAX_OCUPACAO * sizeof(Automovel));
    p->ocupacao = 0;
    p->capacidade = MAX_OCUPACAO;
    p->caixa = 0;
    
    return p;
}

int ocupacaoParque(Parque p){

    obterOcupacaoReal(p);
    return p->ocupacaoReal;
}

bool existeAutomovelParque(Parque p, string mat){
    int i;
    
    i = getI(p, mat);

    if(i == -1){
        return false;
    }

    return true;
}

bool entradaAutomovelParque(Parque p, string mat, int horas, int minutos){
    
    int i;

    i = getI(p, mat);

    if(i != (-1)){
        return false;
    }

    if(p->ocupacao == p->capacidade){
        aumentarCapacidade(p);
    }

    Automovel automovel = criaAutomovel(mat);

    registaEntradaAutomovel(automovel, horas, minutos);

    p->a[p->ocupacao++] = automovel;
    return true;
}

double saidaAutomovelParque(Parque p, string mat, int horas, int minutos){
    int estadia;
    int carro;
    double preco;
    string nao_existe = "NAO_EXISTE";

    carro = getI(p, mat);

    registaSaidaAutomovel(p->a[carro], horas, minutos);

    estadia = getEstadia(p->a[carro]);

    preco = calculaPreco(estadia);

    p->caixa += preco;

    Automovel a = criaAutomovel(nao_existe);

    p->a[carro] = a;

    return preco;
}

double caixaParque (Parque p){
    return p->caixa;
}

Automovel getAuto(Parque p, int i){
    return p->a[i];
}

int getOcupacao(Parque p){
    return p->ocupacao;
}

void destroiParque(Parque p){
    free(p);
}

void destroiTudoParque(Parque p){
    int i;

    free(p->a);
    free(p);
}