#include<iostream.h>
using namespace std;
int main ()
{
int da, ma, aa;
int dn, mn, an;
int dia, mes, ano;
	cout << "Digite o dia atual:\n";
	cin >> da;
	if (da>31)
	{cout << "Data inválida.\n"; cout << "Digite uma data válida:\n";cin >> da;}
	cout << "Digite o mês atual:\n";
	cin >> ma;
	if (ma>12) {cout << "Mês inválido.\n"; cout << "Digite um mês válido:\n"; cin >> ma;}
	cout << "Digite o ano atual:\n";
	cin >> aa;
	cout << "Digite o dia de nascimento:\n";
	cin >> dn;
	if (dn>31) {cout << "Data inválida.\n"; cout << "Digite uma data válida:\n"; cin >> dn;}
	cout << "Digite o mes de nascimento:\n";
	cin >> mn;
	if (mn>12) {cout << "Mês inválido.\n"; cout << "Digite um mês válido:\n"; cin >> mn;}
	cout << "Digite o ano de nascimento:\n";
	cin >> an;
	if (an>aa) {cout << "Ano inválido.\n"; cout << "Digite o ano de nascimento novamente:\n"; cin >> an;}
	if (ma<mn)
	{
	ano=aa-an-1;
		if (da<dn);
		{mes=12-mn+ma-1;}
		if (da>dn);
		{mes=12-mn+ma;}
	dia=dn-da;}
	if (ma>mn)
	{
	ano=aa-an;
		if (da<dn)
		{mes=ma-mn-1;}
		if (da>dn)
		{mes=ma-mn;}
	}
	cout << "A pessoa tem " << ano << " anos, " << mes << " meses e " << dia << " dias\n";
	return 0;
}
