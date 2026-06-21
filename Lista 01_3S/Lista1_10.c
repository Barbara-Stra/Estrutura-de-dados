/*10.Construma um progama em linguagem C que implemente uma FILA
contendo o nome e idade de 10 pessoas fornecidas pelo usuário.
Posteriormente, monte mais duas filas (FILA2 e FILA3) onde a primeira
deverá conter as pessoas até 30 anos e a segunda acima de 30. Apresente
as duas novas filas ao usuário e posteriormente encerre o programa,
liberando a memória das três filas. Obs. A fila inicial deverá ser esvaziada ao
final do processo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct apelido_no {
	int dado;
	char nome[50];
	struct apelido_no *proximo;	
}no;

void inserir_fila(int dado, char *nome, no **inicio, no **fim);
void remover_fila(no **inicio_fila);
void imprimir_fila(no *inico);
void distribui_fila(no **inicio_fila, no **inicio_fila2, no **inicio_fila3, no **fim_fila1, no **fim_fila2, no **fim_fila3);

int main() {
	no *inicio_fila = NULL, *inicio_fila2 = NULL, *inicio_fila3 = NULL;
	no *fim_fila = NULL, *fim_fila2 = NULL, *fim_fila3 = NULL;
	int i, idade;
	char nome[50];
	
	for(i = 0; i < 3; i++) {
		
		system("cls");
		fflush(stdin);
		printf("Digite um nome: \n");
		fgets(nome, 30, stdin);
		nome[strcspn(nome, "\n")] = '\0';
		
		printf("Digite uma idade: \n");
		scanf("%d", &idade);
		
		inserir_fila(idade, nome, &inicio_fila, &fim_fila);
	}
	
	distribui_fila(&inicio_fila, &inicio_fila2, &inicio_fila3, &fim_fila, &fim_fila2, &fim_fila3);
	
	printf("\nFila menor que 30\n");
	imprimir_fila(inicio_fila2);
	
	printf("\n\nFila maior que 30\n");
	imprimir_fila(inicio_fila3);
	
	remover_fila(&inicio_fila);
	remover_fila(&inicio_fila2);
	remover_fila(&inicio_fila3);
}

void inserir_fila(int dado, char *nome, no **inicio, no **fim){
	no *novo = malloc(sizeof(no));
	
	novo->dado = dado;
	novo->proximo = NULL;
	strncpy(novo->nome, nome, 30);
	
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

void distribui_fila(no **inicio_fila, no **inicio_fila2, no **inicio_fila3, no **fim_fila1, no **fim_fila2, no **fim_fila3) {
	no *aux = *inicio_fila;
	
	while (aux) {
		if (aux->dado <= 30) {
			inserir_fila(aux->dado, aux->nome, inicio_fila2, fim_fila2);
		} else {
			inserir_fila(aux->dado, aux->nome, inicio_fila3, fim_fila3);
		}
		aux = aux->proximo;
	}
	
	remover_fila(inicio_fila);
	
}

void remover_fila(no **inicio_fila) {
	no *aux = *inicio_fila;
	
	while (*inicio_fila) {
		*inicio_fila = (*inicio_fila)->proximo;
		free(aux);
		aux = *inicio_fila; 
	}
}

void imprimir_fila(no *inicio_fila) {
		while (inicio_fila) {
			printf("nome: %s - idade: %d \n", inicio_fila->nome, inicio_fila->dado);
			inicio_fila = inicio_fila->proximo; 
		}
}
