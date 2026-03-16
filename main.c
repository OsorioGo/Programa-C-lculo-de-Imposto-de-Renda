#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {


char CPF[12];
char nome[50];
float total_salario_anual;
float total_descontos_anual;

} PessoaFisica;


void AtualizandoBD(char CPFsJaRegistrados[][12]) {


    int contTAM=0, i=0, j=0;
    char BD_PF[50][50];

    //Abrindo o Arquivo
	FILE *p;
    p = fopen("DB_PF.dat", "r");


	//Passando o conteudo do Arquivo para uma matriz de strings
    for (i=0;;i++) {


    //vericando quando que chega no final do programa, para sair do laço
    if (feof(p)!=0) break;


    fgets(BD_PF[i], 50, p);
    contTAM++;

    }


	//Fechando o Arquivo
	fclose(p);


	//Limpando o restante da matriz
	for (i=contTAM;i<=50;i++) {
      strcpy(BD_PF[i], "\0");
	}


    //Copiando o CPF da matriz BD para a matriz CPFsJaRegistrados
	for (i=0;i<=contTAM;) {

        strncpy(CPFsJaRegistrados[j], BD_PF[i],11);
        CPFsJaRegistrados[j][11] = '\0';

        //A linha que o CPF fica sempre é a primeira de cada pessoa. Começa em 0 e vai aumentando de 5 em 5
        i=i+5;
        j++;

	}



    //Limpando o restante da matriz CPFJaRegistrados (j como contator referencia)
	j=j-1;
	for (;j<=10;j++) {
      strcpy(CPFsJaRegistrados[j], "\0");
	}

    return;

}


void CadastrarPF(char CPFsJaRegistrados[][12]) {

    //Limpar tela
	system("cls");
	fflush(stdin);

	int tamString=0, i=0;
	char CPFDeTeste[12];


    //Criando uma variavel do tipo PessoaFisica
    PessoaFisica NovaPessoa;


    //Inserindo dados (nome)
    printf("Insira o CPF a ser registrado (insira apenas os numeros):\n\n");
    printf("OBS: Caso sejam inseridos mais de 11 numeros, o programa registara os 11 primeiros inseridos\n\n");
    fflush(stdin);
    fgets(CPFDeTeste, 12, stdin);
    system("cls");
    fflush(stdin);


    //Verificando se o CPF inserido possui mais ou menos de 11 caracteres
    tamString = strlen(CPFDeTeste);


    if (tamString != 11 ) {
        printf("Error!\n\nO CPF deve conter 11 caracteres (somente os numeros)\nO programa sera encerrado\n");
        system("PAUSE");
        exit(0);
    }


    //Verificando se o CPF ja esta registrado na matriz CPFsJaRegistrados
    for (i=0;i<=10;i++) {

        //Se elas forem iguais
        if (strncmp(CPFsJaRegistrados[i],CPFDeTeste,12)==0) {

        printf("Error!\n\nO CPF ja existe no Banco de Dados!\nO programa sera encerrado\n");
        system("PAUSE");
        exit(0);
    }
    }

    //Registrando novo CPF na matriz CPFJaRegistrados
    for (i=0;i<=10;i++) {

        if (CPFsJaRegistrados[i][0]=='\0') {

        strncpy(CPFsJaRegistrados[i], CPFDeTeste,11);
        CPFsJaRegistrados[i][11] = '\0';
        break;

           }
    }

    //Passando o CPF de teste para NovaPessoa
    strcpy(NovaPessoa.CPF, CPFDeTeste);


    //Inserindo dados
    printf("Insira o nome a ser registrado (insera sem acentos e caracteres especiais):\n");
    fflush(stdin);
    fgets(NovaPessoa.nome, 50, stdin);
    system("cls");
    fflush(stdin);

    printf("Insira o total do salario anual a ser registrado (insira apenas os numeros):\n");
    scanf("%f",&NovaPessoa.total_salario_anual);
    system("cls");
    fflush(stdin);

    printf("Insira o total do desconto anual a ser registrado (insira apenas os numeros):\n");
    scanf("%f",&NovaPessoa.total_descontos_anual);
    system("cls");
    fflush(stdin);


	//Abrindo o Arquivo
	FILE *p;
    p = fopen("DB_PF.dat", "a");

	//Escrevendo no Arquivo
	fprintf(p,"%s\n%s%f\n%f\n\n", NovaPessoa.CPF, NovaPessoa.nome, NovaPessoa.total_salario_anual, NovaPessoa.total_descontos_anual);

	//Fechando o Arquivo
	fclose(p);


	//Mensagem de cadastro bem sucedido
    system("cls");
	fflush(stdin);
	printf("Pessoa Fisica cadastada com sucesso! \n\n");
    system("PAUSE");
    system("cls");
	fflush(stdin);


	return;
}//Cadastrar PessoaFísica


float CalculoAliquota (float total_salario_anual) {


        float aliquota_IRPF=0;

        if (total_salario_anual>=0 && total_salario_anual<=21453.24) aliquota_IRPF = 0;
        if (total_salario_anual>=21453.25 && total_salario_anual<=32151.48) aliquota_IRPF = 0.075;
        if (total_salario_anual>=32151.49 && total_salario_anual<=42869.16) aliquota_IRPF = 0.15;
        if (total_salario_anual>=42869.17 && total_salario_anual<=53565.72) aliquota_IRPF = 0.225;
        if (total_salario_anual>=53565.73) aliquota_IRPF = 0.275;


return aliquota_IRPF;

}


void CalcularIRPF (){

    char CPFdeBusca[12], cpfEncontrado[50], nomeEncontrado[50];
    char BD_PF[50][50];
    int i=0, contTAM=0, tamStringTeste=0;
    int encontrou=0;

    float salario_base_IRPF=0, total_salario_anual=0, total_descontos_anual=0, irpf=0, aliquota_IRPF=0;


    //Solicitando o CPF da pessoa a ser buscada no BD_PF.dat
    printf("Insira o CPF a ser buscado:\n\n");
    printf("OBS: Caso sejam inseridos mais de 11 numeros, o programa pesquisara pelos 11 primeiros numeros inseridos\n\n");
    fflush(stdin);
    fgets(CPFdeBusca,12,stdin);
    system("cls");
    fflush(stdin);


    //Caso tenha inserido um CPF com mais ou menos de 11 caracteres
    tamStringTeste = strlen(CPFdeBusca);

    if (tamStringTeste != 11) {
        printf("Error!\n\nO CPF deve conter 11 caracteres (somente os numeros)\nO programa sera encerrado\n");
        system("PAUSE");
        exit(0);

    }


    //Abrindo o Arquivo
	FILE *p;
    p = fopen("DB_PF.dat", "r");


	//Passando o conteudo do Arquivo para uma matriz de strings
    for (i=0;;i++) {

    fgets(BD_PF[i], 50, p);
    contTAM++;

    //vericando quando que chega no final do programa, para sair do laço
    if (feof(p)!=0) break;

    }


	//Fechando o Arquivo
	fclose(p);


	//Limpando o restante da matriz
	for (i=contTAM;i<=50;i++) {
      strcpy(BD_PF[i], "\0");
	}


    //Pesquisando o CPF na matriz
	for (i=0;i<=contTAM;) {

        //Se encontrou o CPF:
        if (strncmp(BD_PF[i],CPFdeBusca,11)==0) {

        //Booleana para ver se encontrou
        encontrou=1;

        //passando as variaveis de texto da matriz (CPF e nome)
        strcpy(cpfEncontrado, BD_PF[i]);
        strcpy(nomeEncontrado, BD_PF[i+1]);

        //Convertendo as variaveis numericas da matriz para float (salario e desconto anuais)
        total_salario_anual = strtof(BD_PF[i+2], NULL);
        total_descontos_anual = strtof(BD_PF[i+3], NULL);

        //Realizando a operacao do salario base
        salario_base_IRPF = total_salario_anual - total_descontos_anual;

        //Se o valor dos descontos forem maiores do que o do salario, igualar o salario a 0
        if (salario_base_IRPF < 0) salario_base_IRPF =0;

        //Calculo IRPF (função)
        aliquota_IRPF = CalculoAliquota(salario_base_IRPF);
        irpf = salario_base_IRPF*aliquota_IRPF;


        //printar, colocar pause e encerrar o programa

        system("cls");
        fflush(stdin);
        printf("Cadastro Encontrado!\n\n\nCPF:  %sNome: %s\nTotal Salario Anual:   R$%.2f\n",cpfEncontrado, nomeEncontrado, total_salario_anual);
        printf("Total Descontos Anual: R$%.2f\nSalario Base IRPF:     R$%.2f\n\nIRPF: R$%.2f\n\n\n",total_descontos_anual, salario_base_IRPF, irpf);
        system("PAUSE");
        system("CLS");
        //exit(0);

        }//if de comparação (CPF na matriz)


        //A linha que o CPF fica sempre é a primeira de cada pessoa, começa em 0 e vai aumentando de 5 em 5
        i=i+5;

	}//for para pesquisar o CPF na matriz


    //Se não encontrou o CPF
    if (encontrou==0) {

            printf("\nError! cadastro nao encontrado\n\nO programa sera encerrado\n\n");
            system("PAUSE");
            exit(0);

    }

    return;
}//Calcular IPRF



int main()
{

    int choice, i=0;


    //Matriz de strings, para armazenar os CPFs ja registrados no BD
    //Nota: como o projeto e pequeno, presumo que nao terao mais de 10 CPFs no meu BD
    char CPFsJaRegistrados[10][12];


    //Limpando a matriz
	for (i=0;i<=10;i++) {
            strcpy(CPFsJaRegistrados[i],"\0");
	}

    AtualizandoBD(CPFsJaRegistrados);


    //Menu
   for (;;) {

    printf("PROGRAMA DE CALCULO DE IMPOSTO DE RENDA\n\n\n");
    printf("Selecione um numero para as seguintes opcoes:\n\n");
    printf("1 para Cadastrar Pessoa Fisica\n");
    printf("2 para Calcular IRPF\n");
    printf("3 para Sair\n\n");
    scanf("%d",&choice);
    system("cls");
    fflush(stdin);



    //Seleção
    switch(choice) {

    case 1:
    CadastrarPF(CPFsJaRegistrados);
        break;

    case 2:
    CalcularIRPF();
        break;

    case 3:
        exit(0);
        break;

    default:
        system("cls");
        fflush(stdin);
        printf("\n\nOpcao Invalida!\n\n");
        system("pause");
        system("cls");
        fflush(stdin);

    }//Switch

   }//For principal

}//Main
