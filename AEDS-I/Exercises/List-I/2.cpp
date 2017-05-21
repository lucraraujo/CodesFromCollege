#include<iostream.h>
using namespace std;
int main ()
{
	int mult, serie;

    //A partir daqui a conta começa a ser feita. Foi adicionado a variável "serie" para que o usuário indique até qual número ele deseja que a contagem seja feita.

    cout << "Em qual número você deseja que a contagem termine?\n";
    cin >> serie;
    cout << "Os multiplos de 5 são:\n";
	for (mult=5; mult<=serie; mult+=5)
 		         {
                 cout << mult << "\t";
                 }
	cout << "\n";
	return 0;
}
