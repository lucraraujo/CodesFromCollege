#include "ordenacao.h"

int main()
{
	vector<Palavra> palavras = GeraVetorPalavras("palavras.txt");

	ImprimirPalavras(palavras, "saida_alfabetica.txt");
	cout << "arquivo saida_alfabetica.txt criado\n";

	OrdenaPalavrasOcorrencias(palavras);
	ImprimirPalavras(palavras, "saida_ocorrencias.txt");
	cout << "arquivo saida_ocorrencias.txt criado\n";

	return 0;
}
