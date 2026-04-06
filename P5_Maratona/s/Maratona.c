/*
 * Maratona.c
 */

#include "Atleta.h"
#include "Maratona.h"

#define CAP_MASC 150

/*------------------------------------------*/
/* Constantes privadas */

/*------------------------------------------*/
/* Tipo privado */

struct Maratona{
    Info info;
    string designacao;
    Sequencia fem;
    Atleta masc[CAP_MASC];
    int numMasc;
}

/*------------------------------------------*/
/* Funcoes privadas */

static void destroiTudoMaratona(Maratona m){
    int i;

    //destroiInfo(m->info);
    destroiString(m->designacao);
    destroiSequencia(m->fem);
    for(i = 0; i < m->numMasc; i++)
        destroiAtleta(m->masc[i]);
    
    free(m);
}

/*------------------------------------------*/
/* Funcoes publicas */

Maratona criaMaratona(string designacao){
    Maratona m = malloc(sizeof(struct Maratona));

    m->info = criaInfo("Maratona", NULL, destroiTudoMaratona, NULL, NULL, NULL);
    m->designacao = criaString(designacao);
    m->fem = criaSequencia();
    m->numMasc = 0;

    return m;
}

void registaAtletaMaratona(Maratona m, Atleta a){
    if(a->g == FEM)
        insereSequencia(Sequencia m->fem, a, 0);
    else
        if (m->numMasc < CAP_MASC)
            m->masc[m->numMasc++] = a;
}

int quantosRecordistasMaratona(Maratona m){
    int tam = tamanhoSequencia(m->fem);
    int recordistas = 0;
    for(int i = 0; i < tam; i++){
        Atleta a = elementoSequencia(m->fem, i);
        if(a->tempo != NAO_TERMINOU && a->recorde > a->tempo)
            recordistas++;
    }

    tam = m->numMasc;
    for(int i = 0; i < tam; i++){
        if(a->tempo != NAO_TERMINOU && m->masc[i]->recorde > m->masc[i]->tempo)
            recordistas++
    }

    return recordistas;
}

Atleta vencedorMasculinoMaratona(Maratona m){
    Atleta vencedor;
    vencedor->tempo = (-1);

    for(int i = 0; i < m->numMasc; i++){
        if(vencedor->tempo > m->masc[i]->tempo){
            
        }
    }
}

Iterador iteradorRecordistasFemininasMaratona(Maratona m){
    int tamanhoVetor = tamanhoSequencia(m->fem);
    int nAtletas = 0;

    vetor atletas = malloc(sizeof(Atleta)*tamanhoVetor);

    for(int i = 0; i < tamanhoSequencia(m->fem); i++){
        Atleta f = elementoSequencia(m->fem, i);
        
        if(tempoAtleta(f) != NAO_TERMINOU && tempoAtleta(f) < recordeAtleta(f))
            atletas[nAtletas++] = f;
    }

    return criaIterador(atletas, nAtletas);
}