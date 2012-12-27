/**
*@author Joao Machado
*@author Vitor Hugo
*@date 21/12/2012 
*@file Nivel.h 
*Classe responsavel por guardar toda a informacao sobre os niveis de importancia.*/ 

#ifndef NIVEL_H
#define NIVEL_H

class Nivel
{

private:
	int nivelImportancia;
	string descricao;
	static int ID;

	void setNivelImportancia();

public:
	Nivel();
	Nivel(string descricao);
	Nivel(const Nivel &n);
	~Nivel();

	int getNivelImportancia() const;
	string getDescricao() const;

	void setDescricao(string desc);

	virtual Nivel *clone() const;
	void escreve(ostream &out) const;


};


Nivel::ID=0;

/**
 * Construtor vazio.
 */
Nivel::Nivel()
{

}

/**
 * Construtor completo.
 * @param descricao descricao do nivel de importancia.
 */
Nivel::Nivel(string descricao)
{
	setNivelImportancia();
	setDescricao(descricao);
}

/**
 * Construtor copia.
 * @param n objecto Nivel a ser copiado.
 */
Nivel::Nivel(const Nivel &n)
{
	nivelImportancia = n.nivelImportancia;
	descricao = n.descricao;
}

/**
 * Destrutor.
 */
Nivel::~Nivel()
{

}

/**
 * Metodo para retornar o nivel de importancia.
 * @return nivel de importancia.
 */
int Nivel::getNivelImportancia()
{
	return nivelImportancia;
}

/**
 * Metodo para retornar a descricao do nivel de importancia.
 * @return descricao do nivel de importancia.
 */
string Nivel::getDescricao()
{	
	return descricao;
}

/**
 * Metodo de atribuicao do nivel de importancia.
 */
void Nivel::setNivelImportancia()
{
	nivelImportancia = ID++;
}

/**
 * Metodo de atribuicao de uma descricao ao nivel de importancia.
 * @param desc descricao do nivel de importancia.
 */
void Nivel::setDescricao(string desc)
{
	descricao = desc;
}

/**
 * Apresenta os dados do nivel de importancia.
 * @param out objecto stream out.
 */
void Informacao::escreve(ostream &out)
{
	cout << "Nivel de importancia: " << nivelImportancia << endl;
	cout << "Descricao: " << descricao << endl;
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param n objecto Nivel.
 */
ostream & operator << (ostream &out, const Nivel &n)
{
	n.escreve(out);
	return out;
}

#endif