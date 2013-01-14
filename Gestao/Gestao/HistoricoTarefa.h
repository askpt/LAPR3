/**
*@author Tiago Pacheco
*@author Vitor Hugo
*@date 14/01/2013 
*@file HistoricoTarefa.h 
*Classe responsavel por guardar todo o historico das tarefas.*/ 

#ifndef HistoricoTarefa_H
#define HistoricoTarefa_H
#include <iostream>
#include <string>
using namespace std;
#include "Data.h"


class HistoricoTarefa
{
private:
 int codHistorico;
 int codTarefa;
 int codProjecto;
 int codEstado;
 int nivelImportancia;
 int duracao;
 int dependente;
 int nContexto;
 int delegado;
 int codTipo;
 int codUtilizador;
 Data dataInsercao;
 Data dataInicio;
 Data dataFim;
 Data dataEstimada;
 string informacao;
 string info;
 string descricao;
 string tipo;
 string titulo;

public:
 HistoricoTarefa(int codhistorico, int codtarefa, int codprojecto, int codestado, int nivelimportancia, Data datacriacao, Data datafim, string informacao, Data dataestimada, int duracao, string tipo, string titulo, int dependente, int codutilizador, int ncontexto, int delegado, Data datainsercao, int codtipo, string info);
 HistoricoTarefa();
 HistoricoTarefa(const HistoricoTarefa& ht);
 ~HistoricoTarefa();

 int getCodHistorico()const;
 int getCodTarefa() const;
 int getCodProjecto() const;
 int getCodEstado() const;
 int getCodUtilizador() const;
 int getNivelImportancia() const;
 int getDuracao() const;
 int getDependente()const;
 int getNContexto()const;
 int getDelegado()const;
 int getCodTipo()const;
 Data getDataInicio();
 Data getDataFim();
 Data getDataEstimada();
 Data getDataInsercao();
 string getInformacao() const;
 string getInfo() const;
 string getDescricao() const;
 string getTipo()const;
 string getTitulo()const;

 void setCodHistorico(const int codhistorico);
 void setCodTarefa(const int codtarefa) ;
 void setCodProjecto(const int codprojecto) ;
 void setCodEstado(const int codestado) ;
 void setCodUtilizador(const int codutilizador) ;
 void setNivelImportancia(const int nivelimportancia) ;
 void setDuracao(const int duracao) ;
 void setDependente(const int dependente);
 void setNContexto(const int ncontexto);
 void setDelegado(const int delegado);
 void setCodTipo(const int codtipo);
 void setDataInicio(const Data dataInicio);
 void setDataFim(const Data datafim);
 void setDataEstimada(const Data dataestimada);
 void setDataInsercao(const Data datainsercao);
 void setInformacao(const string informacao) ;
 void setInfo(const string info) ;
 void setDescricao(const string descricao) ;
 void setTipo(const string tipo);
 void setTitulo(const string titulo);

 virtual HistoricoTarefa *clone() const;
 void escreve(ostream &out) const;

};

/**
 *Construtor vazio
 */
HistoricoTarefa::HistoricoTarefa()
{
	HistoricoTarefa(0,0,0,0,0,Data(),Data(),"",Data(),0,"","",0,0,0,0,Data(),0,"");
}

/**
 *Construtor completo
 */
HistoricoTarefa::HistoricoTarefa(int codhistorico, int codtarefa, int codprojecto, int codestado, int nivelimportancia, Data datacriacao, Data datafim, string informacao, Data dataestimada, int duracao, string tipo, string titulo, int dependente, int codutilizador, int ncontexto, int delegado, Data datainsercao, int codtipo, string info)
{
 setCodHistorico(codhistorico);
 setCodTarefa(codtarefa) ;
 setCodProjecto(codprojecto) ;
 setCodEstado(codestado) ;
 setCodUtilizador(codutilizador) ;
 setNivelImportancia(nivelimportancia) ;
 setDuracao(duracao) ;
 setDependente(dependente);
 setNContexto(ncontexto);
 setDelegado(delegado);
 setCodTipo(codtipo);
 setDataInicio(datacriacao);
 setDataFim(datafim);
 setDataEstimada(dataestimada);
 setDataInsercao(datainsercao);
 setInformacao(informacao) ;
 setInfo(info) ;
 setDescricao(descricao) ;
 setTipo(tipo);
 setTitulo(titulo);
}

/**
 *Construtor copia
 * @param objeto hi do tipo HistoricoTarefa a ser copiado
 */
HistoricoTarefa::HistoricoTarefa(const HistoricoTarefa& ht)
{
	codHistorico= ht.codHistorico;
	codTarefa= ht.codTarefa;
	codProjecto= ht.codProjecto;
	codEstado= ht.codEstado;
	nivelImportancia= ht.nivelImportancia;
	duracao= ht.duracao;
	dependente= ht.dependente;
	nContexto= ht.nContexto;
	delegado= ht.delegado;
	codTipo= ht.codTipo;
	codUtilizador= ht.codUtilizador;
	dataInsercao= ht.dataInsercao;
	dataInicio= ht.dataInicio;
	dataFim= ht.dataFim;
	dataEstimada= ht.dataEstimada;
	informacao= ht.informacao;
	info= ht.info;
	descricao= ht.descricao;
	tipo= ht.tipo;
	titulo= ht.titulo;
}

/**
* Destrutor.
*/
HistoricoTarefa::~HistoricoTarefa()
{
}
/**
 * @return codigo do historico
 */
int HistoricoTarefa::getCodHistorico()const
{
 return codHistorico;
}
int HistoricoTarefa::getCodTarefa() const
{
 return codTarefa;
}
int HistoricoTarefa::getCodProjecto() const
{
 return codProjecto;
}

int HistoricoTarefa::getCodEstado() const
{
 return codEstado;
}

int HistoricoTarefa::getNivelImportancia() const
{
 return nivelImportancia;
}
Data HistoricoTarefa::getDataInicio()
{
 return dataInicio;
}

Data HistoricoTarefa::getDataFim()
{
 return dataFim;
}

Data HistoricoTarefa::getDataEstimada()
{
 return dataEstimada;
}

Data HistoricoTarefa::getDataInsercao()
{
 return dataInsercao;
}

string HistoricoTarefa::getInformacao() const
{
 return informacao;
}

int HistoricoTarefa::getDuracao() const 
{
	return duracao;
}

string HistoricoTarefa::getTipo() const 
{
	return tipo;
}

string HistoricoTarefa::getTitulo() const 
{
	return titulo;
}

int HistoricoTarefa::getDependente() const 
{
	return dependente;
}

int HistoricoTarefa::getCodUtilizador() const 
{
	return codUtilizador;
}

int HistoricoTarefa::getNContexto() const 
{
	return nContexto;
}

int HistoricoTarefa::getDelegado() const 
{
	return delegado;
}

int HistoricoTarefa::getCodTipo() const 
{
	return codTipo;
}

string HistoricoTarefa::getInfo() const 
{
	return info;
}

 void HistoricoTarefa::setCodHistorico(const int codhistorico)
 {
 	codHistorico = codhistorico;
 }
 void HistoricoTarefa::setCodTarefa(const int codtarefa) 
 {
 	codTarefa = codtarefa;
 }
 void HistoricoTarefa::setCodProjecto(const int codprojecto) 
 {
 	codProjecto = codprojecto;
 }
 void HistoricoTarefa::setCodEstado(const int codestado) 
 {
 	codEstado = codestado;
 }
 void HistoricoTarefa::setCodUtilizador(const int codutilizador) 
 {
 	codUtilizador = codutilizador;
 }
 void HistoricoTarefa::setNivelImportancia(const int nivelimportancia) 
 {
 	nivelImportancia = nivelimportancia;
 }
 void HistoricoTarefa::setDuracao(const int duracao) 
 {
 	this->duracao = duracao;
 }
 void HistoricoTarefa::setDependente(const int dependente)
 {
 	this->dependente = dependente;
 }
 void HistoricoTarefa::setNContexto(const int ncontexto)
 {
 	nContexto = ncontexto;
 }
 void HistoricoTarefa::setDelegado(const int delegado)
 {
 	this->delegado = delegado;
 }
 void HistoricoTarefa::setCodTipo(const int codtipo)
 {
 	codTipo = codtipo;
 }
 void HistoricoTarefa::setDataInicio(const Data dataInicio)
 {
 	this->dataInicio = dataInicio;
 }
 void HistoricoTarefa::setDataFim(const Data datafim)
 {
 	dataFim = datafim;
 }
 void HistoricoTarefa::setDataEstimada(const Data dataestimada)
 {
 	dataEstimada = dataestimada;
 }
 void HistoricoTarefa::setDataInsercao(const Data datainsercao)
 {
 	dataInsercao = datainsercao;
 }
 void HistoricoTarefa::setInformacao(const string informacao) 
 {
 	this->informacao = informacao;
 }
 void HistoricoTarefa::setInfo(const string info) 
 {
 	this->info = info;
 }
 void HistoricoTarefa::setDescricao(const string descricao) 
 {
 	this->descricao = descricao;
 }
 void HistoricoTarefa::setTipo(const string tipo)
 {
 	this->tipo = tipo;
 }
 void HistoricoTarefa::setTitulo(const string titulo)
 {
 	this->titulo = titulo;
 }


/**
 * Apresenta os dados do historico informacao.
 * @param out objecto stream out.
 */
void HistoricoTarefa::escreve(ostream &out) const
{
	out << "Cod. Historico: " << codHistorico << endl;
	out << "Cod. Tarefa: " << codTarefa << endl;
	out << "Cod. Projecto: " << codProjecto << endl;
	out << "Cod. Estado: " << codEstado << endl;
	out << "Nivel Importancia: " << nivelImportancia << endl;
	out << "Data Inicio: ";  dataInicio.listar();
	out << "Data Estimada: ";  dataEstimada.listar();
	out << "Data Fim: ";  dataFim.listar();
	out << "Informacao: " << informacao << endl;
	out << "Duracao: " << duracao << endl;
	out << "Tipo: " << tipo << endl;
	out << "Titulo: " << titulo << endl;
	out << "Dependente: " << dependente << endl;
	out << "Cod. Utilizador: " << codUtilizador << endl;
	out << "Num Contexto: " << nContexto << endl;
	out << "Delegado: " << delegado << endl;
	out << "Data Insercao: ";  dataInsercao.listar();
	out << "Cod. Tipo: " << codTipo << endl;
	out << "Info: " << info << endl;
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param ht objecto HistoricoTarefa.
 */
ostream & operator << (ostream &out, const HistoricoTarefa &ht)
{
	ht.escreve(out);
	return out;
}

HistoricoTarefa* HistoricoTarefa::clone() const
{
	return new HistoricoTarefa(*this);

}


#endif