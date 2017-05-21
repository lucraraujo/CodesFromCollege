#include "ordenacao.h"

string recupera_palavra (istream& in)
{
	char ch;
	string s;

	while( in.get(ch) && ch != ' ' && ch != '.' && ch != ',' && ch != '(' &&
		ch != ')' && ch != '!' && ch != '?' && ch != '\\' && ch != '\'' &&
		ch != '\"' && ch != ':' && ch != '\t' && ch != '\n' && ch != '/' && 
		ch != '_' && ch != '+' && ch != '=' && ch != '*')
	{
		s += ch | ' ';
	}

	return s;
}

vector<Palavra> GeraVetorPalavras (char* nome_arquivo)
{
	vector<Palavra> palavras;

	ifstream arq(nome_arquivo);
	if (!arq.is_open())
	{
		cout << "Erro ao abrir arquivo.\n";
		return palavras;
	}

	string palavra;
	while (!arq.eof())
	{
		palavra = recupera_palavra(arq);
		if (palavra.size() == 0) continue;
		InserirPalavra(palavras,palavra);
	}

	return palavras;
}

void InserirPalavra (vector<Palavra>& palavras, string palavra)
{
	if(palavras.size() == 0)
	{
		Palavra novaPalavra;
		novaPalavra.palavra = palavra;
		novaPalavra.ocorrencias = 1;
		palavras.push_back(novaPalavra);
		return;
	}
	
	int i = busca_binaria (palavras, 0, (palavras.size())-1, palavra);
	
	if (i != -1)
	{
		palavras[i].ocorrencias++;
		return;
	}
		
	Palavra novaPalavra;
	novaPalavra.palavra = palavra;
	novaPalavra.ocorrencias = 1;
	palavras.push_back (novaPalavra);
	insertion (palavras, 0, (palavras.size())-1);
}

void OrdenaPalavrasOcorrencias (vector<Palavra>& palavras)
{
	quicksort (palavras, 0, (palavras.size()) - 1);
}

void ImprimirPalavras (vector<Palavra>& palavras, char* nome_arquivo)
{
	ofstream arq (nome_arquivo);
	if (!arq.is_open())
	{
		cout << "Erro ao abrir arquivo.\n";
		return;
	}

	int i, n = palavras.size();
	for (i = 0 ; i < n ; ++i)
	{
		arq << "(" << palavras[i].ocorrencias << ")\t" << palavras[i].palavra << "\n";
	}
}
