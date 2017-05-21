#include "lista.h"

namespace DataStructure {
	Lista::Lista()
	{
		primeiro = 0;
		ultimo = 0;
		tamanho = 0;
	}

	Lista::No::No(int a)
	{
		valor = a;
		proximo = 0;
	}

	bool Lista::EstaNaLista(int a) const
	{
		if (tamanho == 0)
			return false;
		Lista::No* no = primeiro;
		for (int i = 0; i < tamanho; ++i)
		{
			if (no->GetValor() == a)
				return true;
			no = no->GetProximo();
		}
		return false;
	}

	/*TRABALHO PRATICO 3*/

	Lista& Lista::operator +=(int a)
	{
		if (EstaNaLista(a))
		{
			return *this;
		}
		Lista::No* no = new Lista::No(a);
		if (tamanho == 0)
		{
			primeiro = no;
			ultimo = no;
		}
		else
		{
			if(primeiro->GetValor() > a)
			{
				no->Set(primeiro);
				primeiro = no;
			}
			else if (ultimo->GetValor() < a)
			{
				ultimo->Set(no);
				ultimo = no;
			}
			else
			{
				Lista::No* aux = primeiro;
				for (int i = 0; i < tamanho; ++i)
				{
					if (aux->GetProximo()->GetValor() > a)
					{
						no->Set(aux->GetProximo());
						aux->Set(no);
						break;
					}
					aux = aux->GetProximo();
				}
			}
		}
		++tamanho;
		return *this;
	}



	std::ifstream& operator >> (std::ifstream& in, Lista& l)
	{
		int numero;
		while (!in.eof())
		{
			in >> numero;
			l +=numero;
		}
		return in;
	}

	Lista& Lista::operator-=(const int& x)
	{
		if(!EstaNaLista(x)) //se o elemento não estiver na lista
		{
			return *this;
		}

		Lista::No* aux;
		if(primeiro->GetValor() == x) //se o elemento a ser retirado for o primeiro da lista
		{
			aux = primeiro;
			primeiro = primeiro->GetProximo();
			delete aux;
			tamanho--;
			return *this;
		}

		Lista::No* aux1 = primeiro; //aux1 aponta para o elemento anterior 
		aux = primeiro->GetProximo(); //aux aponta para o elemento a ser removido

		for(int i = 0;i < tamanho;++i)
		{
			if(aux->GetValor() == x)
			{
				if(aux->GetProximo() == 0) //se for o ultimo elemento da lista
				{
					ultimo = aux1; 
					aux1->Set(0); //aterra o ponteiro
					delete aux;
					break;
				}
				else
				{
					aux1->Set(aux->GetProximo());
					delete aux;
					break;
				}
			}
			aux1 = aux;
			aux = aux->GetProximo();
		}

		tamanho--;
		return *this;
	}

	Lista::~Lista()
	{
		destroiLista();
	}

	Lista& Lista::operator+=(const Lista& a)
	{
		Lista::No* noL = a.primeiro;
		for (int i = 0; i < a.tamanho; ++i)
		{
			*this += noL->GetValor();
			noL = noL->GetProximo();
		}
		return *this;
	}

	Lista& Lista::operator =(const Lista& l)
	{
		if (this == &l)
			return *this;
		destroiLista();
		Lista::No* ptr = l.primeiro;
		int n = 0;
		for(int i = 0;i < l.tamanho;++i)
		{
			n = ptr->GetValor();
			*this += n;
			ptr = ptr->GetProximo();
		}
		return *this;
	}

	Lista::Lista(const Lista& l) //construtor de copia
	{
		Lista::No* ptr = l.primeiro;
		int n = 0;
		tamanho = 0;
		for(int i = 0;i < l.tamanho;++i)
		{
			n = ptr->GetValor();
			*this += n;
			ptr = ptr->GetProximo();
		}
	}

	Lista Lista::operator +(Lista &a)
	{
		Lista aux = *this;
		aux += a;
		return aux;
	}

	void Lista::destroiLista()
	{
		Lista::No *aux = primeiro, *aux1 = primeiro;

		for(int i = 0;i < tamanho;++i)
		{
			aux = aux1;	//aux1 aponta para o proximo da lista a ser deletado
			aux1 = aux1->GetProximo();
			delete aux;
		}
	}

	int Lista::operator() (int a)
	{
		if (a > tamanho) return EXIT_FAILURE;
		Lista::No* aux = primeiro;
		for (int i = 0; i < a; ++i)
		{
			aux = aux->GetProximo();
		}
		return aux->GetValor();
	}

	std::istream& operator >> (std::istream& in, Lista& l)
	{
		std::cout << "Digite o tamanho da lista: " << std::endl;
		int tam;
		in >> tam;
		int n;
		for (int i = 0; i < tam; ++i)
		{
			std::cout << "Digite o elemento da posicao " << i << std::endl;
			in >> n;
			l += n;
		}
		return in;
	}

	std::ostream& operator << (std::ostream& out, const Lista& l)
	{
		out << "O tamanho da lista e: " << l.tamanho << std::endl;
		Lista::No* aux = l.primeiro;
		for (int i = 0; i < l.tamanho; ++i)
		{
			out << aux->GetValor() << " "; 
			aux = aux->GetProximo();
		}
		out << std::endl;
		return out;
	}
}