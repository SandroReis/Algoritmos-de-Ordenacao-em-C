#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_file.h"
#include "com112_sort.h"

void menu(vet *vt);

int main() {

    printf("---------Bem vindo(a) ao Trabalho 1---------\n\n");
    vet *vt;
    int opcaoLeitura = 0;
    printf("Voce Deseja: \n 1. Gerar um arquivo aleatorio do tamanho que voce desejar.\n"
            " 2. Ler o arquivo com112_entrada.txt \n ");
    scanf(" %d", &opcaoLeitura);
    switch (opcaoLeitura) {
        case 1:
            //Escreve numeros aleatorios no arquivo
            escreverArq();
            vt = cria_vetor();
            break;
        case 2:
            //Aloca a memoria do vetor
            vt = cria_vetor();
            break;

    }
    //Chama o menu
    menu(vt);
    //Escreve os relatorios
    relatorio(vt);






}

void menu(vet *vt) {
    //variaveis relacionadas a lib time.h 
    //responsavel pelo calculo do tempo de execução
    clock_t tInicio, tFim;

    int i, opcaoSort;

    reset(vt);
    printf("\n\n");
    printf("Tamanho do vetor: %d\n", vt->tam);
    //Escreve o vetor
    //for (i = 0; i < vt->tam; i++) {
    //    printf("%d ", vt->vetor[i]);
    //}
    printf("Escolha o metodo de ordenazacao: \n\n");
    printf("1. Bubble Sort.\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort.\n");
    printf("4. Merge Sort.\n");
    printf("5. Quick Sort.\n");
    printf("6. Finalizar aplicacao.\n");
    scanf(" %d", &opcaoSort);

    if (opcaoSort != 6) {

        // ordena o vetor em ordem crescente
        switch (opcaoSort) {
            case 1:
                //Resetar os valores da struct
                reset(vt);
                tInicio = clock(); //marca do tempo ao inicio de execução
                bubbleSort(vt);
                tFim = clock(); //marca do tempo ao final da execução
                //conversão para milésimos de segundos
                vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                break;
            case 2:
                //Resetar os valores da struct
                reset(vt);
                tInicio = clock(); //marca do tempo ao inicio de execução
                selectionSort(vt);
                tFim = clock(); //marca do tempo ao final da execução
                //conversão para milésimos de segundos
                vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                break;
            case 3:
                //Resetar os valores da struct
                reset(vt);
                tInicio = clock(); //marca do tempo ao inicio de execução
                insertionSort(vt);
                tFim = clock(); //marca do tempo ao final da execução
                //conversão para milésimos de segundos
                vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                break;
            case 4:
                //Resetar os valores da struct
                reset(vt);
                tInicio = clock(); //marca do tempo ao inicio de execução
                mergeSort(vt->vetor, vt->ini, vt->fim, vt);
                tFim = clock(); //marca do tempo ao final da execução
                //conversão para milésimos de segundos
                vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                break;
            case 5:
                //Resetar os valores da struct
                reset(vt);
                tInicio = clock(); //marca do tempo ao inicio de execução
                quickSort(vt->vetor, vt->ini, vt->fim, vt);
                tFim = clock(); //marca do tempo ao final da execução
                //conversão para milésimos de segundos
                vt->time = ((double) (tFim - tInicio) / (CLOCKS_PER_SEC / 1000));
                break;
        }



    } else {
        printf("\nFinalizando...\n\n");
    }
    saida(vt);

}
