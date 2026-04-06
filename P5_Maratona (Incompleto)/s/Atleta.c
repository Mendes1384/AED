/*
 * Atleta.c
 */

#include "Atleta.h"

/*------------------------------------------*/
/* Constantes privadas */

/*------------------------------------------*/
/* Tipo privado */

struct Atleta {
  Info info;
  string nome;
  string pais;
  genero g;
  int recorde;
  int tempo; // Tempo na maratona
  int nAtleta;
};

/*------------------------------------------*/
/* Funcoes privadas */

static bool verificaTermino(Atleta a){
    if(a->tempo == NAO_TERMINOU)
    return false;
  else
    return true;
}

/*------------------------------------------*/
/* Funcoes publicas */

Atleta criaAtleta(string nome, string pais, int recorde, genero gen) {
  Atleta a = malloc(sizeof(struct Atleta));

  a->info = criaInfo("Atleta", destroiAtleta, NULL, NULL, NULL, NULL);
  a->nome = criaString(nome);
  a->pais = criaString(pais);
  a->g = gen;
  a->recorde = recorde;
  a->tempo = NAO_TERMINOU;
  a->nAtleta = 0;

  return a;
}

void destroiAtleta(Atleta a) {
  destroiString(a->nome);
  destroiString(a->pais);
  destroiInfo(a->info);
  free(a);
}

void atribuiTempoAtleta(Atleta a, int tempo){
  a->tempo = tempo;
}

int numeroAtleta(Atleta a){
  return a->nAtleta;
}

string nomeAtleta(Atleta a){
  return a->nome;
}

string paisAtleta(Atleta a){
  return a->pais;
}

genero generoAtleta(Atleta a){
  return a->g;
}

int tempoAtleta(Atleta a){
  return a->tempo;
}

int recordeAtleta(Atleta a){
  return a->recorde;
}

bool terminouAtleta(Atleta a){
  return verificaTermino(a);
}