#ifndef FUNCOES_H
#define	FUNCOES_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
/*using std::std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::std::vector;
using std::stable_sort;
using std::stringstream;*/


struct aresta
{
	int no1;
	int no2;
	int peso;
};

void GeraArestas(std::vector<aresta>&, char*, int&);
bool ordenacao(aresta, aresta);
void Kruskal (std::vector<aresta>&, std::vector<aresta>, int);
void ImprimeArquivoResultado (char *, std::vector<aresta>, int);
void TrataMenor10(std::string&, std::string&);
void NovaAresta(std::vector<aresta> &, int, int&, int);
void Int2Char(int, int, std::string&, std::string&);

#endif