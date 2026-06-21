//12.Construa um programa em linguagem c que monte uma pilha de 15 elementos com valores aleatórios (não repetidos) 
//entre 10 e 100. Posteriormente, monte duas pilhas (pares e ímpares), distribuindo e esfaziando a pilha original.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct apelido_no {
	int dado;
	struct apelido_no *proximo;	
}no;

void imprimir_pilha(no *inicio);
void inserir_pilha(int dado, no **inicio);
void distribui_pilha(no **inicio, no **inicio_impar, no **inicio_par);
void remover_pilha(no **inicio);

int existe(int n, no *inicio);


int main() {
	no *inicio = NULL, *inicio_impar = NULL, *inicio_par = NULL;
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

	printf("\nPilha Normal\n");
	imprimir_pilha(inicio);
	
	distribui_pilha(&inicio, &inicio_impar, &inicio_par);
	
	printf("\n\nPilha Par\n");
	imprimir_pilha(inicio_par);
	
	printf("\n\nPilha Impar\n");
	imprimir_pilha(inicio_impar);
	
	
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

void distribui_pilha(no **inicio, no **inicio_impar, no **inicio_par) {
	no *aux = *inicio;
	
	while (aux) {
		if (aux->dado % 2 == 0) {
			inserir_pilha(aux->dado, inicio_par);
		} else {
			inserir_pilha(aux->dado, inicio_impar);
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




