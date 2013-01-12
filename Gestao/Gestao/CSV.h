/**
*@author Vitor Hugo
*@date 11/01/2013 
*@file CSV.h 
*Classe responsavel por importacoes e exportacoes CSV.*/ 

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
//#include "Nivel.h"
#include "Bdados.h"
#include "Lista.h"

class CSV
{

private:
public:
	int  importarInformacoes(string nomeFicheiro, int codUser);
	int  importarContextos(string nomeFicheiro, int codUser);
	int  importarEstados(string nomeFicheiro, int codUser);
	int  importarNiveis(string nomeFicheiro, int codUser);
	int  importarProjectos(string nomeFicheiro, int codUser);
	int  importarTarefas(string nomeFicheiro, int codUser);
	int  importarTarefaContexto(string nomeFicheiro, int codUser);
	int  importarTipo(string nomeFicheiro, int codUser);
	int  importarUtilizador(string nomeFicheiro, int codUser);

	int  exportarInformacoes(string nomeFicheiro, int codUser);
	int  exportarContextos(string nomeFicheiro, int codUser);
	int  exportarEstados(string nomeFicheiro, int codUser);
	int  exportarNiveis(string nomeFicheiro, int codUser);
	int  exportarProjectos(string nomeFicheiro, int codUser);
	int  exportarTarefas(string nomeFicheiro, int codUser);
	int  exportarTarefaContexto(string nomeFicheiro, int codUser);
	int  exportarTipo(string nomeFicheiro, int codUser);
	int  exportarUtilizador(string nomeFicheiro, int codUser);
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

			string dataInsercao(linha.substr(comeca,pos-comeca)); //guarda a data de insercao

			pos++;

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
	}

	
	return 0;
}

int CSV::importarTarefas(string nomeFicheiro, int codUser)
{
	int codTarefa;
	int codProjecto;
	int codEstado;
	int codUtilizador;
	int nivelImportancia;
	int duracao;
	int codDependente;
	int nContextos;
	int delegado;
	string dataCriacao;
	string dataFim;
	string dataEstimada;
	string informacao;
	string titulo;
	string tipo;
	string linha;
	string _nomeFicheiro;
	stringstream out;


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

			string cTar(linha.substr(comeca,pos-comeca));
			char* aux = &cTar[0];
			codTarefa = atoi(aux); // guarda codTarefa

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cPro(linha.substr(comeca,pos-comeca));
			aux = &cPro[0];
			codProjecto = atoi(aux); // guarda codProjecto

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cEst(linha.substr(comeca,pos-comeca));
			aux = &cEst[0];
			codEstado = atoi(aux); // guarda codEstado

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cUti(linha.substr(comeca,pos-comeca));
			aux = &cUti[0];
			codUtilizador = atoi(aux); // guarda codUtilizador

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cNiv(linha.substr(comeca,pos-comeca));
			aux = &cNiv[0];
			nivelImportancia = atoi(aux); // guarda nivelImportancia

			pos++;                                                                                                                                                                                                                                                                                                                                                                                                  
			comeca = pos;
			pos = linha.find(',',comeca);

			string cDura(linha.substr(comeca,pos-comeca));
			aux = &cDura[0];
			duracao = atoi(aux); // guarda duracao

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cDepe(linha.substr(comeca,pos-comeca));
			aux = &cDepe[0];
			codDependente = atoi(aux); // guarda codDependente

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cCont(linha.substr(comeca,pos-comeca));
			aux = &cCont[0];
			nContextos = atoi(aux); // guarda nContextos

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cDel(linha.substr(comeca,pos-comeca));
			aux = &cDel[0];
			delegado = atoi(aux); // guarda delegado

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cCriacao(linha.substr(comeca,pos-comeca));
			dataCriacao = cCriacao; // guarda dataCriacao

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cFim(linha.substr(comeca,pos-comeca));
			dataFim = cFim; // guarda dataFim

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cEsti(linha.substr(comeca,pos-comeca));
			dataEstimada = cEsti; // guarda dataEstimada

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cInf(linha.substr(comeca,pos-comeca));
			informacao = cInf; // guarda informacao

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cTitulo(linha.substr(comeca,pos-comeca));
			titulo = cTitulo; // guarda titulo

			pos++;
			comeca = pos;
			pos = linha.find(',',comeca);

			string cTipo(linha.substr(comeca,pos-comeca));
			tipo = cTipo; // guarda tipo

			pos++;

			try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				conexao -> inserirTarefaCompleta(codTarefa, codProjecto, codEstado, nivelImportancia, dataCriacao, dataFim, informacao, dataEstimada, duracao, tipo, titulo, codDependente, codUtilizador, nContextos, delegado);
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}
		}
	}
	
	return 0;
}

int CSV::exportarTarefas(string nomeFicheiro, int codUser)
{
	
	string linha;
	string desc;
	string _nomeFicheiro;
	stringstream out;
	Tarefa auxTarefa;
	Tarefa *apTarefa = &auxTarefa;
	Lista<Tarefa> tarefas;


	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();
	ofstream  ficheiro(_nomeFicheiro);

	if(ficheiro.is_open())
	{
		try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				tarefas = conexao ->listarTarefasTodas(codUser);
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}

		for(int i = 1; i< tarefas.comprimento(); i++)
		{
			
			tarefas.encontra(i, auxTarefa);			

			ficheiro << apTarefa->getCodTarefa() << "," << apTarefa->getCodProjecto() << "," << apTarefa->getCodEstado() << "," << apTarefa->getCodUtilizador() << "," << apTarefa->getNivelImportancia() << "," << apTarefa->getDuracao() << "," << apTarefa->getCodDependente() << "," << apTarefa->getNContextos() << "," << apTarefa->getDelegado() << "," << apTarefa->getDataCriacao().toSQL() << "," << apTarefa->getDataFim().toSQL() << "," << apTarefa->getDataEstimada().toSQL()	<< "," << apTarefa->getInformacao() << "," << apTarefa->getTitulo()<< "," << apTarefa->getTitulo() << "\n";
		}
		ficheiro.close();
	}

	return 0;
}

int CSV::exportarInformacoes(string nomeFicheiro, int codUser)
{
	
	string linha;
	string desc;
	string _nomeFicheiro;
	stringstream out;
	Informacao auxInfo;
	Informacao *apInfo = &auxInfo;
	Lista<Informacao> informacoes;


	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();
	ofstream  ficheiro(_nomeFicheiro);

	if(ficheiro.is_open())
	{
		try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				informacoes = conexao ->listaInformacao(codUser);
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}

		for(int i = 1; i< informacoes.comprimento(); i++)
		{
			
			informacoes.encontra(i, auxInfo);	

			ficheiro << apInfo->getCodInformacao() << "," << apInfo->getCodTarefa() << "," << apInfo->getCodUtilizador() << "," << apInfo->getDescricao() << "," << apInfo->getDataInsercao().toSQL() << "\n";
		}
		ficheiro.close();
	}

	return 0;
}

#endif