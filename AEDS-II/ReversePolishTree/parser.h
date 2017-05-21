#ifndef _PARSER_H_
#define _PARSER_H_

#include <vector>
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

enum tipo {NUMERO, OPERADOR, PARENTESE};

struct Elemento
{
	int		tipo;
	double	valor;
	char	operador;
	int		prioridade;
};



Elemento** parse(char* expressao, int i);
int		   numero_de_elementos(char* expressao, int i);
Elemento*  proximo_elemento (char* expressao, int &i);
double     recupera_numero  (char* expressao, int &i);
void       apaga_elementos(Elemento** v);

double calcularesultado(vector<Elemento*> vetor, vector<int> posicao);

#endif
