/* TAD da Arvore Binaria de Busca */

#ifndef __TAD_ARVORE_
#define __TAD_ARVORE_

typedef struct treenode{
	struct treenode *left;		// Apontador que servirá como caminho para os nós da esquerda da raiz
	struct treenode *right;		// Apontador que servirá como caminho para os nós da direita da raiz
	int info;					// Variável inteira que armazenará a informação do nó
	int height;					// Variável inteira que armazenará a altura do nó
}node;

// Função responsável por iniciar o nó raiz da árvore
node *create_root();	// Esta função retornará a raiz com seus ponteiros apontando para NULL, indicando que a árvore está vazia

// Função responsável por inserir um elemento na árvore
node *insert(node *root, int data);	// Esta função irá percorrer a árvore e posicionar uma nova informação de maneira recursiva na árvore

// Função resposável por remover uma informação da árvore
node *remove_node(node *root, int data); // Esta função receberá um número inteiro e o removerá da árvore, caso ele exista

// Função responsável por procurar um elemento na árvore
void search(node *root, int data);	// Esta função vai percorrer a árvore a procura de um elemento e vai exibi-lo caso ele esteja presente, caso contrário exibirá uma mensagem

// Função responsável por exibir a árvore
void in_order(node *root);	// Esta função vai percorrer a árvore utilizando o percurso in-ordem e imprimi-la na tela

// Função responsável por exibir a árvore
void pre_order(node *root);	// Esta função vai percorrer a árvore utilizando o percurso pre-ordem e imprimi-la na tela

// Função responsável por exibir a árvore
void post_order(node *root);	// Esta função vai percorrer a árvore utilizando o percurso pos-ordem e imprimi-la na tela

// Função responsável por calcular a altura da árvore
int tree_depth(node *root);		// esta função vai percorrer a árvore recursivamente calculando á altura da árvore

// Função responsável por balancear á arvore
node *balance(node *root);
#endif
