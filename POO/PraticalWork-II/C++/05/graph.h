#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "edge.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

class Graph
{
	std::vector<std::list<int>> ListaDeAdjacencia;
	size_t Tamanho;
	int Arestas;

public:
	Graph (int);
	bool insert(const Edge&);
	void Imprime() const;
	bool remove(const Edge&);
	void NumArestasVertices() const;
	bool edge(const Edge & aresta);
	Graph *importar(std::string);
};

#endif