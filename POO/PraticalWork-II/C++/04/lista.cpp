#include "lista.h"

Lista::Lista()
{
	primeiro = 0;
	ultimo = 0;
	tamanho = 0;
}

bool Lista::InsereNaLista(int a)
{
	std::cout << "Inserindo o numero " << a << std::endl;
	if (EstaNaLista(a))
	{
		std::cout << "O numero " << a << " ja esta na lista." << std::endl;
		return false;
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
	return true;
}

void Lista::Imprime() const
{
	Lista::No* no = primeiro;
	for (int i = 1; i <= tamanho; ++i)
	{
		std::cout << no->GetValor() << " ";
		no = no->GetProximo();
	}
	std::cout << std::endl;
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

void Lista::Importar(std::string nome_arquivo)
{
	std::cout << "Importando arquivo " << nome_arquivo << std::endl;
	std::ifstream arq;
	arq.open(nome_arquivo.c_str());

	if (!arq.is_open())
	{
		std::cout << "Erro ao abrir o arquivo " << nome_arquivo << "." << std::endl;
		return;
	}

	int numero;
	while (!arq.eof())
	{
		arq >> numero;
		InsereNaLista(numero);
	}
	std::cout << "Arquivo importado com sucesso! " << std::endl;
}

void Lista::Exportar(std::string nome_arquivo)
{
	std::ofstream arq;
	arq.open(nome_arquivo.c_str());

	if (!arq.is_open())
	{
		std::cout << "Erro ao abrir o arquivo " << nome_arquivo << "." << std::endl;
		return;
	}
	Lista::No* no = primeiro;
	for (int i = 0; i  < tamanho; ++i)
	{
		arq << no->GetValor() << " ";
		no = no->GetProximo();
	}
	std::cout << "Arquivo exportado com sucesso! " << std::endl;
}

bool Lista::RetiraDaLista(int x)
{
	std::cout << "Excluindo o numero " << x << std::endl;
	if(!EstaNaLista(x)) //se o elemento não estiver na lista
	{
		std::cout << "O numero " << x << " nao esta na lista." << std::endl;
		return false;
	}

	Lista::No* aux;
	if(primeiro->GetValor() == x) //se o elemento a ser retirado for o primeiro da lista
	{
		aux = primeiro;
		primeiro = primeiro->GetProximo();
		delete aux;
		tamanho--;
		return true;
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
	return true;
}

Lista::~Lista()
{
	Lista::No *aux = primeiro, *aux1 = primeiro;

	for(int i = 0;i < tamanho;++i)
	{
		aux = aux1;	//aux1 aponta para o proximo da lista a ser deletado
		aux1->Set(aux1->GetProximo());
		delete aux;
	}
}