#include <fstream>
#include <string>
#include <iostream>

string contToString(Lista<int> cont)
{
	string ret;
	stringstream out;
	int contexto;

	cont.encontra(1, contexto);
	if(cont.comprimento() == 1)
	{
		for(int i=0;i<contexto;i++)
			out << 0;
		out << 1;
	}
	else
	{
		int contMaior, tmp;

		cont.encontra(2, contMaior);
		if(contMaior < contexto)
		{
			tmp = contMaior;
			contMaior = contexto;
			contexto = tmp;
		}
		for(int i=0; i<contMaior-1;i++)
			if(contexto == (i+1))
				out << 1;
			else
				out << 0;
		out << 1;
	}
	ret = out.str();

	return ret;
}



void exportAssemb()
{
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		Lista<Tarefa> list = conexao ->listarTarefasTodas(codUser);
		Tarefa auxTarefa;
		string contextos;
		

		ofstream ficheiro("FX.csv");


		if(ficheiro.is_open())
		{
			for(int i = 1; i< list.comprimento(); i++)
			{
				list.encontra(i, auxTarefa);
				Lista<int> cont = conexao ->listarCodContextos(auxTarefa.getCodTarefa());
				if(cont.comprimento() > 0)
				{
					string contStr = contToString(cont);
					ficheiro << auxTarefa.getCodTarefa() << "," << auxTarefa.getTitulo() << "," << auxTarefa.getNivelImportancia() << "," << contStr << "\n";
				}
			}
			ficheiro.close();
		}
		delete(conexao);
	} 
	catch(SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}

}