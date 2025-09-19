#include <time.h>
#include "medicao.h"

// Função medirTempo através de uma entrada genérica de função
// O trecho void(*algoritmo)(int [], int n) define exatamente um ponteiro para função com a assinatura void(int[], int)
// Sendo o vet o vetor a ser ordenado
// Por fim ele retorna o tempo de execução em segundos
double medirTempo(void (*algoritmo)(int[], int), int vet[], int n){
    clock_t inicio, fim;
    inicio = clock();
    algoritmo(vet, n);
    fim = clock();
    return((double)(fim - inicio)) / CLOCKS_PER_SEC;
}