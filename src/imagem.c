#include "imagem.h"

/*
ler:
  - *P2
  - *P5
Filtro: 
  - *negativo
  - *rotação simples
  - rotação livre
  - *limiar
  - *redução de ruído pela média
  - *mediana
  - *LBP (Local Binary Patterns)

  -dar free em tudo kkk
*/

void alocacao_matriz(Imagem_t *orig){

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

  	char comentario[BUFSIZ];

  	fscanf(arq, "%s", orig->tipo);


	while (fscanf(arq, "%d", &orig->coluna) == 0) {
		fgets(comentario, BUFSIZ, arq);
	}

	fscanf(arq, "%d", &orig->altura);

	fscanf(arq, "%d", &orig->max);

  	//ler p2
  	if (!strcmp(orig->tipo, "P2") ){
    
    	alocacao_matriz(orig);
    	for (int i=0; i < orig->altura; i++)
      		for (int j = 0; j < orig->coluna; j++)
    	    	fscanf(arq, "%hhu", &orig->img[i][j]);

  	}

	//ler p5
  	else if (!strcmp(orig->tipo, "P5") ){

		alocacao_matriz(orig);
    		for (int i=0; i < orig->altura; i++)
        		fread(orig->img[i], sizeof(unsigned char), orig->coluna, arq);
	}

}

void imprimir_imagem(Imagem_t *orig, FILE *arqs){

  	fprintf(arqs, "%s\n", orig->tipo);
  	fprintf(arqs, "%d ", orig->coluna);
  	fprintf(arqs, "%d\n", orig->altura);
  	fprintf(arqs, "%d\n", orig->max);

	if (!strcmp(orig->tipo, "P2") ){
		for (int i=0; i < orig->altura; i++){
		  for (int j = 0; j < orig->coluna; j++){
		    fprintf(arqs, "%hhu ", orig->img[i][j]);
			}
		}
	}

	else if (!strcmp(orig->tipo, "P5") ){
  		for(int i=0; i<(orig->altura); i++)
			fwrite(orig->img[i], sizeof(unsigned char), orig->coluna, arqs);
	}

}