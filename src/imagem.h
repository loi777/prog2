#ifndef __IMAGEM__
#define __IMAGEM__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define SIZE 1024

typedef struct Imagem_t {

    int **img;
    char tipo[2];
    int altura;
    int coluna;
    int max;  

}Imagem_t;

typedef struct P5_t {

    unsigned char **img;
    char tipo[2];
    int altura;
    int coluna;
    int max;  

}P5_t;

void alocacao_matriz(Imagem_t *orig);
void ler_imagem(Imagem_t *orig, FILE *arq);
void imprimir_imagem(Imagem_t *orig, FILE *arqs);
#endif