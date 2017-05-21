#include "Kruskal.h"

int main(int argc, char** argv)
{

	char *nome_arq = "matriz.txt";
	int ordem;
	std::vector<aresta> arestas, resultado;

	GeraArestas(arestas, nome_arq, ordem);
	stable_sort (arestas.begin(), arestas.end(), ordenacao);
	Kruskal (resultado, arestas, ordem);

	return 0;
}