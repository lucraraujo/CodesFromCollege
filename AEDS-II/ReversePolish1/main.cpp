#include <iostream>
#include "parser.h"
using namespace std;

int main()
{
	const int MAXTAM = 200;
	char expressao[MAXTAM];
	cout << "Digite a expressao: ";
	cin.getline(expressao, MAXTAM);
	//cria uma lista para receber a expressao inicial ja convertida em lista
	Lista* lista = nova_lista();
	lista = parse(expressao, 0);
	
	//se a lista ja esta na notação polonesa inversa
	if (verifica_inversa(lista))
	{	
		cout << "expressao posfixada:\n";
		imprime_elementos(lista);
		//calcula o resultado e imprime
		cout << "Resultado = " << calcula_resultado(lista) << endl;
	}
	//se a lista estiver na notação infixada(normal)
	else
	{
		cout << "expressao infixada:\n";
		imprime_elementos(lista);		
		//coverte a lista para a notaçao polonesa inversa
		lista = polonesa_inversa(lista);
		cout << "expressao posfixada:\n";
		imprime_elementos(lista);
		//calcula o resultado e imprime
		cout << "Resultado = " << calcula_resultado(lista) << endl;
	}
	deletar_lista(lista);
	system("pause");
	return 0; 
}

