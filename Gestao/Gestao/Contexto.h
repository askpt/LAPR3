/**
*@author Joao Machado
*@author Vitor Hugo
*@date 21/12/2012 
*@file Contexto.h 
*Classe responsavel por guardar os contextos referentes as tarefas.*/ 

#ifndef CONTEXTO_H
#define CONTEXTO_H

#include <string>

class Contexto
{

private:
	int codContexto;
	string descricao;
	static int ID;

	void setCodContexto();

public:
	Contexto();
	Contexto(string descricao);
	Contexto(const Contexto &c);
	~Contexto();

	int getCodContexto() const;
	string getDescricao() const;

	void setDescricao(string desc);

	virtual Contexto *clone() const;
	void escreve(ostream &out) const;

};

Contexto::ID=0;

/**
 * Construtor vazio.
 */
Contexto::Contexto()
{
	
}   

/**
 * Construtor completo.
 * @param descricao contexto da tarefa.
 */
Contexto::Contexto(string descricao)
{
	setCodContexto();
	setDescricao(descricao);
}

/**
 * Construtor copia.
 * @param c objecto Contexto a ser copiado.
 */
Contexto::Contexto(const Contexto &c)
{
	codContexto = c.codInformacao;
	descricao = c.descricao;
}

/**
 * Destrutor.
 */
Contexto::~Contexto()
{

}

/**
 * Metodo para retornar o codigo do contexto.
 * @return codigo do contexto.
 */
int Contexto::getCodContexto()
{
	return codContexto;	
}

/**
 * Metodo para retornar o contexto da tarefa.
 * @return contexto da tarefa.
 */
string Contexto::getDescricao()
{	
	return descricao;
}

/**
 * Metodo de atribuicao do codigo do contexto.
 */
void Contexto::setCodContexto()
{
	codContexto = ID++;
}


/**
 * Metodo de atribuicao de um contexto
 * @param desc contexto.
 */
void Contexto::setDescricao(string desc)
{
	descricao = desc;
}

/**
 * Apresenta os dados do contexto.
 * @param out objecto stream out.
 */
void Contexto::escreve(ostream &out)
{
	cout << "Contexto: " << codContexto << endl;
	cout << "Descricao: " << descricao << endl;
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param c objecto Contexto.
 */
ostream & operator << (ostream &out, const Contexto &c)
{
	c.escreve(out);
	return out;
}

#endif