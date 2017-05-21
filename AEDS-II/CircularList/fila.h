#ifndef FILA_H
#define FILA_H

const int MAXTAM = 10;

struct Fila
{
	int v[MAXTAM];	
	int inicio;
	int fim;
	int tamanho;
};

Fila* nova_fila();
bool adicionar_na_fila(Fila*, int) ;
int  remover_da_fila(Fila*) ;
int  elemento_na_posicao(Fila*, int) ;
int  tamanho_da_fila(Fila*) ;
bool fila_vazia(Fila*) ;
void deletar_fila(Fila*) ;
void imprime_fila(Fila*);

#endif
