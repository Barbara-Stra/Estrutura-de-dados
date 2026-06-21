/*20.Desenvolva um programa que leia uma expressão matemática e utilize
PILHA para verificar se:
parênteses;
colchetes;
chaves;
estão balanceados.
Exemplo:
( A + B ) * { C - D }*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct apelido_no {
	char dado;
	struct apelido_no *proximo;	
} no;

void push(char dado, no **inicio);
void remover_pilha(no **inicio);

int pilha_vazia(no *inicio);
int abertura(char c);
int fechamento(char c);
int combina(char abre, char fecha);

char pop(no **inicio);

int main() {
	no *inicio = NULL;
	char expressao[50], top;
	int i, balanceada = 1;
	
	printf("Digite uma expressao: \n");
	fgets(expressao, 50, stdin);
	expressao[strcspn(expressao, "\n")] = '\0';
	
	for(i = 0; expressao[i] != '\0'; i++) {
		
		if(abertura(expressao[i])) {
			push(expressao[i], &inicio);
		}
		else if(fechamento(expressao[i])) {
			
			if(pilha_vazia(inicio)) {
				balanceada = 0;
				break;
			}
			
			top = pop(&inicio);
			
			if(combina(top, expressao[i]) == 0) {
				balanceada = 0;
				break;
			}
		}
	}
	
	if(pilha_vazia(inicio) == 0) {
		balanceada = 0;
	}
	
	if(balanceada == 1) {
		printf("A expressao esta balanceada\n");
	} else {
		printf("A expressao nao esta balanceada\n");
	}
	
	remover_pilha(&inicio);
	
}
//------------------------------------------------
void push(char dado, no **inicio) {
	no *novo = malloc(sizeof(no));
	
	if(novo) {
		novo->dado = dado;
		novo->proximo = *inicio;
		*inicio = novo;
	} else {
		printf("Alocacao nao deu certo\n");
	}
}

char pop(no **inicio) {
	no *aux = *inicio;
	char tmp;
	
	tmp = aux->dado;
	*inicio = (*inicio)->proximo;
	free(aux);
	
	return tmp;
}

int pilha_vazia(no *inicio) {
	if(inicio == NULL) {
		return 1;
	}
	return 0;
}

int abertura(char c) {
	if(c == '(' || c == '[' || c == '{') {
		return 1;
	}
	return 0;
}

int fechamento(char c) {
	if(c == ')' || c == ']' || c == '}') {
		return 1;
	}
	return 0;
}

int combina(char abre, char fecha) {
	if(abre == '(' && fecha == ')') {
		return 1;
	}
	if(abre == '[' && fecha == ']') {
		return 1;
	}
	if(abre == '{' && fecha == '}') {
		return 1;
	}
	return 0;
}

void remover_pilha(no **inicio) {
	no *aux = *inicio;
	
	while(*inicio) {
		*inicio = (*inicio)->proximo;
		free(aux);
		aux = *inicio;
	}
}
