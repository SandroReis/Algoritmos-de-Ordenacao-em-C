/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   com112_sort.h
 * Author: daniel
 *
 * Created on 12 de Abril de 2018, 00:11
 */

#ifndef COM112_SORT_H
#define COM112_SORT_H

void reset (vet *vt);

void bubbleSort(vet *vt);

void insertionSort(vet *vt);

void selectionSort(vet *vt);

void mergeSort(int v[], int inicio, int fim, vet *vt);

void merge(int v[], int inicio, int fim, int meio, vet *vt);

void quickSort(int v[], int ini, int fim, vet *vt);

int particao(int v[], int ini, int fim, vet *vt);


#endif /* COM112_SORT_H */

