#include <iostream>
#include <string>
#include "parser.h"
using namespace std;

//analisa a expressao inserida pelo usuario e insere em uma lista
Lista* parse(char* expressao, int i)
{
	//verifica se a expressao não é vazia
	int n = numero_de_elementos(expressao,i);
	if(n == 0) return 0;
	//cria uma nova lista
	Lista* lista = nova_lista();
	//analisa cada vetor da expressao inicial e adiciona na lista criada
	for(int k = 0 ; k < n; )
		adicionar_na_lista(lista, proximo_elemento(expressao,k));
	//retorna a lista criada
	return lista;
}

//faz a contagem de quantos elementos existem no vetor inicial
int numero_de_elementos(char* expressao, int i)
{
	while(expressao[i] != '\0')
	{
		//ignora espacos em branco
		while(expressao[i] == ' ') ++i;
		if(expressao[i] >= '0' && expressao[i] <= '9' || expressao[i] == '.') 
		{
			while(expressao[i] >= '0' && expressao[i] <= '9' || expressao[i] == '.')
				++i;
		}
		else
			++i;
	}
	return i;
}

//verifica qual o tipo do elemento analisado no vetor inicial e o retorna para ser inserido na lista
Elemento* proximo_elemento(char* expressao, int &i)
{
	//ignora espacos em branco
	while(expressao[i] == ' ') ++i;
	//fim da expressao
	if(expressao[i] == '\0')
		return 0;
	Elemento* e = new Elemento;
	//verifica se eh numero
	if(expressao[i] >= '0' && expressao[i] <= '9' || expressao[i] == '.')
	{
		e->tipo  = NUMERO;
		e->valor = recupera_numero(expressao,i);
		return e;
	}
	
	//verifica se é operador, excluindo o menos"-" que ja foi tratado
	if (expressao[i] == '+' || expressao[i] == '*' || expressao[i] == '-' || expressao[i] == '/'
		|| expressao[i] == '(' || expressao[i] == ')' || expressao[i] == '^')
	{
		e->tipo = OPERADOR;
		e->operador = expressao[i++];
		//define as prioridade de cada operador
		if (expressao[i-1] == '+' || expressao[i] == '-')
			e->prioridade = 1;
		if (expressao[i-1] == '*' || expressao[i-1] == '/')
			e->prioridade = 2;
		if (expressao[i-1] == '^')
			e->prioridade = 3;
		if (expressao[i-1] == '(' || expressao[i-1] == ')')
			e->prioridade = 0;
		return e;
	}
	//se naõ é numero nem operador, entao é funcao
	else
	{
		e->tipo = FUNCAO;
		e->funcao = recupera_funcao(expressao, i);
		e->prioridade = 0;
		return e;
	}
}


//Recupera a funcao inserida pelo usuario
int recupera_funcao(char* expressao, int &i)
{
	string letra, funcao;	
	int j = i;
	//verifica quantas posições tera que andar dentro do vetor
	while (j < numero_de_elementos(expressao,i))
	{
		//condições de parada
		if (expressao[j] == '(')
			break;
		if (expressao[j] == ' ')
			break;
		if (expressao[j] == '\0')
			break;
		j++;
	}
	//anda dentro do vetor e recupera cada letra da funcao
	for (int k = i ; k < j; k++)
	{
	letra = expressao[k];
	funcao += letra;
	}	
	//incrementa o "i" para determinar qual a proxima posição que deve ser analisada
	i = j;
	//verifica qual a funcao q foi inserida e retorna o valor inteiro correspondente no "enum funcao"
	if (funcao == "sin")
		return seno;
	if (funcao == "cos")
		return cosseno;
	if (funcao == "tan")
		return tangente;
	if (funcao == "log")
		return logb10;
	if (funcao == "ln")
		return logn;
	if (funcao == "sec")
		return secante;
	if (funcao == "csc")
		return cossecante;
	if (funcao == "ctg")
		return cotangente;
	if (funcao == "sqrt")
		return raiz;
}
//recupera o numero do vetor inicial, pois cada numero foi inserido em uma posição diferente do vetor
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

//imprime os elementos da lista
void imprime_elementos(Lista* l)
{
	int k = 0;
	Lista::Celula* c = l->primeiro;
	while(k < l->tamanho)
	{
		Elemento* e = c->elemento;
		if(e->tipo == NUMERO)
			cout << "NUM\t";
		if(e->tipo == OPERADOR)
			cout << "OP\t";
		if(e->tipo == FUNCAO)
			cout << "FUNC\t";
		c = c->prox;
		++k;
	}
	cout << endl;
	k = 0;
	c = l->primeiro;
	while(k < l->tamanho)
	{
		Elemento* e = c->elemento;
		if(e->tipo == NUMERO)
			cout << e->valor << "\t";
		if(e->tipo == OPERADOR)
			cout << e->operador <<"\t";
		if(e->tipo == FUNCAO)
		{
			if (e->funcao == seno)
				cout << "sin" << "\t";
			if (e->funcao == cosseno)
				cout << "cos" << "\t";
			if (e->funcao == tangente)
				cout << "tan" << "\t";
			if (e->funcao == logb10)
				cout << "log" << "\t";
			if (e->funcao == logn)
				cout << "ln" << "\t";
			if (e->funcao == secante)
				cout << "sec" << "\t";
			if (e->funcao == cossecante)
				cout << "csc" << "\t";
			if (e->funcao == cotangente)
				cout << "ctg" << "\t";
			if (e->funcao == raiz)
				cout << "sqrt" << "\t";
			if (e->funcao == menos)
				cout << "-" << "\t";
		}
		c = c->prox;
		++k;
	}			
	cout << endl<< endl << endl;		
}
