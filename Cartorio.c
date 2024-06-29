#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()						//criação de funções
{
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: \n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file;    // cria o arquivo
	file = fopen(arquivo, "w");        // cria o arquivo
	fprintf(file, "CPF: ");				//Descrever previamente o tipo de informação na tela do app
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
		printf("Não foi possivel abrir o arquivo (Não localizado!)\n");
		}
		
	printf("\nEssas são as informações do usuário:\n");
		
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
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	else
	{
		fclose(file);
				
		remove (cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		printf("CPF deletado com sucesso!\n");
		system("pause");
		
	}
	
}

int main()
{
	int opcao =0;  // definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		setlocale(LC_ALL, "Portuguese");	// definindo linguagem
	
	
		printf("### Cartório da EBAC ###\n\n"); 		// inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");	
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema!\n\n"); //fim do menu
		printf("Opção: ");
	
		scanf("%d", &opcao);	//armazenando a escolha do usuario
	
		system("cls");
		
		
			switch(opcao) // inicio da seleção de opção
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
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			}  // fim da seleção

	
	}	
}

