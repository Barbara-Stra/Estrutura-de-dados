//15.Utilizando linguagem C, construa um programa que possua um menu (inserir, remover, imprimir e sair) e contemple 
//uma FILA contendo nome e idade. O nome não poderá ter tamanho fixo, ou seja, deverá ser alocado dinamicamente.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct apelido_no {
	int dado;
	char *nome;
	struct apelido_no *proximo;	
}no;

void dequeue(no **inicio);
void enqueue(int dado, char *nome, no **inicio, no **fim);
void imprimir_fila(no *inicio);
void remover_fila(no **inicio);

int main() {
	no *inicio = NULL, *fim = NULL;
	char nome[30];
	int idade, op;
	
	do {
		system("cls");
		printf("\nMenu\n");
		printf("1 - Enqueue\n");
		printf("2 - Dequeue\n");
		printf("3 - Imprimir\n");
		printf("4 - Sair\n");
		scanf("%d", &op);
		
		switch (op) {
			case 1:
				system("cls");
				fflush(stdin);
				printf("Digite um nome: \n");
				fgets(nome, 100, stdin);
				nome[strcspn(nome, "\n")] = '\0';
				
				printf("Digite a idade: \n");
				scanf("%d", &idade);
				
				enqueue(idade, nome, &inicio, &fim);
				break;
			case 2:
				dequeue(&inicio);
				break;
			case 3:
				imprimir_fila(inicio);
				system("pause");
				break;
		}
	} while (op != 4);
	
	remover_fila(&inicio);
	
}
//-----------------------------------------------
void enqueue(int dado, char *nome, no **inicio, no **fim){
	no *novo = malloc(sizeof(no));
	
	if (novo) {
	novo->dado = dado;
	novo->proximo = NULL;
	
	novo->nome = malloc(strlen(nome) + 1);
	strcpy(novo->nome, nome);
	
		if (*fim) {
			(*fim)->proximo = novo;
			*fim = novo;
		} else {
			*fim = novo;
			*inicio = novo;
		}
		
	} else {
		printf("Alocação não foi bem sucedida");
	}
}

void dequeue(no **inicio) {
	no *aux = *inicio;
	
	*inicio = (*inicio)->proximo;
	free(aux);
	aux = *inicio;
}

void imprimir_fila(no *inicio) {
	
		while (inicio) {
			printf("%s, %d anos \n", inicio->nome, inicio->dado);
			inicio = inicio->proximo; 	
		}
		
}

void remover_fila(no **inicio) {
	no *aux = *inicio;
	
	while (*inicio) {
		*inicio = (*inicio)->proximo;
		free(aux);
		aux = *inicio; 
	}
}
