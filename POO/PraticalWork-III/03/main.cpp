#include "graph.h"

int main()
{
	
	GraphSingleton *grafo = GraphSingleton::importar("entrada.txt");
	grafo->Imprime();
	
	Edge aresta(4,5);
	grafo->remove(aresta);

	aresta.Set(3,4);
	grafo->remove(aresta);

	aresta.Set(0,2);
	grafo->remove(aresta);

	aresta.Set(3,7);
	grafo->remove(aresta);

	aresta.Set(7,3);
	grafo->remove(aresta);

	grafo->NumArestasVertices();
	grafo->Imprime();

	return 0;
}