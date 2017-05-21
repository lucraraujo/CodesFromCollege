#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

void remove_pontuacao(std::vector<std::string>&);

int main()
{
	std::string linha, nome_arquivo;
	std::vector<std::string> palavras;
	std::cout << "Digite o nome do arquivo fonte: ";
	std::getline(std::cin,nome_arquivo); //recebe o nome do arquivo

	std::ifstream in(nome_arquivo.c_str()); //abre o arquivo para leitura
	if(!in.is_open())
		std::cerr << "Nao foi possível abrir o arquivo";

	else
	{
		while (! in.eof())
		{
			in >> linha;
			palavras.push_back(linha);
		}

		//removendo pontuação
		for(int i = 0;i < palavras.size();++i)
			remove_pontuacao(palavras);


		std::ofstream out("saida.txt");
		if(!out.is_open())
			std::cerr << "Nao foi possível criar o arquivo de saida";

		else
		{
			out << "Palavras desordenadas: " << std::endl << std::endl;
			for(int i = 0;i < palavras.size();++i)
				out << palavras[i] << std::endl;

			std::sort(palavras.begin(),palavras.end());

			out << std::endl << std::endl
				<< "Palavras ordenadas: " << std::endl << std::endl;
			for(int i = 0;i < palavras.size();++i)
				out << palavras[i] << std::endl;

			std::cout << "Arquivo saida.txt criado." << std::endl;

		}
	}

	return 0;
}


void remove_pontuacao(std::vector<std::string>& palavras)
{
	for(int i = 0;i < palavras.size();++i)
		for(int j = 0;j < palavras[i].length();++j)
			if(palavras[i][j] == ',' || palavras[i][j] == '.' || palavras[i][j] == ':' || palavras[i][j] == ';' 
				|| palavras[i][j] == '!' || palavras[i][j] == '?')

			{			
				palavras[i].erase(j); //remove o caracter da string
				j--; //a string diminui de tamanho...entao tem que decrementar o j
			}
}