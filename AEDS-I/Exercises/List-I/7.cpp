#include<iostream.h>
using namespace std;
int main()
{
    int numero, divisor, soma, limite;
    cout << "Quantos n�meros voc� deseja analisar?\n";
    cin >> limite;
    for (numero=1; numero<=limite; numero++)
        {
        soma=0;
        for (divisor=1; divisor<numero; divisor++)
            {
            if (numero%divisor==0)
                                  {
                                  soma=soma+divisor;
                                  }
            }
        if (soma==numero)
                         {
                         cout << "O n�mero " << numero << " � perfeito.\n";
                         }
        }
    system("pause");
    return 0;
}
