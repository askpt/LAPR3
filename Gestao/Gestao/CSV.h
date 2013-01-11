#ifndef CSV_H
#define CSV_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "Tarefa.h"
#include "Projecto.h"
#include "Utilizador.h"
#include "Informacao.h"
#include "Contexto.h"
#include "Nivel.h"
#include "Bdados.h"

class CSV
{

private:
public:
	int  importarInformacoes(string nomeFicheiro, int codUser);
	int  importarContextos(string nomeFicheiro);
	int  importarEstados(string nomeFicheiro);
	int  importarNiveis(string nomeFicheiro);
	int  importarProjectos(string nomeFicheiro);
	int  importarTarefas(string nomeFicheiro);
	int  importarTarefaContexto(string nomeFicheiro);
	int  importarTipo(string nomeFicheiro);
	int  importarUtilizador(string nomeFicheiro);

	int  exportarInformacoes(string nomeFicheiro);
	int  exportarContextos(string nomeFicheiro);
	int  exportarEstados(string nomeFicheiro);
	int  exportarNiveis(string nomeFicheiro);
	int  exportarProjectos(string nomeFicheiro);
	int  exportarTarefas(string nomeFicheiro);
	int  exportarTarefaContexto(string nomeFicheiro);
	int  exportarTipo(string nomeFicheiro);
	int  exportarUtilizador(string nomeFicheiro);
};

int CSV::importarInformacoes(string nomeFicheiro, int codUser)
{
	int codInformacao;
	int codTarefa;
	int codUtilizador;
	string linha;
	string _nomeFicheiro;
	stringstream out;
	string desc;

	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();

	ifstream ficheiro(_nomeFicheiro); // abre o ficheiro

	if(!ficheiro)
	{
		cout << _nomeFicheiro << "nao existe!" << endl;
		return -1;
	}

	while(!ficheiro.eof()) // enquanto nao chega ao final do ficheiro
	{
		getline(ficheiro,linha,'\n'); // grava o conteudo da linha
		if(linha.size() > 0)
		{
			int  comeca = 0;
			int pos = linha.find(',',comeca);

			string cInf(linha.substr(comeca,pos-comeca));
			char* aux = &cInf[0];
			codInformacao = atoi(aux); // guarda codInformacao

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cTar(linha.substr(comeca,pos-comeca));
			aux = &cTar[0];
			codTarefa = atoi(aux); // guarda codTarefa

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cUti(linha.substr(comeca,pos-comeca));
			aux = &cUti[0];
			codUtilizador = atoi(aux); // guarda codUtilizador

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string descricao(linha.substr(comeca,pos-comeca)); // guarda descricao
			desc = descricao;
			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string dataInsercao(linha.substr(comeca,pos-comeca));

			pos++;
		}
	}
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		conexao -> inserirInfoCompleta(codUser, desc, codTarefa);
		delete(conexao);
	} 
	catch(SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}

}


#endif