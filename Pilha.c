#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"

int pilha_tamanho = -1;

Pilha *topo;

void Pilha_constructor(){
	topo = NULL;
	pilha_tamanho = 0;
}

void Pilha_destructor(){
	free(topo);
	pilha_tamanho = -1;
}

void Pilha_push(int elemento){
	Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
	if(novo == NULL){
		return;
	}
	else {
		novo->elemento = elemento;
		novo->prox = topo;
		topo = novo;
		pilha_tamanho ++;
	}
}

int Pilha_pop(){
	if(Pilha_empty()){
		EXIT_FAILURE;
	}
	
	int valor = topo->elemento;
		
	Pilha *temp = topo->prox;
	
	topo->prox = NULL;
	free(topo);
	topo = temp;
	pilha_tamanho --;
	return valor;	
}

int Pilha_empty(){
	return (topo == NULL);
}

int Pilha_stacktop(){
	if(Pilha_empty()){
		return EXIT_FAILURE;
	}
	return topo->elemento;
}

int Pilha_size(){
	return pilha_tamanho;
}

void Pilha_showTopo(){
	printf("Elemento do Topo:> %i\n", Pilha_stacktop());
}

void Pilha_test(){
	printf("Iniciando teste de Pilha\n\n");
	printf("Iniciando Pilha!\n\n");
	Pilha_constructor();
	printf("%i elementos na pilha!\n\n", Pilha_size());
	printf("Inserindo o '%i' na pilha!\n", 5);
	Pilha_push(5);
	Pilha_showTopo();
	printf("%i elementos na pilha!\n\n", Pilha_size());
	printf("Inserindo o '%i' na pilha!\n", 9);
	Pilha_push(9);
	printf("Inserindo o '%i' na pilha!\n", 4);
	Pilha_push(4);
	printf("Inserindo o '%i' na pilha!\n", 6);
	Pilha_push(6);
	printf("%i elementos na pilha!\n\n", Pilha_size());
	Pilha_showTopo();
	printf("Removendo o Topo!\n");
	Pilha_pop();
	Pilha_showTopo();
	printf("Removendo o Topo!\n");
	Pilha_pop();
	Pilha_showTopo();
	printf("Removendo o Topo!\n");
	Pilha_pop();
	Pilha_showTopo();
	printf("Removendo o Topo!\n");
	Pilha_pop();
	printf("%i elementos na pilha!\n\n", Pilha_size());
	printf("Terminando Teste!...\n");
	Pilha_destructor();
}