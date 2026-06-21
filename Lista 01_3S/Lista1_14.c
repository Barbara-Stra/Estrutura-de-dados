//14.Com base no exercício 12 (PILHA ORIGINAL), construa uma função que retorne a quantidade de elementos maiores que 50 na pilha.

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

int contador(no *inicio);
int existe(int n, no *inicio);


int main() {
	no *inicio = NULL;
	int i = 0, dado, e, cont;
	
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

	printf("\nPilha Normal\n");
	imprimir_pilha(inicio);
	
	cont = contador(inicio);
	printf("\n\nA quantidade de elementos maiores que 50 e: %d", cont);
	
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

int contador(no *inicio) {
	int cont = 0;
	
	while(inicio) {
		if(inicio->dado > 50) {
			cont++;
		}
		inicio = inicio->proximo;
	}
	return cont;
}




