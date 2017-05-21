#include "fila.h"
#include <iostream>

using namespace std;

int main()
{
	Fila * f = nova_fila();

	int i;
	for(i=1 ; i<10 ; ++i)
		adicionar_na_fila(f,i);

	imprime_fila(f);

	cout << remover_da_fila(f) << endl;
	cout << remover_da_fila(f) << endl;
	cout << remover_da_fila(f) << endl;
	cout << remover_da_fila(f) << endl;

	imprime_fila(f);


	for(i=10 ; i<13 ; ++i)
		adicionar_na_fila(f,i);

	imprime_fila(f);

	deletar_fila(f);

	return 0;
}

