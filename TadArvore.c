#include <stdio.h>
#include "TadArvore.h"
#include <stdbool.h>
#include <stdlib.h>

// Vari�vel que impedir� que o usu�rio acesse fun��es que interagem com a �rvore, antes que ela seja criada
bool criou = false;	// Iniciada com False pois quando o programa � iniciado n�o existe raiz

// Fun��o que cria o n� raiz
node *create_root()
{
	if(!criou)	// Se o n� raiz ainda n�o foi criado, cria
	{
		criou = true;
		return NULL;	// Fazendo o n� raiz apontar para NULL, indicando que a �rvore est� vazia
	}else{printf("A �rvore j� foi criada!\n");}	// Caso o n� raiz j� tenha sido criado, exibir mensagem

	system("pause");	// Pausa o programa para que o usu�rio possa ler as informa��es
}

// Fun��o que insere um elemento na �rvore
node *insert(node *root, int data)
{
	if(root == NULL)	// Se a �rvore estiver vazia, criar novo n�
	{
		root = (node*)malloc(sizeof(node));	// Aloca espa�o na mem�ria para o novo n�
		root->info = data;	// Armazena no n�, a informa��o desejada
		root->left = NULL;	// Aponta o ponteiro da esquerda para NULL para indicar que n�o h� mais n�s � esquerda
		root->right = NULL;	// Aponta o ponteiro da direita para NULL para indicar que n�o h� mais n�s � direita
		return root;
	}else{
		if(data > root->info)	// Se o elemento a ser inserido for maior que a informa��o do n�, chama a fun��o insere indo para a direita
		{
			root->right = insert(root->right, data);	// Chamando fun��o insere de maneira recursiva
		}else
		{
			if(data <= root->info)	// Se o elemento a ser inserido for menor que a informa��o do n�, chama a fun��o insere indo para a esquerda
			{
				root->left = insert(root->left, data);	// Chamando fun��o insere de maneira recursiva
			}
		}
	}
	// balance
}

// Fun��o que remove um item da �rvore
node *remove_node(node *root, int data)
{
	node *aux = root;
	if(aux == NULL)	// Se a �rvore estiver vazia, exibir mensagem
	{
		printf("A �rvore est� vazia!");
		system("pause");	// Pausa o programa para que o usu�rio possa ler as informa��es
		return root;
	}else
	{
		if(data > aux->info)	// Se a informa��o for maior que o dado no n�, chamar fun��o indo para a direita
		{
			aux->right = remove_node(root->right, data);	// Chama a fun��o recursivamente para a direita
		}else
		{
			if(data < aux->info)	// Se a informa��o for menor que o dado no n�, chamar fun��o indo para a esquerda
			{
				aux->left = remove_node(root->left, data);	// Chama a fun��o recursivamente para a esquerda
			}else
			{
				/*Primeiro caso de remo��o: Quando o n� a ser removido � uma folha (n�o possui filhos)*/
				if((aux->left == NULL) && (aux->right == NULL))
				{
					free(aux);	// Remove o n�
					aux = NULL;	// Faz com que o espa�o do n� removido fique nulo para indicar que n�o existe mais um n�
				}else
				{
					/*Segundo caso de remo��o: Quando a n� possui apenas um filho*/
					if(aux->left == NULL)	// Quando o filho � � esquerda
					{
						node *aux_2 = aux;
						aux = aux->right;
						free(aux_2);
					}else
					{
						if(aux->right == NULL)	// Quando o filho � � direita
						{
							node *aux_2 = aux;
							aux = aux->left;
							free(aux_2);
						}else
						{
							/*Terceiro caso de remo��o: Quando o n� possui dois filhos*/
							// Procurar antecessor
							node *aux_2 = aux->left;
							while(aux_2->right != NULL)
							{
								aux_2 = aux_2->right;
							}
							// Trocando as informa��es, para que o n� a ser removido seja uma folha
							aux->info = aux_2->info;
							aux_2->info = data;
							aux->left = remove_node(aux->left, data);	// Chamar a fun��o novamente parq retirar a folha
						}
					}
				}
			}
		}
	}
	// balance
	return aux;
}

// Fun��o que confere se uma informa��o est� na �rvore ou n�a
void search(node *root, int data)
{
	node *aux = root;
	if(aux == NULL)	// Se a �rvore estiver vazia nem tenta cuz�o
	{
		system("cls");
		printf("N�mero n�o encontrado\n");
		system("pause");
	}else{
		if(data < aux->info)	// Caso o n�mero procurado seja menor que a informa��o do n�, ir para a esquerda
		{
			search(aux->left, data);	// Chamando fun��o recursivamente indo para a esquerda
		}else{
			if(data > aux->info)	// Caso o n�mero procurado seja maior que a informa��o do n�, ir para a direita
			{
				search(aux->right, data);	// Chamando fun��o recursivamente indo para a direita
			}else{
				system("cls");
				printf("O n�mero [%d] foi encontrado\n", aux->info);
				system("pause");
			}
		}
	}
}

// Imprime na tela com o percurso In Ordem
void in_order(node *root)
{
	node *aux = root;
	if(aux != NULL)		// Se o n� n�o for nulo a informa��o pode ser imprimida
	{
		in_order(aux->left);	// Chama a fun��o para Imprimir os dados � esquerda do n� atual
		printf("%d   ", aux->info);	// Imprime a informa��o do n�
		in_order(aux->right);	// Chama a fun��o para Imprimir os dados � direita do n� atual
	}
}

// Imprime na tela com o percurso Pre Ordem
void pre_order(node *root)
{
	node *aux = root;
	if(aux != NULL)				// Se o n� n�o for nulo a informa��o pode ser imprimida
	{
		printf("%d   ");		// Imprime a informa��o do n�
		pre_order(aux->left);	// Chama a fun��o para Imprimir os dados � esquerda do n� atual
		pre_order(aux->right);	// Chama a fun��o para Imprimir os dados � direita do n� atual
		
	}
}

// Imprime na tela com o percurso P�s ordem
void post_order(node *root)
{
	node *aux = root;
	if(aux != NULL){
		post_order(aux->left);					// Chama a fun��o para imprimir os dados � esquerda do n� atual
		post_order(aux->right);					// Chama a fun��o para imprimir os dados � direita do n� atual
		printf("%d   ");						// Imprime a informa��o do n�
	}else printf("A �rvore est� vazia\n");		// Mensagem caso a �rvore esteja vazia
}

// Fun��o que retorna o tamanho(profundidade) da �rvore
int tree_depth(node *root)
{
	int l_depth = 0,r_depth = 0;	// Iniciando contadores de altura com zero para prevenir futuros erros
	node *aux = root;
	if(aux == NULL)	// Se a n� for zero a �rvore est� vazia, ou seja tem 0 de altura
	{
		return 0;
	}else{
		// Chama a fun��o recursivamente para calcular a altura da sub-�rvore esquerda
		l_depth = tree_depth(aux->left);
		// Chama a fun��o recursivamente para calcular a altura da sub-�rvore direita
		r_depth = tree_depth(aux->right);
		
		// Se o lado esquerdo for maior que o lado direito retorna l_depth(contador de tamanho para o lado esquerdo) + 1, caso contrario retorna r_depth + 1
		if(l_depth > r_depth)
		{
			return (l_depth + 1);
		}else	return r_depth + 1;
	}
}

// Fun��o que faz o balanceamento da �rvore
node *balance(node *root)
{
	// NOT YET AMIGO
}
