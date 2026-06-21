/*16.Construa um programa em linguagem C que implemente uma PILHA através
de 10 elementos (entre 10 e 100) gerados randomicamente (não repetidos).
Posteriormente, apresente o conteúdo da pilha.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct apelido_no {
	int dado;
	struct apelido_no *proximo;	
}no;

void imprimir_pilha(no *inicio);
void inserir_pilha(int dado, no **inicio);
void remover_pilha(no **inicio);

int existe(int n, no *inicio);


int main() {
	no *inicio = NULL;
	int i = 0, dado, e;
	
	srand(time(NULL));
	
	for(i = 0; i < 15; i++) {
		
		if (inicio == NULL) {
			inserir_pilha((rand() % 90) + 10, &inicio);
		} else {
			do {
				dado = (rand() % 90) + 10;
				
				e = existe(dado, inicio);
				if(e == 0) {
					dado = (rand() % 90) + 10;
					e = existe(dado, inicio);
				}
				
			} while (e == 1);
			
			inserir_pilha(dado, &inicio);	
		}
	}

	printf("\nPilha\n");
	imprimir_pilha(inicio);
	
	remover_pilha(&inicio);
	
}
//----------------------------------------------------------------
int existe(int n, no *inicio) {
	
	while (inicio) {
		if (inicio->dado == n){
			return 1;	
		} 
		inicio = inicio->proximo;
	}
	return 0;
}


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

void remover_pilha(no **inicio) {
	no *aux = *inicio;
	
	while (*inicio) {
		*inicio = (*inicio)->proximo;
		free(aux);
		aux = *inicio; 
	}
}




