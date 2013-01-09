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

Utilizador::Utilizador()
{
	Utilizador(0, "", 0, "", "");
}

Utilizador::Utilizador(int codUtilizador, string nome, int telefone, string login, string pass)
{
	setCodUtilizador(codUtilizador);
	setNome(nome);
	setTelefone(telefone);
	setLogin(login);
	setPass(pass);
}

Utilizador::Utilizador(const Utilizador &u)
{
	Utilizador(u.codUtilizador, u.nome, u.telefone, u.login, u.pass);
}

Utilizador::~Utilizador()
{
}

int Utilizador::getCodUtilizador() const
{
	return codUtilizador;
}

string Utilizador::getNome() const
{
	return nome;
}

int Utilizador::getTelefone() const
{
	return telefone;
}

string Utilizador::getLogin() const
{
	return login;
}

string Utilizador::getPass() const
{
	return pass;
}

void Utilizador::setCodUtilizador(const int c)
{
	codUtilizador = c;
}

void Utilizador::setNome(const string n)
{
	nome = n;
}

void Utilizador::setTelefone(const int t)
{
	telefone = t;
}

void Utilizador::setLogin(const string l)
{
	login = l;
}

void Utilizador::setPass(const string p)
{
	pass = p;
}

void Utilizador::escreve(ostream &out) const {
	out << setw(5) << codUtilizador << " | " << nome << " | " << telefone << " | " << login << " | " << pass << endl;
}
ostream & operator << (ostream &out, const Utilizador &c) {
	c.escreve(out);
	return out;
}

#endif