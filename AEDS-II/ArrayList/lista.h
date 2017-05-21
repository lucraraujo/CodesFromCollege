#ifndef LISTA_H
#define LISTA_H

const int MAXTAM = 100;

struct Lista
{
	int v[MAXTAM];
	int ultimo;
};

Lista* nova_lista() ;
bool adicionar_na_lista(Lista*, int) ;
bool adicionar_na_lista(Lista*, int, int) ;
int remover_da_lista(Lista*) ;
int remover_da_lista(Lista*, int) ;
int elemento_na_posicao(Lista*, int) ;
int tamanho_da_lista(Lista*) ;
bool lista_vazia(Lista*) ;
void deletar_lista(Lista*) ;
void imprime_lista(Lista*);

#endif

