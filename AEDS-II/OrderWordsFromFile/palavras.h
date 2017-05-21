#ifndef _PALAVRAS_H_
#define _PALAVRAS_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct Palavra
{
	int  ocorrencias;
	string palavra; 
};

vector<Palavra> GeraVetorPalavras(char* nome_arquivo);
string recupera_palavra(istream &in);
void InserirPalavra(vector<Palavra> &palavras, string palavra);
void OrdenaPalavrasOcorrencias(vector<Palavra> &palavras);
void ImprimirPalavras(vector<Palavra> &palavras, char* nome_arquivo);

#endif
