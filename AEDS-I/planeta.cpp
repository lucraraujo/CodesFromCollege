#include<iostream.h>
using namespace std;
int main ()
{
int pterra, nplan, pplan, grav;
cout << "Digite o peso na Terra\n";
cin >> pterra;
cout << "Digite o número do planeta\n";
cout << "Planeta" << "Número" << "\n";
cout << "Mercúrio = " << 1 << "\n";
cout << "Vênus = " << 2 << "\n";
cout << "Marte = " << 3 << "\n";
cout << "Jupiter = " << 4 << "\n";
cout << "Saturno = " << 5 << "\n";
cout << "Urano = "  << 6 << "\n";
cin >> nplan;
switch (nplan)
{
case 1: cout << (pterra/10)*0.57 << "\n";
break;
case 2: cout << (pterra/10)*0.88 << "\n";
break;
case 3: cout << (pterra/10)*0.39 << "\n";
break;
case 4: cout << (pterra/10)*2.64 << "\n";
break;
case 5: cout << (pterra/10)*1.15 << "\n";
break;
case 6: cout << (pterra/10)*1.17 << "\n";
break;
default: cout << "Operador inválido\n";
}
return 0;
}