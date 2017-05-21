#include <iostream.h>
using namespace std;
int main()
{
int a;
int b;
int c;
int t;
	cout << "Digite um valor para A\n";
	cin >> a;
	cout << "Digite um valor para B\n";
	cin >> b;
	cout << "Digite um valor para C\n";
	cin >> c;
t=a;
a=b;
b=c;
c=t;
	cout << "Valor de A = " << a << "\n";
	cout << "Valor de B = " << b << "\n";
	cout << "Valor de C = " << c << "\n";
	return 0;
}
