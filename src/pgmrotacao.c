#include "imagem.h"

void rotacao_simples(Imagem_t *orig, Imagem_t *novo){

    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->coluna;
    novo->coluna = orig->altura;
    novo->max = orig->max;

    alocacao_matriz(novo);

    unsigned char pixel;

    int aux_c = 0;
    for (int i = 0; i < orig->coluna; i++){
        int aux_l = orig->altura-1;
        for (int j = 0; j < orig->altura; j++){
            pixel = orig->img[aux_l][aux_c];
            novo->img[i][j] = pixel;
            --aux_l; 
        }

        ++aux_c;
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
    
    rotacao_simples(&orig, &novo);
    imprimir_imagem(&novo, arqs);
    fclose (arqs);
    
}
