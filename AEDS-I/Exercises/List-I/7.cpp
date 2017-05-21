#include<iostream.h>
using namespace std;
int main()
{
    int numero, divisor, soma, limite;
    cout << "Quantos números você deseja analisar?\n";
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
                         cout << "O número " << numero << " é perfeito.\n";
                         }
        }
    system("pause");
    return 0;
}
