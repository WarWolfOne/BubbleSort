#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void gerarVetor(int vet[], int num);
void imprimirVetor(int vetor[], int num);
void bubbleSort(int vet[], int num);
#define tamanho 1000
int main() {

	setlocale(LC_ALL, "Portuguese");
	
	int vetor[tamanho];
	
	gerarVetor(vetor, tamanho);
	
	clock_t t; 
	
	t = clock(); 
	bubbleSort(vetor, tamanho);
	imprimirVetor(vetor, tamanho);
	t = clock() - t; 	
	
	printf("Tempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC)));	
	
	return 0;
	 
}
void gerarVetor(int vet[], int num) {
 
 srand(time(NULL));
	
	for (int i = 0; i < num; i++) {
		vet[i] = rand() % 100 + 1;
	}
}



void imprimirVetor(int vet[], int num) {
	
		for (int i = 0; i < num; i++) {
			printf("%5d ", vet[i]);
	}
		printf("\n");
	
}

void bubbleSort(int vet[], int num) {
	
	int aux, trocar = 0;
	
	for (int i = 1; i <= num - 1; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (vet[j] > vet[j + 1]) {
				printf("Trocar %d por -> %d\n", vet[j], vet[j + 1]);
				aux = vet[j + 1];
				vet[j+1] = vet[j];
				vet[j] = aux;	
				trocar++;
			}
			
		}
		imprimirVetor(vet, num);
	}
	printf("Numero de trocas: %d\n", trocar);
}
