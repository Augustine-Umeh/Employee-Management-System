#include "../include/headerA3.h"

int lookOnFullName(struct employee * headLL, char whichName [100]){

    //declares variables
    a3Emp * serat = headLL;
    char joint[100] = {'\0'};
    
    //if there is nothing in the linked list
    if(serat == NULL){

        printf("This list doesn't contain anything"); //prints if list doesn't contain anything
    }

    //goes through the loop if not NULL
    while(serat != NULL){

        //goes through the list and set all to null
        for(int i = 0; i < 100; i++){

            joint[i] = '\0'; //makes all the list null
        }

        // //if there is no similarities
        // if(strcmp(joint, whichName) != 0){

        //     printf("\nThe employee's name doesn't exist\n"); //prints the statement when the strings are not the same
        // }

        strcpy(joint, serat->fname); //copy first name to joint
        joint[strlen(joint)] = ' '; //add a space on the last character of the first name
        strcat(joint, serat->lname); //add the last to the first name

        //if the two strings are the same
        if(strcmp(joint, whichName) == 0){

            printf("\n"); //newline
            printf("\tEmployee Id: %d\n", serat->empId); //prints employee's Id
            printf("\tFirst name: %s\n", serat->fname); //prints employee's name
            printf("\tLast name: %s\n", serat->lname); //prints employee's Id
            printf("\tDependants[%d]: ", serat->numDependents); //prints employee's dependants

            //goes through the loop to print the dependents
            for(int i = 0; i < serat->numDependents; i++){
                printf("%s, ", serat->dependents[i]); //prints the dependants
            }

            printf("\n"); //newline

        }

        serat = serat->nextEmployee; //goes to next employee
    }

    //if there is no similarities
    if(strcmp(joint, whichName) != 0){

        printf("\nThe employee's name doesn't exist\n"); //prints the statement when the strings are not the same
    }

    return 0; //return statement
}