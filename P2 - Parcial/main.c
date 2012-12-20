#include <stdio.h>

typedef struct
{
	int numeroAcao;
	char nomeAcao[54];
	int prioAcao;
	int contexto;
}tarefa;

void lerFicheiro(tarefa *tar)
{
	tarefa temp = tar;
}

int main()
{
	tarefa tar = (tarefa *)malloc(sizeof(tarefa));


	return 0;
}