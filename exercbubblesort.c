#include <stdio.h>
#include <time.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n, long long *instrucoes) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            (*instrucoes)++; // Conta a comparação
            if (arr[j] > arr[j+1]) {
                trocar(&arr[j], &arr[j+1]);
                (*instrucoes) += 3; // Conta a troca
            }
        }
    }
}

int main() {
    int vetor[5] = {64, 25, 12, 22, 11};
    int n = 5;
    
    long long instrucoes = 0;

    clock_t inicio = clock();

    bubbleSort(vetor, n, &instrucoes);

    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\nNumero de instrucoes: %lld\n", instrucoes);
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}
