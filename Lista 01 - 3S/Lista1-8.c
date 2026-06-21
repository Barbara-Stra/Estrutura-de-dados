//8. Com base no exercício anterior, faça o mesmo para uma FILA.

/*Exercicio Anterior

7. Desenvolva um programa em C que simule uma PILHA com 20 valores
aleatorios entre 10 e 125. Posteriormente, remova todos os elementos
ímpares da pilha e apresente a pilha final ao usuário. Não esqueça de liberar
a pilha toda ao encerrar o programa.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct apelido_no {
	int dado;
	struct apelido_no *proximo;	
}no;

void imprimir_fila(no *inicio);
void inserir_fila(int dado, no **inicio, no **fim);
void distribui_fila(no **inicio, no **fim, no **inicio_par, no **fim_par);
void remover_fila(no **inicio);


int main() {
	no *inicio = NULL, *inicio_par = NULL, *fim = NULL, *fim_par = NULL;
	int i = 0, dado, e;
	
	srand(time(NULL));
	
	for(i = 0; i < 20; i++) {
		inserir_fila((rand() % 115) + 10, &inicio, &fim);
	}
	
	distribui_fila(&inicio, &fim, &inicio_par, &fim_par);
	
	printf("\nFila Par\n");
	imprimir_fila(inicio_par);
	
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

void distribui_fila(no **inicio, no **fim, no **inicio_par, no **fim_par) {
	no *aux = *inicio;
	
	while (aux) {
		if (aux->dado % 2 == 0) {
			inserir_fila(aux->dado, inicio_par, fim_par);
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
