#include<iostream.h>
using namespace std;
int main ()
{
	int mult, serie;

    //A partir daqui a conta come�a a ser feita. Foi adicionado a vari�vel "serie" para que o usu�rio indique at� qual n�mero ele deseja que a contagem seja feita.

    cout << "Em qual n�mero voc� deseja que a contagem termine?\n";
    cin >> serie;
    cout << "Os multiplos de 5 s�o:\n";
	for (mult=5; mult<=serie; mult+=5)
 		         {
                 cout << mult << "\t";
                 }
	cout << "\n";
	return 0;
}
