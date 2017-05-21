#include "lista.h"
#include <iostream>
using namespace std;

Lista* nova_lista()
{
	Lista* lista = new Lista;

	lista->primeiro = 0;
	lista->ultimo = 0;
	lista->tamanho = 0;
	return lista;
}

bool adicionar_na_lista(Lista* l, int x)
{
	Lista::Celula* c = new Lista::Celula;
	
	if (c == 0) return false;
	
	c->valor = x;
	c->prox = 0;
	c->ant = 0;

	if(lista_vazia(l))
	{
		l->primeiro = c;		
		l->ultimo = c;
	}
	else
	{
		Lista::Celula* aux = l->ultimo;
		l->ultimo->prox = c;
		l->ultimo = c;
		l->ultimo->ant = aux;
	}
	
	l->tamanho++;
	return true;
}

void imprime_lista(Lista* l)
{
	Lista::Celula* p = l->primeiro;

	while(p!=0)
	{
		cout << p->valor << " ";
		p = p->prox;
	}
	cout << endl;
}

void imprime_lista_inversa(Lista* l)
{
	Lista::Celula* p = l->ultimo;

	while(p!=0)
	{
		cout << p->valor << " ";
		p = p->ant;
	}
	cout << endl;
}

/*bool adicionar_na_lista(Lista* l, int x, int i)
{
	if( i<0 || i>l->tamanho )
		return false;

	Lista::Celula* c = new Lista::Celula;
	if (c == 0) return false;
	c->valor = x;

	if( i == 0 )
	{
		c->prox = l->primeiro;
		l->primeiro = c;
	}
	else
	{
		Lista::Celula* p = l->primeiro;
		int k;
		for(k=0 ; k<i-1 ; ++k)
			p = p->prox;

		c->prox = p->prox;
		p->prox = c;
	}
	if(i == l->tamanho)
		l->ultimo = c;

	l->tamanho++;
	return true;
}


int remover_da_lista(Lista* l)
{
	if(l->tamanho == 0) return 0;
	int x = l->ultimo->valor;

	if(l->tamanho == 1)
	{
		delete l->ultimo;
		l->ultimo = 0;
		l->primeiro = 0;
		l->tamanho = 0;
		return x;
	}

	Lista::Celula* p = l->primeiro;
	int k, n = l->tamanho;
	for(k=0 ; k<n-2 ; ++k)
		p = p->prox;

	delete l->ultimo;
	l->ultimo = p;
	p->prox = 0;

	l->tamanho--;
	return x;
	return remover_da_lista(l,l->tamanho-1);
}
*/

int remover_da_lista(Lista* l, int i)
{
	int n = l->tamanho;

	if(i<0 || i>=n) return 0;

	int x;
	Lista::Celula *p, *aux; 

	if(l->tamanho == 1)
	{
		x = l->ultimo->valor;
		delete l->ultimo;
		l->ultimo = 0;
		l->primeiro = 0;
		l->tamanho = 0;
		return x;
	}

	if(i == 0)
	{
		aux = l->primeiro;
		l->primeiro = l->primeiro->prox;
		x = aux->valor;
		delete aux;
		l->tamanho--;
		return x;
	}

	p = l->primeiro;
	int k;
	for(k=0 ; k<i-1 ; ++k)
		p = p->prox;

	x = p->prox->valor;
	aux = p->prox->prox;
	delete p->prox;
	p->prox = aux;

	if(i==n-1)
		l->ultimo = p;

	return x;
}

int elemento_na_posicao(Lista* l, int i)
{
	int n = l->tamanho;

	if(i<0 || i>=n) return 0;
	
	Lista::Celula *p = l->primeiro;
	for(int k=0 ; k<i ; ++k)
		p = p->prox;

	return p->valor;
}


int tamanho_da_lista(Lista* l)
{
	return l->tamanho;
}


bool lista_vazia(Lista* l)
{
	return l->tamanho == 0;
}


void deletar_lista(Lista* l)
{
	Lista::Celula *aux, *p = l->primeiro;

	while(p)
	{
		aux = p;
		p = p->prox;
		delete aux;
	}

	delete l;
}
