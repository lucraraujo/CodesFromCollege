#include "lista.h"
#include <iostream>
using namespace std;

Lista* nova_lista()
{
	Lista* lista = new Lista;
	lista->ultimo = 0;
	return lista;
}

bool adicionar_na_lista(Lista* l, int x)
{
	int i = l->ultimo;
	
	if(i == MAXTAM) 
		return false;
	
	l->v[i] = x;
	l->ultimo++;
	return true;
}

void imprime_lista(Lista* l)
{
	int i,n;
	n = tamanho_da_lista(l);
	for(i=0 ; i<n ; ++i)
		cout << elemento_na_posicao(l,i) << " ";
	cout << endl;
}

bool adicionar_na_lista(Lista* l, int x, int i)
{
	int n = l->ultimo;
	if(n == MAXTAM) 
		return false;
	
	if(n < i)
		return false;

	int k;
	for(k = n ; k > i ; k--)
		l->v[k] = l->v[k-1];

	l->v[i] = x;

	l->ultimo++;

	return true;
}


int remover_da_lista(Lista* l)
{
	if(l->ultimo == 0) return 0;

	l->ultimo--;
	return l->v[l->ultimo];
}


int remover_da_lista(Lista* l, int i)
{
	int n = l->ultimo;
	if(i<0 || i >= n) return 0;

	int temp = l->v[i];

	for(int k=i ; k<n-1 ; ++k)
		l->v[k] = l->v[k+1];

	l->ultimo--;

	return temp;
}

int elemento_na_posicao(Lista* l, int i)
{
	int n = l->ultimo;
	if(i<0 || i >= n) return 0;

	return l->v[i];
}


int tamanho_da_lista(Lista* l)
{
	return l->ultimo;
}


bool lista_vazia(Lista* l)
{
	return l->ultimo == 0;
}


void deletar_lista(Lista* l)
{
	delete l;
}
