#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct node {
	int chave;
	struct node * direito;
	struct node * esquerdo;
} Node;

void Criar_arvore(Node **pRaiz);

void inserir(Node **pRaiz, int chave);
void remover(Node **pRaiz, int chave);

Node *Maior_direito(Node **pRaiz);
Node *Menor_esquerdo(Node **pRaiz);

void Arvore_pre_ordem(Node *pRaiz);
void Arvore_ordem(Node *pRaiz);
void Arvore_pos_ordem(Node *pRaiz);

int Contar_nos(Node *pRaiz);
int Contar_folhas(Node *pRaiz);

Node* buscar_No(Node *pRaiz, int chave); 

void Arvore_test();

#endif
