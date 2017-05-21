#ifndef __RACIONAL_H
#define __RACIONAL_H 

class Racional
{
	int numerador, denominador;

public:
	Racional(int num = 0, int denom = 1); //construtor
	Racional adicao(const Racional &) const;
	Racional subtracao(const Racional &) const;
	Racional multiplicacao(const Racional &) const;
	Racional divisao(const Racional &) const;
	void reduzir_fracao(); 
	void imprime_numeros() const;
	int mdc(int, int) const; //calcula o maximo divisor comum
	int mmc(int, int) const;
};

#endif