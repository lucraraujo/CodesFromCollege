

int geracodigo()
{
	int codigo=0;
	int i;

	for ( i=0; i<total; i++ )
	{
		if ( codigo < vetfilmes[i].codigo )
		{
			codigo=vetfilmes[i].codigo;
		}
	}
	codigo++;
	return codigo;
}

void inserir ()
{
	system("clear");
	cout << "\n\nINSERIR NOVO FILME" << "\n\n\n\n\nNome:\nCodigo:\nGenero:\n\n\n\n\nEntre com o nome do filme: ";
	cin >> vetfilmes[total].nome;

	system("clear");
	vetfilmes[total].codigo=geracodigo();

	system("clear");
	cout << "\n\nINSERIR NOVO FILME" << "\n\n\n\n\nNome: " << vetfilmes[total].nome << "\nCodigo: " << vetfilmes[total].codigo << "\nGenero:\n\n\n\n\nEntre com o genero do filme: ";
	cin >> vetfilmes[total].genero;

	system("clear");
	cout << "\n\nINSERIR NOVO FILME" << "\n\n\n\n\nNome: " << vetfilmes[total].nome << "\nCodigo: " << vetfilmes[total].codigo << "\nGenero: " << vetfilmes[total].genero << "\n\n\n\n\nFilme inserido com sucesso. Pressione ENTER para continuar...";
	vetfilmes[total].status='D';

	alteracao=1;
	total++;
	__fpurge(stdin);
	getchar();
}

void remover ()
{
	int i, codrem; //codigo do filme a ser removido
	int sinal=0; //sinal irá dizer se há filme com o codigo digitado no banco de dados
	char enter;

	system("clear");
	cout << "\n\n\tREMOVER FILME\n\n\n\n\n\n\n\n\n\n\n\nDigite o codigo do filme a ser removido: ";
	cin >> codrem;

	for ( i=0 ; i<total ; i++ )
	{
		if ( vetfilmes[i].codigo==codrem )
		{
			vetfilmes[i].codigo=0;
			vetfilmes[i].nome[0]='R';
			vetfilmes[i].nome[1]='\0';
			vetfilmes[i].genero='R';
			vetfilmes[i].status='R';
			sinal=1;
			system("clear");
			cout << "\n\n\tREMOVER FILME\n\n\n\n\n\n\n\n\n\nFilme removido com sucesso.\n\nPressione ENTER para continuar...";

			alteracao=1;

			__fpurge(stdin);
			getchar();
		}
	}
	if ( sinal==0 )
	{
		system("clear");
		cout << "\n\n\tCodigo invalido.\n\n\n\n\n\n\n\n\n\n\n\nPressione ENTER para continuar...";
		__fpurge(stdin);
		getchar();
	}
}

void alterar ()
{
	int codalt; //codigo do filme a ser alterado
	int sinal;  //sinal irá dizer se há filme com o codigo digitado no banco de dados
	int i, opcao, pos; /* 'pos' irá armazenar a posição do vetor de filmes onde está o filme com o
		    código escolhido */

	system("clear");
	cout << "\n\n\tALTERAR\n\n\n\n\n\n\n\n\n\n\n\nDigite o codigo do filme a ser alterado: ";
	cin >> codalt;

	for ( i=0, sinal=0; i<total ; i++ )
	{
		if ( vetfilmes[i].codigo==codalt )
		{
			sinal=1;
			pos=i;
		}
	}

	if ( sinal==1 )
	{
		menu:
		system("clear");
		cout << "\n\n\tALTERAR\n\n\n\n\n1) Nome: " << vetfilmes[pos].nome << "\n2) Genero: " << vetfilmes[pos].genero << "\n3) Status: " << vetfilmes[pos].status << "\n\n\n\n\nO que deseja alterar? ";
		cin >> opcao;

		switch (opcao)
		{
			case 1: system("clear");
				cout << "\n\n\tALTERAR\n\n\n\n\n\n\n\n\n\n\n\nNome: ";
				cin >> vetfilmes[pos].nome;
				alteracao=1;
				break;

			case 2: system("clear");
				cout << "\n\n\tALTERAR\n\n\n\n\n\n\n\n\n\n\n\nGenero: ";
				cin >> vetfilmes[pos].genero;
				alteracao=1;
				break;

			case 3: system("clear");
				cout << "\n\n\tALTERAR\n\n\n\n\n\n\n\n\n\n\n\nStatus: ";
				cin >> vetfilmes[pos].status;
				alteracao=1;
				break;

			default: goto menu;
		}
		system("clear");
		cout << "\n\n\tALTERAR\n\n\n\n\nNome: " << vetfilmes[pos].nome << "\nGenero: " << vetfilmes[pos].genero << "\nStatus: " << vetfilmes[pos].status << "\n\n\n\n\nPressione ENTER para continuar...";
		__fpurge(stdin);
		getchar();
	}
	if ( sinal==0 )
	{
		system("clear");
		cout << "\n\n\tALTERAR\n\n\n\n\n\n\n\n\n\n\n\nCodigo invalido. Pressione ENTER para continuar...";
		__fpurge(stdin);
		getchar();
	}
}

void pesquisar ()
{
	int parametro=8, i, j;
	int sinal, sinal2=0; //sinal irá dizer se a pesquisa retornou ou nao algum resultado

	while ( parametro!=4)
	{
		system("clear");
		cout << "\n\n\tPESQUISA DE FILMES\n\n\n\t  PARAMETROS\n\n\t  1) Codigo\n\t  2) Nome\n\t  3) Genero\n\n\t  4) Retornar\n\n\nParametro para pesquisa: ";
		cin >> parametro;

		switch (parametro)
		{
			case 1: int codpes; //código a ser pesquisado
				sinal=0;

				system("clear");
				cout << "\n\n\tPESQUISA DE FILMES\n\n\n\n\n\n\n\n\n\n\n\nCodigo a pesquisar: ";
				cin >> codpes;
				
				for ( i=0 ; i<total ; i++ )
				{
					if ( vetfilmes[i].codigo==codpes )
					{
						system("clear");
						cout << "\n\n\tPESQUISA DE FILMES\n\n\n\nCodigo: " << vetfilmes[i].codigo << "\nNome: " << vetfilmes[i].nome << "\nGenero: " << vetfilmes[i].genero << "\nStatus: " << vetfilmes[i].status << "\n\n\n\n\nPressione ENTER para continuar...";
						sinal=1;
						__fpurge(stdin);
						getchar();
					}
				}

				if ( sinal==0 )
				{
					system("clear");
					cout << "\n\n\tPESQUISA DE FILMES\n\n\n\n\n\n\n\n\n\n\n\nSua pesquisa nao retornou resultados. Pressione ENTER para continuar...";
					__fpurge(stdin);
					getchar();
				}
				break;

			case 2: char nomepes[dig];
				sinal2=0;

				system("clear");
				cout << "\n\n\tPESQUISA DE FILMES\n\n\n\n\n\n\n\n\n\n\n\nNome a pesquisar: ";
				cin >> nomepes;
				
				for ( i=0 ; i<total ; i++ )
				{
					j=0;
					sinal=0;

					while ( vetfilmes[i].nome[j] != '\0' )
					{
						if ( vetfilmes[i].nome[j]==nomepes[j] ) sinal++;
						j++;
					}
					/* Aqui o programa compara cada elemento do vetor nome do filme com o vetor com o nome a ser pesquisado. Se ao final do 'while' as variaveis 'sinal' e 'j' forem iguais, significa que os vetores são iguais */

					if ( sinal==j )
					{
						system("clear");
						cout << "\n\n\tPESQUISA DE FILMES\n\n\n\nCodigo: " << vetfilmes[i].codigo << "\nNome: " << vetfilmes[i].nome << "\nGenero: " << vetfilmes[i].genero << "\nStatus: " << vetfilmes[i].status << "\n\n\n\n\nPressione ENTER para continuar...";

						sinal2=1;
						__fpurge(stdin);
						getchar();
					}
				}

				if ( sinal2 == 0 )
				{
					system("clear");
					cout << "\n\n\tPESQUISA DE FILMES\n\n\n\n\n\n\n\n\n\n\n\nSua pesquisa nao retornou resultados. Pressione ENTER para continuar...";
					__fpurge(stdin);
					getchar();
				}

				break;

			case 3: char generopes; //generopes: genero a ser pesquisado
				sinal=0;

				system("clear");
				cout << "\n\n\tPESQUISA DE FILMES\n\n\n\n\n\n\n\n\n\n\n\nGenero a pesquisar: ";
				cin >> generopes;

				for ( i=0 ; i<total ; i++ )
				{
					if ( vetfilmes[i].genero==generopes )
					{
						system("clear");
						cout << "\n\n\tPESQUISA DE FILMES\n\n\n\nCodigo: " << vetfilmes[i].codigo << "\nNome: " << vetfilmes[i].nome << "\nGenero: " << vetfilmes[i].genero << "\nStatus: " << vetfilmes[i].status << "\n\n\n\n\nPressione ENTER para continuar...";
						sinal=1;
						__fpurge(stdin);
						getchar();
					}
				}

				if ( sinal==0 )
				{
					system("clear");
					cout << "\n\n\tPESQUISA DE FILMES\n\n\n\n\n\n\n\n\n\n\n\nSua pesquisa nao retornou resultados. Pressione ENTER para continuar...";
					__fpurge(stdin);
					getchar();
				}
				break;

			case 4: system("clear");
				break;

			default: cout << "\nCodigo inválido. Pressione ENTER para continuar...";
				__fpurge(stdin);
				getchar();
		}
	}
}





