#include<iostream.h>
using namespace std;
int main()
{
    int matriz[100][200], linha, coluna, soma=0, limitel, limitec, selecionacoluna;
    cout << "Quantas linha voc� deseja para esta matriz?\n";
    cin >> limitel;
    cout << "Quantas colunas voc� deseja para esta matriz?\n";
    cin >> limitec;       
    for (linha=0; linha<limitel; linha++)
        {
        for (coluna=0; coluna<limitec; coluna++)
            {
            cout << "Digite o valor para a linha " << linha+1 << " e coluna " << coluna+1 << ".\n";
            cin >> matriz[linha][coluna];
            }
        }
    cout << "De qual coluna voc� deseja obter o somat�rio?\n";
    cin >> selecionacoluna;
    for (linha=0; linha<limitel; linha++)
        {
        soma = soma + matriz[linha][selecionacoluna-1];
        }
    cout << "O somat�rio dos termos da coluna " << selecionacoluna << " � " << soma << ".\n";
    return 0;
}
