#include "funcoesEvolucao.h"

int genAtual = -1; // geracao atual 

void initpop(individuo *ind, int labirinto[LINHAS][COLUNAS]){ // inicia a populacao na posicao inicial e sem pontos ou movimentos
    for(int i = 0; i < TamPop; i++){  // preenche o vetor com a populacao
        ind[i].pontos = 0;            // define valores padroes para os individuos
        ind[i].posi = LINHAS - 2;
        ind[i].posj = COLUNAS - 2;
        for(int j = 0; j < TAM; j++){
            ind[i].caminho[j] = 0;
        }
    }
}

void avalia(individuo *ind, int labirinto[LINHAS][COLUNAS], FILE *arquivo){ // quantifica o desempenho de cada caminho (individuo)
    genAtual++;
    fprintf(arquivo, "GERACAO: %d\n\n", genAtual); // printa em qual geracao esta
    int chegou = 1;
    for(int i = 0; i < TamPop; i++){                // iteracao para utilizar todos os individuos do vetor
        ind[i].pontos = 0;
        labirinto[1][1] = 2;
        if(genAtual == 0)                           // fazendo a movimentacao dos indiviuos, sendo a inicial uma movimentacao randomica
            chegou = moveIndividuoInicial(labirinto, &ind[i], arquivo);
        else
            chegou = moveIndividuo(labirinto, &ind[i], arquivo);

        for(int j = 0; j < TAM; j++){               // apartir do caminho feito por cada individou, realiza atribuicao de pontos
            if(ind[i].caminho[j] == 1 || ind[i].caminho[j] == 2)
                ind[i].pontos += 10;
            else if(ind[i].caminho[j] == 0 || ind[i].caminho[j] == 3)
                ind[i].pontos -= 10;
            else if(ind[i].caminho[j] == 4)
                ind[i].pontos -= 5;
        }                                       // recompensas caso o individuo chegue proximo ao objetivo
        if(ind[i].posi - 1 < 4)
            ind[i].pontos += 60;
        if(ind[i].posj - 1 < 9)
            ind[i].pontos += 40;
        if(chegou == 0){                            // caso o individuo alcance o objetivo atribui uma quantidade maior de pontos
            printf("chegou no 2 na geração %d\n", genAtual);
            ind[i].pontos += 80;
        }
        fprintf(arquivo, "SOMA DE PONTOS: %.2f\n\n", ind[i].pontos);
    }
}

void exterminio(individuo *ind){ // encontra e elimina os dois piores individuos
    int minfit1 = 0, minfit2 = 1;

    if(ind[0].pontos > ind[1].pontos){
        minfit1 = 1;
        minfit2 = 0;
    }
    //seleciona os dois individuos com menores fitness                                    
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
    //deslocando o restante do vetor para frente
    for(int i = minfit1; i < minfit2; i++)
        ind[i] = ind[i+1];
    for(int i = minfit2; i < TamPop - 1; i++)
        ind[i-1] = ind[i+1];

    //preenchendo os individuos exterminados com valores insignificantes
    individuo vazio;
    ind[TamPop-2] = vazio;
    ind[TamPop-1] = vazio;
}

void elitismo(individuo *ind, int *maxfit1, int *maxfit2){ // encontra os dois melhores individuos
    *maxfit1 = 0;
    *maxfit2 = 1;

    if(ind[0].pontos < ind[1].pontos){
        *maxfit1 = 1;
        *maxfit2 = 0;
    }
    //seleciona os dois individuos com maiores fitness
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
// mistura os movimentos de dois individuos (metade de cada)
individuo misturaGene(individuo indini, individuo indfim){
    individuo ind;                          
    for(int i = 0; i < TAM/2; i++)          //insere primeira metade no vetor
        ind.caminho[i] = indini.caminho[i];

    for(int i = TAM/2; i < TAM; i++)        //insere segunda metade no vetor
        ind.caminho[i] = indfim.caminho[i];

    return ind;
}

void crossover(individuo *ind, int maxfit1, int maxfit2){ // mistura os movimentos dos individuos com os melhores, gerando novos individuos
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

void mutacaoQuatro(individuo *novaPop){ // retira movimentos invalidos e troca por movimentos aleatorios
    for(int i = 2; i < TamPop; i++){
        for(int j = 0; j < TAM; j++){
            if(novaPop[i].caminho[j] == 4){
                int random = rand() % 4;
                novaPop[i].caminho[j] = random; 
            }
        }
    }
}

void mutacao(individuo *novaPop){ // troca alguns movimentos por movimentos aleatorios
    for(int i = 2; i < TamPop; i++){
        int qntMutacoes = rand() % (TAM/4);

        for(int j = 0; j < qntMutacoes; j++){
            int movimento = rand() % 4;
            int posicao = rand() % TAM;

            novaPop[i].caminho[posicao] = movimento;
        }
    }
}

void cruzamento(individuo *ind){ // gera os individuos para a nova geracao
    exterminio(ind);
    int maxfit1, maxfit2;
    elitismo(ind, &maxfit1, &maxfit2);

    crossover(ind, maxfit1, maxfit2);
    mutacaoQuatro(ind);
    mutacao(ind);
}