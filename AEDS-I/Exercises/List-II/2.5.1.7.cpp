#include<iostream.h>
using namespace std;
int main()
{
	int vetor[100][4], limite, linha, soma=0;
	cout << "Quantas mercadorias você deseja cadastrar?\n";
	cin >> limite;
	for (linha=0; linha<limite; linha++)
	    {
        vetor[linha][0]=linha+1;
        cout << "Qual preço do produto " << linha+1 << "?\n";
        cin >> vetor[linha][1];
        cout << "Qual a quantidade vendida do produto " << linha+1 << "?\n";
        cin >> vetor[linha][2];
        vetor[linha][3] = (vetor[linha][1] * vetor[linha][2]);
        soma = soma + vetor[linha][3];
        }
     for (linha=0; linha<limite; linha++)
        {
        cout << "\nCódigo = " << vetor[linha][0] << ".\nPreço = " << vetor[linha][1] << ".\nQuantidade vendida = " << vetor[linha][2] << ".\nLucro do produto = " << vetor[linha][3] << ".\n";
        }
        cout << "\nO lucro total do armazém é " << soma << ".\n";
     return 0;
}
