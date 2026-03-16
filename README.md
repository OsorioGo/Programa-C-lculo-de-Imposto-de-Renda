INCOME TAX CALCULATION PROGRAM


The following program was developed as the final project for the Structured Programming in C course at Fatec.

The project applies several concepts of the C programming language, including:

* Code modularization
* Structures (struct)
* File handling
* Loop structures
* Conditional statements
* String and array manipulation
* Complex mathematical calculations



The program is based on two main commands:


1. User Registration


Allows the user to register a person's data in the file BD_PF.dat.
The information is entered by the user during program execution.

Before saving the new record, the program checks whether the provided ID already exists in the file.
If the ID is already registered, the program displays an error message and cancels the operation.





2. Income Tax Calculation


This command calculates the income tax based on the data previously stored in the file.

The program asks for the taxpayer's ID, searches for the corresponding record in the file, and then performs the tax calculation.





Calculation Method


The income tax is calculated using the following formula:
Income Tax = Base Salary * Tax Rate


The base salary is calculated as:
Total annual salary – Total annual deductions


The tax rate is determined according to the following table:


* 0 – 21453.24		   0%
* 21453.25 – 32151.48	 7.5%
* 32151.49 – 42869.16	15.0%
* 42869.17 – 53565.72	22.5%
* Above 53565.73	  27.5%



👉 Please note that the program interface and messages are only available in Portuguese 🇧🇷
