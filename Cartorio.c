#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	char arquivo[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres representável
	char cpf[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres representável
	char nome[40];
	char sobrenome[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres representável
	char cargo[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres representável
	//Fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações dos usuários
	scanf("%s", cpf); //Armazenando a variavel "cpf" utilizando a função string "%s"  
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo ("w" Serve para escrever no arquivo)
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizar o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,","); //espaçamento entre as informações
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coletando informações dos usuários
	scanf("%s",nome); //Armazenando a variavel "Nome" utilizando a função string "%s"
	
	file = fopen(arquivo, "a");  //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,nome);  //espaçamento entre as informações
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,","); //espaçamento entre as informações
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações dos usuários
	scanf("%s",sobrenome); //Armazenando a variavel "Sobrenome" utilizando a função string "%s" 
	  
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,sobrenome); //espaçamento entre as informações
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,","); //espaçamento entre as informações
	fclose(file); //Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //Coletando informações dos usuários
	scanf("%s",cargo); //Armazenando a variavel "Cargo" utilizando a função string "%s" 
	
	file = fopen(arquivo, "a"); //Atualizando o arquivo (O "a" serve para atualizar o arquivo)
	fprintf(file,cargo); //espaçamento entre as informações
	fclose(file); //Fecha o arquivo
	
	system("pause"); //Pausa o programa

}
				
int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	//Inicio da criação de variáveis/string
	char cpf[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres representável
	char conteudo[200]; //Armazenar o valor inteiro de um membro do conjunto de caracteres representável
	char *token; //Utilizado para dividir a string em linhas 
	//Fim da criação de variáveis/string
		
	printf("Digite o CPF a ser consultado: "); //Coletando informações dos usuários
	scanf("%s",cpf); //Armazenando a variavel "cpf" utilizando a função string "%s"
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf,"r"); //Abre o arquivo CPF E "R" de Read (Ler) a informção
	
	if(file == NULL) //Se a informação não existir traz a seguinte informação
	{
		printf("\nNão foi possivel abrir o arquivo, não localizado!\n"); //Alertando o usuário
	}
		
	while(fgets(conteudo, 200, file)!= NULL) //While (enquanto) tiver informação, armazene a informação em conteudo se for diferente de NULL (nulo)
	{
		printf("\nEssas são as informações do usuário: \n"); //Informando o usuário

		token = strtok(conteudo, ","); //Variavel utilizada para dividir a string em linhas
		printf("CPF: %s\n", token); //Informação a aparecer antes dos dados do CPF
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Nome: %s\n", token); //Informação a aparecer antes dos dados do Nome
		
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Sobrenome: %s\n", token); //Informação a aparecer antes dos dados do Sobrenome
		 
		token = strtok(NULL, ","); //Variavel utilizada para dividir a string em linhas
		printf("Cargo: %s\n", token); //Informação a aparecer antes dos dados do Cargo

	}
	
	printf("\n"); //Pula uma linha
	system("pause"); //Pausa o programa

}

int deletar()
{
	char cpf[40]; //Armazenar o valor inteiro de um membro do conjunto de caracteres representável
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informações dos usuários
	scanf("%s",cpf); //Armazenando a variavel "cpf" utilizando a função string "%s" 
	
	remove(cpf); //Deletando a variavel "cpf"
	
	FILE *file; //Cria o arquivo
	file = fopen(cpf, "r"); //Abre o arquivo CPF e "R" de Read (Ler) a informção
	fclose(file); //Fecha o arquivo
	
	if(file == NULL) //Se a informação não existir traz a seguinte informação
	{
		printf("O usuário não se encontra no sistema!.\n\n"); //Alertando o usuário
		system("pause"); //Pausa o programa
	}
	if(file != NULL) //Se a informação existir traz a seguinte informação
	{
		printf("\nUsuário deletado com sucesso!\n\n"); //Alertando o usuário
		system("pause"); //Pausa o programa
	}

}


int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); 
		
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n"); //Informando o usuário
		printf("\t1 - Registrar nomes\n"); //Coletando informações dos usuários
		printf("\t2 - Consultar nomes\n"); //Coletando informações dos usuários
		printf("\t3 - Deletar nomes\n\n"); //Coletando informações dos usuários
		printf("Opção: "); //Fim do menu
		
		scanf ("%d",&opcao); //Armazenando a escolha do usuário (%d Só permite entrada de um número inteiro com sinal no formato decima)
		system("cls"); //Limpa a tela
		
		
		switch(opcao) 
		{ //Inicio da seleção
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
			printf("Essa opção não está disponivel!\n"); //Alertando o usuário
			system("pause"); //Pausa o programa
			break;		
		} //Fim da seleção							
	}

}

