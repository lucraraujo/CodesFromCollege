#include <iostream>
#include "arvore.h"

using namespace std;

int main()
{
	No* raiz = 0;

	adicionar_na_arvore(raiz,10);
	adicionar_na_arvore(raiz,5);
	adicionar_na_arvore(raiz,15);
	adicionar_na_arvore(raiz,4);
	adicionar_na_arvore(raiz,7);
	adicionar_na_arvore(raiz,16);
	adicionar_na_arvore(raiz,5);
	adicionar_na_arvore(raiz,20);
	adicionar_na_arvore(raiz,25);
	adicionar_na_arvore(raiz,19);
	adicionar_na_arvore(raiz,12);

	imprimir_arvore(raiz);

	cout << endl;
	percorrer_in_order(raiz);
	cout << endl;
	percorrer_pre_order(raiz);
	cout << endl;
	percorrer_pos_order(raiz);
	cout << endl;
	percorrer_largura(raiz);
	cout << endl;

	cout << "16 esta na arvore? " << buscar_na_arvore(raiz,16) << endl;
	cout << "13 esta na arvore? " << buscar_na_arvore(raiz,13) << endl;


	cout << endl;
	cout << endl;
	cout << endl;
	imprimir_arvore(raiz);
	cout << endl;
	cout << endl;
	remover_da_arvore(raiz,10);
	imprimir_arvore(raiz);
	cout << endl;
	remover_da_arvore(raiz,15);
	imprimir_arvore(raiz);
	cout << endl;



	return 0;
}

