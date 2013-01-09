/**
*@author Joao Machado
*@author Vitor Hugo
*@date 09/01/2013 
*@file Tarefa.h 
*Classe responsavel por guardar toda a informacao sobre tarefa.*/ 

#ifndef TAREFA_H
#define TAREFA_H

class Tarefa
{

private:
	int codTarefa;
	int codProjecto;
	int codEstado;
	int codUtilizador;
	int nivelImportancia;
	int duracao;
	int codDependente;
	Data dataCriacao;
	Data dataFim;
	Data dataEstimada;
	string informacao;
	string titulo;
	string tipo;
	Lista<Contexto> listaContextos;

public:
	Tarefa();
	Tarefa(int nivelImportancia, string informacao, Data dataEstimada, int duracao, int codDependente, int codUtilizador);
	~Tarefa();

	int getCodTarefa() const;
	int getCodProjecto() const;
	int getCodEstado() const;
	int getCodUtilizador() const;
	int getNivelImportancia() const;
	int getDuracao() const;
	int getCodDependente() const;
	Data getDataCriacao() const;
	Data getDataFim() const;
	Data getDataEstimada() const;
	string getInformacao() const;
	string getTitulo() const;
	string getTipo() const;
	Lista<Context> getListaContextos() const;

	void setNivelImportancia(int nivelImportancia);
	void setInformacao(string informacao);
	void setDataEstimada(Data dataEstimada);
	void setDuracao(int duracao);
	void setCodDependente(int codDependente);
	void setCodUtilizador(int codUtilizador);

	virtual Tarefa *clone() const;
	void escreve(ostream &out) const;

};

/**
 * Construtor vazio.
 */
Tarefa::Tarefa()
{
	Tarefa(0,"",Data(),0,0,0);
}

/**
 * Construtor completo.
 * @param nivelImportancia nivel de importancia.
 * @param informacao informacao da tarefa.
 * @param dataEstimada data estimada.
 * @param duracao duracao da tarefa.
 * @param codDependente codigo da tarefa dependente.
 * @param codUtilizador codigo de utilizador.
 */
Tarefa::Tarefa(int nivelImportancia, string informacao, Data dataEstimada, int duracao, int codDependente, int codUtilizador)
{
	setNivelImportancia(nivelImportancia);
	setInformacao(informacao);
	setDataEstimada(Data dataEstimada);
	setDuracao(duracao);
	setCodDependente(codDependente);
}

int Tarefa::getCodTarefa() const
{
	
}
	






#endif