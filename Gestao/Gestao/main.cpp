/* Copyright (c) 2010,11 NFM-ACS-DEI/ISEP :-)*/
/* occiexemplo.cpp */
#include <iostream>
#include <string>
using namespace std;
#include "bdados.h"

//BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
int codUser = -1;

void login()
{
	try 
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		cout << "Nome de Utilizador?\nPara sair escreva sair" << endl;
		string user;
		cin >> user;
		if(user != "sair"){
			cout << "Pass?" << endl;
			string pass;
			cin >> pass;
			codUser = conexao -> login(user, pass);
				delete(conexao);
		}
	}
	catch (SQLException erro) 
	{
		cerr << "Erro: " << erro.getMessage () << endl;
	}
}

void inserirInfo()
{
	string info;
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		cout << "Inserir descricao da informacao" << endl;
		cin >> info;
		conexao -> inserirInfo(codUser, info);
			delete(conexao);
	}
	catch (SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}

}

void menu()
{
	int op = 1;
	while(op != 0)
	{	
		cout << "1 - Inserir informacao" << endl;
		cout << "0 - Sair" << endl;
		cin >> op;

	
		switch(op)
		{
		case 1:
			inserirInfo();
			break;
		default:
			cout << "A sair..." << endl;
			break;
		}
	}
}

int main ()
{
	login();
	if(codUser != -1)
	{
		menu();
	
	}


	return 0;
}