#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"

int mediana_de_tres(dado_t ** dados, int esquerda, int direita){

	int mediana = (esquerda + direita) / 2;

	dado_t * dado = NULL;
	if(retornar_temperatura(dados[direita]) < retornar_temperatura(dados[esquerda])){
		dado = dados[esquerda];
		dados[esquerda] = dados[direita];
		dados[direita] = dado;
	}

	if(retornar_temperatura(dados[mediana]) < retornar_temperatura(dados[esquerda])){
		dado = dados[mediana];
		dados[mediana] = dados[esquerda];
		dados[esquerda] = dado;
	}

	if(retornar_temperatura(dados[direita]) < retornar_temperatura(dados[mediana])){
		dado = dados[mediana];
		dados[mediana] = dados[direita];
		dados[direita] = dado;
	}

	return mediana;
}

int partition(dado_t ** dados, int esquerda, int direita){

	int mediana = mediana_de_tres(dados, esquerda, direita);

	float pivot = retornar_temperatura(dados[mediana]);

	int i = esquerda - 1;
	int j = direita + 1;

	for(;;){

		do {
			i = i + 1;
		} while(retornar_temperatura(dados[i]) < pivot);

		do {
			j = j - 1;
		} while(retornar_temperatura(dados[j]) > pivot);

		if(i >= j){
			return j;
		}

		dado_t * dado = dados[i];
		dados[i] = dados[j];
		dados[j] = dado;

	}

	return mediana;
}

void quicksort(dado_t ** dados, int esquerda, int direita){
	if(esquerda < direita){
		int p = partition(dados, esquerda, direita);
		quicksort(dados, esquerda, p);
		quicksort(dados, p + 1, direita);
	}
}
