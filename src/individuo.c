#include "individuo.h"
#include <time.h>

/**
 * @brief Desloca o individuo no labirinto, retorna um valor que denota 
 * se chegou ou não ao destino
 * 
 * @param labirinto matriz de ints, representa o labirinto 
 * @param ind array de individuos
 * @param arquivo usado para o print do labirinto 
 * @return int retorna 0 se chegou no destino, 1 se não
 */
int moveIndividuoInicial(int labirinto[LINHAS][COLUNAS], individuo *ind, FILE  *arquivo){
    ind->posi = LINHAS - 2;
    ind->posj = COLUNAS - 2;

    for(int i = 0; i < TAM; i++){
        int direcao = rand() % 8; // randomiza a direcao

        // chegou no destino
        if(ind->posi == 1 && ind->posj == 1){
            printLabirinto(labirinto, arquivo);
            return 0;
        }

        // se ind esta em posicao valida
        if(labirinto[ind->posi][ind->posj] != 1){
            if(direcao == 0 || direcao == 4){ // para cima
                if(ind->posj < COLUNAS - 2){ // checa se nao bateu na parede de cima
                    labirinto[ind->posi][ind->posj] = 0; // retira a marcacao do individuo na posicao anterior
                    ind->posj++; // atualiza a posicao no individuo
                    labirinto[ind->posi][ind->posj] = 3; // atualiza a posicao no labirinto
                    ind->caminho[i] = 0; // marca o caminho tomado
                }
                else{
                    ind->caminho[i] = 4; // default de posicao invalida
                }
            }
            else if(direcao == 1 || direcao == 5){ // para baixo
                if(ind->posj > 1){ // checa se nao bateu na parede de baixo
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posj--;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 1;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            else if(direcao == 2 || direcao == 6){ // esquerda
                if(ind->posi > 1){ // checa se nao bateu na parede esquerda
                    labirinto[ind->posi][ind->posj] = 0;
                    ind->posi--;
                    labirinto[ind->posi][ind->posj] = 3;
                    ind->caminho[i] = 2;
                }
                else{
                    ind->caminho[i] = 4;
                }
            }
            else if(direcao == 3 || direcao == 7){ // direita
                if(ind->posi < LINHAS - 2){ // checa se nao bateu na parede direita 
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
    // se saiu do loop, empacou em algum lugar
    printLabirinto(labirinto, arquivo);
    labirinto[ind->posi][ind->posj] = 0;

    // retorna flag de nao chegou ao destino
    return 1;
}

/**
 * @brief 
 * 
 * @param labirinto matriz de ints, representa o labirinto
 * @param ind array de individuos
 * @param arquivo usado no print do labirinto
 * @return int 0 se chegou no destino, 1 se nao
 */
int moveIndividuo(int labirinto[LINHAS][COLUNAS], individuo *ind, FILE *arquivo){
    ind->posi = LINHAS - 2;
    ind->posj = COLUNAS - 2;
    
    for(int i = 0; i < TAM; i++){
        if(ind->posi == 1 && ind->posj == 1){
            printLabirinto(labirinto, arquivo);
            return 0;
        }
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
    printLabirinto(labirinto, arquivo);
    labirinto[ind->posi][ind->posj] = 0;
    return 1;
}

/**
 * @brief printa todos os individuos e suas caracteristicas
 * 
 * @param ind array de individuos 
 * @param arquivo log.txt para os outputs
 */
void printIndividuos(individuo *ind, FILE *arquivo){
    for(int i = 0; i < TamPop; i++)
        fprintf(arquivo, "individuo %d (%.0f pontos)\n", i, ind[i].pontos);
    fprintf(arquivo, "\n\n");
}
