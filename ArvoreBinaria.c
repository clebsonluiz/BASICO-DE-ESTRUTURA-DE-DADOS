#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

void Criar_arvore(Node **pRaiz){
	*pRaiz = NULL;
}

void inserir(Node **pRaiz, int chave){
	if(*pRaiz == NULL){
		*pRaiz = (Node*)malloc(sizeof(Node));
		(*pRaiz)->chave = chave;
		(*pRaiz)->esquerdo = NULL;
		(*pRaiz)->direito = NULL;
	}
	else{
		if((*pRaiz)->chave > chave){
			inserir(&(*pRaiz)->esquerdo, chave);
		}
		if((*pRaiz)->chave < chave){
			inserir(&(*pRaiz)->direito, chave);
		}
	}
}

void remover(Node **pRaiz, int chave){
	if(pRaiz != NULL){

		if((*pRaiz)->chave > chave){
			remover(&(*pRaiz)->esquerdo, chave);
		}
		else if((*pRaiz)->chave < chave){
			remover(&(*pRaiz)->direito, chave);
		}
		else{
			Node *pAux = *pRaiz;

			if((*pRaiz)->esquerdo == NULL && (*pRaiz)->direito == NULL){

				free(pAux);
				*pRaiz = NULL;
			}
			else if((*pRaiz)->esquerdo == NULL && (*pRaiz)->direito != NULL){
				Node *direito = (*pRaiz)->direito;
				free(pAux);
				*pRaiz = direito;
			}
			else if((*pRaiz)->esquerdo != NULL && (*pRaiz)->direito == NULL){
				Node *esquerdo = (*pRaiz)->esquerdo;
				free(pAux);
				*pRaiz = esquerdo;
			}
			else{
				*pRaiz = Maior_direito(&(*pRaiz)->esquerdo);
				(*pRaiz)->direito = pAux->direito;
				(*pRaiz)->esquerdo = pAux->esquerdo;
				pAux->direito = NULL;
				pAux->esquerdo = NULL;
				free(pAux);
			}
		}

	}
}

Node *Maior_direito(Node **pRaiz){
	if((*pRaiz)->direito != NULL){
		return Maior_direito(&(*pRaiz)->direito);
	}
	else{
		Node *pAux = *pRaiz;
		if((*pRaiz)->esquerdo != NULL){
			*pRaiz = (*pRaiz)->esquerdo;
		}
		else{
			*pRaiz = NULL;
		}
		return pAux;
	}	
}

Node *Menor_esquerdo(Node **pRaiz){
	if((*pRaiz)->esquerdo != NULL){
		return Menor_esquerdo(&(*pRaiz)->esquerdo);
	}
	else{
		Node *pAux = *pRaiz;
		if((*pRaiz)->direito != NULL){
			*pRaiz = (*pRaiz)->direito;
		}
		else{
			*pRaiz = NULL;
		}
		return pAux;
	}	
}

void Arvore_pre_ordem(Node *pRaiz){
	if(pRaiz != NULL){
		printf("-%i-", pRaiz->chave);
		Arvore_pre_ordem(pRaiz->esquerdo);
		Arvore_pre_ordem(pRaiz->direito);
	}
}

void Arvore_ordem(Node *pRaiz){
	if(pRaiz != NULL){
		Arvore_ordem(pRaiz->esquerdo);
		printf("-%i-", pRaiz->chave);
		Arvore_ordem(pRaiz->direito);
	}
}

void Arvore_pos_ordem(Node *pRaiz){
	if(pRaiz != NULL){
		Arvore_pos_ordem(pRaiz->esquerdo);
		Arvore_pos_ordem(pRaiz->direito);
		printf("-%i-", pRaiz->chave);
	}
}

int Contar_nos(Node *pRaiz){
	if(pRaiz == NULL){
		return 0;
	}
	return 1 + Contar_nos(pRaiz->esquerdo) + Contar_nos(pRaiz->direito);
}

int Contar_folhas(Node *pRaiz){
	if(pRaiz == NULL){
		return 0;
	}
	if(pRaiz->esquerdo == NULL && pRaiz->direito == NULL){
		return 1;
	}
	return Contar_folhas(pRaiz->esquerdo)+Contar_folhas(pRaiz->direito);
}

Node * buscar_No(Node *pRaiz, int valor){
	if(pRaiz != NULL){
		if(pRaiz->chave == valor){
			return pRaiz;
		}
		else{
			if(pRaiz->chave > valor){
				return buscar_No(pRaiz->esquerdo, valor);
			}
			else{
				return buscar_No(pRaiz->direito, valor);
			}
		}
	}	
	return NULL;
}

void Arvore_test(){
	printf("\nIniciando teste de Arvore Binaria...\n");
	Node *raiz;
	Criar_arvore(&raiz);

	int array_lenght = 7;

	int itens[] = {7, 9, 8, 2, 4, 3, 6};
	for(int i = 0; i < array_lenght; i ++ ){
		inserir(&raiz, itens[i]);
	}

	printf("\nPrint em Pre-ordem\n");
	Arvore_pre_ordem(raiz);
	printf("\nPrint em Ordem\n");
	Arvore_ordem(raiz);
	printf("\nPrint em Pós-ordem\n");
	Arvore_pos_ordem(raiz);
	printf("\n");

	printf("Arvore possui %i nós\n", Contar_nos(raiz));
	printf("Arvore possui %i folhas\n", Contar_folhas(raiz));

	printf("\nBuscando por chave == %i...\n", 8);
	Node *busca = buscar_No(raiz, 8);

	if(busca != NULL){
		printf("Encontrado a chave %i\n", busca->chave);
	}else{
		printf("Não encontrado!");
	}
	remover(&raiz, 4);
	printf("\nPrint em Pre-ordem\n");
	Arvore_pre_ordem(raiz);
	printf("\nEncerrando teste de Arvore Binaria...\n");
}