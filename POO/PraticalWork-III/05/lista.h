#ifndef __LISTA_H
#define __LISTA_H

#include <string>
#include <iostream>
#include <fstream>

namespace DataStructure {
	class Lista {
		class No {
			int valor;
			No* proximo;
		public:
			No(int);
			int GetValor() const;
			No* GetProximo() const;
			void Set(Lista::No*);
		};

		Lista::No* primeiro;
		Lista::No* ultimo;
		int tamanho;
		void destroiLista();
	public:
		Lista();
		bool EstaNaLista(int) const;
		~Lista();
		//TP3
		Lista(const Lista&); //construtor de cópia
		Lista& operator =(const Lista&);
		Lista& operator +=(const Lista&);
		Lista& operator -=(const int&);
		Lista operator +(Lista&);
		Lista& operator +=(int);
		int operator() (int i);
		friend std::istream& operator >> (std::istream&, Lista&);
		friend std::ostream& operator << (std::ostream&, const Lista&);
		friend std::ifstream& operator >> (std::ifstream&, Lista&);
	};




	inline int Lista::No::GetValor() const
	{
		return valor;
	}

	inline Lista::No* Lista::No::GetProximo() const
	{
		return proximo;
	}

	inline void Lista::No::Set(Lista::No* no)
	{
		proximo = no;
	}
}

#endif