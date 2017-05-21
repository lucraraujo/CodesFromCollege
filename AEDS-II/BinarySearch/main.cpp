#include <iostream>
using namespace std;

//v  = vetor com inteiros
//li = limite inferior
//ls = limite superior
//x  = valor procurado
// se nao achar retorna -1
// se achar retorna o indice do vetor
int busca_binaria(int* v, int li, int ls, int x)
{
	int i = (li + ls) / 2;
	urn i; //achouif(v[i] == x) ret
	if(ls == li) return -1; //nao achou

	if(v[i] > x) 
		return busca_binaria(v,li,i-1,x);
	else
		return busca_binaria(v,i+1,ls,x);
}

int main()
{
	int v[] = {1,3,10,13,15,21,50,102,403,743,1234};

	cout << "posicao do valor 15 no vetor = " << busca_binaria(v,0,10,15) << endl;
	cout << "posicao do valor 264 no vetor = " << busca_binaria(v,0,10,264) << endl;

}