=========================================================
PROJETO: Análise Empírica de Complexidade de Algoritmos
=========================================================

Autor: Vinícius Dantas Rodrigues
Data: 19 de setembro de 2025

---------------------------------------------------------

1. DESCRIÇÃO
---------------------------------------------------------

Este projeto consiste em um programa desenvolvido em linguagem C com o objetivo de
avaliar empiricamente o tempo de execução de algoritmos de ordenação. O programa
mede o tempo que diferentes algoritmos levam para ordenar vetores de tamanhos
crescentes, permitindo uma comparação prática com suas respectivas complexidades
assintóticas teóricas.

Os dados de tempo são coletados e exportados em um formato simples (CSV) para
facilitar a análise e a visualização em ferramentas externas, como planilhas
eletrônicas (Google Sheets, Microsoft Excel, etc.).


---------------------------------------------------------
2. FUNCIONALIDADES
---------------------------------------------------------

- Implementação de dois algoritmos de ordenação clássicos:
  - Insertion Sort (Complexidade teórica: O(n^2))
  - Merge Sort (Complexidade teórica: O(n log n))

- Medição precisa do tempo de execução médio para cada algoritmo, realizando
  múltiplas repetições para minimizar flutuações e garantir resultados mais
  confiáveis.

- Código modular, com responsabilidades bem divididas entre a lógica dos
  algoritmos, a medição de tempo e a orquestração do experimento.

- Geração de dados de saída em formato CSV (Comma-Separated Values) para fácil
  manipulação e plotagem de gráficos.


---------------------------------------------------------
3. ESTRUTURA DO PROJETO
---------------------------------------------------------

O código-fonte está organizado nos seguintes arquivos:

- main.c:
  Arquivo principal que orquestra todo o experimento. Define os tamanhos de
  entrada a serem testados, o número de repetições e chama os módulos de
  algoritmos e medição, imprimindo o resultado final.

- algoritmos.h / algoritmos.c:
  Módulo que contém as implementações dos algoritmos de ordenação (Insertion
  Sort e Merge Sort), bem como funções auxiliares para gerar e imprimir vetores.

- medicao.h / medicao.c:
  Módulo responsável pela cronometragem do tempo de execução. Utiliza a
  biblioteca <time.h> e ponteiros de função para medir de forma genérica o
  tempo de qualquer algoritmo com uma assinatura compatível.


---------------------------------------------------------
4. COMO COMPILAR E EXECUTAR
---------------------------------------------------------

PRÉ-REQUISITOS:
- É necessário ter um compilador C (como o GCC) instalado no sistema.

PASSO 1: COMPILAÇÃO
Navegue até o diretório do projeto pelo terminal e execute o seguinte comando
para compilar todos os arquivos-fonte em um único programa executável chamado
"meu_programa":

    gcc main.c algoritmos.c medicao.c -o meu_programa


PASSO 2: EXECUÇÃO
Para executar o programa e salvar a saída de dados no arquivo "resultados.csv",
utilize o comando:

    ./meu_programa > resultados.csv

O programa exibirá mensagens de progresso no terminal, e ao final, o arquivo
"resultados.csv" conterá os dados de tempo para a análise.


---------------------------------------------------------
5. SAÍDA DO PROGRAMA
---------------------------------------------------------

A saída principal é o arquivo `resultados.csv`, formatado da seguinte maneira:

    algoritmo,n,tempo_medio_s
    InsertionSort,1000,0.00139180
    InsertionSort,5000,0.02599080
    ...
    MergeSort,25000,0.00868700

- Coluna 1: Nome do algoritmo executado.
- Coluna 2: Tamanho da entrada (n).
- Coluna 3: Tempo médio de execução em segundos.


---------------------------------------------------------
6. ANÁLISE DOS DADOS
---------------------------------------------------------

O arquivo `resultados.csv` foi projetado para ser facilmente importado em
softwares de planilha (Google Sheets, Excel, etc.) ou em scripts de análise
(Python com Pandas/Matplotlib) para a geração dos gráficos e a comparação
visual com as curvas de complexidade teóricas.
