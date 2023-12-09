#include "individuo.h"

void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind ind, float *pontos){
    int n = 10;
    for(int i = 0; i < n; i++){
        printLabirinto(labirinto);
        int direcao = rand() % 4;
        printf("direcao: %d\n", direcao);

        if(labirinto[ind.posi][ind.posj] != 1 || labirinto[ind.posi][ind.posj] != 2){
            if(direcao == 0){
                if(ind.posj < COLUNAS - 1){
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posj++;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos -= 10;
                }
                else{
                    *pontos -= 5; 
                    n++;
                }
            }
            else if(direcao == 1){
                if(ind.posj > 1){
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posj--;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos += 10;
                }
                else{
                    *pontos -= 5; 
                    n++;
                }
            }
            else if(direcao == 2){
                if(ind.posi > 1){
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posi--;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos += 10;
                }
                else{
                    *pontos -= 5; 
                    n++;
                }
            }
            else if(direcao == 3){
                if(ind.posj < LINHAS - 1){
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posi++;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos -= 10;
                }
                else{
                    *pontos -= 5; 
                    n++;
                }
            }
        }
        else 
            n++;
    }
}