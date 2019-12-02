#ifndef QUICK_SORT_H_INCLUDED

#include "dados.h"

int mediana_de_tres(dado_t ** dados, int esquerda, int direita);

int partition(dado_t ** dados, int esquerda, int direita);

void quicksort(dado_t ** dados, int esquerda, int direita);

#endif
