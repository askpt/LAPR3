/* Copyright (c) 2010,11 NFM-ACS-DEI/ISEP :-)*/
/* occiexemplo.cpp */
#include <iostream>
#include <string>
using namespace std;
#include "bdados.h"
#include "cliente.h"

void teste()
{
	string utilizador = "B2-7"; // substituir pelo correcto
	string palavra = "queroarroz"; // substituir pela correcta
	string bd = "193.136.62.27:1521/isepdb"; //ou em vez de ip, gandalf
	try {
		cout << "Exemplo de ligacao: a ligar ..."
			<< endl;
		BDados *exemplo = new BDados (utilizador, palavra, bd);
		list <Cliente> l = exemplo->lerClientes();
		cout << setw(5) << "COD." << " | "
			<< setw(12) << "Nome" << " | "
			<< setw(6) << "NIF" << " | "
			<< setw(14) << "Morada" << " | " << endl;
		for (list<Cliente>::iterator it = l.begin(); it != l.end(); it++)
			cout << *it;
		cout << endl;
		delete (exemplo);
		cout << "Exemplo de ligacao: terminado" << endl;
	}
	catch (SQLException erro) {
		cerr << "Erro: " << erro.getMessage () << endl;
	}
	cin.get();

}


int main ()
{
	teste();

	return 0;
}