#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"

// Função vai gerar um vetor com números aleatórias entre 0 e 10
void gerarVetor(int vet[], int n){
    for (int i = 0; i < n; i ++ ){
        vet[i] = rand() % (n * 10);
    }
}
// Função para imprimir esse vetor aleatório
void imprimirVetor(int vet[], int n){
    for (int i = 0; i < n; i ++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}
//Função do insertion sort para
void insertionSort(int vet[], int n){
    int i, key, j;
    for (i = 1; i< n; i ++){
        key = vet[i];
        j = i - 1;
        while (j >= 0 && vet[j] > key){
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}
//Função que vai organizar os valores, servindo quase como o Mergesort em sí
void merge(int vet[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (R == NULL || L == NULL){
        fprintf(stderr, "Erro de alocação de memoria em merge()\n");
        exit(1);
    }

    for(i = 0; i < n1; i ++){
        L[i] = vet[l + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = vet[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while( i < n1 && j < n2){
        if(L[i] <= R[j]){
            vet[k] = L[i];
            i ++;
        } else {
            vet[k] = R[j];
            j ++;
        }
        k ++;
    }
    while (i < n1){
        vet[k] = L[i];
        i ++;
        k ++;
    }
    while (j < n2){
        vet[k] = R[j];
        j ++;
        k ++;
    }
    free(L);
    free(R);
}
//Função do MergeSort que vai organizar os vetores por meio de chamadas recursivas
void mergeSort(int vet[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(vet, l, m);
        mergeSort(vet, m + 1, r);
        merge(vet, l, m, r);
    }
}
// Vai servir pra ajudar a medir o tempo, já que precisamos que ambas as funções tenham a mesma estrutura de entrada
void mergeSortFacilitado(int vet[], int n){
    mergeSort(vet, 0, n - 1);
}