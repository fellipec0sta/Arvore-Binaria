#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
typedef struct no no;

typedef struct arvorebinaria ABB;

lista *criarArvore();

void adicionar(ABB *arvore, int chave);

void remover(ABB *arvore, int chave);

no *procurarChave(no *n, int chave);

no *minimo(no *n);

no *maximo(no *n);

no *predecessor(no *n);

no *sucessor(no *n);

int arvoreBinariaValida(ABB *arvore);

void free(ABB *arvore);
#endif