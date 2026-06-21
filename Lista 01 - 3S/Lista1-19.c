/*19.Utilizando PILHA, desenvolva um programa que verifique se uma palavra é
palíndromo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct apelido_no {
	char palavra;
	struct apelido_no *proximo;	
}no;

char pop(no **inicio);
void push(char palavra, no **inicio);
void imprimir_pilha(no *inicio);
void remover_pilha(no **inicio);

int main() {
	no *inicio = NULL;
	char palavra[30];
	int palindromo = 1, op, tamanho, i;
	
	do {
		palindromo = 1;
		system("cls");
		printf("\nMenu\n");
		printf("1 - Confere se e palindromo: \n");
		printf("2 - Sair\n");

		scanf("%d", &op);
		
		switch (op) {
			case 1:
				system("cls");
				fflush(stdin);
				printf("Digite uma palavra \n");
				fgets(palavra, 30, stdin);
				palavra[strcspn(palavra, "\n")] = '\0';
				tamanho = strlen(palavra);
				
				for(i = 0; i < tamanho; i ++) {
					push(palavra[i], &inicio);
				}
				
				for (i = 0; i < tamanho; i++) {
					if(palavra[i] != pop(&inicio)) {
						palindromo = 0;
					}
				}
				
				if(palindromo == 1) {
					printf("A Palavra e um palindromo\n");
				} else {
					printf("A Palavra nao e um palindromo\n");
				}
				system("pause");
				break;
		}
	} while (op != 2);
	
	remover_pilha(&inicio);
	
}
//-----------------------------------------------
void push(char palavra, no **inicio){
	no *novo = malloc(sizeof(no));
	
	novo->palavra = palavra;
	
	if (novo) {
		novo->proximo = *inicio;
		*inicio = novo;
		
		
	} else {
		printf("Alocação não foi bem sucedida");
	}
}

char pop(no **inicio) {
	no *aux = *inicio;
	char tmp;
	
	tmp = aux->palavra;
		
	*inicio = (*inicio)->proximo;
	free(aux);
	aux = *inicio;
	
	return tmp;
	
}

void remover_pilha(no **inicio) {
	no *aux = *inicio;
	
	while (*inicio) {
		*inicio = (*inicio)->proximo;
		free(aux);
		aux = *inicio; 
	}
}

