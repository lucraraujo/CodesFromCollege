#ifndef _PARSER_H_
#define _PARSER_H_

//enumera quais os tipos e as funcos q eu vou ter no programa
enum tipo {NUMERO, OPERADOR, FUNCAO};
enum funcao {seno, cosseno, tangente, logb10, logn, secante, cossecante, cotangente, raiz, menos};

//declara o tipo elemento
struct Elemento
{
	int		tipo;
	double	valor;
	char	operador;
	int		funcao;
	int		prioridade;
};

struct Lista
{
	struct Celula
	{
		Elemento *	elemento;
		Celula*		prox;
	};
	Celula* primeiro;
	Celula* ultimo;
	int		tamanho;
};

struct Pilha
{
	struct Celula
	{
		Elemento*	elemento;
		Celula*		ant;
	};
	Celula* ultimo;
	int		tamanho;
};

//funcoes do parser.cpp
Lista*		parse(char*, int);
int			numero_de_elementos(char* expressao, int i);
Elemento*	proximo_elemento (char* expressao, int &i);
int			recupera_funcao(char* expressao, int &i);
double		recupera_numero  (char* expressao, int &i);
void		imprime_elementos(Lista*);

//funcoes do lista.cpp
Lista*		nova_lista();
bool		adicionar_na_lista(Lista*, Elemento*);
void		deletar_lista(Lista*) ;

//funcoes do pilha.cpp
Pilha*		nova_pilha();
bool		empilha(Pilha*, Elemento*);
Elemento*	desempilha(Pilha*);
void		deletar_pilha(Pilha*);

//funcoes do polonesa.cpp
Lista*		polonesa_inversa(Lista*);
double		calcula_resultado(Lista*);
double		calcula_funcao(int, double);
double		calcula_operador(char, double, double);
bool		verifica_inversa(Lista*);

#endif