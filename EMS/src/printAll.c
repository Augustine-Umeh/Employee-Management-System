#include "../include/headerA3.h"

void printAll (struct employee * headLL){

    //declares variables
    int pos = 0, sum = 0;
    a3Emp * serat = headLL;

    //if head has nothing
    if(headLL == NULL){

        printf("\nThere are no employees\n"); //prints this when head has no employee
        return;
    }

    //goes through the loop if not NULL
    while(serat != NULL){

        printf("Employee #%d: \n", pos + 1); //tells the number of employee
        printf("\tEmployee Id: %d\n", serat->empId); //prints employee's Id
        printf("\tFirst name: %s\n", serat->fname); //prints employee's name
        printf("\tLast name: %s\n", serat->lname); //prints employee's Id
        printf("\tDependants[%d]: ", serat->numDependents); //prints employee's dependants

        //goes through the loop to print the dependents
        for(int i = 0; i < serat->numDependents; i++){
            printf("%s, ", serat->dependents[i]); //prints the dependants
        }

        printf("\n\n"); //newline

        pos++; //goes to next position
        sum++; //gets the total number of employee's
        serat = serat->nextEmployee; //goes to the next employee

    }

    //if there are only one employee 
    if(pos == 1){   

        printf("\nThere is only one employee\n"); //gives the value of one employee

     //if there are more than one employee
    }else{ 

        printf("\nThere are %d employees\n", sum); //gives the sum if it is more than one
    }


}