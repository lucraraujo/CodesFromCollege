#include "parser.h"
#include <cmath>
#define PI 3.14159265

//Passa da notação normal para a notação inversa
Lista* polonesa_inversa(Lista* l)
{
	//cria uma nova lista que recebera a expressao ja na notação inversa e que sera retornada ao fim da funcao
	Lista* lista_inversa = nova_lista();
	//cria a pilha que recebera operadores e funcoes durante o processo de inversao da lista
	Pilha* pilha = nova_pilha();
	//cria uma nova celula que recebe a primeira celula da lista a ser analisada
	//para q seja possivel andar dentro da lista a ser analisada
	Lista::Celula* c = l->primeiro;
	//cria o elemento q sera ou empilhado ou inserido na lista
	Elemento* e;
	int i = 0;
	bool eh_numero = false;
	while(i < l->tamanho)
	{
		//elemento "e" recebe o elemento q esta dentro da celula "c"
		e = c->elemento;	
		//se for numero, adiciona na lista
		if (e->tipo == NUMERO)
		{
			adicionar_na_lista(lista_inversa, e);
			if (eh_numero == false)
				adicionar_na_lista(lista_inversa, desempilha(pilha));
			eh_numero = true;
		}
		if (e->operador == '-' && eh_numero == false)
		{
			e->tipo = FUNCAO;
			e->funcao = menos;
			e->prioridade = 0;
		}
		//se for funcao, empilha
		if (e->tipo == FUNCAO)
		{
			empilha(pilha, e);
			eh_numero = false;
		}
				
		//se for operador
		if(e->tipo == OPERADOR && e->operador != '(' && e->operador != ')')
		{
			//se a pilha estiver vazia, empilhe
			if(pilha->tamanho == 0)
				empilha(pilha, e);
			//senao, se a prioridade do ultimo elemento da pilha for maior do q o elemento analisado
			else if(pilha->ultimo->elemento->prioridade >= e->prioridade)
			{
				//enquanto a prioridade do ultimo elemento da pilha for maior do q o elemento analisado
				while(pilha->ultimo->elemento->prioridade >= e->prioridade)
				{
					//desempilha o ultimo elemento da pilha e adiciona na lista inversa
					adicionar_na_lista(lista_inversa, desempilha(pilha));
					//se a pilha ficar vazia, pare.
					if (pilha->tamanho == 0)
						break;
				}
				//empilha o elemento
				empilha(pilha, e);
			}
			//se a prioridade do elemento analisado for maior do que o ultimo da pilha, entao empilha
			else
				empilha(pilha, e);
			eh_numero = false;
		}
		
		//trata abre e fecha parentese
		//se for abre parentese, empilha
		if (e->operador == '(')
		{
			empilha(pilha, e);
			eh_numero = false;
		}
		//se for fecha parentese
		if (e->operador == ')')
		{
			//enquanto não achar o abre parentese, desempilhe e adicione na lista inversa
			while (pilha->ultimo->elemento->operador != '(')
				adicionar_na_lista(lista_inversa, desempilha(pilha));
			//desempilha o abre parentese e despreza ele
			desempilha(pilha);
			//se a pilha não estiever vazia e o ultimo elemento da pilha for funcao, desempilha a funcao
			//e adiciona na lista
			if(pilha->tamanho != 0 && pilha->ultimo->elemento->tipo == FUNCAO)
				adicionar_na_lista(lista_inversa, desempilha(pilha));
			eh_numero = false;
		}
		//incrementa o i
		++i;
		//recebe qual a proxima celula da lista inicial a ser analisada
		c = c->prox;
	}
	//enquanto a pilha não estiver vazia
	while(pilha->tamanho != 0)
	{
		//enquanto tiver abre parentese, desempilhe e despreze
		while (pilha->ultimo->elemento->operador == '(')
			desempilha(pilha);		
		//desempilhe e adicione na lista inversa
		adicionar_na_lista(lista_inversa, desempilha(pilha));
	}
	//retorna a lista inversa
	deletar_pilha(pilha);
	return lista_inversa;
}

//Calcula o resultado da lista na notação polonesa inversa
double calcula_resultado(Lista* l)
{
	//cria uma nova pilha para armazenar os numeros e resultados das operações
	Pilha* numeros = nova_pilha();
	//cria uma nova celula que recebe a primeira celula da lista a ser analisada
	//para q seja possivel andar dentro da lista a ser analisada
	Lista::Celula* c = l->primeiro;
	//cria o elemento q sera ou empilhado ou inserido na lista
	Elemento* e;
	int i = 0;
	while(i < l->tamanho)
	{
		//cria um elemento auxiliar para ajudar nas operações
		Elemento* aux;
		e = c->elemento;
		//se for numero, empilha
		if (e->tipo == NUMERO)
			empilha(numeros, e);
		//se for função
		if (e->tipo == FUNCAO)
		{
			//desempilha um numero
			aux = desempilha(numeros);
			//calcula o resultado do numero desempilhado e da funcao analisada
			aux->valor = calcula_funcao(e->funcao, aux->valor);
			//empilha o resultado
			empilha(numeros, aux);
		}
		//se for operador
		if (e->tipo == OPERADOR)
		{
			double num1, num2;
			//desempilha dois numeros, sendo q o primeiro desempilhado é o segundo numero da expressao, e nao o primeiro
			aux = desempilha(numeros);
			num2 = aux->valor;
			aux = desempilha(numeros);
			num1 = aux->valor;
			//calcula o resultado dos numeros desempilhados e do operador analisada
			aux->valor = calcula_operador(e->operador, num1, num2);
			//empilha o resultado
			empilha(numeros, aux);
		}
		//anda na lista
		c = c->prox;
		i++;
	}
	//desempilha o ultimo numero da pilha e retorna o valor
	e = desempilha(numeros);	
	deletar_pilha(numeros);
	
	return e->valor;
}

//Calcula o valor da função, dado uma função válida, dado um numero qualquer;
double calcula_funcao(int f, double v)
{
	if (f == seno)
		return sin(v*PI/180);
	if (f == cosseno)
		return cos(v*PI/180);
	if (f == tangente)
		return tan(v*PI/180);
	if (f == logb10)
		return log10(v);
	if (f == logn)
		return log(v);
	if (f == secante)
		return 1/cos(v*PI/180);
	if (f == cossecante)
		return 1/sin(v*PI/180);
	if (f == cotangente)
		return 1/tan(v*PI/180);
	if (f == raiz)
		return sqrt(v);
	else
		return -1*v;
}		


//Calcula o valor do operador, dado um operador válido, dado um numero qualquer;
double calcula_operador(char o, double a, double b)
{
	if (o == '^')
		return pow(a, b);
	if (o == '*')
		return a * b;
	if (o == '/') 
		return a / b;
	if (o == '+')
		return a + b;
	else
		return a - b;
}

//Verifica se a expressao é inversa
bool verifica_inversa(Lista* l)
{
	Lista::Celula* c = l->primeiro;
	//se o primeiro elemento da lista for numero e o proximo for funcao, retorna verdadeiro
	if (c->elemento->tipo == NUMERO && c->prox->elemento->tipo == FUNCAO)
		return true;
	//se o primeiro elemento da lista for numero e o proximo tambem for numero, retorna verdadeiro
	if (c->elemento->tipo == NUMERO && c->elemento->tipo == c->prox->elemento->tipo)
		return true;
	//qualquer outro caso, é falso
	else
		return false;
}