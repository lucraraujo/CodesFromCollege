#include "fila.h"
#include <iostream>

using namespace std;

Fila* nova_fila()
{
	Fila* f = new Fila;
	
	f->inicio = 0;
	f->fim = 0;
	f->tamanho = 0;

	return f;
}

bool adicionar_na_fila(Fila* f, int x)
{
	int fim    = f->fim;
	int inicio = f->inicio;

	if((fim+1)%MAXTAM == inicio)
		return false;

	f->v[fim] = x;

	f->fim = (fim+1)%MAXTAM;
	f->tamanho++;

	return true;
}


int  remover_da_fila(Fila* f)
{
	int fim    = f->fim;
	int inicio = f->inicio;

	if(inicio == fim) return 0;

	int ret = f->v[inicio];
	f->v[inicio] = 0;
	f->inicio = (inicio+1)%MAXTAM;
	f->tamanho--;

	return ret;
}

int  elemento_na_posicao(Fila* f, int i)
{
	int n = tamanho_da_fila(f);
	if(i<0 || i>=n) return 0;

	int pos = (f->inicio + i)%MAXTAM;		

	return f->v[pos];
}


int  tamanho_da_fila(Fila* f) 
{
	return f->tamanho;
}

bool fila_vazia(Fila* f)
{
	return f->fim == f->inicio;
}

void deletar_fila(Fila* f)
{
	delete f;
}


void imprime_fila(Fila* f)
{
	int i = f->inicio;
	while(i != f->fim)
	{
		cout << f->v[i] << " ";
		i = (i+1)%MAXTAM;
	}
	cout << endl;
	for(i=0 ; i<MAXTAM ; ++i)
		cout << f->v[i] << " ";
	cout << endl;


}

