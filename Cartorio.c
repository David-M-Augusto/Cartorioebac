#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()						//cria��o de fun��es
{
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file;    // cria o arquivo
	file = fopen(arquivo, "w");        // cria o arquivo
	fprintf(file, "CPF: ");				//Descrever previamente o tipo de informa��o na tela do app
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file);		// fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nNOME: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nCARGO: ");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado: \n");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");	// definindo linguagem
		
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
		{
		printf("N�o foi possivel abrir o arquivo (N�o localizado!)\n");
		}
		
	printf("\nEssas s�o as informa��es do usu�rio:\n");
		
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	printf("\n");
	
	system("pause");
	fclose(file);
}



int deletar()
{
	char cpf1[40];
	char cpf2[40];
	int comparacao1;
	
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf1);
		
	FILE *file;
	file = fopen(cpf1, "r");
	
	fclose(file);
		
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
		
	}
	else
	{
		printf("Confirme o CPF que deseja deletar: ");
		scanf("%s",cpf2);
		
		comparacao1 = strcmp(cpf1, cpf2);
		
		if(comparacao1 == 0)
		{
			fclose(file);	
				
			remove (cpf2);
		
			FILE *file;
			file = fopen(cpf2, "r");
		
			printf("CPF deletado com sucesso!\n");
			system("pause");
		}
		else
		{
			printf("O CPF digitado n�o coincide!\n");
			system("pause");
		}
	}	
}

int main()
	{
		int opcao =0;  // definindo vari�veis
		int laco=1;
		char senhadigitada[10]="a";
		int comparacao;
		
		setlocale(LC_ALL, "Portuguese");	// definindo linguagem
	
	
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Login de administrador!\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
		
		comparacao = strcmp(senhadigitada, "admin");   //comparando de senha
				
		if(comparacao == 0)			//validando senha
		{					
			for(laco=1;laco=1;)
			{
				system("cls");
				setlocale(LC_ALL, "Portuguese");	// definindo linguagem
		
		
				printf("### Cart�rio da EBAC ###\n\n"); 		// inicio do menu
				printf("Escolha a op��o desejada do menu:\n\n");	
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n");
				printf("\t4 - Sair do sistema!\n\n"); //fim do menu
				printf("Op��o: ");
		
				scanf("%d", &opcao);	//armazenando a escolha do usuario
		
				system("cls");
			
			
				switch(opcao) // inicio da sele��o de op��o
				{	
					case 1:
					registro();
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
					
					default:			
					printf("Essa op��o n�o est� disponivel!\n");
					system("pause");
					break;
					
				}  // fim da sele��o
	
		}
	}	
		else
		printf("Senha incorreta!");
			
}

