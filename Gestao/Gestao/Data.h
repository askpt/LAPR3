#ifndef Data_
#define Data_
#include <ctime>

class Data 
{ 	
private:
	int ano;			// qualquer ano
	int mes;			// 1-12
	int dia;			// 1-31 dependente do mês

	
	int validaDia (int d) const;   // Confirma o valor do dia baseado no mes e ano 
	int validaMes (int m) const; 
	int validaAno (int a) const; 
	bool anoBissexto (int a) const;   // Testa se ano é bissexto


public:

	Data();
	Data(int a, int m, int d);
	Data(const Data &d);
	~Data() ;

	void dataHoje();

	void setAno (int a);
	void setMes (int m);
	void setDia (int d);
	void setData (Data dt) ;
	int getAno() const ;
	int getMes() const;
	int getDia() const;
	void listar() const ; 
};


int Data::diasPorMes[]=	{0,31,28,31,30,31,30,31,31,30,31,30,31};


Data::Data() 
{
	setAno(1900);
	setMes(1);
	setDia(1);
}

// Confirma o valor do mes e chama o metodo validaDia
// para confirmar o valor do dia.
Data::Data (int a, int m, int d ) 
{
	setAno(a);
	setMes(m);
	setDia(d);
}

Data::Data (const Data &d)
{
	ano=d.ano;
	mes=d.mes;
	dia=d.dia;
}

Data::~Data()
{

}

void Data::dataHoje()
{
	time_t hoje = time(0);
	tm *ltm = localtime(&hoje);

	ano = 1900+ltm->tm_year;
	mes = 1+ltm->tm_mon;
	dia = 1+ltm->tm_mday;
}

// Outros métodos
void Data::setAno (int a)
{
	ano = validaAno (a) ;
}

void  Data::setMes (int m)
{
	mes = validaMes (m);  // valida o mes
}

void  Data::setDia (int d)
{
	dia = validaDia (d);	// valida o dia
}

void Data::setData (Data dt)
{
	setAno(dt.ano) ;  
	setMes(dt.mes);
	setDia(dt.dia);	 
}

int Data::getAno() const
{
	return ano;
}

int Data::getMes() const
{
	return mes;
}

int Data::getDia() const
{
	return dia;
}


void Data::listar() const 
{
	cout << dia << " / " << mes << " / " << ano << endl ;			 
}

// Confirma o valor do dia baseado no mes e ano.
int Data::validaDia (int d) const
{
	if ( d > 0 && d <= diasPorMes[ mes ] ) 
		return d;

	if (mes == 2 && d == 29 && anoBissexto(ano))   // se Fevereiro: Verifica se ano bissexto
		return d;
	cout<<"Dia " << d << " invalido. Colocado o dia 1.";
	return 1;  // Deixa o objecto num estado consistente
}

int Data::validaMes (int m) const
{
	if ( m > 0 && m <= 12 )		// valida o mes
		return m;	
	else 
	{
		cout<<"\nMês inválido -> mes=1";
		return  1;
	}
}

int Data::validaAno (int a) const
{
	if (a < 0)
	{
		cout<<"\nAno negativo - inválido -> ano=0";
		return 0;
	}
	else
		return a;
}

// Testa se ano é bissexto
bool Data::anoBissexto(int a) const
{	
	return (a % 400 == 0 || a % 4 == 0 && a % 100 != 0 ) ;
}


#endif



