#ifndef _ARVORE_H_
#define _ARVORE_H_

struct No
{
	No* dir;
	No* esq;
	int valor;
};

typedef No* hNo;


bool buscar_na_arvore(hNo r, int x);
bool adicionar_na_arvore(hNo& r, int x);
bool remover_da_arvore(hNo& r, int x);

void imprimir_arvore(hNo r, int h = 0);
void percorrer_in_order(hNo r);
void percorrer_pre_order(hNo r);
void percorrer_pos_order(hNo r);
void percorrer_largura(hNo r);


#endif

