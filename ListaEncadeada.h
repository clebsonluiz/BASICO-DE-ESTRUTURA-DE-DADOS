#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct list {
	int valor;
	struct list * proximo;
} Lista;

void Lista_inicialize();

void Lista_destructor();

int Lista_append(int valor);

int Lista_insertAt(int index, int valor);

int Lista_removeAt(int index);

int Lista_empty();

int Lista_size();

int Lista_elementAt(int index);

void Lista_all();

void Lista_test();



#endif
