#include<iostream.h>
#include<fstream.h>
#include<stdio_ext.h>

using namespace std;

int const dig=20; //dig é o máximo de caracteres que o nome do filme pode ter

struct filme
{
	int codigo;
	char nome[dig];
	char genero;
	char status;
};

int const maximo=100;
filme vetfilmes[maximo];
int total; // tot: total de filmes no banco de dados
int alteracao=0; // alteracao irá dizer se houve alteraçao nos dados do vetor

#include"locadora.h"
#include"arquivo.h"

int main ()
{
	char resposta;
	int operacao=-1;
	carregar();

	while ( operacao != 6 )
	{
		system("clear");
		cout << "\n\n\tMENU PRINCIPAL:\n\n\n\t 1) Inserir\n\t 2) Remover\n\t 3) Alterar\n\t 4) Pesquisar\n\t 5) Salvar\n\n\t 6) Sair\n\n\nCodigo da operacao:  ";
		cin >> operacao;
		
		switch (operacao)
		{
			case 1: inserir (); break;

			case 2: remover (); break;

			case 3: alterar (); break;

			case 4: pesquisar (); break;

			case 5: salvar ();

				alteracao=0;
				system("clear");
				cout << "\n\n\tSALVANDO ARQUIVO\n\n\n\n\n\n\n\n\n\n\n\nPressione ENTER para continuar...";
				__fpurge(stdin);
				getchar();
				break;

			case 6: if ( alteracao==1 )
				{
					while ( resposta != 's' or resposta != 'S' or resposta != 'N' or resposta != 'n' )
					{
						system("clear");
						cout << "\n\n\tSAIR\n\n\n\n\n\n\n\n\n\n\n\nSalvar alteracoes? (S/N) ";
						cin >> resposta;

						if ( resposta=='s' || resposta=='S' ) 
						{
							salvar ();
							goto fim;
						}

						if ( resposta=='n' || resposta=='N' ) goto fim;
					}
				fim: ;
				}
				break;

			default: cout << "Operacao invalida";
		}
	}

	system("clear");

	return 0;
}

