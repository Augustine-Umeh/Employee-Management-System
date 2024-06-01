#include "../include/headerA3.h"

void recruitEmployee(struct employee ** headLL){

    //declares variables
    a3Emp * tempPtr = malloc(sizeof(a3Emp));
    char option = 'y';
    a3Emp * temp = *headLL;
    int j = 0, sum = 0;
    int len, i;

    printf("Enter the first name of the employee: "); //prompts the user for input
    scanf("%s", tempPtr->fname); //validates user input
    printf("Enter the last name of the employee: "); //prompts the user for input
    scanf("%s", tempPtr->lname); //validates user input

    printf("\n"); //newline

    len = strlen(tempPtr->lname); //len represents the length of the last name
    
    i = 0; //sets i to 0

    tempPtr->dependents = malloc(sizeof(char *)); //allocates memory number of dependents
    tempPtr->dependents[i] = malloc(sizeof(char) * MAX_LENGTH); //allocates memory for dependents

    //goes everytime the user enters y
    while(option == 'y' || option == 'Y'){

        printf("Enter name of dependent #%d: ", i + 1); //prompts for user input
        scanf("%s", tempPtr->dependents[i]); //validates user input

        tempPtr->dependents = realloc(tempPtr->dependents, sizeof(char *) * (i + 2)); //allocates memory
        tempPtr->dependents[i + 1] = malloc(sizeof(char) * (MAX_LENGTH + 1)); //allocates memory

        printf("Do you have any more dependents? "); //prompts for user input
        scanf(" %c", &option); //validates user input

        i++; //gets the number of dependents

        printf("\n"); //newline
    }

    tempPtr->numDependents = i; //value goes to tempPtr->numDependents
    printf("You have %d dependent(s)\n", tempPtr->numDependents); //prints the number of dependents

    //goes through the loop while last name is not nothing
    while(tempPtr->lname[j] != '\0'){

        sum = sum + tempPtr->fname[j]; //gets the sum of ascii value in first name
        j++;
    }

    tempPtr->empId = sum + len; //gets the employee Id

    tempPtr->nextEmployee = NULL; //next employee becomes NULL

    //goes through the loop if not NULL
    while(temp != NULL){

        //condition if you have similar employee Id
        if(temp->empId == tempPtr->empId){
            tempPtr->empId = tempPtr->empId + (rand() % (999 - 1) + 1) +1; //generates a random number
        }

        temp = temp->nextEmployee; //goes to the next employee
    }

    //if there is no content
    if(*headLL == NULL){
        *headLL = tempPtr; //head holds tempPtr
        return;
    }

    printf("Your computer-generated empId is %d\n", tempPtr->empId); //prints out the generated employee's number

    temp = *headLL; //temp holds value of headLL

    //goes through the loop if not NULL
    while(temp != NULL){

        //condition
        if(temp->nextEmployee == NULL){
            temp->nextEmployee = tempPtr; //next employee holds tempPtr
            return;
        }

        temp = temp->nextEmployee; //goes to the next employee
    }

}