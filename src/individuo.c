#include "individuo.h"

void moveIndividuo(int labirinto[LINHAS][COLUNAS], ind ind, char direcao){
    if(labirinto[ind.posei][ind.posej] != 1 || labirinto[ind.posei][ind.posej] != 2){
        if(direcao == 'd'){
            if(ind.posej < COLUNAS){
                labirinto[ind.posei][ind.posej] = 0;
                ind.posej++;
                labirinto[ind.posei][ind.posej] = 3;
            }
        }
        else if(direcao == 'e'){
            if(ind.posej > 0){
                labirinto[ind.posei][ind.posej] = 0;
                ind.posej--;
                labirinto[ind.posei][ind.posej] = 3;
            }
        }
        else if(direcao == 'c'){
            if(ind.posei > 0){
                labirinto[ind.posei][ind.posej] = 0;
                ind.posei--;
                labirinto[ind.posei][ind.posej] = 3;
            }
        }
        else if(direcao == 'b'){
            if(ind.posej < LINHAS){
                labirinto[ind.posei][ind.posej] = 0;
                ind.posei++;
                labirinto[ind.posei][ind.posej] = 3;
            }
        }
    }
}