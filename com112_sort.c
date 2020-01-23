/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com112_file.h"
#include "com112_sort.h"

void reset(vet *vt) {
    vt->comp = 0;
    vt->fim = vt->tam - 1;
    vt->ini = 0;
    vt->mov = 0;
}

void bubbleSort(vet *vt) {

    int i = 0, aux;
    int houve_troca = 1;

    vt->comp = 0;
    vt->mov = 0;

    // laço com a quantidade de elementos do vetor e enquanto houver troca
    while (i <= vt->tam && houve_troca) {
        houve_troca = 0;

        // laço que percorre da primeira à penúltima posição do vetor
        for (int j = 0; j < (vt->tam - 1); j++) {
            // acrescenta 1 comparação
            vt->comp++;

            if (vt->vetor[j] > vt->vetor[j + 1]) {

                // sinaliza que houve troca nesta interação
                houve_troca = 1;

                // acrescenta 1 movimentação
                vt->mov++;

                aux = vt->vetor[j];
                vt->vetor[j] = vt->vetor[j + 1];
                vt->vetor[j + 1] = aux;
            }
        }
        i++;
    }
}

void insertionSort(vet *vt) {

    int eleito, j;

    // laço com a quantidade de elementos do vetor - 1
    for (int i = 1; i <= (vt->tam - 1); i++) {
        eleito = vt->vetor[i];
        j = i - 1;

        vt->comp++;

        // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
        while (j >= 0 && vt->vetor[j] > eleito) {

            vt->vetor[j + 1] = vt->vetor[j];
            j--;
            // acrescenta 1 comparação
            vt->comp++;
            // acrescenta 1 movimentação
            vt->mov++;

        }
        vt->vetor[j + 1] = eleito;
    }
}

void selectionSort(vet *vt) {

    int eleito, menor, pos, j;

    // laço com a quantidade de elementos do vetor - 1
    for (int i = 0; i < vt->tam - 1; i++) {
        eleito = vt->vetor[i];
        menor = vt->vetor[i + 1];
        pos = i + 1;

        // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
        for (j = i + 1; j <= vt->tam - 1; j++) {
            if (vt->vetor[j] < menor) {
                menor = vt->vetor[j];
                pos = j;
            }
            // acrescenta 1 comparação
            vt->comp++;
        }
        if (menor < eleito) {
            vt->vetor[i] = vt->vetor[pos];
            vt->vetor[pos] = eleito;
            // acrescenta 1 movimentacao
            vt->mov++;
        }
        // acrescenta 1 comparação
        vt->comp++;
    }
}

void mergeSort(int v[], int inicio, int fim, vet *vt) {
    int meio;
    if (inicio < fim) {
        meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio, vt);
        mergeSort(v, meio + 1, fim, vt);
        merge(v, inicio, fim, meio, vt);
    }
}

void merge(int v[], int inicio, int fim, int meio, vet *vt) {
    int posLivre, inicio_v1, inicio_v2, i;
    int aux[vt->tam];
    inicio_v1 = inicio;
    inicio_v2 = meio + 1;
    posLivre = inicio;

    while (inicio_v1 <= meio && inicio_v2 <= fim) {
        vt->comp++;
        if (v[inicio_v1] <= v[inicio_v2]) {

            aux[posLivre] = v[inicio_v1];
            inicio_v1++;
        } else {

            aux[posLivre] = v[inicio_v2];
            inicio_v2++;
        }
        posLivre++;

    }
    //Caso haja números no primeiro vetor que não foram intercalados
    for (i = inicio_v1; i <= meio; i++) {
        aux[posLivre] = v[i];
        posLivre++;

    }
    //Caso haja número no segundo vetor que não foram intercalados
    for (i = inicio_v2; i <= fim; i++) {
        aux[posLivre] = v[i];
        posLivre++;
    }
    //Retorna os valores de aux para o vetor
    for (i = inicio; i <= fim; i++) {
        v[i] = aux[i];
        // acrescenta 1 movimentação
        vt->mov++;
    }
}

void quickSort(int v[], int ini, int fim, vet *vt) {
    int pivo;
    if (ini < fim) {
        pivo = particao(v, ini, fim, vt);
        quickSort(v, ini, pivo, vt);
        quickSort(v, pivo + 1, fim, vt);

    }
}

int particao(int v[], int ini, int fim, vet *vt) {

    int pivo, i, j;
    pivo = v[(ini + fim) / 2];
    i = ini - 1;
    j = fim + 1;

    while (i < j) {

        do {
            j--;
            vt->comp++;
        } while (v[j] > pivo);

        do {
            i++;
            vt->comp++;
        } while (v[i] < pivo);

        if (i < j) {
            int aux;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            vt->mov++;
        }
    }
    return j;
}