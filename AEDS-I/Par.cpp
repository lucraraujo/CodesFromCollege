#include<iostream.h>
using namespace std;
int main ()
{
	int n;
	cout << "Digite um numero:\n";
	cin >> n;
	if (n%2==0)
	{cout << "\t\nO n�mero " << n << " � par.\n\n";}
	else {cout << "\t\nO n�mero " << n << " � impar.\n\n";}
	
	return 0;
}