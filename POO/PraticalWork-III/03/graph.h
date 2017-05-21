#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "edge.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
typedef std::list<int> ListInt;

class GraphSingleton
{
	std::vector<ListInt> ListaDeAdjacencia;
	size_t Tamanho;
	int Arestas;
	GraphSingleton(int);
	GraphSingleton(const GraphSingleton&);
public:
	bool insert(const Edge&);
	void Imprime() const;
	bool remove(const Edge&);
	void NumArestasVertices() const;
	bool edge(const Edge & aresta);
	static GraphSingleton* instance(int);
	static GraphSingleton *importar(std::string);
};

#endif