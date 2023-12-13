#include "labirinto.h"

//funcao para printar labirinto no arquivo
void printLabirinto(int labirinto[LINHAS][COLUNAS], FILE *arquivo){
    for (int i = 0; i < LINHAS; i++){
        fprintf(arquivo, "%d - ", i);
        for (int j = 0; j < COLUNAS; j++){
            if(labirinto[i][j] == 1)
                fprintf(arquivo, "#");
            else if(labirinto[i][j] == 0)
                fprintf(arquivo, " ");
            else if(labirinto[i][j] == 3 || labirinto[i][j] == 2)
                fprintf(arquivo, "%d", labirinto[i][j]);
        }
        fprintf(arquivo, "\n");
    }
}