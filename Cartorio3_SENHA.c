#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // Alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar dos string

int registro() //Função resonsável por cadastrar os usuários no sistema
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string	
	
	strcpy(arquivo, cpf);// Responsável por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo //O "w" significa WRITE (ESCREVER)
	fprintf(file,cpf); //Salva o valor da variável
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
		printf("Não foi possível abrir o arquivo, não localizado. \n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		system("pause");

	}
	


int deletar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];

	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");	
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema.\n");
		system("pause");
	}
}

int main()
	{
		int opcao=0; // Definindo as variáveis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao;
		
		printf ("### Cartório da EBAC ### \n\n");
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
		
				printf ("### Cartório da EBAC ### \n\n"); // Início do Menu
				printf ("Escolha a opção desejada do Menu \n\n");
				printf ("\t1- Registrar Nomes\n");
				printf ("\t2- Consultar Nomes\n");
				printf ("\t3- Deletar Nomes\n\n");
				printf ("\t4- Sair do sistema\n\n");
				printf ("Opção:"); // Fim do Menu
		
				scanf("%d", &opcao); // Armazenando a escolha do usuário
		
				system("cls"); // Responável por limpar a tela
			
				switch(opcao) //Início da seleção do menu 			
				{
					case 1:
					registro(); // Chamada de funções
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
					printf("Essa opção não está disponível\n");
					system("pause");
					break;	
				}// Fim da seleção
		
			}	
		}
		
		else
			printf("Senha Incorreta!");
	}
