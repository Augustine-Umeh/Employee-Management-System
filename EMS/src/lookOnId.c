#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId){

    int posId = 0;
    a3Emp * serat = headLL;

    //if the employee's Id does not exist 
    if(headLL == NULL){

        printf("\nThis Id doesn't exist\n"); //statement when the employee's Id does not exist
    }

    //goes through the loop if not NULL
    while(serat != NULL){

        //if the user input is the same as the employee's Id
        if(whichEmpId == serat->empId){

            printf("\tEmployee Id: %d\n", serat->empId); //prints employee's Id
            printf("\tFirst name: %s\n", serat->fname); //prints employee's name
            printf("\tLast name: %s\n", serat->lname); //prints employee's Id
            printf("\tDependants[%d]: ", serat->numDependents); //prints employee's dependants

            //goes through the loop to print the names of the dependants
            for(int i = 0; i < serat->numDependents; i++){
                printf("%s, ", serat->dependents[i]); //prints the dependants
            }

        }
        printf("\n"); //new line

        posId++; //goes to the next employee's Id 
        serat = serat->nextEmployee; //goes to next employee
    }

    return 0;
}