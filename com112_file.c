#include <stdio.h>
#include <stdlib.h>
#include "com112_file.h"
#include "com112_sort.h"
#include <time.h>

/*struct vet {
    //tamanho do vetor
    int tam;
    //vetor em si
    int *vetor;
    //numero de comparacoes
    int comp;
    //numero de movimentos
    int mov;
};*/

void escreverArq() {

    int n;
    FILE *arq = fopen("com112_entrada.txt", "w+");
    if (!arq) {
        printf("erro ao criar arquivo");
        exit(0);
    }
    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &n);
    fprintf(arq, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(arq, "%d ", rand() % 1000);
    }
    fclose(arq);

}

vet *cria_vetor() {

    int i = 0;
    int n;
    // criando a variavel ponteiro para o vetor e alocando
    vet *vt = (vet*) malloc(sizeof (vet));
    if (!vt) {
        printf("Erro ao alocar a memoria!");
        exit(0);
    }


    // criando a variável ponteiro para o arquivo e abrindo
    FILE *arq = fopen("com112_entrada.txt", "r");
    if (!arq) {
        printf("Erro ao acessar o arquivo!");
        exit(0);
    }


    //inserindo o tamanho do vetor
    fscanf(arq, "%d\n", &vt->tam);


    //alocando o vetor
    vt->vetor = (int *) malloc(vt->tam * sizeof (int));
    if (!vt->vetor) {
        printf("Erro ao alocar a mamoria!");
    }

    //inicializando os componentes da struct
    vt->comp = 0;
    vt->mov = 0;
    vt->time = 0;


    while (i < vt->tam) {
        fscanf(arq, "%d ", &vt->vetor[i]);
        i++;
    }

    fclose(arq);
    return vt;
}

void saida(vet *vt) {

    int i = 0;
    int n;


    // criando a variável ponteiro para o arquivo e abrindo
    FILE *arq = fopen("com112_saida.txt", "w");
    if (!arq) {
        printf("Erro ao acessar o arquivo!");
        exit(0);
    }


    //inserindo o tamanho do vetor
    fprintf(arq, "%d\n", vt->tam);

    while (i < vt->tam) {
        fprintf(arq, "%d ", vt->vetor[i]);
        i++;
    }

    fclose(arq);

}

void relatorio(vet *vt) {
    // mostra o vetor ordenado
    printf("\n---------------------------------------------------------");
    //printf("\n Vetor ordenado: ");
    //for (int i = 0; i < vt->tam; i++)
    //    printf("%i ", vt->vetor[i]);

    // mostra o número de comparação e movimentações executadas
    printf("\n Tamanho do vetor: %i ", vt->tam);
    printf("\n Número de comparações: %i ", vt->comp);
    printf("\n Número de movimentações: %i ", vt->mov);
    printf("\n Tempo de execução da função sort selecionada: %lf Milésimos de segundos.", vt->time);
    printf("\n---------------------------------------------------------\n\n");
    escreveRelatorio(vt);
}

void escreveRelatorio(vet *vt) {
    clock_t tInicio, tFim;

    FILE *rel = fopen("com112_relatorio.txt", "w+");
    if (!rel) {
        printf("Erro ao acessar o arquivo!");
        exit(0);
    }

    lerVetor(vt);
    fprintf(rel, "Numero de elementos ordenados: %d\n", vt->tam);
    fprintf(rel, "Metodo Bubble Sort\n");
    tInicio = clock(); //marca do tempo ao inicio de execução
    bubbleSort(vt);
    tFim = clock(); //marca do tempo ao final da execução
    //conversão para milésimos de segundos
    vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    auxrelatorio(vt, rel);

    lerVetor(vt);
    fprintf(rel, "Metodo Selection Sort\n");
    tInicio = clock(); //marca do tempo ao inicio de execução
    selectionSort(vt);
    tFim = clock(); //marca do tempo ao final da execução
    //conversão para milésimos de segundos
    vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    auxrelatorio(vt, rel);

    lerVetor(vt);
    fprintf(rel, "Metodo Insertion Sort\n");
    tInicio = clock(); //marca do tempo ao inicio de execução
    insertionSort(vt);
    tFim = clock(); //marca do tempo ao final da execução
    //conversão para milésimos de segundos
    vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    auxrelatorio(vt, rel);

    lerVetor(vt);
    fprintf(rel, "Metodo Merge Sort\n");
    tInicio = clock(); //marca do tempo ao inicio de execução
    mergeSort(vt->vetor, vt->ini, vt->fim, vt);
    tFim = clock(); //marca do tempo ao final da execução
    //conversão para milésimos de segundos
    vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    auxrelatorio(vt, rel);

    lerVetor(vt);
    fprintf(rel, "Metodo Quick Sort\n");
    tInicio = clock(); //marca do tempo ao inicio de execução
    quickSort(vt->vetor, vt->ini, vt->fim, vt);
    tFim = clock(); //marca do tempo ao final da execução
    //conversão para milésimos de segundos
    vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
    auxrelatorio(vt, rel);


    fclose(rel);
}

void lerVetor(vet *vt) {
    int i = 0;
    FILE *ent = fopen("com112_entrada.txt", "r");
    if (!ent) {
        printf("Erro ao acessar o arquivo!");
        exit(0);
    }

    reset(vt);
    //inserindo o tamanho do vetor
    fscanf(ent, "%d\n", &vt->tam);

    while (i < vt->tam) {
        fscanf(ent, "%d ", &vt->vetor[i]);
        i++;
    }
    fclose(ent);
}

void auxrelatorio(vet *vt, FILE *rel) {
    fprintf(rel, "\tTempo de execucao: %.7lf milesimos de segundo.\n", vt->time);
    fprintf(rel, "\tNumero de comparacoes: %d\n", vt->comp);
    fprintf(rel, "\tNumero de movimentacoes: %d\n\n\n", vt->mov);
}