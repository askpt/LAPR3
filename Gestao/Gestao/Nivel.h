/**
 * @author Joao Machado
 * @author Vitor Hugo
 * @date 21/12/2012 
 * @file Nivel.h 
 * Classe responsavel por guardar toda a informacao sobre os niveis de importancia.*/ 


#ifndef NIVEL_H
#define NIVEL_H

class Nivel
{
private:
	int nivelImportancia;
	string descricao;
	void setNivelImportancia();

public:
	Nivel();
	Nivel(string descricao);
	Nivel(const Nivel &n);
	~Nivel();

	int getNivelImportancia() const;
	string getDescricao() const;
	void setDescricao(const string desc);
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
 * Construtor completo
 * @param 	descricao 	descricao do nivel de importancia
 */
Nivel::Nivel(string descricao)
{
	setNivelImportancia();
	setDescricao(descricao);
}


/**
 * Construtor copia.
 * @param 	n 	objecto Nivel a ser copiado.
 */
Nivel::Nivel(const Nivel &n)
{
	nivelImportancia = n.nivelImportancia;
	descricao = n.descricao;
}


/**
 * Destrutor
 */
Nivel::~Nivel()
{
}


/**
 * Metodo para retornar o nivel de importancia
 * @return 	devolve o nivel de importancia
 */
int Nivel::getNivelImportancia() const
{
	return nivelImportancia;
}


/**
 * Metodo para retornar a descricao do nivel de importancia
 * @return 	devolve descricao do nivel de importancia
 */
string Nivel::getDescricao() const
{	
	return descricao;
}


/**
 * Metodo de atribuicao do nivel de importancia
 */
void Nivel::setNivelImportancia()
{
	nivelImportancia = ID++;
}


/**
 * Metodo de atribuicao de uma descricao ao nivel de importancia
 * @param 	desc 	descricao do nivel de importancia
 */
void Nivel::setDescricao(const string desc)
{
	descricao = desc;
}


/**
 * Apresenta os dados do nivel de importancia.
 * @param 	out 	objecto de stream out
 */
void Informacao::escreve(ostream &out)
{
	out << "Nivel de importancia: " << nivelImportancia << endl;
	out << "Descricao: " << descricao << endl;
} 


/**
 * Sobrecarga do operador stream out
 * @param	out 	objecto de stream out
 * @param 	n 		objecto Nivel
 */
ostream & operator << (ostream &out, const Nivel &n)
{
	n.escreve(out);
	return out;
}

#endif