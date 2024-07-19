#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	char arquivo[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres represent�vel
	char cpf[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres represent�vel
	char nome[40];
	char sobrenome[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres represent�vel
	char cargo[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres represent�vel
	//Fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es dos usu�rios
	scanf("%s", cpf); //Armazenando a variavel "cpf" utilizando a fun��o string "%s"  
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo ("w" Serve para escrever no arquivo)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,","); //espa�amento entre as informa��es
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informa��es dos usu�rios
	scanf("%s",nome); //Armazenando a variavel "Nome" utilizando a fun��o string "%s"
	
	file = fopen(arquivo, "a");  //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,nome);  //espa�amento entre as informa��es
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,","); //espa�amento entre as informa��es
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es dos usu�rios
	scanf("%s",sobrenome); //Armazenando a variavel "Sobrenome" utilizando a fun��o string "%s" 
	  
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,sobrenome); //espa�amento entre as informa��es
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,","); //espa�amento entre as informa��es
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informa��es dos usu�rios
	scanf("%s",cargo); //Armazenando a variavel "Cargo" utilizando a fun��o string "%s" 
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,cargo); //espa�amento entre as informa��es
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o programa

}
				
int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Inicio da cria��o de vari�veis/string
	char cpf[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres represent�vel
	char conteudo[200]; //Armazenar o valor inteiro de um membro do conjunto de caracteres represent�vel
	char *token; //Utilizado para dividir a string em linhas 
	//Fim da cria��o de vari�veis/string
		
	printf("Digite o CPF a ser consultado: "); //Coletando informa��es dos usu�rios
	scanf("%s",cpf); //Armazenando a variavel "cpf" utilizando a fun��o string "%s"
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo CPF E "R" de Read (Ler) a inform��o
	
	if(file == NULL) //Se a informa��o n�o existir traz a seguinte informa��o
	{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!\n"); //Alertando o usu�rio
	}
		
	while(fgets(conteudo, 200, file)!= NULL) //While (enquanto) tiver informa��o, armazene a informa��o em conteudo se for diferente de NULL (nulo)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n"); //Informando o usu�rio

		token = strtok(conteudo, ","); //Variavel utilizada para dividir a string em linhas
		printf("CPF: %s\n", token); //Informa��o a aparecer antes dos dados do CPF
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Nome: %s\n", token); //Informa��o a aparecer antes dos dados do Nome
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Sobrenome: %s\n", token); //Informa��o a aparecer antes dos dados do Sobrenome
		 
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Cargo: %s\n", token); //Informa��o a aparecer antes dos dados do Cargo

	}
	
	printf("\n"); //Pula uma linha
	system("pause"); //Pausa o programa

}

int deletar()
{
	char cpf[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres represent�vel
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��es dos usu�rios
	scanf("%s",cpf); //Armazenando a variavel "cpf" utilizando a fun��o string "%s" 
	
	remove(cpf); //Deletando a variavel "cpf"
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo CPF e "R" de Read (Ler) a inform��o
	fclose(file); //Fecha o arquivo
	
	if(file == NULL) //Se a informa��o n�o existir traz a seguinte informa��o
	{
		printf("O usu�rio n�o se encontra no sistema!.\n\n"); //Alertando o usu�rio
		system("pause"); //Pausa o programa
	}
	if(file != NULL) //Se a informa��o existir traz a seguinte informa��o
	{
		printf("\nUsu�rio deletado com sucesso!\n\n"); //Alertando o usu�rio
		system("pause"); //Pausa o programa
	}

}


int main ()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 
		
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n"); //Informando o usu�rio
		printf("\t1 - Registrar nomes\n"); //Coletando informa��es dos usu�rios
		printf("\t2 - Consultar nomes\n"); //Coletando informa��es dos usu�rios
		printf("\t3 - Deletar nomes\n\n"); //Coletando informa��es dos usu�rios
		printf("Op��o: "); //Fim do menu
		
		scanf ("%d",&opcao); //Armazenando a escolha do usu�rio (%d S� permite entrada de um n�mero inteiro com sinal no formato decima)
		system("cls"); //Limpa a tela
		
		
		switch(opcao) 
		{ //Inicio da sele��o
			case 1: 
			registro(); //Esta chamando a int registro
			break; //Fecha o switch
				
			case 2:	
			consulta(); //Esta chamando a int consulta
			break; //Fecha o switch
				
			case 3:	
			deletar(); //Esta chamando a int deletar
			break; //Fecha o switch
			
			default:
			printf("Essa op��o n�o est� disponivel!\n"); //Alertando o usu�rio
			system("pause"); //Pausa o programa
			break;		
		} //Fim da sele��o							
	}

}

