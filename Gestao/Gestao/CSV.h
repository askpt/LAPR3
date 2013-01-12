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
#include "Nivel.h"
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
	int  importarTipos(string nomeFicheiro, int codUser);
	int  importarUtilizador(string nomeFicheiro, int codUser);

	int  exportarInformacoes(string nomeFicheiro, int codUser); // done
	int  exportarContextos(string nomeFicheiro, int codUser); // done
	int  exportarEstados(string nomeFicheiro, int codUser);
	int  exportarNiveis(string nomeFicheiro, int codUser); // done
	int  exportarProjectos(string nomeFicheiro, int codUser); // done
	int  exportarTarefas(string nomeFicheiro, int codUser); // done
	int  exportarTarefaContexto(string nomeFicheiro, int codUser);
	int  exportarTipos(string nomeFicheiro, int codUser);
	int  exportarUtilizador(string nomeFicheiro, int codUser); // done
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
	string dataEstimada;
	string dataFim;


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

		for(int i = 1; i< tarefas.comprimento()+1; i++)
		{
			
			tarefas.encontra(i, auxTarefa);	

			if(apTarefa->getDataFim().getAno() != 1900)
				dataFim = apTarefa->getDataFim().toSQL();
			else
				dataFim = "---";
			if(apTarefa->getDataEstimada().getAno() != 1900)
				dataEstimada = apTarefa->getDataEstimada().toSQL();
			else
				dataEstimada = "---";

			ficheiro << apTarefa->getCodTarefa() << "," << apTarefa->getCodProjecto() << "," << apTarefa->getCodEstado() << "," << apTarefa->getCodUtilizador() << "," << apTarefa->getNivelImportancia() << "," << apTarefa->getDuracao() << "," << apTarefa->getCodDependente() << "," << apTarefa->getNContextos() << "," << apTarefa->getDelegado() << "," << apTarefa->getDataCriacao().toSQL() << "," << dataFim << "," << dataEstimada << "," << apTarefa->getInformacao() << "," << apTarefa->getTitulo()<< "," << apTarefa->getTitulo() << "\n";	
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

		for(int i = 1; i< informacoes.comprimento()+1; i++)
		{
			
			informacoes.encontra(i, auxInfo);	

			ficheiro << apInfo->getCodInformacao() << "," << apInfo->getCodTarefa() << "," << apInfo->getCodUtilizador() << "," << apInfo->getDescricao() << "," << apInfo->getDataInsercao().toSQL() << "\n";
		}
		ficheiro.close();
	}

	return 0;
}

int CSV::exportarContextos(string nomeFicheiro, int codUser)
{
	
	string linha;
	string desc;
	string _nomeFicheiro;
	stringstream out;
	Contexto auxCon;
	Contexto *apCon = &auxCon;
	Lista<Contexto> contextos;


	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();
	ofstream  ficheiro(_nomeFicheiro);

	if(ficheiro.is_open())
	{
		try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				contextos = conexao ->listarContextos();
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}

		for(int i = 1; i< contextos.comprimento()+1; i++)
		{
			
			contextos.encontra(i, auxCon);	

			ficheiro << apCon->getCodContexto() << "," << apCon->getDescricao() << "\n";
		}
		ficheiro.close();
	}

	return 0;
}

int CSV::exportarNiveis(string nomeFicheiro, int codUser)
{
	
	string linha;
	string desc;
	string _nomeFicheiro;
	stringstream out;
	Nivel auxNiv;
	Nivel *apNiv = &auxNiv;
	Lista<Nivel> niveis;


	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();
	ofstream  ficheiro(_nomeFicheiro);

	if(ficheiro.is_open())
	{
		try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				niveis = conexao ->listarNiveis();
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}

		for(int i = 1; i< niveis.comprimento()+1; i++)
		{
			
			niveis.encontra(i, auxNiv);	

			ficheiro << apNiv->getNivelImportancia() << "," << apNiv->getDescricao() << "\n";
		}
		ficheiro.close();
	}

	return 0;
}

int CSV::exportarUtilizador(string nomeFicheiro, int codUser)
{

	string linha;
	string desc;
	string _nomeFicheiro;
	stringstream out;
	Utilizador auxUti;
	Utilizador *apUti = &auxUti;
	Lista<Utilizador> utilizadores;


	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();
	ofstream  ficheiro(_nomeFicheiro);

	if(ficheiro.is_open())
	{
		try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				utilizadores = conexao ->listarUtilizadores();
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}

		for(int i = 1; i< utilizadores.comprimento()+1; i++)
		{
			
			utilizadores.encontra(i, auxUti);	

			ficheiro << apUti->getCodUtilizador() << "," << apUti->getNome()  << "," << apUti->getTelefone()  << "," << apUti->getLogin()  << "," << apUti->getPass() << "\n";
		}
		ficheiro.close();
	}

	return 0;
}

int CSV::exportarProjectos(string nomeFicheiro, int codUser)
{
	
	string linha;
	string desc;
	string _nomeFicheiro;
	stringstream out;
	Projecto auxProjecto;
	Projecto *apProjecto = &auxProjecto;
	Lista<Projecto> projectos;
	string dataFim;


	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();
	ofstream  ficheiro(_nomeFicheiro);

	if(ficheiro.is_open())
	{
		try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				projectos = conexao ->listarProjectos(codUser);
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}

			cout << projectos.comprimento();
		for(int i = 1; i< projectos.comprimento()+1; i++)
		{
			
			projectos.encontra(i, auxProjecto);	

			if(apProjecto->getDataFim().getAno() != 1900)
				dataFim = apProjecto->getDataFim().toSQL();
			else
				dataFim = "---";

			ficheiro << apProjecto->getCodProjecto() << "," << apProjecto->getCodEstado() << "," << apProjecto->getCodUtilizador() << "," << apProjecto->getNivelImportancia() << "," << apProjecto->getDataCriacao().toSQL() << "," << dataFim << "," << apProjecto->getInformacao() << "," << apProjecto->getNome() << "\n";	
		}
		ficheiro.close();
	}

	return 0;
}

int CSV::exportarTipos(string nomeFicheiro, int codUser)
{

	string linha;
	string desc;
	string _nomeFicheiro;
	stringstream out;
	int codigo;
	Lista<int> codigos;
	Lista<string> descricoes;
	Lista<int> *apCodigos = &codigos;
	Lista<string> *apDescricoes = &descricoes;


	out << nomeFicheiro << ".csv";
	_nomeFicheiro = out.str();
	ofstream  ficheiro(_nomeFicheiro);

	if(ficheiro.is_open())
	{
		try
			{
				BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
				conexao ->listaTipos(apCodigos, apDescricoes);
				delete(conexao);
			} 
			catch(SQLException erro)
			{
				cerr << "Erro: " << erro.getMessage() << endl;
			}

		for(int i = 1; i< codigos.comprimento()+1; i++)
		{
			
			codigos.encontra(i, codigo);	
			descricoes.encontra(i, desc);

			ficheiro << codigo << "," << desc << "\n";
		}
		ficheiro.close();
	}

	return 0;
}

#endif