/*20) Exercício – Integração de Lista, Fila e Pilha
As turmas de Análise e Desenvolvimento de Sistemas (ADS) e Engenharia de
Software (ESOFT) da Unicesumar estão realizando uma promoção para arrecadar
recursos para a formatura.
Para a retirada das pizzas vendidas, foi realizado um sorteio com 10 participantes.
Os nomes dos sorteados deverão ser armazenados em uma LISTA, que
representará o cadastro das pessoas autorizadas a retirar as pizzas.
No dia da retirada, os participantes chegarão à pizzaria e serão atendidos por ordem
de chegada. Portanto, deverá ser utilizada uma FILA para organizar os sorteados
que aguardam atendimento. 
A pizzaria produzirá as pizzas conforme sua disponibilidade. Cada pizza pronta será
embalada e colocada sobre as demais, formando uma PILHA de pizzas prontas para
entrega.
O funcionamento do sistema deverá seguir as seguintes regras:
• Cadastrar os 10 sorteados em uma LISTA.
• À medida que os sorteados chegarem à pizzaria, inseri-los na FILA de
atendimento.
• Conforme as pizzas forem ficando prontas, elas deverão ser EMPILHADAS na
PILHA de pizzas prontas.
• Quando ocorrer uma entrega:
1. A pessoa que está no início da FILA deverá ser atendida (desenfileiramento);
2. A pizza que estiver no topo da PILHA deverá ser retirada (desempilhamento);
3. Na LISTA de sorteados, a pessoa deverá ser marcada como "Pizza Retirada".
• O processo continua até que todas as pizzas tenham sido entregues.
O programa deverá permitir:
• Inserir e visualizar os sorteados da LISTA;
• Inserir e visualizar pessoas na FILA de atendimento;
• Inserir e visualizar pizzas na PILHA de pizzas prontas;
• Realizar a entrega de pizzas, efetuando simultaneamente o desenfileiramento
da pessoa e o desempilhamento da pizza;
• Consultar a LISTA de sorteados, identificando quais pessoas já retiraram sua
pizza e quais ainda não retiraram.

Estruturas de Dados
Professor Moreno

Lista2 – pilhas, filas e listas

Observações
• As estruturas de dados (LISTA, FILA e PILHA) deverão ser implementadas
utilizando linguagem C.
• Cada aluno deverá definir livremente as structs necessárias, bem como seus
atributos, de acordo com sua interpretação da regra de negócio.
• É recomendado que as structs possuam informações suficientes para
identificar pessoas, pizzas e o status de retirada.
• A implementação deverá demonstrar claramente o uso correto das operações
fundamentais de cada estrutura de dados:
o Lista: inserção, consulta e atualização;
o Fila: enqueue (enfileirar) e dequeue (desenfileirar);
o Pilha: push (empilhar) e pop (desempilhar).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct apelido_no {
	int dado;
	struct apelido_no *proximo;	
}no;

typedef struct apelido_no_lista {
	int dado;
	int pizza_retirada;
	struct apelido_no_lista *proximo;
	struct apelido_no_lista *anterior;	
}lista;


void inserir_fila(int dado, no **inicio_fila, no **fim_fila);
void imprimir_fila(no *inico);
void remover_fila(no **inicio);

void inserir_lista(int n, lista **inicio_lista);
void imprimir_lista(lista *inicio_lista);
int existe(int n, lista *inicio_lista);
void remover_lista(int dado, lista **inicio_lista);

void imprimir_pilha(no *inicio_pilha);
void inserir_pilha(int dado, no **inicio_pilha);
void remover_pilha(no **inicio_pilha);

int main() {
	lista *inicio_lista = NULL;
	lista *aux;
	
	no *inicio_fila = NULL;
	no *fim_fila = NULL;
	
	no *inicio_pilha = NULL;
	
	int i, op, dado, e, encontrou = 0;
	int pizza = 0;
	
	srand(time(NULL));
	
	do {
		system("cls");
		printf("\nMenu\n");
		printf("1 - Inserir 10 participantes na lista\n");
		printf("2 - Consultar lista\n");
		printf("3 - Inserir 1 participante na fila\n");
		printf("4 - Imprimir fila\n");
		printf("5 - Registrar pizza pronta\n");
		printf("6 - Imprimir pilha\n");
		printf("7 - Atender fila\n");
		printf("8 - Sair\n");
		scanf("%d", &op);
		printf("\n-------------------------------------\n");
		
		switch (op) {
			case 1:
				for(i = 0; i < 10; i++) {
		
					if (inicio_lista == NULL) {
						inserir_lista((rand() % 90) + 10, &inicio_lista);
					} else {
						do {
							dado = (rand() % 90) + 10;
							
							e = existe(dado, inicio_lista);
							if(e == 0) {
								dado = (rand() % 90) + 10;
								e = existe(dado, inicio_lista);
							}
							
						} while (e == 1);
						
						inserir_lista(dado, &inicio_lista);	
					}
				}
				break;	
			case 2:
				imprimir_lista(inicio_lista);
				break;
			case 3:
				system("cls");
				printf("Quem entrou na fila?\n");
				scanf("%d", &dado);
				
				encontrou = 0;
				aux = inicio_lista;
				while (aux) {
					if (aux->dado == dado) {
						encontrou = 1;
					}
					aux = aux->proximo;
				}
				
				if (encontrou == 1) {
					inserir_fila(dado, &inicio_fila, &fim_fila);
					
				} else {
					printf("valor nao encontrado na lista\n");
					system("pause");
				}
				
				break;
			case 4:
				imprimir_fila(inicio_fila);
				system("pause");
				break;
			case 5:
				pizza++;
				inserir_pilha(1, &inicio_pilha);
				printf("Pizza entrou na pilha!\n");
				break;
				
			case 6:
				imprimir_pilha(inicio_pilha);
				system("pause");
				break;
			case 7:
				
				if (inicio_fila && inicio_pilha) {
					dado = inicio_fila->dado;
					remover_lista(dado, &inicio_lista);
					remover_fila(&inicio_fila);
					remover_pilha(&inicio_pilha);
					printf("Fila atendida!\n");
					break;
				} else {
					printf("A fila esta vazia ou nao tem pizzas na pilha\n");
				}
				system("pause");
		}
	} while (op != 8 );
}
//-------------------------------------- LISTA
void remover_lista(int dado, lista **inicio_lista) {
	lista *aux = *inicio_lista;
	
	while (aux && aux->dado != dado) {
		aux = aux->proximo;
	}
	aux->pizza_retirada = 1;
}

int existe(int n, lista *inicio_lista) {
	
	while (inicio_lista) {
		if (inicio_lista->dado == n){
			return 1;	
		} 
		inicio_lista = inicio_lista->proximo;
	}
	return 0;
}

void inserir_lista(int n, lista **inicio_lista) {
	lista *novo = malloc(sizeof(lista));
	
	novo->dado = n;
	novo->anterior = NULL;
	novo->pizza_retirada = 0;
	
	if (*inicio_lista == NULL) {
		novo->proximo = NULL;
		*inicio_lista = novo;
	} else {
		novo->proximo = *inicio_lista;
		*inicio_lista = novo;
		novo->proximo->anterior = novo;
	}
	
}
void imprimir_lista(lista *inicio_lista) {
	while (inicio_lista){
		
		if (inicio_lista->pizza_retirada == 0) {
			printf("%d - Pizza nao retirada\n", inicio_lista->dado);
			inicio_lista = inicio_lista->proximo;
		} else {
			printf("%d - Pizza retirada\n", inicio_lista->dado);
			inicio_lista = inicio_lista->proximo;
		}
		
	}
	system("pause");
}
//-------------------------------------- FILA
void inserir_fila(int dado, no **inicio, no **fim){
	no *novo = malloc(sizeof(no));
	
	novo->dado = dado;
	novo->proximo = NULL;
	
	if (novo) {
		if (*fim) {
			(*fim)->proximo = novo;
			*fim = novo;
		} else {
			*inicio = novo;
			*fim = novo;	
		}
			
	} else {
		printf("Alocação nao foi bem sucedida");
	}
}

void imprimir_fila(no *inicio_fila) {
		while (inicio_fila) {
			printf("pessoa: %d \n", inicio_fila->dado);
			inicio_fila = inicio_fila->proximo; 
		}
}

void remover_fila(no **inicio_fila) {
	no *aux = *inicio_fila;
	
	*inicio_fila = (*inicio_fila)->proximo;
	free(aux);
	aux = *inicio_fila;
}
//-------------------------------------- PILHA
void inserir_pilha(int dado, no **inicio_pilha){
	no *novo = malloc(sizeof(no));
	
	novo->dado = dado;
	
	if (novo) {
		novo->proximo = *inicio_pilha;
		*inicio_pilha = novo;
		
		
	} else {
		printf("Alocação nao foi bem sucedida");
	}

}

void imprimir_pilha(no *inicio_pilha) {
	
		while (inicio_pilha) {
			printf("%d pizza pronta\n", (inicio_pilha)->dado);
			inicio_pilha = (inicio_pilha)->proximo; 
		}
		
}

void remover_pilha(no **inicio_pilha) {
	no *aux = *inicio_pilha;
	
	*inicio_pilha = (*inicio_pilha)->proximo;
	free(aux);
}













