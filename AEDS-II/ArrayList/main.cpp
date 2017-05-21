#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
	Lista* lista = nova_lista();

	cout << "Lista vazia? " << lista_vazia(lista) << endl;

	int i;
	for(i=1 ; i<=5 ; ++i)
		adicionar_na_lista(lista,i);

	imprime_lista(lista);

	cout << "Lista vazia? " << lista_vazia(lista) << endl;

	adicionar_na_lista(lista,7,5);
	adicionar_na_lista(lista,7,0);
	adicionar_na_lista(lista,7,2);

	imprime_lista(lista);

	cout << remover_da_lista(lista) << endl;

	imprime_lista(lista);

	cout << remover_da_lista(lista,2) << endl;
	cout << remover_da_lista(lista,0) << endl;
	cout << remover_da_lista(lista,4) << endl;

	imprime_lista(lista);

	deletar_lista(lista);

	return 0;
}

