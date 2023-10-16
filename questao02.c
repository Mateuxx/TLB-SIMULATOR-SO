#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double time_diff(struct timeval *start, struct timeval *end) {
    return (double)(end->tv_sec - start->tv_sec) * 1000.0 + (double)(end->tv_usec - start->tv_usec) / 1000.0;
}

int main(int argc, char *argv[]) {
    
    int maxPageSize = atoi(argv[1]);
    
    int numIterations = 10000;

    FILE *outputFile = fopen("resultados.txt", "w");
    if (outputFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    for (int pageSize = 1; pageSize <= maxPageSize; pageSize++) {
        int PAGESIZE = pageSize;
        int salto = PAGESIZE / sizeof(int);
        int v[PAGESIZE];
        
        struct timeval inicio, fim;
        double tempoTotal = 0.0;

        for (int i = 0; i < numIterations; i++) {
            gettimeofday(&inicio, NULL);
            for (int j = 0; j < PAGESIZE; j++) {
                v[j] += 1;
            }

            gettimeofday(&fim, NULL);

            double tempoIteracao = time_diff(&inicio, &fim);
            tempoTotal += tempoIteracao;
        }

        double tempoMedioPorAcesso = tempoTotal / numIterations;

        fprintf(outputFile, "Numero de Paginas: %d, Tempo %f \n", PAGESIZE, tempoMedioPorAcesso);
    }

    fclose(outputFile);

    return 0;
}

