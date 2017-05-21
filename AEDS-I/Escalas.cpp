#include<iostream.h>
using namespace std;
int main()
{
int F;
int C;
int K;
int N;
int n;
int c;
int f;
int k;
cout << "Digite o valor a ser transfomado.\n";
cin >> n;
cout << "Em qual escala está o número acima? (C=1, F=2, K=3?)\n";
cin >> N;
if (N==2)
{c=(5*n-160)/9;
k=c+273; cout << "Temperatura em escala Celcius = " << c << "\n"; cout << "Temperatura em escala Kelvin = " << k << "\n";}
if (N==1)
{f=(9*n+160)/5; k=n+273; cout << "Temperatura em escala Farenheit = " << f << "\n"; cout << "Temperatura em escala Kelvin = " << k << "\n";}
if (N==3)
{c=n-273; f=(9*c+160)/5; cout << "Temperatura em escala Celcius = " << c << "\n"; cout << "Temperatura em escala Farenheit =" << f << "\n";}
return 0;
}
