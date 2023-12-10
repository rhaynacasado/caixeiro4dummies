#include "labirinto.h"

void printLabirinto(int labirinto[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++){
        printf("%d - ", i);
        for (int j = 0; j < COLUNAS; j++){
            if(labirinto[i][j] == 1)
                printf("#");
            else if(labirinto[i][j] == 0)
                printf(" ");
            else
                printf("%d", labirinto[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}