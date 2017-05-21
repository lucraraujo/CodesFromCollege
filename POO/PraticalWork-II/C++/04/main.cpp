#include "lista.h"

int main()
{
	Lista *lista = new Lista;
	lista->Importar("entrada.txt");

	lista->InsereNaLista(11);
	lista->InsereNaLista(21);
	lista->InsereNaLista(100);
	lista->InsereNaLista(9);
	lista->InsereNaLista(5);
	lista->InsereNaLista(30);
	lista->InsereNaLista(5);
	lista->InsereNaLista(65);
	lista->InsereNaLista(1);
	lista->InsereNaLista(3);
	lista->InsereNaLista(0);
	lista->RetiraDaLista(10);
	lista->Imprime();
	lista->RetiraDaLista(30);
	lista->RetiraDaLista(65);
	lista->RetiraDaLista(75);
	lista->RetiraDaLista(5);
	lista->RetiraDaLista(16);

	lista->Imprime();
	lista->Exportar("saida.txt");


	return 0;
}