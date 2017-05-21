#include<iostream.h>
using namespace std;
int main()
{
    int matriza[20][10], matrizb[21][11], limitel, limitec, linha, coluna, produto;
    cout << "Quantas linhas tem a matriz?\n";
    cin >> limitel;
    cout << "Quantas colunas tem a matriz?\n";
    cin >> limitec;
    for (linha=0; linha<limitel; linha++)
        {
         for (coluna=0; coluna<limitec; coluna++)   
             {
              cout << "Digite o valor para a linha " << linha+1 << " e coluna " << coluna+1 << " da matriz.\n";   
              cin >> matriza[linha][coluna];
              }
         }
    cout << "\n\n";
    cout << "A matriz A está impressa abaixo\n";
    for (linha=0; linha<limitel; linha++)
        {
        for (coluna=0; coluna<limitec; coluna++)
           {
           cout <<  matriza[linha][coluna] << "\t";
           }
        cout << "\n";
        }
    cout << "\n\n";
     for (linha=0; linha<limitel; linha++)
        {
        produto=1;
        for (coluna=0; coluna<limitec; coluna++)
           {
           matrizb[linha][coluna] = matriza[linha][coluna];
           produto = produto * matriza[linha][coluna];
           }
        matrizb[linha][limitec] = produto;
        }
        cout << "A matriz B está impressa abaixo\n";
        for (linha=0; linha<limitel; linha++)
            {
            for (coluna=0; coluna<limitec+1; coluna++)
                {
                cout <<  matrizb[linha][coluna] << "\t";
                }
            cout << "\n";
            }
        cout << "\n";
        return 0;
}
