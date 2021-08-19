#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"


int fila_tamanho = -1;

Fila *inicio;
Fila *fim;

void Fila_initialize(){
	inicio = NULL;
	fim = inicio;
	fila_tamanho = 0;
}

void Fila_destructor(){
	free(inicio);
	free(fim);
	fila_tamanho = -1;
}

int Fila_enqueue(int valor){
	Fila *novo = (Fila*)malloc(sizeof(Fila));
	if(novo == NULL){
		return EXIT_FAILURE;
	}
	
	novo->valor = valor;

	if(Fila_empty()){
		inicio = novo;
	}
	else {
		fim->prox = novo;
	}
	fim = novo;
	fila_tamanho ++;

	return 1;
}

int Fila_dequeue(){
	if(Fila_empty()){
		return 0;
	}

	Fila *temp = inicio;
	inicio = temp->prox;
	
	free(temp);
	if(inicio == NULL){
		fim = inicio;
	}

	fila_tamanho --;
	return 1;	
}

int Fila_empty(){
	return (inicio == fim && inicio == NULL);
}

int Fila_front(){
	if(Fila_empty()){
		return EXIT_FAILURE;
	}
	return inicio->valor;
}

int Fila_size(){
	return fila_tamanho;
}

void Fila_showFront(){
	printf("Elemento no inicio:> %i\n", Fila_front());
}

void Fila_test(){
	printf("Iniciando Teste de Fila!\n\n");
	printf("Iniciando Fila!\n\n");
	Fila_initialize();
	printf("%i elementos na fila!\n\n", Fila_size());
	printf("Inserindo o '%i' na fila!\n", 5);
	Fila_enqueue(5);
	Fila_showFront();
	printf("%i elementos na fila!\n\n", Fila_size());
	printf("Inserindo o '%i' na fila!\n", 9);
	Fila_enqueue(9);
	printf("Inserindo o '%i' na fila!\n", 4);
	Fila_enqueue(4);
	printf("Inserindo o '%i' na fila!\n", 6);
	Fila_enqueue(6);
	printf("%i elementos na fila!\n\n", Fila_size());
	Fila_showFront();
	printf("Removendo o inicio!\n");
	Fila_dequeue();
	Fila_showFront();
	printf("Removendo o inicio!\n");
	Fila_dequeue();
	Fila_showFront();
	printf("Removendo o inicio!\n");
	Fila_dequeue();
	Fila_showFront();
	printf("Removendo o inicio!\n");
	Fila_dequeue();
	printf("%i elementos na fila!\n\n", Fila_size());
	printf("Terminando Teste!...\n");
	Fila_destructor();
}