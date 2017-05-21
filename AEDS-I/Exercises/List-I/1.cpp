#include<iostream.h>
using namespace std;
int main()
{
	int pares, contador, serie;
	pares=-2;
    cout << "Quantos numeros pares você deseja?\n";
    cin >> serie;
    cout << "Os " << serie << " primeiros numeros pares são:";
	for (contador=1; contador<=serie; contador++)
		{
		pares=pares+2;
		cout << pares << "\t";
		}
	cout << "\n";
	return 0;
}
