#include "graph.h"

Graph::Graph(int a) : Tamanho(a)
{
	ListaDeAdjacencia.assign(a, 0);
	Arestas = 0;
}

bool Graph::insert(const Edge& aresta)
{
	int no1 = aresta.GetNode1();
	int no2 = aresta.GetNode2();

	if (no1 > (Tamanho-1) || no2 > (Tamanho-1))
		return false;

	if (edge(aresta))
		return false;

	ListaDeAdjacencia [aresta.GetNode1()].push_back(aresta.GetNode2());
	ListaDeAdjacencia [aresta.GetNode1()].sort();
	ListaDeAdjacencia [aresta.GetNode2()].push_back(aresta.GetNode1());
	ListaDeAdjacencia [aresta.GetNode2()].sort();
	++Arestas;
	return true;
}

void Graph::Imprime() const
{
	std::list<int>::const_iterator i;
	for (int j = 0; j < ListaDeAdjacencia.size(); ++j)
	{
		std::cout << j << " | ";
		for (i = ListaDeAdjacencia[j].begin(); i!=ListaDeAdjacencia[j].end(); ++i)
			std::cout << *i << " -> ";
		std::cout << std::endl;
	}
}

bool Graph::remove(const Edge & aresta)
{
	int no1 = aresta.GetNode1();
	int no2 = aresta.GetNode2();

	if (no1 > (Tamanho-1) || no2 > (Tamanho-1))
		return false;

	if (!edge(aresta))
		return false;

	ListaDeAdjacencia[no1].remove(no2);
	ListaDeAdjacencia[no2].remove(no1);
	--Arestas;
	return true;
}

void Graph::NumArestasVertices() const
{
	std::cout << "O grafo tem " << Arestas << " arestas e " << Tamanho << " vertices." << std::endl;
}

bool Graph::edge(const Edge & aresta)
{
	if(std::find(ListaDeAdjacencia[aresta.GetNode1()].begin(),
		ListaDeAdjacencia[aresta.GetNode1()].end(), aresta.GetNode2())
		!= ListaDeAdjacencia[aresta.GetNode1()].end())
		return true;
	else
		return false;
}

Graph *Graph::importar(std::string nomeArquivo)
{
	std::ifstream arq;
	arq.open(nomeArquivo.c_str());
	if (!arq.is_open())
	{
		std::cerr << "Erro ao abrir o arquivo" << std::endl;
		return false;
	}
	Edge aresta(0,0);
	int tamanho, no1, no2;
	arq >> tamanho;
	Graph *grafo = new Graph(tamanho);
	while (!arq.eof())
	{
		arq >> no1;
		arq >> no2;
		aresta.Set(no1, no2);
		grafo->insert(aresta);
	}
	return grafo;
}