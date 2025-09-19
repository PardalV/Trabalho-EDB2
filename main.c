#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"
#include "medicao.h"

#define REPETICOES 5

int main(){
    //Vai servir para o gerador de números aleatórios
    srand(time(NULL));

    // Vetor com diferentes tamanhos de vetor para teste
    int tamanhos[] = {1000, 5000, 10000, 15000, 20000, 25000};
    int num_tamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);
    //Ponteiros para as funções que estabelecemos
    //Aqui usamos o mergeSortFacilitado por conta da estrutura que definimos para o ponteiro
    void (*algoritmos_a_testar[])(int[], int) = {
        insertionSort , mergeSortFacilitado
    };
    //Nomes dos algoritmos para imprimir o resultado
    char *nomes_algoritmos[] = {
        "InsertionSort" , "MergeSort"
    };

    int num_algoritmos = sizeof(algoritmos_a_testar)/sizeof(algoritmos_a_testar[0]);

    // Imprime o cabeçalho do arquivo CSV que vamos gerar no final
    printf("algoritmo,n,tempo_medio_s\n");
    
    // Loop para iterar sobre cada algoritmo
    for (int i = 0; i < num_algoritmos; i ++){
    
        //o segundo Loop vai ser para iterar sobre o tamanho de entrada
        for(int j = 0; j < num_tamanhos; j ++){
            int n = tamanhos[j];
            double tempo_total = 0.0;

            //printf("Executando %s para N = %d...\n", nomes_algoritmos[i], n);
            fprintf(stderr, "Executando %s para N = %d...\n", nomes_algoritmos[i], n);
            // Executa várias vezes para poder calcular a média
            for (int k = 0; k < REPETICOES; k ++){
                int *vetor = (int *)malloc(n * sizeof(int));
                if (vetor == NULL) {
                    printf("Falha ao alocar memoria.\n");
                    return 1;
                }
                // Gera um vetor aleatória a cada repetição do loop
                gerarVetor(vetor, n);
                // Medição do tempo de execução do algoritmo atual
                tempo_total += medirTempo(algoritmos_a_testar[i], vetor, n);

                free(vetor);
            }
            //Calculo do tempo médio
            double tempo_medio = tempo_total / REPETICOES;
            //Imprime a linha de resultado em formato CSV
            printf("%s, %d, %.8f\n", nomes_algoritmos[i], n, tempo_medio);

        }
    }
    //printf("Finalizado\n");
    fprintf(stderr, "Experimento concluido!\n");
    return 0;
}