#ifndef FILA_H
#define FILA_H

typedef struct queue {
	int valor;
	struct queue * prox;
} Fila;

void Fila_inicialize();

void Fila_destructor();

int Fila_enqueue(int valor);

int Fila_dequeue();

int Fila_empty();

int Fila_size();

int Fila_front();

void Fila_showFront();

void Fila_test();

#endif
