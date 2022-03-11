#include "imagem.h"

void limiar(Imagem_t *orig, Imagem_t *novo, double n){

    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->altura;
    novo->coluna = orig->coluna;
    novo->max = orig->max;

    alocacao_matriz(novo);

    int limiar = n*novo->max;
    for (int i = 0; i < orig->altura; i++){
        for (int j = 0; j < orig->coluna; j++){
            if (orig->img[i][j] >= limiar)
                novo->img[i][j] = novo->max;
            else 
                novo->img[i][j] = 0;
        }
    }

}

int main(int argc, char **argv){

    FILE *arq;
    FILE *arqs;
    char input[MAX] , output[MAX];
    double n = 0.5;
    Imagem_t orig, novo;

    for (int i = 0; i < argc; i++){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'i')
                strcpy(input, argv[i+1]);
            else if (argv[i][1] == 'o')
                strcpy(output, argv[i+1]);
            else if (argv[i][1] == 'l')
                n = strtod(argv[i+1], NULL);
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
    
    limiar(&orig, &novo, n);
    
    imprimir_imagem(&novo, arqs);
    fclose (arqs);
    
}
