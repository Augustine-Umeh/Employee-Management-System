#include "../include/headerA3.h"

void fireOne(a3Emp **headLL, int whichOne){

    //declares variables
    a3Emp * serat = *headLL;
    a3Emp * prev = NULL;

    int count = 1; //sets count to one

    //if there are no employees
    if(serat == NULL){
        
        printf("There are no employees to fire.\n"); //prints there are no employees
        return;
    }
    
    //if the user input is greater than the total number of employees
    if(whichOne > countEmployees(serat)){

        printf("\nThis position does not exist\n"); //prints this statement
        return;
    }

    printf("\nCurrently there are %d employees.\n\n", countEmployees(serat)); //prints the employees before it gets fired

    //goes through the loop if not NULL
    while(serat != NULL && count != whichOne){

        prev = serat; //previous equals the next
        serat = serat->nextEmployee; //goes to the next employee
        count++; //count variable
    }

    //if previous employee has nothing
    if(prev == NULL) {

        *headLL = serat->nextEmployee; //take the position of the next

    }else{

        prev->nextEmployee = serat->nextEmployee; //remain in the same position

    }

    printf("Employee [Id: %d] fired.\n", serat->empId); //prints the employee that was fired
    free(serat); //free's serat

}
