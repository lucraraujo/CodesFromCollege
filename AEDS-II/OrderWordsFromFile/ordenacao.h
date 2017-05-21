#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_

#include "palavras.h"

void compexch(Palavra &A, Palavra &B);
void exch(Palavra &A, Palavra &B);
void insertion(vector<Palavra> &a, int l, int r);
int partition(vector<Palavra> &a, int l, int r);
void quicksort(vector<Palavra> &a, int l, int r);

int busca_binaria(vector<Palavra> v, int li, int ls, string x);


#endif
