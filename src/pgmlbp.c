#include "imagem.h"

void lbp(Imagem_t *orig, Imagem_t *novo){

    strcpy(novo->tipo, orig->tipo);
    novo->altura = orig->altura;
    novo->coluna = orig->coluna;
    novo->max = 255;

    alocacao_matriz(novo);

    int matriz_lbp[3][3] = 
    {
        {  1,  2, 4 },
        {  8,  0, 16 },
        {  32, 64,  128 }
    };

    int aux[3][3];

    int aux_l, aux_c, lbp_l, lbp_c;
    int soma = 0;
    for (int i = 0; i < orig->altura; i++){
        for (int j = 0; j < orig->coluna; j++){
            aux_l = i;
            aux_c = j;
            lbp_l = 0;
            for (int k = aux_l-1; k <= aux_l+1 ; k++){
                lbp_c = 0;
                for (int l = aux_c-1; l <= aux_c+1; l++){
                    if ( k >= 0 && l >=0 && k < orig->altura && l < orig->coluna ){
                        if (orig->img[k][l] <= orig->img[aux_l][aux_c]) {
                            aux[lbp_l][lbp_c] = 1;
                            aux[lbp_l][lbp_c] = aux[lbp_l][lbp_c]*matriz_lbp[lbp_l][lbp_c];
                            soma = aux[lbp_l][lbp_c] + soma;
                        }
                        else{ 
                            aux[lbp_l][lbp_c] = 0;
                            aux[lbp_l][lbp_c] = aux[lbp_l][lbp_c]*matriz_lbp[lbp_l][lbp_c];
                            soma = aux[lbp_l][lbp_c] + soma;
                        }
                    }
                    lbp_c++;
                }
                lbp_l++;
            } 
            novo->img[i][j] = soma;
            soma = 0;
        }
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
    
    lbp(&orig, &novo);
    
    imprimir_imagem(&novo, arqs);
    fclose (arqs);
    
}
