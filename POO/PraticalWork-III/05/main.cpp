#include "lista.h"

using DataStructure::Lista;
using DataStructure::operator <<;
using DataStructure::operator >>;
int main()
{
	Lista a, b, c, e;
	std::ifstream arqIn("entrada.txt");
	std::ofstream arqOut("saida.txt");
	std::cout << "Lendo do arquivo e colocando em a" << std::endl;
	arqIn >> a;
	std::cout << "Lendo do teclado e colocando em b" << std::endl;
	std::cin >> b;
	std::cout << "Atribuindo a em c" << std::endl;
	c = a;
	std::cout << "construtor de copia de b para d" << std::endl;
	Lista d = b;

	std::cout << "Imprimindo a" << std::endl;
	std::cout << a;
	std::cout << "Imprimindo b" << std::endl;
	std::cout << b;
	std::cout << "Imprimindo c" << std::endl;
	std::cout << c;
	std::cout << "Imprimindo d" << std::endl;
	std::cout << d;

	std::cout << "a+b" << std::endl;
	e = a+b;
	std::cout << e;

	std::cout << "a+=b" << std::endl;
	a += b;
	std::cout << a;
	std::cout << "a+=15" << std::endl;
	a += 15;
	std::cout << a;
	std::cout << "a -= 10" << std::endl;
	a -= 10;
	std::cout << a;

	std::cout << "Exportando a para arquivo" << std::endl;
	arqOut << a;




	return 0;
}