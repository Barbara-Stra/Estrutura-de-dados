/*7. Desenvolva um programa em C que simule uma PILHA com 20 valores
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

void imprimir_pilha(no *inicio);
void inserir_pilha(int dado, no **inicio);
void distribui_pilha(no **inicio, no **inicio_par);
void remover_pilha(no **inicio);


int main() {
	no *inicio = NULL, *inicio_par = NULL;
	int i = 0, dado, e;
	
	srand(time(NULL));
	
	for(i = 0; i < 20; i++) {
		inserir_pilha((rand() % 115) + 10, &inicio);
	}
	
	distribui_pilha(&inicio, &inicio_par);
	
	printf("\nPilha Par\n");
	imprimir_pilha(inicio_par);
	
}
//----------------------------------------------------------------
void inserir_pilha(int dado, no **inicio){
	no *novo = malloc(sizeof(no));
	
	novo->dado = dado;
	
	if (novo) {
		novo->proximo = *inicio;
		*inicio = novo;
		
		
	} else {
		printf("Alocação não foi bem sucedida");
	}

}

void imprimir_pilha(no *inicio) {
	
		while (inicio) {
			printf("%d ", inicio->dado);
			inicio = inicio->proximo; 
		}
		
}

void distribui_pilha(no **inicio, no **inicio_par) {
	no *aux = *inicio;
	
	while (aux) {
		if (aux->dado % 2 == 0) {
			inserir_pilha(aux->dado, inicio_par);
		}
		aux = aux->proximo;
	}
	
	remover_pilha(inicio);
	
}

void remover_pilha(no **inicio) {
	no *aux = *inicio;
	
	while (*inicio) {
		*inicio = (*inicio)->proximo;
		free(aux);
		aux = *inicio; 
	}
}
