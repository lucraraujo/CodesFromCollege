#include<iostream.h>
using namespace std;
int main()
{
    int matriza[2][4], matrizb[2][4],  coluna, linha,matrizc[2][4];
    for (linha=0; linha<2; linha++)
        {
         for (coluna=0; coluna<4; coluna++)             
             {
             cout << "Digite o valor para a linha " << linha+1 << " e coluna " << coluna+1 << " da matriz A.\n";
             cin >> matriza[linha][coluna];
             }
        }
    cout << "\n";
    for (linha=0; linha<2; linha++)
        {
         for (coluna=0; coluna<4; coluna++)             
             {
             cout << "Digite o valor para a linha " << linha+1 << " e coluna " << coluna+1 << " da matriz B.\n";
             cin >> matrizb[linha][coluna];
             }
        }
        cout << "\nA matriz C é\n";
        for (linha=0; linha<2; linha++)
        {
         for (coluna=0; coluna<4; coluna++)             
             {
             matrizc[linha][coluna] = matriza[linha][coluna] + matrizb[linha][coluna];
             cout << matrizc[linha][coluna] << "\t";
             }
         cout << "\n";
         }
    return 0;
}
