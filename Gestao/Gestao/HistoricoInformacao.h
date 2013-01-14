/**
*@author Tiago Pacheco
*@date 14/01/2013 
*@file HistoricoInformacao.h 
*Classe responsavel por guardar todo o historico das informacoes.*/ 

#ifndef HistoricoInformacao_H
#define HistoricoInformacao_H
#include <iostream>
#include <string>
using namespace std;
#include "Data.h"


class HistoricoInformacao
{
private:
 int codHistorico;
 int codInformacao;
 int codTarefa;
 int codTipo;
 int codUtilizador;
 Data dataInsercao;
 string info;
 string descricao;

public:
 HistoricoInformacao(int codhistorico, int codinformacao, int codtarefa, string desc, int codutilizador, Data datainsercao, int codtipo, string info);
 HistoricoInformacao();
 HistoricoInformacao(const HistoricoInformacao& hi);
 ~HistoricoInformacao();

 int getCodHistorico()const;
 int getCodInformacao() const;
 int getCodTarefa() const;
 int getCodTipo() const;
 int getCodUtilizador() const;
 Data getDataInsercao();
 string getInfo() const;
 string getDescricao() const;

 void setCodHistorico(const int codhistorico);
 void setCodInformacao(const int codinformacao);
 void setCodTarefa(const int codtarefa);
 void setDescricao(const string descricao);
 void setCodUtilizador(const int codutilizador);
 void setDataInsercao(const Data datainsercao);
 void setCodTipo(const int codtipo);
 void setInfo(const string info);

 virtual HistoricoInformacao *clone() const;
 void escreve(ostream &out) const;

};

/**
 *Construtor vazio
 */
HistoricoInformacao::HistoricoInformacao()
{
	HistoricoInformacao(0,0,0,"",0,Data(),0,"");
}

/**
 *Construtor completo
 */
HistoricoInformacao::HistoricoInformacao(int codhistorico, int codinformacao, int codtarefa, string descricao, int codutilizador, Data datainsercao, int codtipo, string info)
{
 setCodHistorico(codhistorico);
 setCodInformacao(codinformacao);
 setCodTarefa(codtarefa);
 setDescricao(descricao);
 setCodUtilizador(codutilizador);
 setDataInsercao(datainsercao);
 setCodTipo(codtipo);
 setInfo(info);
}

/**
 *Construtor copia
 * @param objeto hi do tipo HistoricoInformacao a ser copiado
 */
HistoricoInformacao::HistoricoInformacao(const HistoricoInformacao& hi)
{
 codHistorico=hi.codHistorico;
 codInformacao=hi.codInformacao;
 codTarefa=hi.codTarefa;
 descricao=hi.descricao;
 codUtilizador=hi.codUtilizador;
 dataInsercao=hi.dataInsercao;
 codTipo=hi.codTipo;
 info=hi.info;
}

/**
* Destrutor.
*/
HistoricoInformacao::~HistoricoInformacao()
{
}
/**
 * @return codigo do historico
 */
int HistoricoInformacao::getCodHistorico()const
{
 return codHistorico;
}
int HistoricoInformacao::getCodInformacao() const
{
 return codInformacao;
}
int HistoricoInformacao::getCodTarefa() const
{
 return codTarefa;
}

string HistoricoInformacao::getDescricao() const
{
 return descricao;
}

int HistoricoInformacao::getCodUtilizador() const
{
 return codUtilizador;
}
Data HistoricoInformacao::getDataInsercao()
{
 return dataInsercao;
}

int HistoricoInformacao::getCodTipo() const
{
 return codTipo;
}

string HistoricoInformacao::getInfo() const
{
 return info;
}

 void HistoricoInformacao::setCodHistorico(const int codhistorico)
 {
 	codHistorico = codhistorico;
 }

 void HistoricoInformacao::setCodInformacao(const int codinformacao)
 {
 	codInformacao = codinformacao;
 }

 void HistoricoInformacao::setCodTarefa(const int codtarefa)
 {
 	codTarefa = codtarefa;
 }

 void HistoricoInformacao::setDescricao(const string descricao)
 {
 	this->descricao = descricao;
 }

 void HistoricoInformacao::setCodUtilizador(const int codutilizador)
 {
 	codUtilizador = codutilizador;
 }

 void HistoricoInformacao::setDataInsercao(const Data datainsercao)
 {
 	dataInsercao = datainsercao;
 }

 void HistoricoInformacao::setCodTipo(const int codtipo)
 {
 	codTipo = codtipo;
 }

 void HistoricoInformacao::setInfo(const string info)
 {
 	this->info = info;
 }


/**
 * Apresenta os dados do historico informacao.
 * @param out objecto stream out.
 */
void HistoricoInformacao::escreve(ostream &out) const
{
	out << "Cod. Historico: " << codHistorico << endl;
	out << "Cod. Tarefa: " << codTarefa << endl;
	out << "Cod. Tipo: " << codTipo << endl;
	out << "Cod. Informacao: " << codInformacao << endl;
	out << "Cod. Utilizador: " << codUtilizador << endl;
	out << "Data Insercao: ";  dataInsercao.listar();
	out << "Informacao: " << info << endl;
	out << "Descricao: " << descricao << endl;
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param hi objecto HistoricoInformacao.
 */
ostream & operator << (ostream &out, const HistoricoInformacao &hi)
{
	hi.escreve(out);
	return out;
}

HistoricoInformacao* HistoricoInformacao::clone() const
{
	return new HistoricoInformacao(*this);

}


#endif