#include "Kruskal.h"

void GeraArestas(std::vector<aresta> &arestas, char *nome_arq, int &ordem)
{
	int i = 0, j = 0;
	std::ifstream arq;
	arq.open(nome_arq);
	if (arq.is_open())
	{
		arq >> ordem; 
		while (!arq.eof())
		{
			int peso;
			if (j == ordem)
			{
				j = 0;
				i++;
				continue;
			}
			arq >> peso;
			if (peso == 0)
				j++;
			else
				NovaAresta(arestas, i, j, peso);
		}
	}
	else
		std::cout << "Erro ao abrir o arquivo " << nome_arq << std::endl;

	arq.close();
}

bool ordenacao(aresta aresta1, aresta aresta2)
{
	return (aresta1.peso < aresta2.peso);
}

void Kruskal(std::vector<aresta> &resultado, std::vector<aresta> arestas, int ordem)
{
	std::vector<std::string> controle;
	std::string no1, no2;
	bool existe1, existe2;
	int pos1, pos2, custo = 0, i = 0;
	size_t achou;
	for (int i = 0; i < int(arestas.size()); i++)
	{
		if (int(resultado.size()) < (ordem-1))
		{
			existe1 = false;
			existe2 = false;
			if(arestas[i].no1 <= arestas[i].no2)
			{

				Int2Char(arestas[i].no1, arestas[i].no2, no1, no2);

				for (int j = 0; j < int(controle.size()); j++)
				{
					achou = controle[j].rfind(no1);
					if (int(achou) != -1)
					{
						existe1 = true;
						pos1 = j;
					}
					achou = controle[j].rfind(no2);
					if (int(achou) != -1)
					{
						existe2 = true;
						pos2 = j;
					}

					if (existe1 && existe2)
						break;
				}
				if (existe1 || existe2)
				{
					if (existe1 && existe2)
					{
						if (pos1 == pos2)
							continue;
						else
						{
							controle[pos1] += "," + controle[pos2];
							controle.erase(controle.begin() + pos2);
							resultado.push_back(arestas[i]);
							custo += arestas[i].peso;
						}
					}
					else
					{
						if (existe1)
						{
							controle[pos1] += "," + no2;
							resultado.push_back(arestas[i]);
							custo += arestas[i].peso;
						}
						else
						{
							controle[pos2] += "," + no1;
							resultado.push_back(arestas[i]);
							custo += arestas[i].peso;
						}
					}
				}
				else
				{
					no1 += "," + no2;
					controle.push_back(no1);
					resultado.push_back(arestas[i]);
					custo += arestas[i].peso;
				}
			}

		}
		else
			break;
	}
	ImprimeArquivoResultado("AGM.txt", resultado, custo);
}

void ImprimeArquivoResultado (char *nome_arq, std::vector<aresta> vetor, int custo)
{
	std::ofstream arquivo;
	arquivo.open(nome_arq);
	if (arquivo.is_open())
	{
		arquivo << "Custo Total = " << custo << std::endl;
		for (int i = 0; i < int(vetor.size()); i++)
		{
			if (vetor[i].no1 < 10 || vetor[i].no2 < 10)
			{
				if (vetor[i].no1 < 10 && vetor[i].no2 < 10)
					arquivo << vetor[i].no1 << "  <-->  "  << vetor[i].no2 << " Peso = " << vetor[i].peso << std::endl;
				else if (vetor[i].no1 < 10)
					arquivo << vetor[i].no1 << "  <--> "  << vetor[i].no2 << " Peso = " << vetor[i].peso << std::endl;
				else
					arquivo << vetor[i].no1 << " <-->  "  << vetor[i].no2 << " Peso = " << vetor[i].peso << std::endl;
			}
			else
				arquivo << vetor[i].no1 << " <--> "  << vetor[i].no2 << " Peso = " << vetor[i].peso << std::endl;
		}

	}
	else
		std::cout << "Erro ao abrir o arquivo " << nome_arq << std::endl;

	arquivo.close();
}

void NovaAresta(std::vector<aresta> &arestas, int i, int &j, int peso)
{
	aresta edge;
	edge.no1 = i;
	edge.no2 = j;
	edge.peso = peso;
	arestas.push_back(edge);
	j++;
}

void Int2Char(int num1, int num2, std::string &no1, std::string &no2)
{
	std::stringstream buffer;

	buffer << num1;
	no1 = buffer.str();
	buffer.str(std::string());
	if (num1 < 10)
		no1.insert(0, "0");

	buffer << num2;
	no2 = buffer.str();
	if (num2 < 10)
		no2.insert(0, "0");

}