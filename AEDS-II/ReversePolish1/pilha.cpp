#include "parser.h"

//Contem todas as funções para operar pilhas

Pilha* nova_pilha()
{
	Pilha* pilha = new Pilha;
	pilha->ultimo = 0;
	pilha->tamanho = 0;
	return pilha;
}


bool empilha(Pilha* p, Elemento* e)
{
	Pilha::Celula* c = new Pilha::Celula;
	if (c == 0) return false;
	c->elemento = e;	
	c->ant = 0;
	if(p->tamanho == 0)
		p->ultimo = c;
	else
	{
		Pilha::Celula* aux = p->ultimo;
		p->ultimo = c;
		p->ultimo->ant = aux;
	}
	p->tamanho++;
	return true;
}
Elemento* desempilha(Pilha* l)
{
	if(l->tamanho == 0) return 0;
	Elemento* e = l->ultimo->elemento;
	if(l->tamanho == 1)
	{
		delete l->ultimo;
		l->ultimo = 0;
		l->tamanho = 0;
		return e;
	}
	else
	{
		Pilha::Celula* p = l->ultimo;
		p = p->ant;
		delete l->ultimo;
		l->ultimo = p;
	}
	l->tamanho--;
	return e;
}

void deletar_pilha(Pilha* l)
{
	Pilha::Celula *aux, *p = l->ultimo;
	while(p)
	{
		aux = p;
		p = p->ant;
		delete aux;
	}
	delete l;
}