#ifndef LISTA_H
#define LISTA_H

struct Lista
{
	struct Celula
	{
		int valor;
		Celula* prox;
		Celula* ant;
	};

	Celula* primeiro;
	Celula* ultimo;
	int tamanho;
};

Lista* nova_lista() ;
bool adicionar_na_lista(Lista*, int) ;
//bool adicionar_na_lista(Lista*, int, int) ;
//int remover_da_lista(Lista*) ;
int remover_da_lista(Lista*, int) ;
int elemento_na_posicao(Lista*, int) ;
int tamanho_da_lista(Lista*) ;
bool lista_vazia(Lista*) ;
void deletar_lista(Lista*) ;
void imprime_lista(Lista*);
void imprime_lista_inversa(Lista*)

#endif

