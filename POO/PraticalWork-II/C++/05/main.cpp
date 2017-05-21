#include "graph.h"

int main()
{
	Graph *grafo = 0;
	grafo = grafo->importar("entrada.txt");

	grafo->Imprime();
	grafo->NumArestasVertices();

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

	grafo->Imprime();
	grafo->NumArestasVertices();

	return 0;
}