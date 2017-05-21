
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#define MAXTAM 50

int main()
{
	std::ofstream arq;
	arq.open("matriz.txt");
	int nos;
	std::cout << "Insira o numero de nos" << std::endl;
	std::cin >> nos;
	int matrizad[MAXTAM][MAXTAM];
	srand(time(NULL));
	for (int i = 0; i < nos; i++)
	{
		for (int j = 0; j < nos; j++)
		{
			if (i == j)
			{
				matrizad[i][j] = 0;
				break;
			}
			//int sorteio1 = rand() % 2;
			int sorteio1 = 1;
			if (sorteio1)
			{
				int sorteio2 = rand() % 10 + 1;
				matrizad[i][j] = sorteio2;
				matrizad[j][i] = sorteio2;
			}
			else
			{
				matrizad[i][j] = 0;
				matrizad[j][i] = 0;
			}
		}
	}

	if (arq.is_open())
	{
		arq << nos << std::endl;
		for (int i = 0; i < nos; i++)
		{
			for (int j = 0; j < nos; j++)
			{
				arq << matrizad[i][j] << " ";
			}
			arq << std::endl;
		}
	}
	else
	{
		std::cout << "Não pode abrir arquivo" << std::endl;
	}
	arq.close();
	return 0;
}