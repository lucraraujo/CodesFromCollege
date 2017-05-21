#include "racional.h"
#include <iostream>

Racional::Racional(int num, int denom) : numerador(num),denominador(denom)
{
	reduzir_fracao();	//método que reduz a fração
}

void Racional::reduzir_fracao() 
{
	int mdc = Racional::mdc(numerador, denominador);	
	numerador /= mdc;
	denominador /= mdc;
}

int Racional::mdc(int num, int denom) const
{
    if (denom == 0)
        return num;
    else
        return mdc(denom, num % denom);
}

int Racional::mmc(int denom1, int denom2) const
{
	return (denom1 * denom2) / Racional::mdc(denom1, denom2);
}

Racional Racional::adicao(const Racional& b) const
{
	Racional c;
	if(b.denominador == denominador) //se os denominadores forem iguais, o denominador resultante é o próprio denominador do objeto	
	{								//e o numerador é a soma dos numeradores	
		c.denominador = denominador;
		c.numerador = numerador + b.numerador;
		c.reduzir_fracao();
		return c;
	}

	//senão, tem que calcular o minimo multiplo comum
	else
	{
		int mmc = Racional::mmc(denominador, b.denominador); //calcula o minimo multiplo comum
		c.denominador = mmc;
		c.numerador = ((mmc / denominador) * numerador) + ((mmc / b.denominador) * b.numerador);
		c.reduzir_fracao();
		return c;
	}

}

void Racional::imprime_numeros()const
{
	std::cout << numerador << "/" << denominador; 
}

Racional Racional::subtracao(const Racional & b) const
{
	Racional c;
	if(denominador == b.denominador)
	{
		c.denominador = denominador;
		c.numerador = numerador - b.numerador;
		c.reduzir_fracao();
		return c;
	}

	else
	{
		int mmc = Racional::mmc(denominador, b.denominador); //calcula o minimo multiplo comum
		c.denominador = mmc;
		c.numerador = ((mmc / denominador) * numerador) - ((mmc / b.denominador) * b.numerador);
		c.reduzir_fracao();
		return c;
	}
}

Racional Racional::multiplicacao(const Racional & b) const
{
	Racional c;
	c.numerador = numerador * b.numerador;
	c.denominador = denominador * b.denominador;
	c.reduzir_fracao();
	return c;
}

Racional Racional::divisao(const Racional & b) const
{
	Racional c;
	c.numerador = numerador * b.denominador;
	c.denominador = denominador * b.numerador;
	c.reduzir_fracao();
	return c;
}