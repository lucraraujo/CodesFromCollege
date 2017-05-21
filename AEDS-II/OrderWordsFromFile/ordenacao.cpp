#include "ordenacao.h"

void compexch (Palavra &A, Palavra &B) 
{
	if (B.palavra < A.palavra)
		exch(A, B);
}

void exch (Palavra &A, Palavra &B) 
{
	Palavra t = A;
	A = B;
	B = t;
}

void insertion (vector<Palavra> &a, int l, int r)
{
	int i;
	for (i = r; i > l; i--)
		compexch(a[i-1], a[i]);
	
	for (i = l+2; i <= r; i++)
	{
		int j = i; Palavra v = a[i];
		while (v.palavra < a[j-1].palavra)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = v;
	} 
}

int partition (vector<Palavra> &a, int l, int r)
{
	int i = l - 1, j = r;
	Palavra v = a[r];
	for (;;)
	{
		while (a[++i].ocorrencias < v.ocorrencias);
		
		while (v.ocorrencias < a[--j].ocorrencias)
			if (j == l)
				break;
		
		if (i >= j)
			break;
		exch(a[i], a[j]);
	}
	exch (a[i], a[r]);
	return i;
}

void quicksort (vector<Palavra> &a, int l, int r)
{
	if (r <= l)
		return;
	int i = partition (a, l, r);
	quicksort (a, l, i-1);
	quicksort (a, i+1, r);
}

int busca_binaria (vector<Palavra> v, int li, int ls, string x)
{
	if (li > ls)
		return -1;

	int i = (li + ls) / 2;
	
	if (v[i].palavra == x)
		return i; //achou
	if (ls == li) 
		return -1; //nao achou

	if (v[i].palavra > x) 
		return busca_binaria (v, li, i-1, x);
	else
		return busca_binaria (v, i+1, ls, x);
}