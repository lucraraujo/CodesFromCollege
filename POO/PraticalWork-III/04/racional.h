#ifndef __RACIONAL_H
#define __RACIONAL_H 

namespace DataStructures
{
	class Racional
	{
		int numerador, denominador;

	public:
		Racional(int num = 0, int denom = 1); //construtor
		Racional operator+(const Racional &) const;
		Racional operator-(const Racional &) const;
		Racional operator*(const Racional &) const;
		Racional operator/(const Racional &) const;
		Racional& operator++();
		Racional& operator++(int);

		void reduzir_fracao(); 
		void imprime_numeros() const;
		int mdc(int, int) const; //calcula o maximo divisor comum
		int mmc(int, int) const;
	};
}
#endif