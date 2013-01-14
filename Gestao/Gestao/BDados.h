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
	void inserirTarefa(int nivelImportancia, string informacao, string dataEstimada, int duracao, string tipo, string titulo, int tarefaDependente, int codUtilizador);
	bool associarInformacao(int codTarefa, int codInformacao);
	bool podeAssociarInfo(int codInformacao);
    void inserirData(string data, string tabela, string campo);
	int ultimaTarefa(int codUser);
	Lista<Informacao> listaInfoSemTarefa(int codUser);
	int ultimaInfo(int codUser);
	void alterarInformacao(int codinformacao, string descricao);
	void alterarTarefa(int codTare, int codestado, int nivelimportancia, int duracao, int coddependente, int delegado, string datafim, string dataestimada, string info, string titulo, string tipo);
	Lista<Tarefa> listarTarefasRealizadas(int codUser);
	Lista<Tarefa> listarTarefasPorRealizar(int codUser);
	void realizarTarefa(int codUser, int codtarefa);
	void associarDuracao(int codUser, int codTarefa, int duracao);
	void eliminarTarefa(int codUser, int codTarefa);
	Lista<Tarefa> ordenarPrioridade(int codUser);
	Lista<Tarefa> ordenarTarefasEstimativa(int codUser);
	Lista<Tarefa> ordenarTarefasContexto(int codUser);
	void associarTarefaNivel(int codUser, int codTarefa, int nivel);
	Lista<Tarefa> verTarefasDelegadas(int codUser);
	void delegarTarefa(int codUser, int codTarefa, int codUtil);
	void alterarDelegacao(int codUser, int codTarefa, int codUtil);
	void removerDelegacao(int codUser, int codTarefa);
	Lista<Contexto> listaContextos();
	void criarContexto(string descricao);
	void alterarContexto(int codContexto, string descricao);
	void eliminarContexto(int codContexto);
	void associarTarefaContexto(int codContexto, int codTarefa);
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
		instrucao->closeResultSet(rset);
		return uti.getCodUtilizador();	
	}
	else
	{
		instrucao->closeResultSet(rset);
		return -1;
	}
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

void BDados::inserirTarefa(int nivelImportancia, string informacao, string dataEstimada, int duracao, string tipo, string titulo, int tarefaDependente, int codUtilizador)
{
	stringstream out;
	out << "BEGIN\nITAREFA(" << nivelImportancia << ",'" << informacao << "', '" << dataEstimada << "'," << duracao << ",'" << tipo << "', '" << titulo << "', " << tarefaDependente << ", " << codUtilizador << ");\nEND;";
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	instrucao->executeUpdate();
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
}

bool BDados::associarInformacao(int codTarefa, int codInformacao)
{
	stringstream out;
	if(podeAssociarInfo(codInformacao))
	{
		out << "UPDATE Informacao SET cod_tarefa=" << codTarefa << " WHERE cod_informacao=" << codInformacao;
		string comando = out.str();
		instrucao = ligacao->createStatement(comando);
		instrucao->executeUpdate();
		ligacao->commit();
		ligacao->terminateStatement(instrucao);

		return true;
	}else
		return false;
}

bool BDados::podeAssociarInfo(int codInformacao)
{
	stringstream out;
	int aux = NULL;
	bool ret;

	out << "select * from informacao where cod_informacao=" << codInformacao;
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	ResultSet *rset = instrucao->executeQuery ();
	rset->next();
	if(rset->isNull(2))
		ret = true;
	else
		ret = false;
	instrucao->closeResultSet (rset);

	return ret;
}

int BDados::ultimaTarefa(int codUser)
{
	int ret = -1;
	stringstream out;
	string comando;

	out << "SELECT COD_TAREFA FROM TAREFA WHERE COD_UTILIZADOR =" << codUser << "ORDER BY COD_TAREFA DESC";
	comando = out.str();
	instrucao = ligacao->createStatement(comando);
	ResultSet *rset = instrucao -> executeQuery();
	rset->next();
	ret = rset->getInt(1);
	instrucao->closeResultSet (rset);

	return ret;
}

int BDados::ultimaInfo(int codUser)
{
	int ret = -1;
	stringstream out;
	string comando;

	out << "SELECT COD_INFORMACAO FROM INFORMACAO WHERE COD_UTILIZADOR =" << codUser << "ORDER BY COD_INFORMACAO DESC";
	comando = out.str();
	instrucao = ligacao->createStatement(comando);
	ResultSet *rset = instrucao -> executeQuery();
	rset->next();
	ret = rset->getInt(1);
	instrucao->closeResultSet (rset);

	return ret;
}

Lista<Informacao> BDados::listaInfoSemTarefa(int codUser)
{
	Lista<Informacao> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM INFORMACAO WHERE COD_TAREFA IS NULL AND COD_UTILIZADOR = " << codUser;
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data tmp = convertData(rset->getString(4));
		Informacao inf(rset->getInt(1), rset->getInt(2), rset->getString(3), tmp, rset->getInt(5));
		if(rset->isNull(2))
			ret.insere(ret.comprimento() + 1, inf);
	}
	instrucao->closeResultSet (rset);

	return ret;

}
void BDados::alterarInformacao(int codinformacao, string descricao)
{
	    string operacao;
		stringstream out;
		out << "UPDATE INFORMACAO SET DESCRICAO = '" << descricao << "'WHERE COD_INFORMACAO = " << codinformacao;
		operacao=out.str();
		cout << operacao << endl;
		instrucao = ligacao->createStatement(operacao);
		instrucao->executeUpdate();
		ligacao->commit();
		ligacao->terminateStatement(instrucao);
		
}

void BDados::alterarTarefa(int codTarefa, int codestado, int nivelimportancia, int duracao, int coddependente, int delegado, string datafim, string dataestimada, string info, string titulo, string tipo)
{
	
	string operacao;
	if(codestado!=0)
	{
		stringstream out;
		out << "UPDATE TAREFA SET COD_ESTADO = " << codestado << "WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
		instrucao->executeUpdate();
		ligacao->commit();
		
	}
	if(nivelimportancia!=0)
	{
		stringstream out;
		out << "UPDATE TAREFA SET NIVEL_IMPORTANCIA = " << nivelimportancia << "WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
		instrucao->executeUpdate();
		ligacao->commit();
		out.flush();
	}
	if(duracao!=0)
	{
		stringstream out;
		out << "UPDATE TAREFA SET DURACAO = " << duracao << "WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
		instrucao->executeUpdate();
		ligacao->commit();
		out.flush();
	}
	if(coddependente!=0)
	{
		stringstream out;
		out << "UPDATE TAREFA SET DEPENDENTE = " << coddependente << "WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
		instrucao->executeUpdate();
		ligacao->commit();
		out.flush();
	}
	if(delegado!=0)
	{
		stringstream out;
		out << "UPDATE TAREFA SET DELEGADO = " << delegado << "WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
		instrucao->executeUpdate();
		ligacao->commit();
		out.flush();
	}
	if(datafim!="")
	{
		stringstream out;
		
		out << "UPDATE TAREFA SET DATA_FIM ='" << datafim << "'WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
		instrucao->executeUpdate();
		ligacao->commit();
		out.flush();
	}
	if(dataestimada!="")
	{
		stringstream out;
		
		out << "UPDATE TAREFA SET ESTIMATIVA ='" << dataestimada << "'WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
	    instrucao->executeUpdate();
	    ligacao->commit();
		out.flush();
	}
	if(info!="")
	{
		stringstream out;
				
		out << "UPDATE TAREFA SET INFORMACAO ='" << info << "'WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
	    instrucao->executeUpdate();
	    ligacao->commit();
		out.flush();
	}
	if(titulo!="")
	{
		stringstream out;
		out << "UPDATE TAREFA SET TITULO ='" << titulo << "'WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
	    instrucao->executeUpdate();
	    ligacao->commit();
		out.flush();
	}
	if(tipo!="")
	{
		stringstream out;
				
		out << "UPDATE TAREFA SET TIPO ='" << tipo << "'WHERE COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
	    instrucao->executeUpdate();
	    ligacao->commit();
		out.flush();
	}

	ligacao->terminateStatement(instrucao);

}
Lista<Tarefa> BDados::listarTarefasRealizadas(int codUser)
{
	Lista<Tarefa> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM TAREFA WHERE COD_UTILIZADOR = " << codUser << " AND COD_ESTADO = 2";
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data dataCria = convertData(rset->getString(5));
		Data dataFim;
		if(!rset->isNull(6))
			dataFim=convertData(rset->getString(6));
		else
		{
			Data tmp(1900,1,1);
			dataFim = tmp;
		}
		Data estimativa;
		if(!rset->isNull(8))
			estimativa=convertData(rset->getString(8));
		else
		{
			Data tmp(1900,1,1);
			estimativa = tmp;
		}
		Tarefa taref(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getInt(4), dataCria, dataFim, rset->getString(7), estimativa, rset->getInt(9), rset->getString(10), rset->getString(11), rset->getInt(12),rset->getInt(13), rset->getInt(14), rset->getInt(15));
		
		ret.insere(ret.comprimento() + 1, taref);
	}
	instrucao->closeResultSet (rset);

	return ret;
}

Lista<Tarefa> BDados::listarTarefasPorRealizar(int codUser)
{
	Lista<Tarefa> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM TAREFA WHERE COD_UTILIZADOR = " << codUser << " AND COD_ESTADO = 1";
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data dataCria = convertData(rset->getString(5));
		Data dataFim;
		if(!rset->isNull(6))
			dataFim=convertData(rset->getString(6));
		else
		{
			Data tmp(1900,1,1);
			dataFim = tmp;
		}
		Data estimativa;
		if(!rset->isNull(8))
			estimativa=convertData(rset->getString(8));
		else
		{
			Data tmp(1900,1,1);
			estimativa = tmp;
		}
		Tarefa taref(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getInt(4), dataCria, dataFim, rset->getString(7), estimativa, rset->getInt(9), rset->getString(10), rset->getString(11), rset->getInt(12),rset->getInt(13), rset->getInt(14), rset->getInt(15));
		
		ret.insere(ret.comprimento() + 1, taref);
	}
	instrucao->closeResultSet (rset);

	return ret;
}
void BDados::realizarTarefa(int codUser, int codTarefa)
{
		string operacao;
		stringstream out;
				
		out << "UPDATE TAREFA SET COD_ESTADO = 2 WHERE COD_UTILIZADOR = " << codUser << " AND COD_TAREFA = " << codTarefa;
		operacao=out.str();
		instrucao = ligacao->createStatement(operacao);
	    instrucao->executeUpdate();
	    ligacao->commit();
		cout << "Processo realizado com sucesso!!!" << endl;
	
	ligacao->terminateStatement(instrucao);

}
void BDados::associarDuracao(int codUser, int codTarefa, int duracao)
{
	string operacao;
	stringstream out;
	out << "UPDATE TAREFA SET DURACAO = " << duracao << "WHERE COD_UTILIZADOR = " << codUser << " AND COD_TAREFA = "<< codTarefa;
	operacao=out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
    cout << "Processo realizado com sucesso!!!" << endl;
	ligacao->terminateStatement(instrucao);
}
void BDados::eliminarTarefa(int codUser, int codTarefa)
{
	string operacao;
	stringstream out, out2, out3;
	
	out << "UPDATE INFORMACAO SET COD_TAREFA = NULL WHERE COD_TAREFA = " << codTarefa << " AND COD_UTILIZADOR = " << codUser;
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	
	ligacao->commit();
	ligacao->terminateStatement(instrucao);

	
	out2 << "DELETE FROM TAREFA_CONTEXTO WHERE COD_TAREFA = " << codTarefa;
	operacao = out2.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
		
	out3 << "DELETE FROM TAREFA WHERE COD_TAREFA = " << codTarefa << " AND COD_UTILIZADOR= " << codUser;
	operacao = out3.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
	cout << "Tarefa eliminada com sucesso" << endl;
	ligacao->terminateStatement(instrucao);
	
	
}
Lista<Tarefa> BDados::ordenarPrioridade(int codUser)
{
	Lista<Tarefa> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM TAREFA WHERE COD_UTILIZADOR = " << codUser << " ORDER BY NIVEL_IMPORTANCIA";
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data dataCria = convertData(rset->getString(5));
		Data dataFim;
		if(!rset->isNull(6))
			dataFim=convertData(rset->getString(6));
		else
		{
			Data tmp(1900,1,1);
			dataFim = tmp;
		}
		Data estimativa;
		if(!rset->isNull(8))
			estimativa=convertData(rset->getString(8));
		else
		{
			Data tmp(1900,1,1);
			estimativa = tmp;
		}
		Tarefa taref(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getInt(4), dataCria, dataFim, rset->getString(7), estimativa, rset->getInt(9), rset->getString(10), rset->getString(11), rset->getInt(12),rset->getInt(13), rset->getInt(14), rset->getInt(15));
		
		ret.insere(ret.comprimento() + 1, taref);
	}
	instrucao->closeResultSet (rset);

	return ret;
}
Lista<Tarefa> BDados::ordenarTarefasEstimativa(int codUser)
{
	Lista<Tarefa> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM TAREFA WHERE COD_UTILIZADOR = " << codUser << " AND ESTIMATIVA IS NOT NULL ORDER BY ESTIMATIVA DESC";
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data dataCria = convertData(rset->getString(5));
		Data dataFim;
		if(!rset->isNull(6))
			dataFim=convertData(rset->getString(6));
		else
		{
			Data tmp(1900,1,1);
			dataFim = tmp;
		}	
		Data estimativa;
		if(!rset->isNull(8))
			estimativa=convertData(rset->getString(8));
		else
		{
			Data tmp(1900,1,1);
			estimativa = tmp;
		}
	
	    
		Tarefa taref(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getInt(4), dataCria, dataFim, rset->getString(7), estimativa, rset->getInt(9), rset->getString(10), rset->getString(11), rset->getInt(12),rset->getInt(13), rset->getInt(14), rset->getInt(15));
		
		if(taref.getDataEstimada().getAno()!=1900)
			ret.insere(ret.comprimento() + 1, taref);
	}
	instrucao->closeResultSet (rset);

	return ret;
}
Lista<Tarefa> BDados::ordenarTarefasContexto(int codUser)
{
	Lista<Tarefa> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM TAREFA WHERE COD_UTILIZADOR = " << codUser << " ORDER BY NCONTEXTO";
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data dataCria = convertData(rset->getString(5));
		Data dataFim;
		if(!rset->isNull(6))
			dataFim=convertData(rset->getString(6));
		else
		{
			Data tmp(1900,1,1);
			dataFim = tmp;
		}
		Data estimativa;
		if(!rset->isNull(8))
			estimativa=convertData(rset->getString(8));
		else
		{
			Data tmp(1900,1,1);
			estimativa = tmp;
		}
		Tarefa taref(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getInt(4), dataCria, dataFim, rset->getString(7), estimativa, rset->getInt(9), rset->getString(10), rset->getString(11), rset->getInt(12),rset->getInt(13), rset->getInt(14), rset->getInt(15));
		
		ret.insere(ret.comprimento() + 1, taref);
	}
	instrucao->closeResultSet (rset);

	return ret;
}
void BDados::associarTarefaNivel(int codUser, int codTarefa, int nivel)
{
	string operacao;
	stringstream out;
	out << "UPDATE TAREFA SET NIVEL_IMPORTANCIA = " << nivel << "WHERE COD_UTILIZADOR = " << codUser << " AND COD_TAREFA = "<< codTarefa;
	operacao=out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
    cout << "Processo realizado com sucesso!!!" << endl;
	ligacao->terminateStatement(instrucao);
}
Lista<Tarefa> BDados::verTarefasDelegadas(int codUser)
{
	Lista<Tarefa> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM TAREFA WHERE COD_UTILIZADOR = " << codUser << "AND DELEGADO IS NOT NULL";
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Data dataCria = convertData(rset->getString(5));
		Data dataFim;
		if(!rset->isNull(6))
			dataFim=convertData(rset->getString(6));
		else
		{
			Data tmp(1900,1,1);
			dataFim = tmp;
		}
		Data estimativa;
		if(!rset->isNull(8))
			estimativa=convertData(rset->getString(8));
		else
		{
			Data tmp(1900,1,1);
			estimativa = tmp;
		}
		Tarefa taref(rset->getInt(1), rset->getInt(2), rset->getInt(3), rset->getInt(4), dataCria, dataFim, rset->getString(7), estimativa, rset->getInt(9), rset->getString(10), rset->getString(11), rset->getInt(12),rset->getInt(13), rset->getInt(14), rset->getInt(15));
		
		ret.insere(ret.comprimento() + 1, taref);
	}
	instrucao->closeResultSet (rset);

	return ret;
}
void BDados::delegarTarefa(int codUser, int codTarefa, int codUtil)
{
	string operacao;
	stringstream out;
	out << "UPDATE TAREFA SET DELEGADO = " << codUtil << "WHERE COD_UTILIZADOR = " << codUser << " AND COD_TAREFA = "<< codTarefa;
	operacao=out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
    cout << "Tarefa delegada com sucesso!!!" << endl;
	ligacao->terminateStatement(instrucao);
}
void BDados::alterarDelegacao(int codUser, int codTarefa, int codUtil)
{
	string operacao;
	stringstream out;
	out << "UPDATE TAREFA SET DELEGADO = " << codUtil << "WHERE COD_UTILIZADOR = " << codUser << " AND COD_TAREFA = "<< codTarefa;
	operacao=out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
    cout << "Delegacao alterada com sucesso!!!" << endl;
	ligacao->terminateStatement(instrucao);
}
void BDados::removerDelegacao(int codUser, int codTarefa)
{
	string operacao;
	stringstream out;
	out << "UPDATE TAREFA SET DELEGADO = NULL WHERE COD_UTILIZADOR = " << codUser << " AND COD_TAREFA = "<< codTarefa;
	operacao=out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
    cout << "Delegacao removida com sucesso!!!" << endl;
	ligacao->terminateStatement(instrucao);
}
Lista<Contexto> BDados::listaContextos()
{
	Lista<Contexto> ret;
	stringstream out;
	string operacao;

	out << "SELECT * FROM CONTEXTO";
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	ResultSet *rset = instrucao->executeQuery ();
	while (rset->next ())
	{
		Contexto cont(rset->getInt(1), rset->getString(2));
		ret.insere(ret.comprimento() + 1, cont);
	}
	instrucao->closeResultSet (rset);

	return ret;
}

void BDados::criarContexto(string descricao)
{
	stringstream out;
	out << "BEGIN\nICONTEXTO('" << descricao << "');\nEND;";
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	instrucao->executeUpdate();
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
}

void BDados::alterarContexto(int codContexto, string descricao)
{
	string operacao;
	stringstream out;
	out << "UPDATE CONTEXTO SET DESCRICAO = '" << descricao << "' WHERE COD_CONTEXTO = "<< codContexto;
	operacao=out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
    cout << "Contexto alterado com sucesso!!!" << endl;
	ligacao->terminateStatement(instrucao);
}

void BDados::eliminarContexto(int codContexto)
{
	string operacao;
	stringstream out, out2;
	
	out << "DELETE FROM TAREFA_CONTEXTO WHERE COD_CONTEXTO = " << codContexto;
	operacao = out.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
	
		
	out2 << "DELETE FROM CONTEXTO WHERE COD_CONTEXTO = " << codContexto;
	operacao = out2.str();
	instrucao = ligacao->createStatement(operacao);
	instrucao->executeUpdate();
	ligacao->commit();
	cout << "Contexto eliminado com sucesso" << endl;
	ligacao->terminateStatement(instrucao);
}

void BDados::associarTarefaContexto(int codContexto, int codTarefa)
{
	stringstream out;
	out << "BEGIN\nITAREFA_CONTEXTO('" << codTarefa << "', " << codContexto << ");\nEND;";
	string comando = out.str();
	instrucao = ligacao->createStatement(comando);
	instrucao->executeUpdate();
	ligacao->commit();
	ligacao->terminateStatement(instrucao);
}

#endif