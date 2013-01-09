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

/**
 * Metodo para retornar o codigo da tarefa.
 * @return codigo da tarefa.
 */
int Tarefa::getCodTarefa() const
{
	return codTarefa;
}

/**
 * Metodo para retornar o codigo do projecto.
 * @return codigo do projecto.
 */
int Tarefa::getCodProjecto() const
{
	return codProjecto;
}

/**
 * Metodo para retornar o codigo do estado.
 * @return codigo do estado.
 */
int Tarefa::getCodEstado() const
{
	return codEstado;
}

/**
 * Metodo para retornar o codigo do utilizador.
 * @return codigo do utilizador.
 */
int Tarefa::getCodUtilizador() const
{
	return codUtilizador;
}

/**
 * Metodo para retornar o nivel de importancia.
 * @return nivel de importancia.
 */
int Tarefa::getNivelImportancia() const
{
	return nivelImportancia;
}

/**
 * Metodo para retornar a duracao.
 * @return duracao.
 */
int Tarefa::getDuracao() const
{
	return duracao;
}

/**
 * Metodo para retornar o codigo da tarefa dependente.
 * @return codigo da tarefa dependente.
 */
int Tarefa::getCodDependente() const
{
	return codDependente;
}

/**
 * Metodo de atribuicao do nivel de importancia.
 * @param nivelImportancia nivel de importancia.
 */
void Tarefa::setNivelImportancia(int nivelImportancia)
{
	this->nivelImportancia = nivelImportancia;
}

/**
 * Metodo de atribuicao da informacao.
 * @param informacao informacao.
 */
void Tarefa::setInformacao(string informacao)
{
	this->informacao = informacao;
}

/**
 * Metodo de atribuicao da data estimada.
 * @param estimada data estimada.
 */
void Tarefa::setDataEstimada(Data estimada)
{
	this->dataEstimada = dataEstimada;
}

/**
 * Metodo de atribuicao da duracao.
 * @param duracao duracao.
 */
void Tarefa::setDuracao(int duracao)
{
	this->duracao = duracao;
}

/**
 * Metodo de atribuicao do codigo da tarefa dependente.
 * @param codDependente codigo da tarefa dependente
 */
void Tarefa::setCodDependente(int codDependente)
{
	this->codDependente = codDependente;
}

/**
 * Metodo de atribuicao do codigo de utilizador.
 * @param codUtilizador codigo do utilizador.
 */
void Tarefa::setCodUtilizador(int codUtilizador)
{
	this->codUtilizador = codUtilizador;
}

/**
 * Apresenta os dados do projecto.
 * @param out objecto stream out.
 */
void Tarefa::escreve(ostream &out)
{
	cout << "Cod. Tarefa: " << codTarefa << endl;
	cout << "Cod. Projecto: " << codProjecto << endl;
	cout << "Cod. Tarefa dependente: " << codDependente << endl;
	cout << "Nome: " << titulo << endl;
	cout << "Tipo: " << tipo << endl;
	cout << "Nivel de importancia: " << nivelImportancia << endl;
	cout << "Data de criacao: " << dataCriacao.listar();
	cout << "Informacao: " << informacao << endl;
	cout << "Data estimada: " << dataEstimada.listar();
	cout << "Data de fim: " << dataFim.listar();
} 

/**
 * Sobrecarga do operador stream out.
 * @param out object stream out.
 * @param t objecto Tarefa.
 */
ostream & operator << (ostream &out, const Tarefa &t)
{
	t.escreve(out);
	return out;
}

#endif