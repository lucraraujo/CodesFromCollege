#include<iostream.h>
using namespace std;
int main()
{
	double matricula, nota1, nota2, nota3, frequencia, alunos, contador, notafinal, maior=0, notatotal=0, mediaturma, reprovados, reprovadosfrequencia=0, porcentagenreprovadosfrequencia, menor=100;
	cout << "Quantos alunos tem na sala?\n";
	cin >> alunos;
	for (contador=1; contador<=alunos; contador++)
	    {
		cout << "Digite a matrícula do aluno?\n";
		cin >> matricula;
		cout << "Quanta aulas o aluno freqüentou?\n";
		cin >> frequencia;
		cout << "Digite a primeira nota?\n";
		cin >> nota1;
		cout << "Digite a segunda nota?\n";
		cin >> nota2;
		cout << "Digite a terceira nota?\n";
		cin >> nota3;
		notafinal=(nota1+nota2+nota3)/3;
		notatotal=notatotal+notafinal;	
		if (notafinal>maior)
			                {
                            maior=notafinal;
                            }
		if (notafinal<menor)
			                {
                            menor=notafinal;
                            }
		if (notafinal<60 or frequencia<40)
		   {  
			cout << "Aluno matrícula número " << matricula << "\n";
			cout << "Freqüentou " << frequencia << " aulas.\n";
			cout << "A sua nota final foi " << notafinal << " .\n";
			cout << "O aluno foi reprovado\n\n";
			reprovados++;
           }
		else
		    {
			cout << "Aluno matrícula número " << matricula << "\n";
			cout << "Freqüentou " << frequencia << " aulas.\n";
			cout << "A sua nota final foi " << notafinal << " .\n";
			cout << "O aluno foi aprovado\n\n";
		    }
		if (frequencia<40)
			              {
                          reprovadosfrequencia++;
                          }
        }	
	cout << "\n\n\n";
	mediaturma=notatotal/alunos;
	porcentagenreprovadosfrequencia=(100*reprovadosfrequencia)/alunos;
	cout << "A maior nota da turma é " << maior << " .\n";
	cout << "A menor nota da turma é " << menor << " .\n";
	cout << "A nota média da turma é " << mediaturma << " .\n";
	cout << "O total de alunos reprovados é " << reprovados << " .\n";
	cout << "A porcentagem de alunos reprovados por infreqüencia é " << porcentagenreprovadosfrequencia << " .\n";
	return 0;
}
