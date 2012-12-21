/**
*@author Joao Machado
*@author Vitor Hugo
*@date 21/12/2012 
*@file Informacao.h 
*Classe responsavel por guardar toda a informacao que o utilizador desejar colocar no programa, que pode ser ou nao uma tarefa.*/ 

#ifndef INFORMACAO_H
#define INFORMACAO_H

#include "Data.h"

class Informacao
{

private:
	int codInformacao;
	string descricao;
	Data dataInsercao;
	static int ID;


public:
	Informacao();
	Informacao(int codInformacao, string descricao);
	Informacao(const Informacao &i);

	~Informacao();

	int getCodInformacao() const;
	string getDescricao() const;

	void setCodInformacao(int codInf);
	void setDescricao(string desc);

	virtual Informacao *clone() const;
	void escreve(ostream &out) const;
};


Informacao::ID=0;

/**
 * Construtor vazio.
 */
Informacao::Informacao()
{
	
}   

/**
 * Construtor completo.
 * @param descricao descricao da informacao.
 */
Informacao::Informacao(string descricao)
{
	setCodInformacao();
	setDescricao(descricao);
	dataInsercao.dataHoje();
}

/**
 * Construtor copia.
 * @param i objecto Informacao a ser copiado.
 */
Informacao::Informacao(const Informacao &i)
{
	codInformacao = i.codInformacao;
	descricao = i.descricao;
}

/**
 * Destrutor.
 */
Informacao::~Informacao()
{

}

/**
 * Metodo para retornar o codigo da informacao.
 * @return codigo da informacao.
 */
int Informacao::getCodInformacao()
{
	return codInformacao;	
}

/**
 * Metodo para retornar a descricao da informacao.
 * @return descricao da informacao.
 */
string Informacao::getDescricao()
{	
	return descricao;
}

/**
 * Metodo de atribuicao do codigo da informacao.
 */
void Informacao::setCodInformacao()
{
	codInformacao = ID++;
}


/**
 * Metodo de atribuicao de um descricao da informacao.
 * @param desc descricao da informacao.
 */
void Informacao::setDescricao(string desc)
{
	descricao = desc;
}

/**
 * Apresenta os dados da informacao.
 * @param out objecto stream out.
 */
void Informacao::escreve(ostream &out)
{
	cout << "Informacao: " << codInformacao << endl;
	cout << "Descricao: " << descricao << endl;
	cout << "Data de Insercao: " << dataInsercao.listar() << endl;
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param i objecto informacao.
 */
ostream & operator << (ostream &out, const Informacao &i)
{
	i.escreve(out);
	return out;
}

#endif