/*
 * MainParque.c
 */

#include "Automovel.h"
#include "Parque.h"

#define MAX_LINHA 80
#define MAX_MAT 20

void listaParque(Parque p) {
  Iterador it = iteradorParque(p);
  if (!temSeguinteIterador(it)) {
    printf("Parque sem automoveis.\n");
  }
  while (temSeguinteIterador(it)) {
    Automovel a = (Automovel)seguinteIterador(it);
    if (strcmp(getMat(a), "NAO_EXISTE") != 0)
      printf("%s\n", getMat(a));
  }
  destroiIterador(it);
}

void cmdDinheiro(Parque p) {
  printf("Dinheiro em caixa: %.2lf euros.\n", caixaParque(p));
}

void cmdEntradaAutomovel(Parque p, string linha) {
  char mat[MAX_MAT];
  int h, m;
  if (sscanf(linha, "%s %d:%d", mat, &h, &m) != 3) {
    printf("Dados invalidos.\n");
  } else {
    if (!entradaAutomovelParque(p, mat, h, m)) {
      printf("Automovel ja no parque.\n");
    } else {
      printf("Entrada autorizada.\n");
    }
  }
}

void cmdSaidaAutomovel(Parque p, string linha) {

  char mat[MAX_MAT];
  int h, m;
  if (sscanf(linha, "%s %d:%d", mat, &h, &m) != 3) {
    printf("Dados invalidos.\n");
  } else {
    if (!existeAutomovelParque(p, mat)) {
      printf("Automovel nao existe no parque.\n");
    } else {
      printf("Automovel com matricula %s deve pagar %.2lf euros.\n", mat,
             saidaAutomovelParque(p, mat, h, m));
    }
  }
}

void cmdListaAutomoveis(Parque p) {
  /*int n = ocupacaoParque(p);
  string mat;
  if (n == 0){
          printf("Parque sem automoveis.\n");
  }

  n = getOcupacao(p);

  for (int i = 0; i < n; i++){
          mat = getMat(posParque(p, i));
          if(strcmp(mat, "NAO_EXISTE") != 0){
                  printf("Matricula: %s\n", mat);
          }
          // completar
  }*/
  listaParque(p);
}

char lerComando(string linha) {
  printf("> ");
  if (fgets(linha, MAX_LINHA, stdin) == NULL) {
    linha[0] = 'x';
  }
  return toupper(linha[0]);
}

void interpretador(Parque p) {
  char linha[MAX_LINHA], cmd;
  string args = linha + 2;
  do {
    cmd = lerComando(linha);
    switch (cmd) {
    case 'E':
      cmdEntradaAutomovel(p, args);
      break;
    case 'S':
      cmdSaidaAutomovel(p, args);
      break;
    case 'C':
      cmdDinheiro(p);
      break;
    case 'L':
      cmdListaAutomoveis(p);
      break;
    case 'X':
      break;
    case '\n':
      break;
    default:
      printf("Comando invalido.\n");
      break;
    }
  } while (cmd != 'X');
  cmdDinheiro(p);
  printf("%d automoveis no parque.\n", ocupacaoParque(p));
}

int main(void) {
  Parque fctParque = criaParque();
  interpretador(fctParque);
  destroiTudoParque(fctParque);
  return 0;
}