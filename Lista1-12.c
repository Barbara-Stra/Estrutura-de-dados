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
void inserir_pilha(int dado, no **incio);
int existe(int n, no *inicio);


int main() {
	no *inicio = NULL, *aux;
	int i = 0, dado, e;
	
	srand(time(NULL));
	
	for(i = 0; i < 18; i++) {
		
		if (inicio == NULL) {
			inserir_pilha(rand() % 20, &inicio);
		} else {
			do {
				dado = rand() % 20;
				
				e = existe(dado, inicio);
				if(e == 0) {
					dado = rand() % 20;
					e = existe(dado, inicio);
				}
				
			} while (e == 1);
			
			inserir_pilha(dado, &inicio);
			
		}
		
	}

	imprimir_pilha(inicio);
}
	
int existe(int n, no *inicio) {
	
	while (inicio) {
		if (inicio->dado == n){
			printf("oi\n");
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
