/* TAD da Arvore Binaria de Busca */

#ifndef __TAD_ARVORE_
#define __TAD_ARVORE_

typedef struct treenode{
	struct treenode *left;		// Apontador que servir� como caminho para os n�s da esquerda da raiz
	struct treenode *right;		// Apontador que servir� como caminho para os n�s da direita da raiz
	int info;					// Vari�vel inteira que armazenar� a informa��o do n�
	int height;					// Vari�vel inteira que armazenar� a altura do n�
}node;

// Fun��o respons�vel por iniciar o n� raiz da �rvore
node *create_root();	// Esta fun��o retornar� a raiz com seus ponteiros apontando para NULL, indicando que a �rvore est� vazia

// Fun��o respons�vel por inserir um elemento na �rvore
node *insert(node *root, int data);	// Esta fun��o ir� percorrer a �rvore e posicionar uma nova informa��o de maneira recursiva na �rvore

// Fun��o respos�vel por remover uma informa��o da �rvore
node *remove_node(node *root, int data); // Esta fun��o receber� um n�mero inteiro e o remover� da �rvore, caso ele exista

// Fun��o respons�vel por procurar um elemento na �rvore
void search(node *root, int data);	// Esta fun��o vai percorrer a �rvore a procura de um elemento e vai exibi-lo caso ele esteja presente, caso contr�rio exibir� uma mensagem

// Fun��o respons�vel por exibir a �rvore
void in_order(node *root);	// Esta fun��o vai percorrer a �rvore utilizando o percurso in-ordem e imprimi-la na tela

// Fun��o respons�vel por exibir a �rvore
void pre_order(node *root);	// Esta fun��o vai percorrer a �rvore utilizando o percurso pre-ordem e imprimi-la na tela

// Fun��o respons�vel por exibir a �rvore
void post_order(node *root);	// Esta fun��o vai percorrer a �rvore utilizando o percurso pos-ordem e imprimi-la na tela

// Fun��o respons�vel por calcular a altura da �rvore
int tree_depth(node *root);		// esta fun��o vai percorrer a �rvore recursivamente calculando � altura da �rvore

// Fun��o respons�vel por balancear � arvore
node *balance(node *root);
#endif
