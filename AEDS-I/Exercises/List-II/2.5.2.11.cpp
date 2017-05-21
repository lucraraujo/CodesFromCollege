#include<iostream.h>
using namespace std;
int main()
{
    int matriz[23][10], linha, coluna, populosa=0, estado, cidade, capitais=0, media;
    for (linha=0; linha<23; linha++)
        {
        for (coluna=0; coluna<10; coluna++)
            {
            cout << "Digite a população da cidade " << coluna+1 << " do estado " << linha+1 << ".\n";
            cin >> matriz[linha][coluna];
            }
        }
        cout << "\n";
        for (linha=0; linha<23; linha++)
            {
            for (coluna=0; coluna<10; coluna++)
                {
                if (populosa<matriz[linha][coluna])
                   {
                   populosa = matriz[linha][coluna];
                   estado = linha+1;
                   cidade = coluna+1;
                   }
                }
            }
        cout << "A cidade " << cidade << " é a cidade mais populosa do estado " << estado << ".\n";
        for (linha=0; linha<23; linha++)
            {
            capitais = capitais + matriz[linha][0];
            }
        media = (capitais/23);
        cout << "A média da população das capitais dos 23 estados é: " << media << ".\n";
        return 0;
}
