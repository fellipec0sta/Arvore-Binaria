#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"

int main()
{
	char funcao[20];
	int valor;
	p *ABB = criarArvore();
	do
	{
		scanf("%s %d", funcao, &valor);
		if (strcmp(funcao,"insert") == 0)
		{
			adicionar(arvore->raiz, valor);
		}
		else if(strcmp(funcao,"remove") == 0)
		{
			remover(arvore->raiz, valor);
		}
	} while(strcmp(funcao,"fim") != 0);
	printf("END\n");
	return 0;
}