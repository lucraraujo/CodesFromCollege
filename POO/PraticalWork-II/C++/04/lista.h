#ifndef __LISTA_H
#define __LISTA_H

#include <string>
#include <iostream>
#include <fstream>

class Lista {
	class No {
		int valor;
		No* proximo;
	public:
		No(int);
		//friend class Lista;
		int GetValor() const;
		No* GetProximo() const;
		void Set(Lista::No*);
	};

	Lista::No* primeiro;
	Lista::No* ultimo;
	int tamanho;
public:
	Lista(); //construtor letra a
	bool InsereNaLista(int); //letra b
	bool EstaNaLista(int) const; //letra c
	bool RetiraDaLista(int); //letra d
	void Importar(std::string); //letra f
	void Exportar(std::string); //letra e
	~Lista(); //destrutor letra g
	void Imprime() const;
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

#endif