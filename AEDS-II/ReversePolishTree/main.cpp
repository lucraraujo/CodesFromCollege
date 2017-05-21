#include "arvore.h"

int main()
{
	const int MAXTAM = 200;
	char expressao[MAXTAM];
	vector<int> vetor;
	vector<Elemento*> vetor_corrigido;

	cout << "Digite a expressao: ";
	cin.getline(expressao, MAXTAM);
	
	Elemento** v = parse(expressao, 0);
	
	int k = 0;
	while (v[k])
		++k;

	verifica_parentese(v, 0, k, vetor_corrigido);
	
	No* raiz = novo_No(menorprioridade(vetor_corrigido, 0, (vetor_corrigido.size())-1));

	cospiarvore (vetor_corrigido, 0, (vetor_corrigido.size())-1, raiz);
	
	imprimir_arvore(raiz, vetor_corrigido);
	
	percorrer_pos_order(raiz, vetor);
	
	//Imprime o vetor na notacao polonessa
	for (int i = 0; i < int(vetor.size()); i++)
	{
		if (vetor_corrigido[vetor[i]]->tipo == NUMERO)
			cout << vetor_corrigido[vetor[i]]->valor << ' ';
		
		if (vetor_corrigido[vetor[i]]->tipo == OPERADOR)
			cout << vetor_corrigido[vetor[i]]->operador << ' ';
	}
	cout << endl;
	
	
	double resultado = calcularesultado(vetor_corrigido, vetor);
	
	cout << "Resultado = " << resultado << endl;

	deleta_arvore(raiz);

	apaga_elementos(v);

	return 0; 
}
