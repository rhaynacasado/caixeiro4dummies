#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoesEvolucao.h"

int gen = 0;

void initpop(ind *ind, int labirinto[LINHAS][COLUNAS]){
    for(int i = 0; i < TamPop; i++){  // preenche o vetor com a populacao
        ind[i].pontos = 0; 
        ind[i].posi = LINHAS - 2;
        ind[i].posj = COLUNAS - 2;
        //printf("ind[%d] = %f\n", i, ind[i]); //mostrar individuos gerados
    }
}

void avalia(float *fit, ind *ind, int labirinto[LINHAS][COLUNAS]){
    printf("Generacao: %d\n", gen); // printa em qual geracao esta
    int gereacaoRandomica = 0;
    gen++;
    for(int i = 0; i < TamPop; i++){
        if(gereacaoRandomica == 0)
            moveIndividuoInicial(labirinto, &ind[i]);
        else if(gereacaoRandomica == 1)
            moveIndividuo(labirinto, &ind[i]);
        for(int j = 0; j < TAM; j++){
            if(ind[i].caminho[j] == 1 || ind[i].caminho[j] == 2)
                ind[i].pontos += 10;
            else if(ind[i].caminho[j] == 0 || ind[i].caminho[j] == 3)
                ind[i].pontos -= 10;
            else if(ind[i].caminho[j] == 4)
                ind[i].pontos -= 5;
            printf("%d, ", ind[i].caminho[j]);
        }
        if(ind[i].posi - 1 < 4)
            ind[i].pontos += 60;
        if(ind[i].posj - 1 < 9)
            ind[i].pontos += 40;
        printf("SOMA DE PONTOS: %f\n", ind[i].pontos);
    }
    gereacaoRandomica = 1;
}

void exterminio(ind *ind){
    int minfit1 = 0, minfit2 = 1;

    if(ind[0].pontos > ind[1].pontos){
        minfit1 = 1;
        minfit2 = 0;
    }

    for(int i = 2; i < TamPop - Exterminio; i++){
        if(ind[i].pontos < ind[minfit2].pontos){
            if(ind[i].pontos < ind[minfit1].pontos){
                minfit2 = minfit1;
                minfit1 = i;
            }
            else 
                minfit2 = i;
        }
    }

    for(int i = minfit1; i < minfit2; i++)
        ind[i] = ind[i+1];
    for(int i = minfit2; i < TamPop - 1; i++)
        ind[i-1] = ind[i+1];
}

int* elitismo(ind *ind){
    int maxfit1 = 0, maxfit2 = 1;

    if(ind[0].pontos < ind[1].pontos){
        maxfit1 = 1;
        maxfit2 = 0;
    }

    for(int i = 2; i < TamPop - Exterminio; i++){
        if(ind[i].pontos > ind[maxfit2].pontos){
            if(ind[i].pontos > ind[maxfit1].pontos){
                maxfit2 = maxfit1;
                maxfit1 = i;
            }
            else 
                maxfit2 = i;
        }
    }

    int *maxfit;
    maxfit[0] = maxfit1;
    maxfit[1] = maxfit2;

    return maxfit;
}

void crossover(ind ind, ind* novaPop, int maxfit1, int maxfit2){
    int tamNovaPop = 2;

    for(int i = 0; (i < TamPop - Exterminio) && (tamNovaPop < TamPop); i++){
        if(i == maxfit1 || i == maxfit2)
            continue;
        
        ind novoInd1 = ind[maxfit1];
        ind novoInd2 = ind[i];
        for(int j = TAM/2; j < TAM; j++){
            novoInd1.caminho[j] = ind[i].caminho[j];
            novoInd2.caminho[j] = ind[maxfit2].caminho[j];
        }
        novaPop[tamNovaPop++] = novoInd1;
        novaPop[tamNovaPop++] = novoInd2;
    }
}

// void mutacao(ind *novaPop){
//     for(int i = 2; i < TamPop; i++){
//         int qntMutacoes = rand() % (TAM/4);

//         for(int j = 0; j < qntMutacoes; j++){
//             int movimento = rand() % 4;
//             int posicao = rand() % TAM;

//             novaPop[i].caminho[posicao] = movimento;
//         }
//     }
// }

ind* cruzamento(ind *ind){
    exterminio(ind);
    int *maxfit = elitismo(ind);

    ind novaPop[TamPop];
    novaPop[0] = ind[maxfit[0]];
    novaPop[1] = ind[maxfit[1]];

    // crossover();
    // mutacao(&novaPop);

    return &novaPop;
}