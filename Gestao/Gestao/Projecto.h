/**
*@author Joao Machado
*@author Tiago Pacheco
*@author Vitor Hugo
*@date 08/01/2013 
*@file Projecto.h 
*Classe responsavel por guardar toda a informacao sobre o projecto.*/ 

#ifndef PROJECTO_H
#define PROJECTO_H
#include "Data.h"
#include "Lista.h"
#include "Tarefa.h"

class Projecto
{

private:
	int codProjecto;
	int codEstado;
	int codUtilizador;
	int nivelImportancia;
	Data dataCriacao;
	Data dataFim;
	string informacao;
	string nome;
	Lista<Tarefa> listaTarefas;
	

public:
	Projecto();
	Projecto(int nivelImportancia, string informacao, string nome, int codUtilizador);
	Projecto(const Projecto& p);
	~Projecto();

	int getCodProjecto() const;
	int getCodEstado() const;
	int getCodUtilizador() const;
	int getNivelImportancia() const;
	string getInformacao();
	string getNome();
	Data& getDataCriacao();
	Data& getDataFim();
	Lista<Tarefa> getListaTarefas() const;

	void setInformacao(const string informacao);
	void setNivelImportancia(const int nivelImportancia);
	void setNome(const string nome);
	void setCodUtilizador(const int codUtilizador);
	void setDataCriacao(const Data& dataCriacao);
	void setDataFim(const Data& dataFim);

	virtual Projecto *clone() const;
	void escreve(ostream &out) const;

};

/**
 * Construtor vazio.
 */
Projecto::Projecto()
{
	Projecto(0,"","",0);
}

/**
* Construtor completo.
* @param nivelImportancia nivel de importancia
* @param informacao informacao
* @param nome nome
* @param codUtilizador codigo do utilizador
*/
Projecto::Projecto(int nivelImportancia, string informacao, string nome, int codUtilizador)
{
	setNivelImportancia(nivelImportancia);
	setInformacao(informacao);
	setNome(nome);
	setCodUtilizador(codUtilizador);
}

/**
 * Construtor copia.
 * @param endereco de memoria do objeto a copiar
 */
Projecto::Projecto(const Projecto& p)
{
	codProjecto=p.getCodProjecto();
	nivelImportancia=p.getNivelImportancia();
	dataCriacao=p.getDataCriacao();
	dataFim=p.getDataFim();
	informacao=p.getInformacao();
	nome=p.getNome();
	codEstado=p.getCodEstado();
	codUtilizador=p.getCodUtilizador();
	listaTarefas=p.getListaTarefas();
}

/*
 * Destrutor
 */
Projecto::~Projecto()
{
}

/**
 * Metodo para retornar o codigo do projecto.
 * @return codigo do projecto.
 */
int Projecto::getCodProjecto() const
{
	return codProjecto;
}

/**
 * Metodo para retornar o codigo do estado.
 * @return codigo do estado.
 */
int Projecto::getCodEstado() const
{
	return codEstado;
}

/**
 * Metodo para retornar o codigo do utilizador.
 * @return codigo do utilizador.
 */
int Projecto::getCodUtilizador() const
{
	return codUtilizador;
}

/**
 * Metodo para retornar o nivel de importancia.
 * @return nivel de importancia.
 */
int Projecto::getNivelImportancia() const
{
	return nivelImportancia;
}

/**
* Metodo para retornar a informacao.
* @return informacao.
*/
string Projecto::getInformacao() const
{
	return informacao;
}

/**
* Metodo para retornar o nome.
* @return nome.
*/
string Projecto::getNome() const
{
	return nome;
}

/**
 * Metodo para retornar a data de criacao.
 * @return data de criacao.
 */
Data& Projecto::getDataCriacao()
{
	return dataCriacao;
}

/**
 * Metodo para retornar a data fim.
 * @return data fim.
 */
Data& Projecto::getDataFim()
{
	return dataFim;
}

/**
 * Metodo que retorna o endereco da lista de tarefas
 */
Lista<Tarefa> Projecto::getListaTarefas() const
{
	return listaTarefas;
}

/**
 * Metodo de atribuicao da informacao.
 * @param informacao informacao.
 */
void Projecto::setInformacao(const string informacao)
{
	this->informacao = informacao;
}

/**
 * Metodo de atribuicao do nivel de importancia.
 * @param nivelImportancia nivel de importancia.
 */
void Projecto::setNivelImportancia(const int nivelImportancia)
{
	this->nivelImportancia = nivelImportancia;
}

/**
 * Metodo de atribuicao do nome.
 * @param nome nome.
 */
void Projecto::setNome(const string nome)
{
	this->nome = nome;
}

/**
 * Metodo de atribuicao do codigo de utilizador.
 * @param codUtilizador codigo do utilizador.
 */
void Projecto::setCodUtilizador(const int codUtilizador)
{
	this->codUtilizador = codUtilizador;
}

/**
 * Metodo de atribuicao de data de criacao.
 * @param dataCriacao data de criacao.
 */
void Projecto::setDataCriacao(const Data& dataCriacao)
{
	this->dataCriacao = dataCriacao;
}

/**
 * Metodo de atribuicao de data fim.
 * @param dataFim data fim.
 */
void Projecto::setDataFim(const Data& dataFim)
{
	this->dataFim = dataFim;
}

/**
 * Apresenta os dados do projecto.
 * @param out objecto stream out.
 */
void Projecto::escreve(ostream &out)
{
	out << "Cod. Projecto: " << codProjecto << endl;
	out << "Nome: " << nome << endl;
	out << "Nivel de importancia: " << nivelImportancia << endl;
	out << "Data de criacao: " << dataCriacao.listar();
	out << "Cod. Estado: " << codEstado << endl;
	out << "Cod. Utilizador: " << codUtilizador << endl;
	out << "Informacao: " << informacao << endl;
	out << "Data de fim: " << dataFim.listar();
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param p objecto Projecto.
 */
ostream & operator << (ostream &out, const Projecto &p)
{
	p.escreve(out);
	return out;
}

#endif