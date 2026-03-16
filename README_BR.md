PROGRAMA DE CALCULO DE IMPOSTO DE RENDA


O programa a seguir foi realizado como trabalho final da disciplina de Programação Estrutural em C da Fatec.

O projeto utiliza diversos conceitos da linguagem C, incluindo:

* Modularização de código
* Estruturas de registro (struct)
* Manipulação de arquivos
* Laços de repetição
* Estruturas condicionais
* Manipulação de strings e vetores
* Cálculos matemáticos complexos



O programa se baseia em dois comandos principais:


1. Realizar Cadastro


Permite cadastrar os dados de uma pessoa no arquivo BD_PF.dat.
Os dados são inseridos pelo usuário durante a execução do programa.

Antes de salvar o novo registro, o programa verifica se o CPF informado já existe no arquivo.
Caso o CPF já esteja cadastrado, o programa exibe uma mensagem de erro e encerra a operação.





2. Cálculo do Imposto de Renda


Este comando realiza o cálculo do imposto com base nos dados previamente cadastrados no arquivo.

O programa solicita o CPF do contribuinte, localiza o registro correspondente no arquivo e então realiza o cálculo do imposto.





Método de cálculo


O imposto é calculado pela fórmula:
Imposto de Renda = Salário Base * Alíquota


O salário base é obtido pela seguinte operação:
Total do salário anual – Total dos descontos anuais


A alíquota é definida de acordo com a seguinte tabela:


* De 0 até 21453.24		   0%
* De 21453.25 até 32151.48	 7.5%
* De 32151.49 até 42869.16	15.0%
* De 42869.17 até 53565.72	22.5%
* Acima de 53565.73		27.5%
