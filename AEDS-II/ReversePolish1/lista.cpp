#include "parser.h"

//Contem todas as funções para operar pilhas
Lista* nova_lista()
{
	Lista* lista = new Lista;
	lista->primeiro = 0;
	lista->ultimo = 0;
	lista->tamanho = 0;
	return lista;
}

bool adicionar_na_lista(Lista* l, Elemento* e)
{
	Lista::Celula* c = new Lista::Celula;
	if (c == 0)
		return false;
	c->elemento = e;
	c->prox = 0;
	if(l->tamanho == 0)
	{
		l->primeiro = c;		
		l->ultimo = c;
	}
	else
	{
		l->ultimo->prox = c;
		l->ultimo = c;
	}
	l->tamanho++;
	return true;
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
}
