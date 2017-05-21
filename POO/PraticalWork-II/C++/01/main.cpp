#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
	std::ifstream entrada;
	std::ofstream saida;
	std::string arq_saida, arq_entrada, linha;
	std::vector<std::string> linhas;
	size_t found;

	std::cout << "Qual o nome do arquivo a ser aberto?" << std::endl;
	getline(std::cin, arq_entrada);

	entrada.open(arq_entrada.c_str());

	arq_saida = arq_entrada;
	arq_saida.insert(((int)arq_saida.size() - 4), "SemComentario");



	//Trata erro de abertura de arquivo
	if (!entrada.is_open())
	{
		std::cout << "Falha ao abrir arquivo" << std::endl;
		return 1;
	}

	//pega as linhas do arquivo e coloca cada linha em uma posicao de um vetor de string
	while (!entrada.eof())
	{
		getline(entrada, linha);
		linhas.push_back(linha);
	}

	entrada.close();
	saida.open(arq_saida.c_str());

	for (int i = 0; i < (int)linhas.size(); ++i)
	{
		found = linhas[i].find("//", 0);
		if (found != -1)
		{
			for (int j = 0; j < (int)found; j++)
				saida << linhas[i][j];
			saida << std::endl;
			continue;
		}

		found = linhas[i].find("/*", 0);
		if (found != -1)
		{
			size_t found2;
			found2 = linhas[i].find("*/", found);
			if (found2 != -1)
			{
				for (int j = 0; j < (int)found; j++)
					saida << linhas[i][j];
				for (int j = (found2 + 2); j < (int)linhas[i].size(); j++)
					saida << linhas[i][j] << std::endl;
			}
			else
			{
				for (i; i < (int)linhas.size(); i++)
				{
					found2 = linhas[i].find("*/", 0);
					if (found2 != -1)
					{
						saida << linhas[++i] << std::endl;
						break;
					}
				}
			}
			continue;
		}
		saida << linhas[i] << std::endl;
	}
	std::cout << "Arquivo " << arq_saida << " gerado." << std::endl;
	return 0;
}