#ifndef BDados_
#define BDados_
#include <iostream>
#include <iomanip>
#include <occi.h>
#include "Lista.h"
using namespace oracle::occi;
#include "Informacao.h"
#include "Tarefa.h"
#include "Utilizador.h"
#include <sstream>
#include <string>

class BDados
{
private:
	Environment *env;
	Connection *ligacao;
	Statement *instrucao;
public:
	BDados(string user, string passwd, string db);
	~ BDados();
	Lista<Informacao> listaInformacao(int user);
	Lista<Tarefa> listarTarefasTodas(int codUser);
	int login(string user, string pass);
	void inserirInfo(int codUser, string info);
	Data convertData(string date);
	void inserirTarefa(int nivelImportancia, string informacao, Data dataEstimada, int duracao, string tipo, string titulo, int tarefaDependente, int codUtilizador, int delegado);
	bool associarInformacao(int codTarefa, int codInformacao);
	bool podeAssociarInfo(int codTarefa);
    void inserirData(string data, string tabela, string campo);

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

Data BDados::convertData(string date)
{
	//DATE: AA.MM.DD
	string diaS, mesS, anoS;
	int dia = 1, mes = 1, ano = 1900;

	anoS = date.substr(0,2);
	mesS = date.substr(3,2);
	diaS = date.substr(6,2);
	stringstream(diaS) >> dia;
	stringstream(mesS) >> mes;
	stringstream(anoS) >> ano;
	ano += 2000;
	Data temp(ano, mes, dia);

	return temp;
}

Lista<Informacao> BDados::listaInformacao(int user)
{
	Lista<Informacao> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM INFORMACAO WHERE COD_UTILIZADOR = " << user;
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data tmp = convertData(rset->getString(4));
		Informacao inf(rset->getInt(1), rset->getInt(2), rset->getString(3), tmp, rset->getInt(5));
		ret.insere(ret.comprimento() + 1, inf);
	}
	instrucao->closeResultSet (rset);

	return ret;
}

Lista<Tarefa> BDados::listarTarefasTodas(int codUser)
{
	Lista<Tarefa> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM TAREFA WHERE COD_UTILIZADOR = " << codUser;
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery();
	while (rset->next ())
	{
		Data dcria, dfim, dest;
		if(!rset->isNull(5))
			dcria = convertData(rset->getString(5));
		if(!rset->isNull(6))
			dfim = convertData(rset->getString(6));
		if(!rset->isNull(8))
			dest = convertData(rset ->getString(8));
		Tarefa tar(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getInt(4), dcria, dfim, rset->getString(7),dest, rset->getInt(9), rset->getString(10),rset->getString(11), rset->getInt(12), rset->getInt(13), rset->getInt(14), rset->getInt(15));
		ret.insere(ret.comprimento() + 1, tar);
	}
	instrucao->closeResultSet (rset);

	return ret;
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

void BDados::inserirTarefa(int nivelImportancia, string informacao, Data dataEstimada, int duracao, string tipo, string titulo, int tarefaDependente, int codUtilizador, int delegado)
{
	stringstream out;
	string aux = dataEstimada.toSQL(); 
	out << "BEGIN\nITAREFA(" << nivelImportancia << ",'" << informacao << "', '" << aux << "'," << duracao << ",'" << tipo << "', '" << titulo << "', " << tarefaDependente << ", " << codUtilizador << "," << delegado << ");\nEND;";
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	instrucao->executeUpdate();
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
}

bool BDados::associarInformacao(int codTarefa, int codInformacao)
{
	stringstream out;
	if(podeAssociarInfo(codTarefa))
	{
		out << "UPDATE Informacao SET cod_tarefa=" << codTarefa << "WHERE cod_informacao=" << codInformacao << ";";
		string comando = out.str();
		instrucao = ligacao->createStatement(comando);
		instrucao->executeUpdate();
		ligacao->commit();
		ligacao->terminateStatement(instrucao);

		return true;
	}else
		return false;
}

bool BDados::podeAssociarInfo(int codTarefa)
{
	stringstream out;
	int aux = NULL;
	out << "select cod_tarefa into " << aux << " from informacao where cod_tarefa=" << codTarefa << ";";
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	instrucao->executeUpdate();
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
	if(aux == NULL)
		return true;
	return false;
}

#endif