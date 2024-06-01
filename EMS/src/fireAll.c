#include "../include/headerA3.h"

void fireAll(a3Emp ** headLL){

    //declares variables
    a3Emp * serat = *headLL;
    char option = 'y';

    printf("Are you sure you want to fire everyone: "); //prompts for user input
    scanf(" %c", &option); //validates user input

    //goes through the list
    while (serat != NULL){

        *headLL = serat; //head holds serat

        //if option equals y
        if(option == 'y' || option == 'Y'){

            free(*headLL); //free head

            *headLL = NULL; //fill all content with NULL
        
            //if option equals n
        }else if(option == 'n' || option == 'N'){

            printf("No Employee was fired.\n"); //print no employee was fired
            
            return;
        }else{

            return;
        }
        serat = serat->nextEmployee; //goes to next employee
        
    }

    printf("All fired. Linked list is now empty.\n"); //prints all employees have been fired
}