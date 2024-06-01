#include "../include/headerA3.h"

int main(int argc, char * argv[]){

    //declares variables
    a3Emp ** tempPtr = malloc(sizeof(a3Emp*));
    char testing;
    char name[100];
    int choice, optionPrintOne, optionLookOnId, resultCountEmployee, optionFireOne = 0;


    loadEmpData(tempPtr, argv[1]); //function call to print the data from the file
    
    printf("\nWelcome to employee data management\n\n"); //print statement

    do //do loop
    {
        //the list of available choices
        printf("\n1 - Add a new employee\n");
        printf("2 - Print data of all employees\n");
        printf("3 - Print employee data at position n in the LL\n");
        printf("4 - View employee data based on empId\n");
        printf("5 - View employee data based on full name\n");
        printf("6 - Count number of employees\n");
        printf("7 - Sort employee data in ascending order of empId\n");
        printf("8 - Fire the nth employee\n");
        printf("9 - Fire all employees\n\n");

        printf("Choose a menu option: "); //propmts the user for input
        scanf("%d", &choice); //validates user input

        testing = getchar(); //fixes issues concerning fgets

        printf("%c", testing); //fixes issues concerning fgets

        //switch statement
        switch(choice){
            
            case 1:

                recruitEmployee(tempPtr); //function call
                
                break;

            case 2:

                printAll(tempPtr[0]); //function call

                break;

            case 3:

                printf("Enter a position: "); //prompts for user input
                scanf("%d", &optionPrintOne); //validates for user input

                printOne(tempPtr[0], optionPrintOne); //function call

                break;

            case 4:

                printf("Enter an employee ID: "); //prompts for user input
                scanf("%d", &optionLookOnId); //validates for user input

                printf("\n"); //newline

                lookOnId(tempPtr[0], optionLookOnId); //function call
                
                break;

            case 5: 

                printf("Enter the full name of the employee: "); //prompts for user input
                fgets(name, 50, stdin); //gets user input

                name[strlen(name) - 1] = '\0'; //puts the NULL character 
                lookOnFullName(tempPtr[0], name); //function call

                break;

            case 6:

                resultCountEmployee = countEmployees(tempPtr[0]); //fuction call
                printf("Total number of employees = %d\n\n", resultCountEmployee); //prints the total amount of employees
                
                break;

            case 7:

                printf("After sorting on empId, the employees are as follows:\n\n"); //print statement
                sortEmployeesId(tempPtr[0]); //function call

                break;

            case 8:
                printf("Enter a position: "); //prompts for user input
                scanf("%d", &optionFireOne); //validates for user input
                 
                fireOne(tempPtr, optionFireOne); //function call

                printf("There are now %d employees.\n", countEmployees(tempPtr[0])); //prints the updated number of employees
                break;

            case 9: 

                fireAll(tempPtr); //fuction call

                break;

        }

    }while(choice >= 1 && choice <= 9); //loop that goes from choice one to nine


    return 0;
}