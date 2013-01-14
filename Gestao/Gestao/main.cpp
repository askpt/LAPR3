#include <iostream>
#include <string>
//#include <conio.h>
using namespace std;

int codUser = -1;

#include "bdados.h"
#include "Projecto.h"
#include "Data.h"
#include "csvassembly.h"

void eliminaProjeto()
{
	try
	{
		BDados *conexao = new BDados("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		Lista<Projecto> list = conexao->listarProjetosTodos(codUser);
		cout << list;
		cout << "Projeto a eliminar?" << endl;
		int codProjeto;
		cin >> codProjeto;
		conexao->eliminarProjeto(codUser, codProjeto);
		cout << "Projeto eliminado com sucesso" << endl;
		delete (conexao);
	}
	catch(SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}


}

/*
Meter no menu:
-> 	exportAssemb(); exportacao para Assembly
-> listarProjetos(); listar todos os projectos
-> eliminaProjeto(); eliminar um projeto
*/

/**
 * associa informação a uma tarefa, com base nos código de informção e tarefa
 * pedidos ao utilizador
 */
void associarInfo(){
    // variáveis para guardar código de tarefa e código de informação
    int codTar = 0;
    int codInf = 0;
    // início de try-catch para verificar conexão à base de dados
    try
	{
        // conexão à base de dados
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
        // pede ao utilizador qual a tarefa que pretende associar
        cout << "Indique qual a tarefa que pretende associar:" << endl;
        // lista as tarefas (com base na variável global)
        Lista<Tarefa> list = conexao ->listarTarefasTodas(codUser);
		cout << list;
        // guarda código tarefa na variável respectiva
        cin >> codTar;
        // pede ao utilizador qual a informação que pretende associar
        cout << "Indique qual a informação que prentende associar" << endl;
        // lista informação com base na variável global
        Lista<Informacao> listInf = conexao ->listaInformacao(codUser);
        cout << listInf;
        cin >> codInf;
        // associa informação
        conexao->associarInformacao(codInf, codTar);
        // termina ligação
        delete(conexao);
	} // end try
	catch (SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	} // end catch
} // end associarInfo


void inserirInfo()
{
	string info;
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		cout << "Inserir descricao da informacao" << endl;
		fflush(stdin);
		getline(cin, info);
		conexao -> inserirInfo(codUser, info);
		delete(conexao);
	}
	catch (SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}
}
void alteraTarefa()
{
	int codTar;
	int codestado=0, nivelimportancia=0, duracao=0, coddependente=0, delegado=0;
	string datafim="", dataestimada="",informacao="",titulo="",tipo="";

	char resposta='n';
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		Lista<Tarefa> list = conexao ->listarTarefasTodas(codUser);
	
		
		cout << list;
		cout << "**********************************************************************" << endl;
		cout << "Codigo da Tarefa a alterar?" << endl;
		
		cin >> codTar;
		cout << "Pretende alterar o estado da tarefa? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Estado?" << endl;
			cin >> codestado;
		}
		cout << "Pretende alterar o nivel de importancia? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Nivel de importancia?" << endl;
			cin >> nivelimportancia;
		}
		cout << "Pretende alterar a duracao? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Duracao?" << endl;
			cin >> duracao;
		}
			cout << "Pretende alterar a dependencia? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Dependencia?" << endl;
			cin >> coddependente;
		}
		cout << "Pretende alterar o estado delegado? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Nova delegacao?" << endl;
			cin >> delegado;
		}
		cout << "Pretende alterar a data de fim de tarefa? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Data de fim de tarefa?" << endl;
			fflush(stdin);
			getline(cin, datafim);
			
		}
		cout << "Pretende alterar a data estimada? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Data estimada?" << endl;
				fflush(stdin);
			getline(cin, dataestimada);
		
		}
		cout << "Pretende alterar a informacao? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Informacao?" << endl;
				fflush(stdin);
			getline(cin, informacao);
			
		}
		cout << "Pretende alterar o titulo? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Titulo?" << endl;
				fflush(stdin);
			getline(cin, titulo);
		}
		cout << "Pretende alterar o tipo da tarefa? (S/N) " << endl;
		cin >> resposta;
		if(resposta=='S'|| resposta=='s')
		{
			cout << "Tipo?" << endl;
				fflush(stdin);
			getline(cin, tipo);
		}
		conexao->alterarTarefa(codTar, codestado, nivelimportancia,duracao,coddependente,delegado,datafim,dataestimada,informacao,titulo,tipo);
		
		
		delete(conexao);
	} 
	catch(SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}
}
void listarTarefas()
{
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		Lista<Tarefa> list = conexao ->listarTarefasTodas(codUser);
		cout << list;
		delete(conexao);
	} 
	catch(SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}
}

void listarProjetos()
{
	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		Lista<Projecto> list = conexao ->listarProjetosTodos(codUser);
		cout << list;
		delete(conexao);
	} 
	catch(SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}
}

void inserirTarefa()
{
	int nivelImportancia;
	int duracao;
	string informacao;
	string titulo;
	string tipo;
	string dataEstimada;

	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		
		int codTarefa, codInfo;
		char opcao = 's';
		
		cout << "Inserir nivel de importancia da tarefa" << endl;
		cin >> nivelImportancia;
		cout << "Inserir informacao" << endl;
		fflush(stdin);
		getline(cin, informacao);
		cout << "Insira a data estimada (AA.MM.DD)" << endl;
		fflush(stdin);
		getline(cin, dataEstimada);
		cout << "Insira a duracao" << endl;
		cin >> duracao;
		cout << "Insira o tipo" << endl;
		fflush(stdin);
		getline(cin, tipo);
		cout << "Insira o titulo" << endl;
		fflush(stdin);
		getline(cin, titulo);
		conexao -> inserirTarefa(nivelImportancia, informacao, dataEstimada, duracao, tipo, titulo, NULL, codUser);
		codTarefa = conexao->ultimaTarefa(codUser);
		while(opcao == 's' || opcao == 'S')
		{
			Lista<Informacao> list = conexao->listaInfoSemTarefa(codUser);
			cout << list;
			cout << "Quer associar alguma informacao listada?" << endl;
			cout << "Para criar nova informacao insira -1" << endl;
			cin >> codInfo;
			if(codInfo == -1)
			{
				inserirInfo();
				codInfo = conexao->ultimaInfo(codUser);
			}	
			conexao->associarInformacao(codTarefa, codInfo);
			cout << "Deseja inserir mais informacao? (S/N)" << endl;
			cin >> opcao;
		}
		delete(conexao);
	}
	catch (SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}
}

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

void inserirProjeto()
{
	int nivelImportancia;
	string dataFim;
	string informacao;
	string nome;
	int codEstado;

	try
	{
		BDados *conexao = new BDados ("B2-7", "queroarroz", "193.136.62.27:1521/isepdb");
		
		int codProjeto, codTarefa;
		char opcao = 's';
		
		cout << "Inserir nivel de importancia do projeto" << endl;
		cin >> nivelImportancia;
		cout << "Inserir informacao" << endl;
		fflush(stdin);
		getline(cin, informacao);
		cout << "Insira a data de fim (AA.MM.DD)" << endl;
		fflush(stdin);
		getline(cin, dataFim);
		cout << "Insira o estado" << endl;
		cin >> codEstado;
		cout << "Insira o nome" << endl;
		fflush(stdin);
		getline(cin, nome);
		conexao -> inserirProjeto(codUser, nivelImportancia, dataFim, informacao, nome, codEstado);
		codProjeto = conexao->ultimoProjeto(codUser);
		
		while(opcao == 's' || opcao == 'S')
		{
			Lista<Tarefa> list = conexao->listaTarefaSemProjecto(codUser);
			cout << list;
			cout << "Quer associar alguma tarefa listada?" << endl;
			cout << "Para criar nova tarefa insira -1" << endl;
			cin >> codTarefa;
			
			if(codTarefa == -1)
			{
				inserirTarefa();
				codTarefa = conexao->ultimaTarefa(codUser);
			}
			conexao->associarTarefa(codTarefa, codProjeto);
			cout << "Deseja inserir mais tarefas? (S/N)" << endl;
			cin >> opcao;
		}
		delete(conexao);
	}
	catch (SQLException erro)
	{
		cerr << "Erro: " << erro.getMessage() << endl;
	}
}

void menuDependencias()
{
				
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Dependencias                            *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Criar dependencias                          *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 3:
					sair=true;
					break;

				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuDuracaoTarefa()
{
				
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Duracao da tarefa                       *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Calcular estimativa                         *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;

				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuHistoricoTarefas()
{
				
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Consultar historico de tarefas          *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Visualizar historico                        *\n";
				cout << "*        2 - Alterar nivel de visualizacao               *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 3:
					sair=true;
					break;

				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuEditarContextos()
{
				
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Editar Contextos                        *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Adicionar Contexto                          *\n";
				cout << "*        2 - Alterar Contexto                            *\n";
				cout << "*        3 - Remover Contexto                            *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 3:
					sair=true;
					break;

				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuContextoTarefas()
{
				
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Contexto de tarefas                     *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Consultar lista de tarefas                  *\n";
				cout << "*        2 - Editar contextos                            *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					menuEditarContextos();
					sair=true;
					break;
				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuReferencias()
{
				
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "***********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******             Referencias                     *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Criar referencias                           *\n";
				cout << "*        2 - Anexar documento                            *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;

				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuDeferirTarefa()
{
			
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Definir tarefa                          *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Definir datas                               *\n";
				cout << "*        2 - Criar lembrete                              *\n";
				cout << "*        3 - Associar a calendario                       *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 3:
					sair=true;
					break;

				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuPartilhar()
{
		
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "***********************************************************" << endl;
				cout << "******                                              *******" << endl;
				cout << "******     Partilhar na cloud                       *******" << endl;
				cout << "******                                              *******" << endl;
				cout << "***********************************************************" << endl;
				cout << "*     Menu:                                               *\n" ;
				cout << "*        1 - Definir grau visibilidade                    *\n";
				cout << "*        2 - Encriptar                                    *\n";
				cout << "*        0 - Menu anterior                                *\n" ;
				cout << "*---------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                    *\n";
				cout << "*                                                         *" << endl;
				cout << "*                                                         *" << endl;
				cout << "***********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}
void menuTarefasDelegadas()
{
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "***********************************************************" << endl;
				cout << "******                                              *******" << endl;
				cout << "******         Tarefas Delegadas                    *******" << endl;
				cout << "******                                              *******" << endl;
				cout << "***********************************************************" << endl;
				cout << "*     Menu:                                               *\n" ;
				cout << "*        1 - Ver tarefas delegadas                        *\n";
				cout << "*        2 - Delegar tarefa                               *\n";
				cout << "*        3 - Alterar delegacao                            *\n";
				cout << "*        4 - Remover delegacao                            *\n";
				cout << "*        5 - Partilhar na cloud                           *\n";
				cout << "*        0 - Menu anterior                                *\n" ;
				cout << "*---------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                    *\n";
				cout << "*                                                         *" << endl;
				cout << "*                                                         *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 3:
					sair=true;
					break;
				case 4:
					sair=true;
					break;
				case 5:
					menuPartilhar();
					sair=true;
					break;
					
				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}

void menuMarcarTarefa()
{
	
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Marcar tarefas para 'algum dia'         *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Adicionar data para relembrar               *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
			
				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
		}
void menuPrioridadeTarefa()
{
	
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******         Prioridades de tarefas              *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Atribuir prioridade                         *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
			
				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
		}
void menuInformacao()
{
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**************************************************************" << endl;
				cout << "******                                                 *******" << endl;
				cout << "******          Menu Informacao                        *******" << endl;
				cout << "******                                                 *******" << endl;
				cout << "**************************************************************" << endl;
				cout << "*     Menu:                                                  *\n" ;
				cout << "*        1 - Inserir Informacao                              *\n";
				cout << "*        2 - Listar Informacao                               *\n" ;
                cout << "*        3 - Associar Informacao                             *\n" ;
				cout << "*        0 - Menu Anterior                                   *\n" ;
				cout << "*------------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                       *\n";
				cout << "*                                                            *" << endl;
				cout << "*                                                            *" << endl;
				cout << "**************************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					inserirInfo();
					sair=true;
					break;
				case 2:
					listarInfo();
					sair=true;
					break;
                case 3:
                    associarInfo();
                    sair = true;
                    break;
				case 0:
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		
			}
		}
void menuCriterioOrdenacao()
{
		
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******         Criterio de ordenacao               *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Ordenar por prioridade                      *\n";
				cout << "*        2 - Ordenar por estimativa de tempo             *\n";
				cout << "*        1 - Ordenar por contexto                        *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
			
				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}
void menuListarTarefas()
{
	
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******          Listar Tarefas                     *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Ver todas as tarefas                        *\n";
				cout << "*        2 - Ver tarefas realizadas                      *\n" ;
				cout << "*        3 - Ver tarefas por realizar                    *\n" ;
				cout << "*        4 - Marcar tarefa como realizada                *\n" ;
				cout << "*        5 - Associar duracao                            *\n" ;
				cout << "*        6 - Alterar criterio ordenacao                  *\n" ;
				cout << "*        7 - Alterar nivel de informacao                *\n" ;
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					listarTarefas();
					sair=true;
					break;
				case 2:
					
					sair=true;
					break;
				case 6: 
					menuCriterioOrdenacao();
					sair=true;
					break;
				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
		}
void menuTarefas()
{
	bool sair=false;
	int op=1;
	while (!sair){
				cout << endl;
				cout << endl;
				cout << "**********************************************************" << endl;
				cout << "*******                                            *******" << endl;
				cout << "*******         Menu Tarefas                       *******" << endl;
				cout << "*******                                            *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Criar Tarefa                                *\n";
				cout << "*        2 - Alterar Tarefa                              *\n" ;
				cout << "*        3 - Converter tarefa para projecto              *\n" ;
				cout << "*        4 - Listar tarefas                              *\n" ;
				cout << "*        5 - Eliminar Tarefa                             *\n" ;
				cout << "*        6 - Marcar tarefa como 'algum dia'              *\n" ;
				cout << "*        7 - Tarefas Delegadas                           *\n" ;
				cout << "*        8 - Deferir tarefa                              *\n" ;
				cout << "*        9 - Prioridades de tarefas                      *\n" ;
				cout << "*        10 - Referencias                                *\n" ;
				cout << "*        11 - Contexto de tarefas                        *\n" ;
				cout << "*        12 - Consultar historico de tarefas             *\n" ;
				cout << "*        13 - Duracao de tarefas                         *\n" ;
				cout << "*        14 - Dependencias                               *\n" ;
				cout << "*        15 - Importar tarefas                           *\n" ;
				cout << "*        16 - Exportar tarefas                           *\n" ;
				cout << "*        17 - Adicionar notas                            *\n" ;
				cout << "*        0 - Menu Anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					inserirTarefa();
					sair=true;
					break;
				case 2:
				    alteraTarefa();
					sair=true;
					break;
				case 3:
					sair=true;
					break;

				case 4:
					menuListarTarefas();
					sair=true;
					break;
				case 5:
					sair=true;
					break;
				case 6:
					menuMarcarTarefa();
					sair=true;
					break;
				case 7:
					menuTarefasDelegadas();
					sair=true;
					break;
				case 8:
					menuDeferirTarefa();
					sair=true;
					break;
				case 9:
					menuPrioridadeTarefa();
					sair=true;
					false;
				case 10:
					menuReferencias();
					sair=true;
					break;
				case 11:
					menuContextoTarefas();
					sair=true;
					break;
				case 12:
					menuHistoricoTarefas();
					sair=true;
					break;
				case 13:
					menuDuracaoTarefa();
					sair=true;
					break;
				case 14:
					menuDependencias();
					sair=true;
					break;
				case 15:
					sair=true;
					break;
				case 16:
					sair=true;
					break;
				case 17:
					sair=true;
					break;
				case 0:
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
			break;}
}
void menuDependenciasProjecto()
{
				
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******     Dependencias                            *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Visualizar dependencias de um projeto       *\n";
				cout << "*        2 - Visualizar dependencias entre projetos      *\n";
				cout << "*        3 - Associar a calendario                       *\n";
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 3:
					sair=true;
					break;

				case 0:
					
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
						
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				
		break;
			}
}
void menuProjetos()
{

	int op;
	bool sair=false;
	

	while (!sair){
				cout << "**********************************************************" << endl;
				cout << "******                                             *******" << endl;
				cout << "******          Menu Projectos                     *******" << endl;
				cout << "******                                             *******" << endl;
				cout << "**********************************************************" << endl;
				cout << "*     Menu:                                              *\n" ;
				cout << "*        1 - Criar Projecto                              *\n";
				cout << "*        2 - Converter para tarefa                       *\n" ;
				cout << "*        3 - Prioridades de tarefas                      *\n" ;
				cout << "*        4 - Dependencias                                *\n" ;
				cout << "*        0 - Menu anterior                               *\n" ;
				cout << "*--------------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                   *\n";
				cout << "*                                                        *" << endl;
				cout << "*                                                        *" << endl;
				cout << "**********************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					inserirProjeto();
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 3:
					menuPrioridadeTarefa();
					sair=true;
					break;
				case 4:
					menuDependenciasProjecto();
					sair=true;
					break;
				case 0:
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
			break;
}}
void menuSincronizar()
{
	
	int op;
	bool sair=false;
	

	while (!sair){
				cout << "*******************************************************" << endl;
				cout << "******                                          *******" << endl;
				cout << "******          Menu Sincronizar                *******" << endl;
				cout << "******                                          *******" << endl;
				cout << "*******************************************************" << endl;
				cout << "*     Menu:                                           *\n" ;
				cout << "*        1 - Sincronizar com servidor                 *\n";
				cout << "*        2 - Integrar com outra lista de tarefas      *\n" ;
				cout << "*        0 - Menu anterior                            *\n" ;
				cout << "*-----------------------------------------------------*" << endl;
				cout << "*     Escolha a opcao:                                *\n";
				cout << "*                                                     *" << endl;
				cout << "*                                                     *" << endl;
				cout << "*******************************************************" << endl;
				cin >> op;
				switch(op){
				case 1:
					sair=true;
					break;
				case 2:
					sair=true;
					break;
				case 0:
					cout << "A sair..." << endl;
					sair=true;
					break;
				default:
					cout << "A sair..." << endl;
					sair=true;
					break;
				}
				break;
			}
		}

void menu()
{   
	bool sair=false;
	int op = 1;
	while(!sair)
	{	
		cout << endl;
		cout << endl;
		cout << "**************************************************************" << endl;
		cout << "******                                                 *******" << endl;
		cout << "******          GESTAO PESSOAL                         *******" << endl;
		cout << "******                                                 *******" << endl;
		cout << "**************************************************************" << endl;
		cout << "*     Menu:                                                  *\n" ;
		cout << "*        1 - Informacao                                      *\n";
		cout << "*        2 - Tarefas                                         *\n" ;
		cout << "*        3 - Projectos                                       *\n" ;
		cout << "*        4 - Sincronizar                                     *\n";
		cout << "*        0 - Sair                                            *\n" ;
		cout << "*------------------------------------------------------------*" << endl;
		cout << "*     Escolha a opcao:                                       *\n";
		cout << "*                                                            *" << endl;
		cout << "*                                                            *" << endl;
		cout << "**************************************************************" << endl;
		
		
		cin >> op;

		switch(op)
		{
		case 1:
			
		menuInformacao();
		
		break;
		case 2:
			
			menuTarefas();
			
			break;
		case 3:
			menuProjetos();
			
			break;
		case 4:
			menuSincronizar();
			break;
		case 0:
			sair=true;
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
	
		//menu();
		
	}


	return 0;
}