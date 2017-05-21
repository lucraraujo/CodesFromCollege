#include "arvore.h"
#include <iostream>
#include <stack>
#include <list>

using namespace std;

static No* novo_No(int x)
{
	No* n = new No;
	n->valor = x;
	n->esq = 0;
	n->dir = 0;
	return n;
}

bool adicionar_na_arvore(hNo& r, int x)
{
	if(r == 0)
	{
		r = novo_No(x);
		return true;
	}

	if(x > r->valor)
		return adicionar_na_arvore(r->dir,x);
	
	if(x < r->valor)
		return adicionar_na_arvore(r->esq,x);
	
	return false;
}

bool buscar_na_arvore(hNo r, int x)
{
	if(r == 0)
		return false;

	if(r->valor == x)
		return true;

	if(x > r->valor)
		return buscar_na_arvore(r->dir, x);
	else
		return buscar_na_arvore(r->esq, x);
}



void imprimir_arvore(hNo r, int h)
{
	if (r == 0) return;

	imprimir_arvore(r->dir, h+1);

	for(int k=0 ; k<h ; ++k)
		cout << '\t';
	cout << r->valor << endl;

	imprimir_arvore(r->esq, h+1);
}

void percorrer_in_order(hNo r)
{
	if(r == 0) return;

	percorrer_in_order(r->esq);
	cout<< r->valor << ' ';
	percorrer_in_order(r->dir);
}

void percorrer_pre_order(hNo r)
{
	stack<hNo> pilha;
	
	hNo p = r;
	
	pilha.push(p);
	while(!pilha.empty())
	{
		p = pilha.top();
		pilha.pop();
		cout << p->valor << ' ';

		if(p->dir != 0) pilha.push(p->dir);
		if(p->esq != 0) pilha.push(p->esq);
	}

}

//void percorrer_pre_order(hNo r)
//{
//	if(r == 0) return;
//
//	cout<< r->valor << ' ';
//	percorrer_pre_order(r->esq);
//	percorrer_pre_order(r->dir);
//}

void percorrer_pos_order(hNo r)
{
	if(r == 0) return;

	percorrer_pos_order(r->esq);
	percorrer_pos_order(r->dir);
	cout<< r->valor << ' ';
}

void percorrer_largura(hNo r)
{
	list<hNo> fila;

	fila.push_back(r);
	while(!fila.empty())
	{
		r = *(fila.begin());	
		fila.pop_front();
		cout << r->valor << ' ';
		
		if (r->esq != 0) fila.push_back(r->esq);
		if (r->dir != 0) fila.push_back(r->dir);
	}
}

bool remover_da_arvore(hNo& r, int x)
{
	if(r == 0)
		return false;

	if(x > r->valor)
		return remover_da_arvore(r->dir, x);

	if(x < r->valor)
		return remover_da_arvore(r->esq, x);

	hNo aux;

	if(r->esq == 0 && r->dir == 0)
	{
		aux = r;
		r = 0;
		delete aux;
		return true;
	}

	if(r->esq == 0 || r->dir == 0)
	{
		aux = r;
		r = (r->esq != 0) ? r->esq : r->dir;
		delete aux;
		return true;
	}

	//procura menor do lado direito
	aux = r->dir;
	hNo aux_pai = r;
	while(aux->esq != 0)
	{
		aux_pai = aux;
		aux = aux->esq;
	}

	r->valor = aux->valor;
	aux_pai->esq = aux->dir;
	delete aux;
	return true;
}


