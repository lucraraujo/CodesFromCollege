#ifndef VETOR_H
#define	VETOR_H
#include <iostream>

namespace DataStructures{
	class Vetor
	{
	private:
		int tamanho; //tamanho do vetor
		double* ptr; //ponteiro que aponta para a primeira posiçao de memoria do vetor
	public:
		Vetor(int); //parametro: tamanho do vetor
		Vetor(const Vetor &);//construtor de copia
		~Vetor(); //destrutor
		double & operator [](int); //operador colchetes
		Vetor & operator =(const Vetor&); //sobrecarga do operador =
		double & operator ()(int);
		Vetor operator +(const Vetor&);
		Vetor operator -(const Vetor&);
		friend std::istream& operator >>(std::istream&, Vetor&);
		friend std::ostream& operator <<(std::ostream&, const Vetor&);
	};
}

#endif
