#ifndef PILHA_H
#define PILHA_H

typedef struct stack {
	int elemento;
	struct stack * prox;
} Pilha;

void Pilha_constructor();

void Pilha_destructor();

void Pilha_push(int elemento);

int Pilha_pop();

int Pilha_empty();

int Pilha_stacktop();

int Pilha_size();

void Pilha_showTopo();

void Pilha_test();

#endif
