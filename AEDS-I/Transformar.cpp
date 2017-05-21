#include <iostream.h>
using namespace std;
int main()
{
char F;
char C;
char K;
char N;
int n;
int c;
int f;
int k;
cout << "Digite o valor a ser transfomado.\n";
cin >> n;
cout << "Em qual escala está o número acima? (C, F, K?)\n";
cin >> N;
if (N==F);
{c=(5*n-160)/9; k=c+273; cout << "Temperatura em escala Celcius = " << c << "\n"; cout << "Temperatura em escala Kelvin = " << k << "\n";}
if (N==C); {f=(9*n+160)/5; k=n+273; cout << "Temperatura em escala Farenheit = " << f << "\n"; cout << "Temperatura em escala Kelvin = " << k << "\n";}
return 0;
}
