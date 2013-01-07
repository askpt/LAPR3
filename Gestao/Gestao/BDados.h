#ifndef BDados_
#define BDados_
#include <iostream>
#include <iomanip>
#include <occi.h>
#include <list>
using namespace oracle::occi;
#include "cliente.h"
class BDados
{
private:
	Environment *env;
	Connection *ligacao;
	Statement *instrucao;
public:
	BDados(string user, string passwd, string db);
	~ BDados();
	list <Cliente> lerClientes(); // Método para ler uma lista de
};
BDados::BDados(string user, string passwd, string db)
{
	env = Environment::createEnvironment (Environment::DEFAULT);
	ligacao = env->createConnection (user, passwd, db);
}
BDados::~BDados()
{
	env->terminateConnection (ligacao);
	Environment::terminateEnvironment (env);
}
list <Cliente> BDados::lerClientes()
{
	list <Cliente> ret;
	instrucao = ligacao->createStatement("SELECT * FROM CLIENTES");
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Cliente c(rset->getInt(1), rset->getString(2), rset->getNumber(3), rset->getString(4));
		ret.push_back(c);
	}
	instrucao->closeResultSet (rset);
	return ret;
}

#endif