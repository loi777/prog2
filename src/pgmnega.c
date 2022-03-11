#include "imagem.h"

void negativo(Imagem_t *orig, Imagem_t *neg){

    int pixel;
    
    strcpy(neg->tipo, orig->tipo);
    neg->altura = orig->altura;
    neg->coluna = orig->coluna;
    neg->max = orig->max;

    alocacao_matriz(neg);

    for (int i = 0; i < orig->altura; i++)
        for (int j = 0; j < orig->coluna; j++){
            pixel = orig->img[i][j];
            pixel = orig->max - pixel;
            neg->img[i][j] = pixel;
        }

}

int main(int argc, char **argv){

    FILE *arq;
    FILE *arqs;
    char input[MAX] , output[MAX];
    Imagem_t orig, novo;

    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'i')
                strcpy(input, argv[i+1]);
            else if (argv[i][1] == 'o')
                strcpy(output, argv[i+1]);
        }
    }

    arq = fopen (input, "r");
    if ( ! arq ){
        printf ("Erro ao abrir arquivo");
        exit (1);
    }

    arqs = fopen (output, "w");


    ler_imagem(&orig, arq);
    fclose (arq);
    
    negativo(&orig, &novo);
    imprimir_imagem(&novo, arqs);
    fclose (arqs);
    
}
