#include "vetor.h"
namespace DataStructures{
	Vetor::Vetor(int tam) : tamanho(tam)
	{
		ptr = new double[tamanho];
		for(int i = 0;i < tamanho;++i)
			ptr[i] = 0;
	}

	Vetor::Vetor(const Vetor& v) : tamanho(v.tamanho)
	{
		ptr = new double[tamanho];
		for(int i = 0;i < tamanho;++i)
			ptr[i] = v.ptr[i];
	}

	Vetor::~Vetor()
	{
		delete [] ptr;
	}

	double & Vetor::operator [](int indice)
	{
		return ptr[indice];
	}

	Vetor & Vetor::operator =(const Vetor& obj)
	{
		if(this == &obj) //elimina problema da auto-atribuição
			return *this;

		delete [] ptr;
		tamanho = obj.tamanho;
		ptr = new double[tamanho];
		for(int i = 0;i < tamanho;++i)
			ptr[i] = obj.ptr[i];

		return *this;

	}

	double & Vetor::operator ()(int indice)
	{
		return ptr[indice];
	}

	Vetor Vetor::operator +(const Vetor& B)
	{
		if(tamanho > B.tamanho)
		{
			Vetor C = *this;
			for(int i = 0;i < B.tamanho;++i)
				C.ptr[i] += B.ptr[i];
			return C;
		}
		else
		{
			Vetor C = B;
			for(int i = 0;i < tamanho;i++)
				C.ptr[i] += ptr[i];
			return C;
		}
	}

	Vetor Vetor::operator -(const Vetor& B)
	{
		if(tamanho > B.tamanho || tamanho == B.tamanho)
		{
			Vetor C = *this;
			for(int i = 0;i < B.tamanho;++i)
				C.ptr[i] -= B.ptr[i];
			return C;
		}

		Vetor C(B.tamanho);
		for(int i = 0;i < tamanho;++i) //nas primeiras posições, copia o valor do proprio objeto
			C.ptr[i] = ptr[i];

		for(int j = tamanho;j < B.tamanho;++j) //as outras posiçoes ficam com valor 0
			C.ptr[j] = 0;

		for(int i = 0;i < B.tamanho;++i)
			C.ptr[i] -= B.ptr[i];

		return C;
	}

	std::ostream& operator <<(std::ostream& o, const Vetor& v)
	{
		//o << v.tamanho << std::endl;
		for(int i = 0;i < v.tamanho;++i)
			o << v.ptr[i] << " ";
		o << std::endl;
		return o;
	}

	std::istream& operator >>(std::istream& in, Vetor& v)
	{
		std::cout << "Digite o tamanho do vetor: ";
		in >> v.tamanho;
		delete [] v.ptr;
		v.ptr = new double[v.tamanho];
		for(int i = 0;i < v.tamanho;++i)
		{
			std::cout << "Digite o valor do indice " << i << " : ";
			in >> v.ptr[i];
		}
		return in;
	}
}
