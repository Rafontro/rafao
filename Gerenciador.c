#include <stdio.h>
#include <locale.h>
#include "TadArvore.c"

int main(void){
	setlocale(LC_ALL, "portuguese");
	node *root = create_root();
	
	return 0;
}
