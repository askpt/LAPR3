/**
*@author Joao Machado
*@author Vitor Hugo
*@date 09/01/2013 
*@file Tarefa.h 
*Classe responsavel por guardar toda a informacao sobre tarefa.*/ 

#ifndef TAREFA_H
#define TAREFA_H
#include <iostream>
#include <string>
using namespace std;
#include "Data.h"
#include "Contexto.h"
#include "Informacao.h"

class Tarefa
{

private:
	int codTarefa;
	int codProjecto;
	int codEstado;
	int codUtilizador;
	int nivelImportancia;
	int duracao;
	int codDependente;
	Data dataCriacao;
	Data dataFim;
	Data dataEstimada;
	string informacao;
	string titulo;
	string tipo;
	Lista<Contexto> listaContextos;
	Lista<Informacao> listaInformacoes;

public:
	Tarefa();
	Tarefa(int nivelImportancia, string informacao, Data dataEstimada, int duracao, int codDependente, int codUtilizador);
	Tarefa(const Tarefa& t);
	~Tarefa();

	int getCodTarefa() const;
	int getCodProjecto() const;
	int getCodEstado() const;
	int getCodUtilizador() const;
	int getNivelImportancia() const;
	int getDuracao() const;
	int getCodDependente() const;
	Data& getDataCriacao();
	Data& getDataFim();
	Data& getDataEstimada();
	string getInformacao() const;
	string getTitulo() const;
	string getTipo() const;
	Lista<Contexto> getListaContextos();
	Lista<Informacao> getListaInformacoes();

	void setNivelImportancia(const int nivelImportancia);
	void setInformacao(const string informacao);
	void setDataEstimada(const Data& dataEstimada);
	void setDataCriacao(const Data& dataCriacao);
	void setDataFim(const Data& dataFim);
	void setDuracao(const int duracao);
	void setCodDependente(const int codDependente);
	void setCodUtilizador(const int codUtilizador);
	void setListaContextos(const Lista<Contexto>& listaContextos);
	void setListaInformacoes(const Lista<Informacao>& listaInformacoes);

	virtual Tarefa *clone() const;
	void escreve(ostream &out) const;

};

/**
 * Construtor vazio.
 */
Tarefa::Tarefa()
{
	Tarefa(0,"",Data(),0,0,0);
}

/**
 * Construtor completo.
 * @param nivelImportancia nivel de importancia.
 * @param informacao informacao da tarefa.
 * @param dataEstimada data estimada.
 * @param duracao duracao da tarefa.
 * @param codDependente codigo da tarefa dependente.
 * @param codUtilizador codigo de utilizador.
 */
Tarefa::Tarefa(int nivelImportancia, string informacao, Data dataEstimada, int duracao, int codDependente, int codUtilizador)
{
	setNivelImportancia(nivelImportancia);
	setInformacao(informacao);
	setDataEstimada(Data dataEstimada);
	setDuracao(duracao);
	setCodDependente(codDependente);
}

/**
 * Construtor copia.
 * @param t objecto tarefa a ser copiado
 */
Tarefa::Tarefa(const Tarefa& t)
{
	codTarefa=t.getCodTarefa();
	codProjecto=t.getCodProjecto();
	codEstado=t.getCodEstado();
	codUtilizador=t.getCodUtilizador();
	nivelImportancia=t.getNivelImportancia();
	duracao=t.getDuracao();
	codDependente=t.getCodDependente();
	dataCriacao=t.getDataCriacao();
	dataFim=t.getDataFim();
	dataEstimada=t.getDataEstimada();
	informacao=t.getInformacao();
	titulo=t.getTitulo();
	tipo=t.getTipo();
	listaContextos=t.getListaContextos();
}

/**
 * Metodo para retornar o codigo da tarefa.
 * @return codigo da tarefa.
 */
int Tarefa::getCodTarefa() const
{
	return codTarefa;
}

/**
 * Metodo para retornar o codigo do projecto.
 * @return codigo do projecto.
 */
int Tarefa::getCodProjecto() const
{
	return codProjecto;
}

/**
 * Metodo para retornar o codigo do estado.
 * @return codigo do estado.
 */
int Tarefa::getCodEstado() const
{
	return codEstado;
}

/**
 * Metodo para retornar o codigo do utilizador.
 * @return codigo do utilizador.
 */
int Tarefa::getCodUtilizador() const
{
	return codUtilizador;
}

/**
 * Metodo para retornar o nivel de importancia.
 * @return nivel de importancia.
 */
int Tarefa::getNivelImportancia() const
{
	return nivelImportancia;
}

/**
 * Metodo para retornar a duracao.
 * @return duracao.
 */
int Tarefa::getDuracao() const
{
	return duracao;
}

/**
 * Metodo para retornar a data de criacao.
 * @return data de criacao.
 */
Data& Tarefa::getDataCriacao()
{
	return dataCriacao;
}

/**
 * Metodo para retornar a data estimada.
 * @return data estimada
 */
Data& Tarefa::getDataEstimada() 
{
	return dataEstimada;
}

/**
 * Metodo para retornar a data fim.
 * @return data fim
 */
Data& Tarefa::getDataFim() 
{
	return dataFim;
}

/**
 * Metodo para retornar o codigo da tarefa dependente.
 * @return codigo da tarefa dependente.
 */
int Tarefa::getCodDependente() const
{
	return codDependente;
}

/**
 * Metodo para retornar a lista de contextos referentes à tarefa.
 * @return lista de contextos referentes à tarefa.
 */
Lista<Contexto> Tarefa::getListaContextos() 
{
	return listaContextos;
}

/**
 * Metodo para retornar a lista de informacoes referentes à tarefa.
 * @return lista de informacoes referentes à tarefa.
 */
Lista<Informacao> Tarefa::getListaInformacoes()
{
	return listaInformacoes;
}

/**
 * Metodo de atribuicao do nivel de importancia.
 * @param nivelImportancia nivel de importancia.
 */
void Tarefa::setNivelImportancia(const int nivelImportancia)
{
	this->nivelImportancia = nivelImportancia;
}

/**
 * Metodo de atribuicao da informacao.
 * @param informacao informacao.
 */
void Tarefa::setInformacao(const string informacao)
{
	this->informacao = informacao;
}

/**
 * Metodo de atribuicao da data estimada.
 * @param estimada data estimada.
 */
void Tarefa::setDataEstimada(const Data& dataEstimada)
{
	this->dataEstimada = dataEstimada;
}

/**
 * Metodo de atribuicao da data de criacao.
 * @param estimada data de criacao.
 */
void Tarefa::setDataCriacao(const Data& dataCriacao)
{
	this->dataCriacao = dataCriacao;
}

/**
 * Metodo de atribuicao da data fim.
 * @param estimada data fim.
 */
void Tarefa::setDataFim(const Data& dataFim)
{
	this->dataFim = dataFim;
}

/**
 * Metodo de atribuicao da duracao.
 * @param duracao duracao.
 */
void Tarefa::setDuracao(const int duracao)
{
	this->duracao = duracao;
}

/**
 * Metodo de atribuicao do codigo da tarefa dependente.
 * @param codDependente codigo da tarefa dependente
 */
void Tarefa::setCodDependente(const int codDependente)
{
	this->codDependente = codDependente;
}

/**
 * Metodo de atribuicao do codigo de utilizador.
 * @param codUtilizador codigo do utilizador.
 */
void Tarefa::setCodUtilizador(const int codUtilizador)
{
	this->codUtilizador = codUtilizador;
}

/**
 * Metodo de atribuicao da lista de contextos.
 * @param listaContextos lista de contextos.
 */
void Tarefa::setListaContextos(const Lista<Contexto> listaContextos)
{
	this->listaContextos = listaContextos;
}

/**
 * Metodo de atribuicao da lista de informacoes.
 * @param listaContextos lista de informacoes.
 */
void Tarefa::setListaInformacoes(const Lista<Informacao> listaInformacoes)
{
	this->listaInformacoes = listaInformacoes;
}

/**
 * Apresenta os dados do projecto.
 * @param out objecto stream out.
 */
void Tarefa::escreve(ostream &out)
{
	out << "Cod. Tarefa: " << codTarefa << endl;
	out << "Cod. Projecto: " << codProjecto << endl;
	out << "Cod. Tarefa dependente: " << codDependente << endl;
	out << "Cod. Utilizador : " << codUtilizador << endl;
	out << "Estado: " << codEstado << endl;
	out << "Nome: " << titulo << endl;
	out << "Tipo: " << tipo << endl;
	out << "Nivel de importancia: " << nivelImportancia << endl;
	out << "Data de criacao: "; dataCriacao.listar();
	out << "Informacao: " << informacao << endl;
	out << "Duracao: " << duracao << endl;
	out << "Data estimada: "; dataEstimada.listar();
	out << "Data de fim: "; dataFim.listar();
	out << listaContextos << endl;
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param t objecto Tarefa.
 */
ostream & operator << (ostream &out, const Tarefa &t)
{
	t.escreve(out);
	return out;
}

#endif