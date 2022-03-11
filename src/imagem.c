#include "imagem.h"

/*
ler:
  - *P2
  - P5
Filtro: 
  - *negativo
  - *rotação simples
  - rotação livre
  - *limiar
  - *redução de ruído pela média
  - *mediana
  - LBP (Local Binary Patterns)
*/

void alocacao_matriz(Imagem_t *orig){

  int i,j;
  //alocando a matriz
  orig->img = malloc (orig->altura * sizeof (int*)); 
  for (i=0; i < orig->altura; i++)
    orig->img[i] = malloc (orig->coluna * sizeof (int));

  //zerando a matriz
  for (i=0; i < orig->altura; i++)
    for (j=0; j < orig->coluna; j++)
      orig->img[i][j] = 0;  

}

void alocacao_p5(P5_t *orig){

  int i,j;
  //alocando a matriz
  orig->img = malloc (orig->altura * sizeof (unsigned char*)); 
  for (i=0; i < orig->altura; i++)
    orig->img[i] = malloc (orig->coluna * sizeof (unsigned char));

  //zerando a matriz
  for (i=0; i < orig->altura; i++)
    for (j=0; j < orig->coluna; j++)
      orig->img[i][j] = 0;  

}


void ler_imagem(Imagem_t *orig, FILE *arq){

  char line[SIZE + 1];

  fscanf(arq, "%s", orig->tipo);

  fgets(line, SIZE, arq);
	while( line[0] == '\0' || !strcmp(line,"\n") || line[0] == '#' ){
		fgets(line, SIZE, arq);
	};

  fscanf(arq, "%d", &orig->coluna);

  fgets(line, SIZE, arq);
	while( line[0] == '\0' || !strcmp(line,"\n") || line[0] == '#' ){
		fgets(line, SIZE, arq);
	};

  fscanf(arq, "%d", &orig->altura);

  fgets(line, SIZE, arq);
	while( line[0] == '\0' || !strcmp(line,"\n") || line[0] == '#' ){
		fgets(line, SIZE, arq);
	};

  fscanf(arq, "%d", &orig->max);

  //ler p2
  if (!strcmp(orig->tipo, "P2") ){
    

    alocacao_matriz(orig);
    for (int i=0; i < orig->altura; i++)
      for (int j = 0; j < orig->coluna; j++)
        fscanf(arq, "%d", &orig->img[i][j]);

  }

  //ler p5
  else if (!strcmp(orig->tipo, "P5") ){

    P5_t aux;
    aux.altura = orig->altura;
    aux.coluna = orig->coluna;

    alocacao_p5(&aux);
    for (int i=0; i < orig->altura; i++)
        fread(aux.img[i], sizeof(unsigned char), aux.coluna, arq);
    
    alocacao_matriz(orig);

    for (int i=0; i < orig->altura; i++)
      for (int j = 0; j < orig->coluna; j++)
        orig->img[i][j] = (int) aux.img[i][j];
  }
}

void imprimir_imagem(Imagem_t *orig, FILE *arqs){

  fprintf(arqs, "%s\n", orig->tipo);
  fprintf(arqs, "%d\n", orig->coluna);
  fprintf(arqs, "%d\n", orig->altura);
  fprintf(arqs, "%d\n", orig->max);

  for (int i=0; i < orig->altura; i++)
    for (int j = 0; j < orig->coluna; j++)
      fprintf(arqs, "%d ", orig->img[i][j]);
}