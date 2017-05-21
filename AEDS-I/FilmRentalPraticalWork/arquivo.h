void carregar()
{
	int n=0;
	ifstream dados;

	dados.open("dados.txt");

	total=-1;

	while ( !dados.eof() )
	{
		dados >> vetfilmes[n].codigo;
		dados >> vetfilmes[n].nome;
		dados >> vetfilmes[n].genero;
		dados >> vetfilmes[n].status;

		total++; // Ao carregar o banco de dados será calculado a quantidade de filmes 
			 // no banco de dados, através da variável 'total'
		n++;
	}
	dados.close();
}

void salvar()
{
	int j=0, n;
	ofstream dados;

	dados.open("dados.txt");

	for ( n=0 ; n<total ; n++ )
	{
		if ( vetfilmes[n].codigo!=0 )
		{
			if ( j >= 1 ) dados << "\n";
			
			dados << vetfilmes[n].codigo << " ";
			dados << vetfilmes[n].nome << " ";
			dados << vetfilmes[n].genero << " ";
			dados << vetfilmes[n].status;
			j++;
		}
	}
	dados.close();
}

