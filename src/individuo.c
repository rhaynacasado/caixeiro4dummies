#include "individuo.h"

void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind ind, float *pontos){
    int n = 10;
    for(int i = 0; i < n; i++){
        printLabirinto(labirinto);
        int direcao = rand() % 4;
        printf("direcao: %d\n", direcao);

        if(labirinto[ind.posei][ind.posej] != 1 || labirinto[ind.posei][ind.posej] != 2){
            if(direcao == 0){
                if(ind.posej < COLUNAS){
                    labirinto[ind.posei][ind.posej] = 0;
                    ind.posej++;
                    labirinto[ind.posei][ind.posej] = 3;
                    *pontos -= 10;
                }
                else{
                    *pontos -= 5; 
                    n++;
                }
            }
            else if(direcao == 1){
                if(ind.posej > 0){
                    labirinto[ind.posei][ind.posej] = 0;
                    ind.posej--;
                    labirinto[ind.posei][ind.posej] = 3;
                    *pontos += 10;
                }
                else{
                    *pontos -= 5; 
                    n++;
                }
            }
            else if(direcao == 2){
                if(ind.posei > 0){
                    labirinto[ind.posei][ind.posej] = 0;
                    ind.posei--;
                    labirinto[ind.posei][ind.posej] = 3;
                    *pontos += 10;
                }
                else{
                    *pontos -= 5; 
                    n++;
                }
            }
            else if(direcao == 3){
                if(ind.posej < LINHAS){
                    labirinto[ind.posei][ind.posej] = 0;
                    ind.posei++;
                    labirinto[ind.posei][ind.posej] = 3;
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