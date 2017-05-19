#include <iostream>
#include <time.h>

#define VetorSize 100

void PreencherVetor(int vetor[], int tamanho) {
	int aux = 0;

	for (int i = 0; i < tamanho; i++) {

		aux = (1 + rand() % tamanho);
		int aux2 = 0;

		while (aux2 < i) {
			if (aux != vetor[aux2])
				aux2++;
			else {
				aux = (1 + rand() % tamanho);
				aux2 = 0;
			}
		}
		vetor[i] = aux;
	}
}

void ResetarCopia(int vetor[], int copia[], int tamanho) {
	for (int i = 0; i < VetorSize; i++)
		copia[i] = vetor[i];
}

int InsertionSort(int vetor[], int tamanho) {
	int i, j, aux;
	int trocas = 0;

	for (i = 1; i < tamanho; i++) {
		j = i;
		while (j > 0 && vetor[j - 1] > vetor[j]) {
			aux = vetor[j];
			vetor[j] = vetor[j - 1];
			trocas++;
			vetor[j - 1] = aux;
			j--;
		}
	}
	return trocas;
}

int BubbleSort(int vetor[], int tamanho) {
	int aux;
	int trocas = 0;

	for (int i = 0; i < tamanho; i++) {
		for (int j = i + 1; j < tamanho; j++) {
			if (vetor[i] > vetor[j]) {
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
				trocas++;
			}
		}
	}
	return trocas;
}

int QuickSort(int vetor[VetorSize], int inicio, int fim) {
	int pivo, aux, i, j, meio;
	int trocas = 0;

	i = inicio;
	j = fim;

	meio = (int)((i + j) / 2);
	pivo = vetor[meio];

	do {
		while (vetor[i] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;

		if (i <= j) {
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
			trocas++;
		}
	} while (j > i);

	if (inicio < j) trocas += QuickSort(vetor, inicio, j);
	if (i < fim) trocas += QuickSort(vetor, i, fim);

	return trocas;
}

int main() {
	srand(time(NULL));

	int Vetor[VetorSize];
	int Copia[VetorSize];

	PreencherVetor(Vetor, VetorSize);
	ResetarCopia(Vetor, Copia, VetorSize);

	int TrocasInsertion = InsertionSort(Copia, VetorSize);
	ResetarCopia(Vetor, Copia, VetorSize);

	int TrocasBubble = BubbleSort(Copia, VetorSize);
	ResetarCopia(Vetor, Copia, VetorSize);

	int TrocasQuick = QuickSort(Copia, 0, VetorSize - 1);
	ResetarCopia(Vetor, Copia, VetorSize);

	int TrocasInsertion = InsertionSort(Copia, VetorSize);
	int TrocasBubble = BubbleSort(Copia, VetorSize);
	int TrocasQuick = QuickSort(Copia, 0, VetorSize - 1);

	std::cout << "Algoritmo de Insercao: " << TrocasInsertion << "\n";
	std::cout << "Algoritmo de Bubble: " << TrocasBubble << "\n";
	std::cout << "Algoritmo de Quick: " << TrocasQuick << "\n";

	system("pause");
	return 0;
}




