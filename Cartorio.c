#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //alica��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o respons�vel por cadastrar usu�rios
{
	printf("Op��o selecionada: Registrar nomes\n");	
	
	//Criando vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: \n"); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a String
	
	strcpy(arquivo, cpf); //Reposns�vel por copiar os valores das string
	
	FILE *file;
	file = fopen(arquivo,"w"); //cria arquivo W significa write
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: \n");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: \n");	
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: \n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
//	file = fopen(arquivo, "a");
//	fprintf(file, ", ");
//	fclose(file);
		
	system("pause");
}

int consultar(){
    setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	printf("Op��o selecionada: Consultar nomes\n");
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL){
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n");
    }
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
    
	system("pause");	
}

int deletar(){
	printf("Op��o selecionada: Deletar nomes\n");
    char cpf[40];
	printf("\nDigite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usu�rio n�o foi encontrado \n");
		system("pause");
	}
		if(file != NULL){
		printf("O usu�rio deletado com sucesso \n");
		system("pause");
	}
    
	
}

int main()
{
	int  opcao = 0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;){
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n"); //fim do menu
	printf("\nOp��o: ");
	
	scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
	system("cls"); // limpa a tela
		
	switch (opcao) 
    {
        case 1:
            registrar(); //Chamada de fun��o
            break;
        
        case 2:
            consultar(); //Chamada de fun��o
			break;
            
        case 3:
            deletar(); //Chamada de fun��o
			break;
			    
        default:
            printf("Op��o inv�lida\n");
            system("pause");
			break;
    }
    
	printf("\n Software por  Alves e Alves Tec. LTDA.\n\n");
}
}

