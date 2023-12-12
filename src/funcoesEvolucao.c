#include "funcoesEvolucao.h"

int genAtual = -1;

void initpop(individuo *ind, int labirinto[LINHAS][COLUNAS]){
    for(int i = 0; i < TamPop; i++){  // preenche o vetor com a populacao
        ind[i].pontos = 0; 
        ind[i].posi = LINHAS - 2;
        ind[i].posj = COLUNAS - 2;
        for(int j = 0; j < TAM; j++){
            ind[i].caminho[j] = 0;
        }
    }
}

void avalia(individuo *ind, int labirinto[LINHAS][COLUNAS], FILE *arquivo){
    genAtual++;
    fprintf(arquivo, "GERACAO: %d\n\n", genAtual); // printa em qual geracao esta
    int chegou = 1;
    for(int i = 0; i < TamPop; i++){
        ind[i].pontos = 0;
        labirinto[1][1] = 2;
        if(genAtual == 0)
            chegou = moveIndividuoInicial(labirinto, &ind[i], arquivo);
        else
            chegou = moveIndividuo(labirinto, &ind[i], arquivo);

        for(int j = 0; j < TAM; j++){
            if(ind[i].caminho[j] == 1 || ind[i].caminho[j] == 2)
                ind[i].pontos += 10;
            else if(ind[i].caminho[j] == 0 || ind[i].caminho[j] == 3)
                ind[i].pontos -= 10;
            else if(ind[i].caminho[j] == 4)
                ind[i].pontos -= 5;
        }
        if(ind[i].posi - 1 < 4)
            ind[i].pontos += 60;
        if(ind[i].posj - 1 < 9)
            ind[i].pontos += 40;
        if(chegou == 0){
            printf("chegou no 2 na geração %d\n", genAtual);
            ind[i].pontos += 80;
        }
        fprintf(arquivo, "SOMA DE PONTOS: %.2f\n\n", ind[i].pontos);
    }
}

void exterminio(individuo *ind){
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

    individuo vazio;
    ind[TamPop-2] = vazio;
    ind[TamPop-1] = vazio;
}

void elitismo(individuo *ind, int *maxfit1, int *maxfit2){
    *maxfit1 = 0;
    *maxfit2 = 1;

    if(ind[0].pontos < ind[1].pontos){
        *maxfit1 = 1;
        *maxfit2 = 0;
    }

    for(int i = 2; i < TamPop - Exterminio; i++){
        if(ind[i].pontos > ind[*maxfit2].pontos){
            if(ind[i].pontos > ind[*maxfit1].pontos){
                *maxfit2 = *maxfit1;
                *maxfit1 = i;
            }
            else
                *maxfit2 = i;
        }
    }
}

individuo misturaGene(individuo indini, individuo indfim){
    individuo ind;
    for(int i = 0; i < TAM/2; i++)
        ind.caminho[i] = indini.caminho[i];

    for(int i = TAM/2; i < TAM; i++)
        ind.caminho[i] = indfim.caminho[i];

    return ind;
}

void crossover(individuo *ind, int maxfit1, int maxfit2){
    individuo novaPop[TamPop];
    int TamNovaPop = 0;

    novaPop[TamNovaPop++] = ind[maxfit1];
    novaPop[TamNovaPop++] = ind[maxfit2];
    novaPop[TamNovaPop++] = misturaGene(ind[maxfit1], ind[maxfit2]);
    novaPop[TamNovaPop++] = misturaGene(ind[maxfit2], ind[maxfit1]);

    int auxiliar[TamPop - 2 - Exterminio];
    int posAuxiliar = 0;
    
    for(int i = 0; i < TamPop - Exterminio; i++){
        if(i != maxfit1 && i != maxfit2)
            auxiliar[posAuxiliar++] = i;
    }

    novaPop[TamNovaPop++] = misturaGene(ind[maxfit1], ind[auxiliar[0]]);
    novaPop[TamNovaPop++] = misturaGene(ind[maxfit2], ind[auxiliar[1]]);
    novaPop[TamNovaPop++] = misturaGene(ind[auxiliar[2]], ind[maxfit1]);
    novaPop[TamNovaPop++] = misturaGene(ind[auxiliar[3]], ind[maxfit2]);
    novaPop[TamNovaPop++] = misturaGene(ind[maxfit1], ind[auxiliar[4]]);
    novaPop[TamNovaPop++] = misturaGene(ind[maxfit2], ind[auxiliar[5]]);

    for(int i = 0; i < TamPop; i++)
        ind[i] = novaPop[i];
}

void cruzamento(individuo *ind){
    exterminio(ind);
    int maxfit1, maxfit2;
    elitismo(ind, &maxfit1, &maxfit2);

    crossover(ind, maxfit1, maxfit2);
}