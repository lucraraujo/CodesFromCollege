#include "arvore.h"

No* novo_No (int posicao)
{
	No* n = new No;
	n->posicao = posicao;
	n->esq = 0;
	n->dir = 0;
	return n;
}

int menorprioridade(vector<Elemento*> vetor, int l, int r)
{
	int prioridade = 1000, posicao = 0, i = r;
	
	if (l == r) return r;
	
	while (i > l)
	{
		if(vetor[i]->tipo == OPERADOR)
		{
			if(vetor[i]->prioridade < prioridade)
			{
				posicao = i;
				prioridade = vetor[i]->prioridade;
			}
		}
		--i;
		if (prioridade == 1)
				break;
	}
	return posicao;
}

void cospiarvore (vector<Elemento*> v, int l, int r, No* &a)
{
	int i;
	
	i = menorprioridade(v, l, r);
	
	a = new No;
	a->posicao = i;
	a->esq = 0;
	a->dir = 0;
	
	if(i == l) return;
	
	cospiarvore(v, i+1, r, a->dir);
	cospiarvore(v, l, i-1, a->esq);
	
}

void verifica_parentese(Elemento** &v, int l, int r, vector<Elemento*> &vetor_corrigido)
{
	int penalidade = 0;

	for(int k = l ; k < r ; ++k)
	{ 
		if(v[k]->operador == '(') penalidade += 10;
		if(v[k]->operador == ')') penalidade -= 10;
		if (v[k]->tipo == OPERADOR)
			v[k]->prioridade += penalidade;
	}
	for(int k = l ; k < r ; ++k)
	{
		if (v[k]->tipo != PARENTESE)
			vetor_corrigido.push_back(v[k]);	
	}

}

void imprimir_arvore(No* r, vector<Elemento*> v, int h)
{
	if (r == 0) return;

	imprimir_arvore(r->dir, v ,h+1);

	for(int k=0 ; k<h ; ++k)
		cout << '\t';

	if (v[r->posicao]->tipo == OPERADOR)
		cout << v[r->posicao]->operador << endl;
	else
		cout << v[r->posicao]->valor << endl;

	imprimir_arvore(r->esq, v, h+1);
}

void percorrer_pos_order(No* r, vector<int>& vetor)
{
	if(r == 0) return;

	percorrer_pos_order(r->esq, vetor);
	percorrer_pos_order(r->dir, vetor);

	vetor.push_back(r->posicao);
}

void deleta_arvore(No* no)
{
	if(no != 0)
	{
		deleta_arvore(no->esq);
		deleta_arvore(no->dir);
		delete no;
	}
}