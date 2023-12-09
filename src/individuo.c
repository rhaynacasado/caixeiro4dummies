#include "individuo.h"

void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind ind, float *pontos){
    for(int i = 0; i < 20; i++){
        printLabirinto(labirinto);
        printf("\nPONTOS: %f\n", *pontos);
        int direcao = rand() % 4;

        if(labirinto[ind.posi][ind.posj] != 1 || labirinto[ind.posi][ind.posj] != 2){
            if(direcao == 0){
                if(ind.posj < COLUNAS - 2){
                    printf("\nandou pra direita\n");
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posj++;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos -= 10;
                }
                else{
                    printf("\nburrooou pra direita\n");
                    *pontos -= 5; 
                }
            }
            else if(direcao == 1){
                if(ind.posj > 1){
                    printf("\nandou pra esquerda\n");
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posj--;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos += 10;
                }
                else{
                    printf("\nburrooou pra esquerda\n");
                    *pontos -= 5; 
                }
            }
            else if(direcao == 2){
                if(ind.posi > 1){
                    printf("\nandou pra cima\n");
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posi--;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos += 10;
                }
                else{
                    printf("\nburrooou pra cima\n");
                    *pontos -= 5; 
                }
            }
            else if(direcao == 3){
                if(ind.posj < LINHAS - 1){
                    printf("\nandou pra baixo\n");
                    labirinto[ind.posi][ind.posj] = 0;
                    ind.posi++;
                    labirinto[ind.posi][ind.posj] = 3;
                    *pontos -= 10;
                }
                else{
                    printf("\nburrooou pra baixo\n");
                    *pontos -= 5; 
                }
            }
        }
    }
    labirinto[ind.posi][ind.posj] = 0;
}