#include "arvore.h"

Elemento** parse(char* expressao, int i)
{
	int n = numero_de_elementos(expressao,i);
	if(n == 0) return 0;

	Elemento ** v = new Elemento*[n+1];
	v[n] = 0;
	for(int k=0 ; k<n ; ++k)
		v[k] = proximo_elemento(expressao,i);

	return v;
}

int numero_de_elementos(char* expressao, int i)
{
	int n = 0;
	
	while(expressao[i] != '\0')
	{
		//ignora espacos em branco
		while(expressao[i] == ' ') ++i;
	
		if(expressao[i] >= '0' && expressao[i] <= '9' || expressao[i] == '.') 
		{
			while(expressao[i] >= '0' && expressao[i] <= '9' || expressao[i] == '.')
				++i;
			++n;
		}
		else
		{
		    ++i;
			++n;
		}
	}

	return n;
}

Elemento* proximo_elemento(char* expressao, int &i)
{
	//ignora espacos em branco
	while(expressao[i] == ' ') ++i;
	
	//fim da expressao
	if(expressao[i] == '\0') return 0;

	Elemento* e = new Elemento;

	//verifica se eh numero
	if(expressao[i] >= '0' && expressao[i] <= '9' || expressao[i] == '.')
	{
		e->tipo  = NUMERO;
		e->valor = recupera_numero(expressao,i);
		return e;
	}

	if (expressao[i] == '(' || expressao[i] == ')')
	{
		e->tipo = PARENTESE;
		e->operador = expressao[i++];
		return e;
	}
	
	//recupera operador
	e->tipo = OPERADOR;
	if (expressao[i] == '^')
	  e->prioridade = 3;
	if (expressao[i] == '*' || expressao[i] == '/')
	  e->prioridade = 2;
	if (expressao[i] == '+' || expressao[i] == '-')
	  e->prioridade = 1;
	e->operador = expressao[i++];

	return e;
}

double recupera_numero(char* expressao, int &i)
{
	double v = 0;
	
	//parte inteira
	while(expressao[i] >= '0' && expressao[i] <= '9')
	{
		v *= 10;
		v += expressao[i] - '0';
		++i;
	}

	//ignora '.'
	if(expressao[i] == '.') ++i;

	//parte decimal
	double div = 1;
	double dec = 0;
	while(expressao[i] >= '0' && expressao[i] <= '9')
	{
		dec *= 10;
		dec += expressao[i] - '0';
		div *= 10;
		++i;
	}

	v += dec/div;

	return v;
}

void apaga_elementos(Elemento** v)
{
	int k=0;
	while(v[k])
	{
		delete v[k];
		++k;
	}
	delete[] v;
}

static double resultadooperador(char operador, double numero1, double numero2)
{
	if (operador == '^')
		return pow(numero1, numero2);
	if (operador == '*')
		return numero1 * numero2;
	if (operador == '/') 
		return numero1 / numero2;
	if (operador == '+')
		return numero1 + numero2;
	if (operador == '-') 
		return numero1 - numero2;
	else 
		return 0;
}

double calcularesultado(vector<Elemento*> vetor, vector<int> posicao)
{
	stack<double> numero;
	for (int i = 0; i < int(posicao.size()); i++)
	{
		if (vetor[posicao[i]]->tipo == NUMERO)
			numero.push(vetor[posicao[i]]->valor);
	
		if (vetor[posicao[i]]->tipo == OPERADOR)
		{
			double num1, num2;
			num2 = numero.top();
			numero.pop();
			num1 = numero.top();
			numero.pop();
			numero.push(resultadooperador(vetor[posicao[i]]->operador, num1, num2));
		}
	}
	return numero.top();
}
