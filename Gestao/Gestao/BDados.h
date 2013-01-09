#ifndef BDados_
#define BDados_
#include <iostream>
#include <iomanip>
#include <occi.h>
#include <list>
using namespace oracle::occi;
#include "Utilizador.h"
#include <sstream>
class BDados
{
private:
	Environment *env;
	Connection *ligacao;
	Statement *instrucao;
public:
	BDados(string user, string passwd, string db);
	~ BDados();
	int login(string user, string pass);
	void inserirInfo(int codUser, string info);
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

int BDados::login(string user, string pass)
{
	stringstream out;
	out << "SELECT * FROM UTILIZADOR WHERE LOGIN = '" << user << "'";
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	ResultSet *rset = instrucao -> executeQuery();
	rset->next();
	Utilizador uti(rset->getInt(1), rset->getString(2), rset->getInt(3), rset->getString(4), rset->getString(5));
	if(uti.getPass() == pass)
	{
		return uti.getCodUtilizador();	
	}else
		return -1;
}

void BDados::inserirInfo(int codUser, string info)
{
	stringstream out;
	out << "BEGIN\nIINFORMACAO(NULL, '" << info << "', " << codUser << ");\nEND;";
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	instrucao->executeUpdate();
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
}

#endif