#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	int numeroAcao;
	char nomeAcao[50];
	int prioAcao;
	int contexto;
}tarefa;

int binConvert(char *string)
{
	int pos = 0, valor = 0;

	for (pos = 0; string[pos] != 0; ++pos)
	{
		if(string[pos] == '1')
			valor += (int)pow(2.0, (double)pos);
	}

	return valor;
}

/*void strSplit(char charToSplit, char *string, char *dest)
{
	int posArr=0, ind=0, posInt=0;
	char *strTemp;

	strTemp = (char *)malloc(sizeof(char)*50);
	
	for(posArr=0; array[posArr] != 0; posArr++)
	{
		if(array[posArr] == ',')
		{
			printf("%d - ", ind);
			strTemp[posInt]=0;
			printf("%s\n", strTemp);
			dest[ind]=strTemp;
			printf("%s\n", dest[ind]);
			ind++;
			posInt=0;
		}
		else
		{
			strTemp[posInt]=array[posArr];
			posInt++;
		}
	}
}*/

int lerFicheiro(tarefa **tar)
{
	tarefa *temp = *tar;
	int tamanho = 0;
	FILE *ficheiro;
	char *strTemp, *str;
	int i;

	strTemp=(char *)malloc(sizeof(char)*150);

	ficheiro = fopen("FX.csv", "r");
	if(ficheiro == NULL)
	{
		printf("Ficheiro vazio");

		return 0;
	}
	while(!feof(ficheiro))
	{

		fgets(strTemp, 150, ficheiro);
		if(strTemp != NULL)
		{
			//printf("%s\n", strTemp);
			temp = (tarefa *)realloc(*tar, sizeof(tarefa)*(tamanho+2));
			if(temp == NULL)
			{
				printf("Erro na alocacao de memoria");

				return 0;
			}
			*tar=temp;

			str = strtok(strTemp, ",");
			(*tar)[tamanho].numeroAcao = atoi(str);

			str = strtok(NULL, ",");
			strncpy((*tar)[tamanho].nomeAcao, str, 50);
		
			str = strtok(NULL, ",");

			(*tar)[tamanho].prioAcao = atoi(str);
			str = strtok(NULL, ",");
			(*tar)[tamanho].contexto = binConvert(str);

			tamanho++;
		}
		
	}
	
	fclose(ficheiro);
	return tamanho;
}

int main()
{
	tarefa *tar = (tarefa *)malloc(sizeof(tarefa));
	int i;
	int tamanho = lerFicheiro(&tar);

	for (i = 0; i < tamanho; ++i)
	{
		printf("%d, %s, %d, %X\n", tar[i].numeroAcao, tar[i].nomeAcao, tar[i].prioAcao, 	tar[i].contexto);
	}


	return 0;
}