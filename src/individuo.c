#include "individuo.h"
#include <time.h>

void moveIndividuoInicial(int labirinto[LINHAS][COLUNAS], individuo *ind){
    ind->posi = LINHAS - 2;
    ind->posj = COLUNAS - 2;

    for(int i = 0; i < TAM; i++){
        int direcao = rand() % 8;

        if(labirinto[ind->posi][ind->posj] == 2)
            break;

        if(labirinto[ind->posi][ind->posj] != 1){
            if(direcao == 0 || direcao == 4){
                if(ind->posj < COLUNAS - 2){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posj++;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 0;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            else if(direcao == 1 || direcao == 5){
                if(ind->posj > 1){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posj--;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 1;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            else if(direcao == 2 || direcao == 6){
                if(ind->posi > 1){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posi--;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 2;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            else if(direcao == 3 || direcao == 7){
                if(ind->posi < LINHAS - 2){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posi++;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 3;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
        }
    }
    printLabirinto(labirinto);
    labirinto[ind->posi][ind->posj] = 0;
}

void moveIndividuo(int labirinto[LINHAS][COLUNAS], individuo *ind){
    ind->posi = LINHAS - 2;
    ind->posj = COLUNAS - 2;
    
    for(int i = 0; i < TAM; i++){
        if(labirinto[ind->posi][ind->posj] == 2)
            break;
        if(labirinto[ind->posi][ind->posj] != 1){
            if(ind->caminho[i] == 0){
                if(ind->posj < COLUNAS - 2){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posj++;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 0;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            if(ind->caminho[i] == 1){
                if(ind->posj > 1){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posj--;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 1;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            if(ind->caminho[i] == 2){
                if(ind->posi > 1){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posi--;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 2;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            if(ind->caminho[i] == 3){
                if(ind->posi < LINHAS - 2){
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posi++;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 3;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
        }
    }
    printLabirinto(labirinto);
    labirinto[ind->posi][ind->posj] = 0;
}

void printIndividuos(individuo *ind){
    for(int i = 0; i < TamPop; i++)
        printf("ind %d (%.0f pontos)\n", i, ind[i].pontos);
    printf("\n\n");
}