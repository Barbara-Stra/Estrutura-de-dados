/*18.Construa uma FILA contendo 20 valores aleatórios entre 1 e 100.
Posteriormente:
• remova os valores múltiplos de 5;
• apresente a fila final.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct apelido_no {
	int dado;
	struct apelido_no *proximo;	
}no;

void imprimir_fila(no *inicio);
void inserir_fila(int dado, no **inicio, no **fim);
void distribui_fila(no **inicio, no **fim, no **inicio_mult5, no **fim_mult5);
void remover_fila(no **inicio);

int main() {
	no *inicio = NULL, *inicio_mult5 = NULL, *fim = NULL, *fim_mult5 = NULL;
	int i = 0, dado, e;
	
	srand(time(NULL));
	
	for(i = 0; i < 20; i++) {
		inserir_fila((rand() % 99) + 1, &inicio, &fim);
	}
	
	distribui_fila(&inicio, &fim, &inicio_mult5, &fim_mult5);
	
	printf("\nFila Múltiplos de 5\n");
	imprimir_fila(inicio_mult5);
	
}
//----------------------------------------------------------------
void inserir_fila(int dado, no **inicio, no **fim){
	no *novo = malloc(sizeof(no));
	
	novo->dado = dado;
	novo->proximo = NULL;
	
	if (novo) {
		if (*fim) {
			(*fim)->proximo = novo;
			*fim = novo;
		} else {
			*inicio = novo;
			*fim = novo;	
		}
			
	} else {
		printf("Alocação não foi bem sucedida");
	}

}

void imprimir_fila(no *inicio) {
	
		while (inicio) {
			printf("%d ", inicio->dado);
			inicio = inicio->proximo; 
		}
		
}

void distribui_fila(no **inicio, no **fim, no **inicio_mult5, no **fim_mult5) {
	no *aux = *inicio;
	
	while (aux) {
		if (aux->dado % 5 == 0) {
			inserir_fila(aux->dado, inicio_mult5, fim_mult5);
		}
		aux = aux->proximo;
	}
	
	remover_fila(inicio);
	
}

void remover_fila(no **inicio) {
	no *aux = *inicio;
	
	while (*inicio) {
		*inicio = (*inicio)->proximo;
		free(aux);
		aux = *inicio; 
	}
}
