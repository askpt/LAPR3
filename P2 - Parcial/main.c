/**
*@author André Silva
*@date 20/12/2012
*@file main.c
*Ficheiro onde será processados os metodos principais de importação e tratamento de dados.
*/
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


/**
*@param string apontador onde está guardado um array de carateres a ser convertido
*@return retorna o valor que foi convertido para decimal
*Função que converte determinada string que terá um número em binario e que o ira converter
*em decimal e retornado.
*/
int binConvert(char *string)
{
	int pos = 0, valor = 0;

	for (pos = 0; string[pos] != 0; ++pos)
	{
		///Caso o valor na posição da string seja '1', ele irá converter para decimal e somar ao valor de retorno
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

/**
*@param tar Apontador de apontador que passa por parametro o endereço de memoria do array
*de structs onde serão guardados os valores do csv.
*@return retorna o tamanho da estrutura definida
*Função que retira os valores de uma linha de csv e que os irá guardar num array de estruturas do tipo tarefa
*/
int lerFicheiro(tarefa **tar)
{
	tarefa *temp = *tar;
	int tamanho = 0;
	FILE *ficheiro;
	char *strTemp, *str;

	strTemp=(char *)malloc(sizeof(char)*150);
	ficheiro = fopen("FX.csv", "r");
	///Caso ocorra algum erro na importação, dará um erro de Ficheiro vazio.
	if(ficheiro == NULL)
	{
		printf("Ficheiro vazio");

		return 0;
	}
	///Ciclo que irá percorrer todas as linhas do ficheiro
	while(!feof(ficheiro))
	{
		fgets(strTemp, 150, ficheiro);
		if(strTemp != NULL)
		{
			temp = (tarefa *)realloc(*tar, sizeof(tarefa)*(tamanho+2));
			if(temp == NULL)
			{
				printf("Erro na alocacao de memoria");

				return 0;
			}
			*tar=temp;
			///usou-se o strtok para dividir cada linha pelos atributos da struct
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

/**
*@return retorna o valor do código do erro caso tenha. Se for 0, não houve nenhum erro.
*Função principal do programa, onde faz tambem uma listagem dos valores guardados na estrutura.
*/
int main()
{
	tarefa *tar = (tarefa *)malloc(sizeof(tarefa));
	int i;
	int tamanho = lerFicheiro(&tar);
	int mCont = maiorContexto(tar, sizeof(tarefa), 0);

	for (i = 0; i < tamanho; ++i)
	{
		printf("%d, %s, %d, %X\n", tar[i].numeroAcao, tar[i].nomeAcao, tar[i].prioAcao, tar[i].contexto);
	}

	printf("Maior Contexto: %d\n", mCont);

	return 0;
}
