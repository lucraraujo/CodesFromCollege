#ifndef _ARVORE_H_
#define _ARVORE_H_

#include "parser.h"

struct No
{
	No* dir;
	No* esq;
	int posicao;
};


No* novo_No (int posicao);
void cospiarvore (vector<Elemento*> v, int l, int r, No* &a);
void imprimir_arvore(No* r, vector<Elemento*> v, int h = 0);
void percorrer_pos_order(No* r, vector<int>& vetor);
int menorprioridade (vector<Elemento*> vetor, int l, int r);
void verifica_parentese(Elemento** &v, int l, int r, vector<Elemento*> &vetor_corrigido);
void deleta_arvore(No* no);

#endif