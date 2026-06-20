/*11.Desenvolva um programa denominado PILHA1 em linguagem C que
implemente as operações de uma pilha (pop, push e imprimir) cujo nó deverá
conter nome[30] e idade. O usuário deverá ter a opção de empilhar,
desempilhar, mostrar pilha e sair.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct apelido_no {
	int dado;
	char nome[30];
	struct apelido_no *proximo;	
}no;

void pop(no **inicio);
void push(int dado, char *nome, no **inicio);
void imprimir_pilha(no *inicio);
void remover_pilha(no **inicio);

int main() {
	no *inicio = NULL;
	char nome[30];
	int idade, op;
	
	do {
		system("cls");
		printf("\nMenu\n");
		printf("1 - Push\n");
		printf("2 - Pop\n");
		printf("3 - Imprimir\n");
		printf("4 - Sair\n");
		scanf("%d", &op);
		
		switch (op) {
			case 1:
				system("cls");
				fflush(stdin);
				printf("Digite um nome: \n");
				fgets(nome, 30, stdin);
				nome[strcspn(nome, "\n")] = '\0';
				
				printf("Digite a idade: \n");
				scanf("%d", &idade);
				
				push(idade, nome, &inicio);
				break;
			case 2:
				pop(&inicio);
				break;
			case 3:
				imprimir_pilha(inicio);
				system("pause");
				break;
		}
	} while (op != 4);
	
	remover_pilha(&inicio);
	
}
//-----------------------------------------------
void push(int dado, char *nome, no **inicio){
	no *novo = malloc(sizeof(no));
	
	novo->dado = dado;
	strncpy(novo->nome, nome, 30);
	
	if (novo) {
		novo->proximo = *inicio;
		*inicio = novo;
		
		
	} else {
		printf("Alocação não foi bem sucedida");
	}
}

void pop(no **inicio) {
	no *aux = *inicio;
	
	*inicio = (*inicio)->proximo;
	free(aux);
	aux = *inicio;
}

void imprimir_pilha(no *inicio) {
	
		while (inicio) {
			printf("%s, %d anos \n", inicio->nome, inicio->dado);
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
