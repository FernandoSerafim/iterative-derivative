//CABEÇALHO
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
//#define TAM 5

//PROTÓTIPOS
void progressivaDois(float matriz[][5]);
void regressivaDois(float matriz[][5]);
void centralDois(float matriz[][5]);
void progressivaTres(float matriz[][5]);
void regressivaTres(float matriz[][5]);

//MAIN.C
int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Portuguese_Brazil");
int i, j;
int opcao, TAM = 5;
float matriz[2][TAM];

printf("No início do processo, faremos uma tabela com %d pontos...", TAM);
system("pause");
printf("Digite todas as %d entradas no eixo X\n\n", TAM);

	/*for(j=0; j<TAM; j++)
	{
		scanf(" %f", &matriz[0][j]);
	}
    */
matriz[0][0] = 1.8; matriz[0][1] = 1.9; matriz[0][2] = 2.0; matriz[0][3] = 2.1; matriz[0][4] = 2.2;
matriz[1][0] = 10.889365; matriz[1][1] = 12.703199; matriz[1][2] = 14.778112; matriz[1][3] = 17.148957; matriz[1][4] = 19.855030;
/*printf("Digite todas as %d componentes no eixo Y\n\n", TAM);
	for(j=0; j<TAM; j++)
	{
		scanf(" %f", &matriz[1][j]);
	}
*/
do
{
printf("Digite a operação que deseja realizar: D.P com dois pontos[1], D.R com dois pontos[2], D.C com dois pontos[3], D.P com trÊs pontos[4], D.R com trÊs pontos[5]\n\n");
scanf(" %d", &opcao);

switch(opcao)
{
	case 1:
		progressivaDois(matriz);
		break;
	case 2:
		regressivaDois(matriz);
		break;
	case 3:
		centralDois(matriz);
	    break;
	case 4:
		progressivaTres(matriz);
		break;
	case 5:
		regressivaTres(matriz);
		break;
}
}while(opcao!=0);
return 0;
}

void progressivaDois(float matriz[][5])
{
	float x, derivada;
	int i, posicao;

	printf("Digite o ponto em que deseja calcular a derivada progressiva com dois pontos\n\n");
	scanf(" %f", &x);

	for(i=0; i<5; i++)
	{
		if(matriz[0][i] == x)
			posicao = i;
	}
	if(posicao > 4 )
	{
		printf("ERRO: NÃO HÁ PONTOS SUFICIENTES PARA O CÁLCULO DESTA DERIVADA NESTE PONTO\n\n");
		return;
	}
derivada = (matriz[1][posicao+1] - matriz[1][posicao])/(matriz[0][posicao+1] - matriz[0][posicao]);
printf("O valor da derivada é: %f\n\n", derivada);
}

void regressivaDois(float matriz[][5])
{
	float x, derivada;
	int i, posicao;

	printf("Digite o ponto em que deseja calcular a derivada regressiva com dois pontos\n\n");
	scanf(" %f", &x);

	for(i=0; i<5; i++)
	{
		if(matriz[0][i] == x)
			posicao = i;
	}

derivada = (matriz[1][posicao] - matriz[1][posicao-1])/(matriz[0][posicao] - matriz[0][posicao-1]);
printf("O valor da derivada é: %f\n\n", derivada);
}
void centralDois(float matriz[][5])
{
	float x, derivada;
	int i, posicao;

	printf("Digite o ponto em que deseja calcular a derivada central com dois pontos\n\n");
	scanf(" %f", &x);

	for(i=0; i<5; i++)
	{
		if(matriz[0][i] == x)
			posicao = i;
	}
	if(posicao == 0 || posicao == 5 )
	{
		printf("ERRO: NÃO HÁ PONTOS SUFICIENTES PARA O CÁLCULO DESTA DERIVADA NESTE PONTO\n\n");
		return;
	}
derivada = (matriz[1][posicao+1] - matriz[1][posicao-1])/(matriz[0][posicao+1] - matriz[0][posicao-1]);
printf("O valor da derivada é: %f\n\n", derivada);
}
void progressivaTres(float matriz[][5])
{

	float index, derivada, h;
	int i, j, posicao;

	printf("Digite o ponto em que deseja calcular a derivada progressiva com três pontos\n\n");
	scanf(" %f", &index);

	for(i=0; i<5; i++)
	{
		if(matriz[0][i] == index)
			posicao = i;
	}
		if(posicao > 3 )
	{
		printf("ERRO: NÃO HÁ PONTOS SUFICIENTES PARA O CÁLCULO DESTA DERIVADA NESTE PONTO\n\n");
		return;
	}
    h = matriz[0][posicao+2] - matriz[0][posicao+1];

    derivada = (-3*matriz[1][posicao] + 4*matriz[1][posicao+1]- matriz[1][posicao+2])/(2*h);

    printf("O valor da derivada é: %f\n\n", derivada);

}
void regressivaTres(float matriz[][5])
{
	float x, derivada, h;
	int i, posicao;

	printf("Digite o ponto em que deseja calcular a derivada regressiva com três pontos\n\n");
	scanf(" %f", &x);

	for(i=0; i<5; i++)
	{
		if(matriz[0][i] == x)
			posicao = i;
	}
		if(posicao < 2)
	{
		printf("ERRO: NÃO HÁ PONTOS SUFICIENTES PARA O CÁLCULO DESTA DERIVADA NESTE PONTO\n\n");
		return;
	}
    h = matriz[0][posicao] - matriz[0][posicao-1];

    derivada = (matriz[1][posicao-2] - 4*matriz[1][posicao-1] + 3*matriz[1][posicao])/(2*h);

    printf("O valor da derivada é: %f\n\n", derivada);
}
