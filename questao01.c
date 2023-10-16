#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double time_diff(struct timeval *start, struct timeval *end) {
    return (double)(end->tv_sec - start->tv_sec) * 1000.0 + (double)(end->tv_usec - start->tv_usec) / 1000.0;
}

int main(int argc, char *argv[]) {

    int numPages = atoi(argv[1]);
    int numIterations = atoi(argv[2]);

    int PAGESIZE = 4096;
    int salto = PAGESIZE / sizeof(int);
    int v[numPages * salto];

    struct timeval inicio, fim;

    gettimeofday(&inicio, NULL);

    for (int i = 0; i < numIterations; i++) {
        for (int j = 0; j < numPages * salto; j += salto) {
            v[j] += 1;
        }
    }

    gettimeofday(&fim, NULL);

    double tempo = time_diff(&inicio, &fim);

    printf("Tempo total: %.2f ms\n", tempo);
    double tempoMedioPorAcesso = tempo / (numPages * numIterations);
    printf("Tempo médio por acesso: %f \n", tempoMedioPorAcesso);


    return 0;
}
