#include "labirinto.h"
#include <stdio.h>
#include <string.h>

void printLabirinto(int labirinto[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++){
        printf("%d - ", i);
        for (int j = 0; j < COLUNAS; j++){
            if(labirinto[i][j] == 1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}