#include<iostream.h>
using namespace std;
int main ()
{
    int fet1, fet2, fet, valor, serie;
    cout << "Digite o valor do primeiro FETUCCINE:\n";
    cin >> fet1;
    cout << "Digite o valor do segundo FETUCCINE:\n";
    cin >> fet2;

    //Declarei variável "serie" para que a pessoa escolha quantos números da série ela deseja obter.

    cout << "Quantos numeros da série você deseja calcular?\n";
    cin >> serie;
    cout << "\n";

    //A partir daqui a conta começa a ser feita. Eu declarei uma variável "valor" para receber o valor calculado e imprimir o valor a partir dessa variável "valor".

    for (fet=0; fet<serie; fet++)
	    {
		if (fet%2!=0)
        
                     {
                     valor=fet2-fet1;
                     }
		else
		    {
            valor=fet2+fet1;
            }
        fet1=fet2;
        fet2=valor;
        cout << valor << "\n";
	    }
	return 0;
}
