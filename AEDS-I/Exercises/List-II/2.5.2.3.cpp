#include<iostream.h>
using namespace std;
int main()
{
    int matriz[100][200], linha, coluna, soma=0, limitel, limitec, selecionalinha;
    cout << "Quantas linha você deseja para esta matriz?\n";
    cin >> limitel;
    cout << "Quantas colunas você deseja para esta matriz?\n";
    cin >> limitec;       
    for (linha=0; linha<limitel; linha++)
        {
        for (coluna=0; coluna<limitec; coluna++)
            {
            cout << "Digite o valor para a linha " << linha+1 << " e coluna " << coluna+1 << ".\n";
            cin >> matriz[linha][coluna];
            }
        }
    cout << "De qual linha você deseja obter o somatório?\n";
    cin >> selecionalinha;
    for (coluna=0; coluna<limitec; coluna++)
        {
        soma = soma + matriz[selecionalinha-1][coluna];
        }
    cout << "O somatório dos termos da linha " << selecionalinha << " é " << soma << ".\n";
    return 0;
}
