/**
*@author Tiago Pacheco
*@author Vitor Hugo
*@date 14/01/2013 
*@file HistoricoProjecto.h 
*Classe responsavel por guardar todo o historico dos projectos
*/ 

#ifndef HistoricoProjecto_H
#define HistoricoProjecto_H
#include <iostream>
#include <string>
using namespace std;
#include "Data.h"


class HistoricoProjecto
{
private:
 int codHistorico;
 int codProjecto;
 int codEstado;
 int nivelImportancia;
 int codTipo;
 int codUtilizador;
 Data dataInsercao;
 Data dataInicio;
 Data dataFim;
 string informacao;
 string nome;
 string info;

public:
 HistoricoProjecto(int codhistorico, int codprojecto, int nivelimportancia, Data dataInicio, Data dataFim, string informacao, string nome, int codEstado, int codUtilizador, Data dataInsercao, int codTipo, string info);
 HistoricoProjecto();
 HistoricoProjecto(const HistoricoProjecto& hp);
 ~HistoricoProjecto();

 int getCodHistorico()const;
 int getCodProjecto() const;
 int getCodEstado() const;
 int getCodUtilizador() const;
 int getNivelImportancia() const;
 int getCodTipo()const;
 Data getDataInicio();
 Data getDataFim();
 Data getDataInsercao();
 string getInformacao() const;
 string getInfo() const;
 string getNome()const;

 void setCodHistorico(const int codhistorico);
 void setCodProjecto(const int codprojecto) ;
 void setCodEstado(const int codestado) ;
 void setCodUtilizador(const int codutilizador) ;
 void setNivelImportancia(const int nivelimportancia) ;
 void setCodTipo(const int codtipo);
 void setDataInicio(const Data dataInicio);
 void setDataFim(const Data datafim);
 void setDataInsercao(const Data datainsercao);
 void setInformacao(const string informacao) ;
 void setInfo(const string info) ;
 void setNome(const string nome);

 virtual HistoricoProjecto *clone() const;
 void escreve(ostream &out) const;

};

/**
 *Construtor vazio
 */
HistoricoProjecto::HistoricoProjecto()
{
	HistoricoProjecto(0,0,0,Data(), Data(), "","",0,0,Data(),0,"");
}

/**
 *Construtor completo
 *@param codhistorico 		codigo de historico
 *@param codprojecto 		codigo de projeco
 *@param nivelimportnacia	nivel de importancia
 *@param datainsercao 		data de insercao
 *@param datafim 			data fim
 *@param informacao 		informacao
 *@param nome 				nome 
 *@param codestado 			codigo de estado
 *@param codigoutilizador	codigo do utilizador
 *@param dataInsercao 		data de insercao
 *@param codtipo 			codigo do tipo
 *@param info 				informacao
 *
 */
HistoricoProjecto::HistoricoProjecto(int codhistorico, int codprojecto, int nivelimportancia, Data datainsercao, Data datafim, string informacao, string nome, int codestado, int codutilizador, Data dataInsercao, int codtipo, string info)
{
	setCodHistorico( codhistorico);
	setCodProjecto( codprojecto) ;
	setCodEstado( codestado) ;
	setCodUtilizador( codutilizador) ;
	setNivelImportancia( nivelimportancia) ;
	setCodTipo( codtipo);
	setDataInicio( dataInicio);
	setDataFim( datafim);
	setDataInsercao( datainsercao);
	setInformacao(informacao) ;
	setInfo(info) ;
	setNome(nome);
}

/**
 *Construtor copia
 * @param objeto hi do tipo HistoricoProjecto a ser copiado
 */
HistoricoProjecto::HistoricoProjecto(const HistoricoProjecto& hp)
{
	codHistorico = hp.codHistorico;
	codProjecto = hp.codProjecto;
	codEstado = hp.codEstado;
	nivelImportancia = hp.nivelImportancia;
	codTipo = hp.codTipo;
	codUtilizador = hp.codUtilizador;
	dataInsercao = hp.dataInsercao;
	dataInicio = hp.dataInicio;
	dataFim = hp.dataFim;
	informacao = hp.informacao;
	nome = hp.nome;
	info = hp.info;
}

/**
* Destrutor.
*/
HistoricoProjecto::~HistoricoProjecto()
{
}
/**
 * @return codigo do historico
 */
int HistoricoProjecto::getCodHistorico()const
{
 return codHistorico;
}

int HistoricoProjecto::getCodProjecto() const
{
 return codProjecto;
}

int HistoricoProjecto::getCodEstado() const
{
 return codEstado;
}

int HistoricoProjecto::getNivelImportancia() const
{
 return nivelImportancia;
}
Data HistoricoProjecto::getDataInicio()
{
 return dataInicio;
}

Data HistoricoProjecto::getDataFim()
{
 return dataFim;
}

Data HistoricoProjecto::getDataInsercao()
{
 return dataInsercao;
}

string HistoricoProjecto::getInformacao() const
{
 return informacao;
}

string HistoricoProjecto::getInfo() const
{
 return info;
}

string HistoricoProjecto::getNome() const 
{
	return nome;
}

int HistoricoProjecto::getCodUtilizador() const 
{
	return codUtilizador;
}

int HistoricoProjecto::getCodTipo() const 
{
	return codTipo;
}


 void HistoricoProjecto::setCodHistorico(const int codhistorico)
 {
 	codHistorico = codhistorico;
 }

 void HistoricoProjecto::setCodProjecto(const int codprojecto) 
 {
 	codProjecto = codprojecto;
 }
 void HistoricoProjecto::setCodEstado(const int codestado) 
 {
 	codEstado = codestado;
 }
 void HistoricoProjecto::setCodUtilizador(const int codutilizador) 
 {
 	codUtilizador = codutilizador;
 }
 void HistoricoProjecto::setNivelImportancia(const int nivelimportancia) 
 {
 	nivelImportancia = nivelimportancia;
 }
 
 void HistoricoProjecto::setCodTipo(const int codtipo)
 {
 	codTipo = codtipo;
 }
 void HistoricoProjecto::setDataInicio(const Data dataInicio)
 {
 	this->dataInicio = dataInicio;
 }
 void HistoricoProjecto::setDataFim(const Data datafim)
 {
 	dataFim = datafim;
 }

 void HistoricoProjecto::setDataInsercao(const Data datainsercao)
 {
 	dataInsercao = datainsercao;
 }
 void HistoricoProjecto::setInformacao(const string informacao) 
 {
 	this->informacao = informacao;
 }
 void HistoricoProjecto::setInfo(const string info) 
 {
 	this->info = info;
 }

 void HistoricoProjecto::setNome(const string nome)
 {
 	this->nome = nome;
 }


/**
 * Apresenta os dados do historico informacao.
 * @param out objecto stream out.
 */
void HistoricoProjecto::escreve(ostream &out) const
{
	out << "Cod. Historico: " << codHistorico << endl;
	out << "Cod. Projecto: " << codProjecto << endl;
	out << "Cod. Estado: " << codEstado << endl;
	out << "Nivel Importancia: " << nivelImportancia << endl;
	out << "Data Inicio: ";  dataInicio.listar();
	out << "Data Fim: ";  dataFim.listar();
	out << "Informacao: " << informacao << endl;
	out << "Nome: " << nome << endl;
	out << "Cod. Utilizador: " << codUtilizador << endl;
	out << "Data Insercao: ";  dataInsercao.listar();
	out << "Cod. Tipo: " << codTipo << endl;
	out << "Info: " << info << endl;
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param hp objecto HistoricoProjecto.
 */
ostream & operator << (ostream &out, const HistoricoProjecto &hp)
{
	hp.escreve(out);
	return out;
}

HistoricoProjecto* HistoricoProjecto::clone() const
{
	return new HistoricoProjecto(*this);

}


#endif