#include <iostream>
#include "racional.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int n1, d1, n2, d2;
	cout << "Digite o numerador do primeiro racional:" << endl;
	cin >> n1;
	cout << "Digite o denominador do primeiro racional:" << endl;
	cin >> d1;
	cout << "Digite o numerador do segundo racional:" << endl;
	cin >> n2;
	cout << "Digite o denominador do primeiro racional:" << endl;
	cin >> d2;

	DataStructures::Racional a(n1,d1), b(n2,d2), c;

	a.imprime_numeros(); cout << " + "; b.imprime_numeros(); cout << " = ";
	c = a+b;
	c.imprime_numeros();
	cout << endl;

	a.imprime_numeros(); cout << " - "; b.imprime_numeros(); cout << " = ";
	c = a-b;
	c.imprime_numeros();
	cout << endl;

	a.imprime_numeros(); cout << " * "; b.imprime_numeros(); cout << " = ";
	c = a*b;
	c.imprime_numeros();
	cout << endl;

	a.imprime_numeros(); cout << " / "; b.imprime_numeros(); cout << " = ";
	c = a/b;
	c.imprime_numeros();
	cout << endl;

	cout << "++"; a.imprime_numeros(); cout << " = ";
	++a;
	a.imprime_numeros();
	cout << endl;
	
	a.imprime_numeros(); cout << "++"; cout << " = ";
	a++;
	a.imprime_numeros();
	cout << endl;

	return 0;
}