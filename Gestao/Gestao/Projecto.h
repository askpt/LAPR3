/**
*@author Joao Machado
*@author Vitor Hugo
*@date 08/01/2013 
*@file Projecto.h 
*Classe responsavel por guardar toda a informacao sobre o projecto.*/ 

#ifndef PROJECTO_H
#define PROJECTO_H

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
	

public:
	Projecto();
	Projecto(int nivelImportancia, string informacao, string nome, int codUtilizador);
	~Projecto();

	int getCodProjecto() const;
	int getCodEstado() const;
	int getCodUtilizador() const;
	int getNivelImportancia() const;
	string getInformacao();
	string getNome();

	void setInformacao(string informacao);
	void setNivelImportancia(int nivelImportancia);
	void setNome(string nome);
	void setCodUtilizador(int codUtilizador);

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
 * Metodo de atribuicao da informacao.
 * @param informacao informacao.
 */
void Projecto::setInformacao(string informacao)
{
	this->informacao = informacao;
}

/**
 * Metodo de atribuicao do nivel de importancia.
 * @param nivelImportancia nivel de importancia.
 */
void Projecto::setNivelImportancia(int nivelImportancia)
{
	this->nivelImportancia = nivelImportancia;
}

/**
 * Metodo de atribuicao do nome.
 * @param nome nome.
 */
void Projecto::setNome(string nome)
{
	this->nome = nome;
}

/**
 * Metodo de atribuicao do codigo de utilizador.
 * @param codUtilizador codigo do utilizador.
 */
void Projecto::setCodUtilizador(int codUtilizador)
{
	this->codUtilizador = codUtilizador;
}

/**
 * Apresenta os dados do projecto.
 * @param out objecto stream out.
 */
void Projecto::escreve(ostream &out)
{
	cout << "Cod. Projecto: " << codProjecto << endl;
	cout << "Nome: " << nome << endl;
	cout << "Nivel de importancia: " << nivelImportancia << endl;
	cout << "Data de criacao: " << dataCriacao.listar();
	cout << "Cod. Estado: " << codEstado << endl;
	cout << "Cod. Utilizador: " << codUtilizador << endl;
	cout << "Informacao: " << informacao << endl;
	cout << "Data de fim: " << dataFim.listar();
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