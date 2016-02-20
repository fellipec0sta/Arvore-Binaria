typedef no no;
struct no
{
	no *esquerda;
	no *direita;
	no *pai
	int chave;
};

typedef arvorebinaria ABB;
struct arvorebinaria
{
	no *raiz;
};

ABB *criarArvore()
{
	no *arvore;
	arvore = (ABB *) malloc(sizeof(ABB));
	arvore->raiz = NULL;
}

void adicionar(no *n, int chave)
{
	if(n == NULL)
		no *a = (no *) malloc(sizeof(no));
		a->chave = chave;
		a->pai = NULL;
		arvore->raiz = a;
	else if(n->chave < chave)
	{
		if(n->direita != NULL)
		{
			n = n->direita;
			return adicionar(n, chave);
		}
		else
		{
			no *a = (no *) malloc(sizeof(no));
			a->chave = chave;
			a->pai = n;
			n->direita = a;
		}
	}
	else if(n->chave > chave)
	{
		if(n->esquerda != NULL)
		{
			n = n->esquerda;
			return adicionar(n, chave);
		}
		else
		{
			no *a = (no *) malloc(sizeof(no));
			a->chave = chave;
			a->pai = n;
			n->esquerda = a;
		}
	}
	else
	{

	}
}

void remover(no * n, int chave)
{

	if(n->chave == chave)
	{

		if(n->esquerda != NULL && n->direita != NULL)
		{

			no *p = sucessor(n);

			if(p->direita != NULL){
				p->pai->esquerda = p->direita;
				p->direita->pai = p->pai;
			}
			p->direita = n->direita;
			p->direita->pai = p;
			p->esquerda = n->esquerda;
			p->esquerda->pai = p;
			p->pai = n->pai;
			no *aux;
			aux = n;
			n = p;
			free(aux);
			free(p);
		}
		//esquerda
		else if(n->esquerda != NULL && n->direita == NULL){

			no *p = predecessor(n);
			// filho esquerdo.
			if(p->esquerda != NULL){
				p->pai->direita = p->esquerda;
				p->esquerda->pai = p->pai;
			}

			p->direita = NULL;
			p->esquerda = n->esquerda;
			p->esquerda->pai = p;
			p->pai = n->pai;
			no *aux;
			aux = n;
			n = p;
			free(aux);
			free(p);
		}
		//direita
		else if(n->esquerda == NULL && n->direita != NULL){

			no *p = sucessor(n);

			if(p->direita != NULL)
			{
				p->pai->esquerda = p->direita;
				p->direita->pai = p->pai;
			}

			p->direita = n->direita;
			p->direita->pai = p;
			p->esquerda = n->esquerda;
			p->esquerda->pai = p;
			p->pai = n->pai;
			no *aux;
			aux = n;
			n = p;
			free(aux);
			free(p);
		}
		//Nada
		else if(n->esquerda == NULL && n->direita == NULL)
		{
			if(n->pai != NULL)
			{
				if(n->chave < n->pai->chave)
				{
					n->esquerda = NULL;
					n = NULL;
				}
				else
				{
					n->direita = NULL;
					n = NULL;
				}
			}

			else
			{
				n = NULL;
			}
		}
	}
	else
	{

		if(chave > n->chave)
		{
			n = n->direita;
			remover(n,chave);
		}
		else
		{
			n = n->esquerda;
			remover(n,chave);
		}
	}
}

no *procurarChave(no *n, int chave)
{

	if(n->direita == NULL && n->esquerda == NULL && n->chave != chave)
	{
		return NULL;
	}
	else if(chave < n->chave)
	{
		return procurarChave(n->esquerda, chave);
	}
	else if(chave > n->chave)
	{
		return procurarChave(n->direita, chave);
	}
	return n;
}

no *minimo(no *n)
{

	if(n->esquerda == NULL)
		return no;
	return minimo(n->esquerda);
}

no *maximo(no *n)
{

	if(n->direita == NULL)
		return n;
	return minimo(n->direita);
}

no *predecessor(no *n)
{

	if(n->esquerdo == NULL)
	{
		return NULL;
	}
	else
	{

		n = n->esquerdo;
		while(n->direita != NULL)
		{
			n = n->direita;
		}
	}
	return n;
}

no *sucessor(no *n);
{

	if(n->direita == NULL)
	{
		return NULL;
	}
	else
	{

		n = n->direita;
		while(n->esquerda != NULL)
		{
			n = n->esquerda;
		}
	}
	return n;
}

int arvoreBinariaValida(ABB *arvore)
{
	percorrer(arvore);
	if(n->pai > n->esquerda && n->pai < n->direita)
		return 1;
	return -1;
	 //criar uma segunda função para fazer o percurso recebendo um nó como parametro de forma
	 //recursiva e te responda se a árvore com raiz naquele nó é uma ABB ou não
	//se você souber que a subárvore esquerda e direita desse nó x obedecem às propriedades da ABB,
	// é possível concluir que a subárvore com raiz em x obedece uma ABB
}

void free(ABB *arvore)
{
	if(arvore->raiz != NULL)
		return remover(arvore->raiz, arvore->raiz->chave);
}

void percorrer(no *n)
{
	printf("%d ", n->chave);
	if(n->esquerda != NULL)
		return percorrer(n->esquerda);
	if(n->direita != NULL)
		return percorrer(n->direita);
}