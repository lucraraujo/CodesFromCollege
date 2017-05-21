#include <iostream>
#include "racional.h"

int main()
{
	int n1, d1, n2, d2;
	std::cout << "Digite o numerador do primeiro racional:" << std::endl;
	std::cin >> n1;
	std::cout << "Digite o denominador do primeiro racional:" << std::endl;
	std::cin >> d1;
	std::cout << "Digite o numerador do segundo racional:" << std::endl;
	std::cin >> n2;
	std::cout << "Digite o denominador do primeiro racional:" << std::endl;
	std::cin >> d2;

	Racional a(n1,d1), b(n2,d2), c;

	a.imprime_numeros(); std::cout << " + "; b.imprime_numeros(); std::cout << " = ";
	c = a.adicao(b);
	c.imprime_numeros();
	std::cout << std::endl;

	a.imprime_numeros(); std::cout << " - "; b.imprime_numeros(); std::cout << " = ";
	c = a.subtracao(b);
	c.imprime_numeros();
	std::cout << std::endl;

	a.imprime_numeros(); std::cout << " * "; b.imprime_numeros(); std::cout << " = ";
	c = a.multiplicacao(b);
	c.imprime_numeros();
	std::cout << std::endl;

	a.imprime_numeros(); std::cout << " / "; b.imprime_numeros(); std::cout << " = ";
	c = a.divisao(b);
	c.imprime_numeros();
	std::cout << std::endl;

	return 0;
}