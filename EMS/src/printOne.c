#include "../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne){
    
    //declares variables
    a3Emp * serat = headLL;
    int pos = 0;

    //if head contains nothing
    if(headLL == NULL){
        
        printf("The linked list is empty.\n"); //prints when there is nothing in the list
    }

    //goes through the loop if not NULL
    while(serat != NULL){

        //if the user input is the same as the position
        if(whichOne == (pos + 1)){
            
            printf("\n"); //newline
            printf("\tEmployee Id: %d\n", serat->empId); //prints employee's Id
            printf("\tFirst name: %s\n", serat->fname); //prints employee's name
            printf("\tLast name: %s\n", serat->lname); //prints employee's Id
            printf("\tDependants[%d]: ", serat->numDependents); //prints employee's dependants

            //goes through the loop to print the names of the dependants
            for(int i = 0; i < serat->numDependents; i++){
                printf("%s, ", serat->dependents[i]); //prints the dependants
            }

        }
        printf("\n"); //newline
        
        pos++; //increaments the position
        serat = serat->nextEmployee; //goes to the next employee
    }
}