#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar dos string

int registro() //Fun��o resons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string	
	
	strcpy(arquivo, cpf);// Respons�vel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo //O "w" significa WRITE (ESCREVER)
	fprintf(file,cpf); //Salva o valor da vari�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); // O "a" significa ATUALIZAR
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // O "r" significa READ (LER)
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		system("pause");

	}
	


int deletar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];

	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");	
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema.\n");
		system("pause");
	}
}

int main()
	{
		int opcao=0; // Definindo as vari�veis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao;
		
		printf ("### Cart�rio da EBAC ### \n\n");
		printf ("Login do Administrador\n\nDigite a sua senha: ");
		scanf ("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "123");
		
		if(comparacao == 0)
		{
		
			system("cls");
			for(laco=1;laco=1;)
			{	
		
			system("cls");
		
				setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		
				printf ("### Cart�rio da EBAC ### \n\n"); // In�cio do Menu
				printf ("Escolha a op��o desejada do Menu \n\n");
				printf ("\t1- Registrar Nomes\n");
				printf ("\t2- Consultar Nomes\n");
				printf ("\t3- Deletar Nomes\n\n");
				printf ("\t4- Sair do sistema\n\n");
				printf ("Op��o:"); // Fim do Menu
		
				scanf("%d", &opcao); // Armazenando a escolha do usu�rio
		
				system("cls"); // Respon�vel por limpar a tela
			
				switch(opcao) //In�cio da sele��o do menu 			
				{
					case 1:
					registro(); // Chamada de fun��es
					break;
				
					case 2:	
					consulta();
					break;
				
					case 3:
					deletar();
					break;
					
					case 4:
					printf("Obrigado por utilizar o sistema!\n");
					return 0;
					break;
					
					default:
					printf("Essa op��o n�o est� dispon�vel\n");
					system("pause");
					break;	
				}// Fim da sele��o
		
			}	
		}
		
		else
			printf("Senha Incorreta!");
	}
