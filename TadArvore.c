#include <stdio.h>
#include "TadArvore.h"
#include <stdbool.h>
#include <stdlib.h>

// Variável que impedirá que o usuário acesse funções que interagem com a árvore, antes que ela seja criada
bool criou = false;	// Iniciada com False pois quando o programa é iniciado não existe raiz

// Função que cria o nó raiz
node *create_root()
{
	if(!criou)	// Se o nó raiz ainda não foi criado, cria
	{
		criou = true;
		return NULL;	// Fazendo o nó raiz apontar para NULL, indicando que a árvore está vazia
	}else{printf("A árvore já foi criada!\n");}	// Caso o nó raiz já tenha sido criado, exibir mensagem

	system("pause");	// Pausa o programa para que o usuário possa ler as informações
}

// Função que insere um elemento na árvore
node *insert(node *root, int data)
{
	if(root == NULL)	// Se a árvore estiver vazia, criar novo nó
	{
		root = (node*)malloc(sizeof(node));	// Aloca espaço na memória para o novo nó
		root->info = data;	// Armazena no nó, a informação desejada
		root->left = NULL;	// Aponta o ponteiro da esquerda para NULL para indicar que não há mais nós à esquerda
		root->right = NULL;	// Aponta o ponteiro da direita para NULL para indicar que não há mais nós à direita
		return root;
	}else{
		if(data > root->info)	// Se o elemento a ser inserido for maior que a informação do nó, chama a função insere indo para a direita
		{
			root->right = insert(root->right, data);	// Chamando função insere de maneira recursiva
		}else
		{
			if(data <= root->info)	// Se o elemento a ser inserido for menor que a informação do nó, chama a função insere indo para a esquerda
			{
				root->left = insert(root->left, data);	// Chamando função insere de maneira recursiva
			}
		}
	}
	// balance
}

// Função que remove um item da árvore
node *remove_node(node *root, int data)
{
	node *aux = root;
	if(aux == NULL)	// Se a árvore estiver vazia, exibir mensagem
	{
		printf("A árvore está vazia!");
		system("pause");	// Pausa o programa para que o usuário possa ler as informações
		return root;
	}else
	{
		if(data > aux->info)	// Se a informação for maior que o dado no nó, chamar função indo para a direita
		{
			aux->right = remove_node(root->right, data);	// Chama a função recursivamente para a direita
		}else
		{
			if(data < aux->info)	// Se a informação for menor que o dado no nó, chamar função indo para a esquerda
			{
				aux->left = remove_node(root->left, data);	// Chama a função recursivamente para a esquerda
			}else
			{
				/*Primeiro caso de remoção: Quando o nó a ser removido é uma folha (não possui filhos)*/
				if((aux->left == NULL) && (aux->right == NULL))
				{
					free(aux);	// Remove o nó
					aux = NULL;	// Faz com que o espaço do nó removido fique nulo para indicar que não existe mais um nó
				}else
				{
					/*Segundo caso de remoção: Quando a nó possui apenas um filho*/
					if(aux->left == NULL)	// Quando o filho é à esquerda
					{
						node *aux_2 = aux;
						aux = aux->right;
						free(aux_2);
					}else
					{
						if(aux->right == NULL)	// Quando o filho é à direita
						{
							node *aux_2 = aux;
							aux = aux->left;
							free(aux_2);
						}else
						{
							/*Terceiro caso de remoção: Quando o nó possui dois filhos*/
							// Procurar antecessor
							node *aux_2 = aux->left;
							while(aux_2->right != NULL)
							{
								aux_2 = aux_2->right;
							}
							// Trocando as informações, para que o nó a ser removido seja uma folha
							aux->info = aux_2->info;
							aux_2->info = data;
							aux->left = remove_node(aux->left, data);	// Chamar a função novamente parq retirar a folha
						}
					}
				}
			}
		}
	}
	// balance
	return aux;
}

// Função que confere se uma informação está na árvore ou nõa
void search(node *root, int data)
{
	node *aux = root;
	if(aux == NULL)	// Se a árvore estiver vazia nem tenta cuzão
	{
		system("cls");
		printf("Número não encontrado\n");
		system("pause");
	}else{
		if(data < aux->info)	// Caso o número procurado seja menor que a informação do nó, ir para a esquerda
		{
			search(aux->left, data);	// Chamando função recursivamente indo para a esquerda
		}else{
			if(data > aux->info)	// Caso o número procurado seja maior que a informação do nó, ir para a direita
			{
				search(aux->right, data);	// Chamando função recursivamente indo para a direita
			}else{
				system("cls");
				printf("O número [%d] foi encontrado\n", aux->info);
				system("pause");
			}
		}
	}
}

// Imprime na tela com o percurso In Ordem
void in_order(node *root)
{
	node *aux = root;
	if(aux != NULL)		// Se o nó não for nulo a informação pode ser imprimida
	{
		in_order(aux->left);	// Chama a função para Imprimir os dados à esquerda do nó atual
		printf("%d   ", aux->info);	// Imprime a informação do nó
		in_order(aux->right);	// Chama a função para Imprimir os dados à direita do nó atual
	}
}

// Imprime na tela com o percurso Pre Ordem
void pre_order(node *root)
{
	node *aux = root;
	if(aux != NULL)				// Se o nó não for nulo a informação pode ser imprimida
	{
		printf("%d   ");		// Imprime a informação do nó
		pre_order(aux->left);	// Chama a função para Imprimir os dados à esquerda do nó atual
		pre_order(aux->right);	// Chama a função para Imprimir os dados à direita do nó atual
		
	}
}

// Imprime na tela com o percurso Pós ordem
void post_order(node *root)
{
	node *aux = root;
	if(aux != NULL){
		post_order(aux->left);					// Chama a função para imprimir os dados à esquerda do nó atual
		post_order(aux->right);					// Chama a função para imprimir os dados à direita do nó atual
		printf("%d   ");						// Imprime a informação do nó
	}else printf("A árvore está vazia\n");		// Mensagem caso a árvore esteja vazia
}

// Função que retorna o tamanho(profundidade) da árvore
int tree_depth(node *root)
{
	int l_depth = 0,r_depth = 0;	// Iniciando contadores de altura com zero para prevenir futuros erros
	node *aux = root;
	if(aux == NULL)	// Se a nó for zero a árvore está vazia, ou seja tem 0 de altura
	{
		return 0;
	}else{
		// Chama a função recursivamente para calcular a altura da sub-árvore esquerda
		l_depth = tree_depth(aux->left);
		// Chama a função recursivamente para calcular a altura da sub-árvore direita
		r_depth = tree_depth(aux->right);
		
		// Se o lado esquerdo for maior que o lado direito retorna l_depth(contador de tamanho para o lado esquerdo) + 1, caso contrario retorna r_depth + 1
		if(l_depth > r_depth)
		{
			return (l_depth + 1);
		}else	return r_depth + 1;
	}
}

// Função que faz o balanceamento da árvore
node *balance(node *root)
{
	// NOT YET AMIGO
}
