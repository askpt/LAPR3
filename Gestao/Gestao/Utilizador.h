/**
*@author Andre Silva
*@date 08/01/2013
*@file Utilizador.h
*Classe responsavel por guardar a informacao acerca do utilizador.
*/

#ifndef Utilizador_
#define Utilizador_

class Utilizador
{
private:
	int codUtilizador;
	string nome;
	int telefone;
	string login;
	string pass;
public:
	Utilizador();
	Utilizador(int codUtilizador, string nome, int telefone, string login, string pass);
	Utilizador(const Utilizador &u);
	~Utilizador();

	int getCodUtilizador() const;
	string getNome() const;
	int getTelefone() const;
	string getLogin() const;
	string getPass() const;

	void setCodUtilizador(const int c);
	void setNome(const string n);
	void setTelefone(const int t);
	void setLogin(const string l);
	void setPass(const string p);

	void escreve(ostream &out) const;
};

/**
*Construtor vazio.
*/
Utilizador::Utilizador()
{
	Utilizador(0, "", 0, "", "");
}

/**
*Construtor completo
*@param codUtilizador codigo do utilizador
*@param nome nome do utilizador
*@param telefone telefone do utilizador
*@param login username do utilizador
*@param pass password do utilizdor
*/
Utilizador::Utilizador(int codUtilizador, string nome, int telefone, string login, string pass)
{
	setCodUtilizador(codUtilizador);
	setNome(nome);
	setTelefone(telefone);
	setLogin(login);
	setPass(pass);
}

/**
*Construtor copia
*@param u utilizador a ser copiado
*/Utilizador::Utilizador(const Utilizador &u)
{
	Utilizador(u.codUtilizador, u.nome, u.telefone, u.login, u.pass);
}

/**
*Destrutor
*/
Utilizador::~Utilizador()
{
}

/**
*Metodo para retornar o codigo de utilizador
*@return codigo do utilizador
*/
int Utilizador::getCodUtilizador() const
{
	return codUtilizador;
}

/**
*Metodo para retornar o nome
*@return nome do utilizador
*/
string Utilizador::getNome() const
{
	return nome;
}

/**
*Metodo para retornar telefone
*@return telefone do utilizador
*/
int Utilizador::getTelefone() const
{
	return telefone;
}

/**
*Metodo para retornar nome de login
*@return nome de login 
*/
string Utilizador::getLogin() const
{
	return login;
}

/**
*Metodo para retornar password do utilizador
*@return password do utilizador
*/
string Utilizador::getPass() const
{
	return pass;
}

/**
*Metodo para alterar codigo de utilizador
*@param codigo de utilizador para alterar
*/
void Utilizador::setCodUtilizador(const int c)
{
	codUtilizador = c;
}

/**
*Metodo para alterar o nome do utilizador
*@param nome para alterar
*/
void Utilizador::setNome(const string n)
{
	nome = n;
}

/**
*Metodo para alterar o telefone do utilizador
*@param telefone para alterar
*/
void Utilizador::setTelefone(const int t)
{
	telefone = t;
}

/**
*Metodo para alterar o nome de login do utilizador
*@param nome para alterar
*/
void Utilizador::setLogin(const string l)
{
	login = l;
}

/**
*Metodo para alterar a password do utilizador
*@param nova password para ser alterada
*/
void Utilizador::setPass(const string p)
{
	pass = p;
}

/**
*Metodo para escrever todos os atributos do objeto Utilizador
*@param out objeto stream out
*/
void Utilizador::escreve(ostream &out) const {
	out << setw(5) << codUtilizador << " | " << nome << " | " << telefone << " | " << login << " | " << pass << endl;
}

/**
*Sobrecarga do operador stream out
*@param out objet stream out
*@param c objeto objeto Utilizador
*/
ostream & operator << (ostream &out, const Utilizador &c) {
	c.escreve(out);
	return out;
}

#endif