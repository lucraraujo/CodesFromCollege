#include "vetor.h"
using DataStructures::Vetor;
using DataStructures::operator <<;
using DataStructures::operator >>;

int main()
{
	DataStructures::Vetor a(5),b(10);

    std::cin >> a;
    std::cin >> b;

    std::cout << a;
    std::cout << b;

    Vetor c = a - b;
    Vetor d = a + b;
    std::cout<< "Subtracao: " << c;
    std::cout<< "Soma: " << d;

    std::cout << std::endl;
    return 0;
}

