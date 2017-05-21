#include<iostream.h>
using namespace std;
int main()
{
    double media, idade, soma, pessoas;
    soma=0;
    pessoas=0;
    do{
              cout << "Digite a idade do indivíduo.\t";
              cin >> idade;
              soma=soma+idade;
              pessoas=pessoas+1;
    }while (idade!=0);
    if (idade==0)
       {
       pessoas=pessoas-1;
       }
    media=(soma/pessoas);
    cout << "A idade média dos " << pessoas << " indivíduos é: " << media << "\n";
    return 0;
}
	
