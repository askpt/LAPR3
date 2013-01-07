#ifndef Cliente_
#define Cliente_
#include <iostream>
#include <iomanip>
#include <string>
/*
Classe para carregamento da tabela de CLIENTES
*/
class Cliente
{
private:
	int codigo;
	string nome;
	long nif;
	string morada;
public:
	Cliente();
	Cliente(int codigo, string nome, long nif, string morada);
	Cliente(const Cliente &c);
	void escreve(ostream &out) const;
};
Cliente::Cliente() : nome(), morada() {
	codigo = 0;
	nif = 0;
}
Cliente::Cliente(int codigo, string nome, long nif, string morada) :
nome(nome), morada(morada) {
	this->codigo = codigo;
	this->nif = nif;
}
Cliente::Cliente(const Cliente &c) : nome(c.nome), morada(c.morada) {
	this->codigo = c.codigo;
	this->nif = c.nif;
}
void Cliente::escreve(ostream &out) const {
	out << setw(5) << codigo << " | "
		<< setw(20) << nome << " | "
		<< setw(9) << nif << " | "
		<< setw(20) << morada << " | " << endl;
}
ostream & operator << (ostream &out, const Cliente &c) {
	c.escreve(out);
	return out;
}
#endif
