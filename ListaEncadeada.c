#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int lista_tamanho = -1;

Lista *inicio;
Lista *fim;

void Lista_inicialize(){
	inicio = NULL;
	fim = inicio;
	lista_tamanho = 0;
}

void Lista_destructor(){
	free(inicio);
	free(fim);
	lista_tamanho = -1;
}

int Lista_append(int valor){
	return Lista_insertAt(-1, valor);
}

int Lista_insertAt(int index, int valor){
	Lista *novo = (Lista*)malloc(sizeof(Lista));
	
	if(novo == NULL || index < -1){
		return EXIT_FAILURE;
	}
		
	novo->valor = valor;

	if(index >= lista_tamanho || index == -1){
		
		if(Lista_empty()){
			inicio = novo;
		}
		else {
			fim->proximo = novo;
		}
		fim = novo;
		lista_tamanho ++;

		return 1;	
	}
	else {
		
		int tempI = index;
		Lista *anterior = inicio;

		while (tempI > 0){
			anterior = anterior->proximo;
			tempI --;
		}
		
		if(index == 0){
			inicio = novo;
			inicio->proximo = anterior;
		}
		else{
			novo->proximo = anterior->proximo;
			anterior->proximo = novo;
		}

		lista_tamanho ++;

		return 1;
	}
}

int Lista_removeAt(int index){
	if(Lista_empty()) return 0;

	Lista *temp = inicio;

	if(index <= 0){
		
		inicio = temp->proximo;
	
		free(temp);
		if(inicio == NULL){
			fim = inicio;
		}

		lista_tamanho --;
		return 1;	

	}
	else {
		int tempI = index;

		if(index >= (lista_tamanho - 1)){
			tempI = lista_tamanho - 1;
		}

		while ((tempI -1) > 0){
			temp = temp->proximo;
			tempI --;
		}
		
		Lista *lixo = temp->proximo;
		temp->proximo = lixo->proximo;
		lixo->proximo = NULL;

		free(lixo);

		if(index >= (lista_tamanho - 1)){
			fim = temp;
		}

		lista_tamanho --;

		return 1;
	}
}

int Lista_empty(){
	return lista_tamanho <= 0;
}

int Lista_size(){
	return lista_tamanho;
}

int Lista_elementAt(int index){
	if(Lista_empty() || index >= lista_tamanho) {
		return EXIT_FAILURE;
	}

	int tempI = index;
	Lista *temp = inicio;

	while(tempI > 0){
		temp = temp->proximo;
		tempI --;
	}
	return temp->valor;
}
void Lista_all(){
	printf("lista: [");
	for(int i = 0; i < lista_tamanho; i++){
		if(i == lista_tamanho - 1){
			printf("%i]\n", Lista_elementAt(i));
		}
		else{
			printf("%i, ", Lista_elementAt(i));
		}
	}
}
void Lista_test(){
	printf("Iniciando Teste de Lista!\n\n");
	printf("Iniciando Lista!\n\n");
	Lista_inicialize();
	Lista_all();
	printf("%i elementos na Lista!\n\n", Lista_size());
	printf("Inserindo o '%i' no fim!\n", 5);
	Lista_append(5);
	Lista_all();
	printf("%i elementos na Lista!\n\n", Lista_size());
	printf("Inserindo o '%i' no inicio!\n", 9);
	Lista_insertAt(0, 9);
	Lista_all();
	printf("Inserindo o '%i' no fim!\n", 4);
	Lista_insertAt(-1, 4);
	Lista_all();
	printf("Inserindo o '%i' em index(1)!\n", 6);
	Lista_insertAt(1, 6);
	printf("%i elementos na Lista!\n\n", Lista_size());
	Lista_all();
	printf("Removendo o penultimo!\n");
	Lista_removeAt(2);
	Lista_all();
	printf("Removendo o inicio!\n");
	Lista_removeAt(0);
	Lista_all();
	printf("Removendo o fim!\n");
	Lista_removeAt(Lista_size() - 1);
	Lista_all();
	printf("Removendo o inicio!\n");
	Lista_removeAt(0);
	printf("%i elementos na Lista!\n\n", Lista_size());
	printf("Terminando Teste!...\n");
	Lista_destructor();
}