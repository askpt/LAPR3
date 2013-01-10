#include <iostream>
#include <string>
//#include <conio.h>
using namespace std;
#include "bdados.h"

int codUser = -1;

/*void getPassword(string &get)
{
	get.erase();
	char key;

	do
	{
		key = getch();

		switch (key)
		{
		case '\b': //backspace pressed
			if(get.length() > 0)
			{
				get.erase(get.length() - 1, 1);
				//erase the last character in password
				cout << '\b' << " " << '\b';
			}

			break;

		default:
			if(key > 31 && key < 127) 
			{
				get.push_back(key);
				cout << "*";
			}
		}
	} while(key != '\r'); //quit if enter is pressed
	cout << endl;
}*/

void login()
{
	try 
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		cout << "Nome de Utilizador?\nPara sair escreva sair" << endl;
		string user;
		getline(cin, user);
		if(user != "sair"){
			cout << "Pass?" << endl;
			string pass;
			getline(cin, pass);
			//getPassword(pass);
			codUser = conexao -> login(user, pass);
			delete(conexao);
		}
		else
		{
			codUser = -2;
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
		fflush(stdin);
		getline(cin, info);
		fflush(stdin);
		conexao -> inserirInfo(codUser, info);
		delete(conexao);
	}
	catch (SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}
}

void listarInfo()
{
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		Lista<Informacao> list = conexao ->listaInformacao(codUser);
		cout << list;
		delete(conexao);
	} 
	catch(SQLException erro)
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
		cout << "2 - Listar informacao" << endl;
		cout << "0 - Sair" << endl;
		cin >> op;
		switch(op)
		{
		case 1:
			inserirInfo();
			break;
		case 2:
			listarInfo();
			break;
		default:
			cout << "A sair..." << endl;
			break;
		}
	}
}

int main ()
{
	while(codUser == -1)
		login();
	if(codUser > 0)
	{
		menu();

	}


	return 0;
}