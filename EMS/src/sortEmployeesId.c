#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL){

    //declares variables
    a3Emp * serat = headLL;
    char tempFname[MAX_LENGTH];
    char tempLname[MAX_LENGTH];
    int tempEmpId;
    int tempNumDependents;
    char ** tempDependents;
    int swap;

    //if head contains nothig
    if(headLL == NULL){
        
        printf("\nThere list doesn't contain any employee\n\n"); //prints if there are no empoyee
        return;
    }

    //if next emploee contains nothing
    if(headLL->nextEmployee == NULL){

        printf("Only one employee. Cannot sort. \n"); //prints this if its only one employee
        return;
    }

    do{
        swap = 0; //sets swap to 0
        serat = headLL; //serat takes headLL
        
        //goes through the loop if not NULL
        while(serat->nextEmployee != NULL){
            
            //if the current employee's Id is greater than the next employee's Id
            if(serat->empId > serat->nextEmployee->empId){
                
                tempEmpId = serat->empId; //temp variables takes position of current employee
                serat->empId = serat->nextEmployee->empId; //current variable takes the place of next employee
                serat->nextEmployee->empId = tempEmpId; //next employee takes the place of current employee

                strcpy(tempFname, serat->fname); //copy's first name to temp variable
                strcpy(serat->fname, serat->nextEmployee->fname); //copy's next employee to first name variable
                strcpy(serat->nextEmployee->fname, tempFname); //copy's first name to next employee

                strcpy(tempLname, serat->lname); //copy's last name to temp variable
                strcpy(serat->lname, serat->nextEmployee->lname); //copy's next employee to last name variable
                strcpy(serat->nextEmployee->lname, tempLname); //copy's last name to next employee

                tempNumDependents = serat->numDependents; //temp variables takes position of current employee
                serat->numDependents = serat->nextEmployee->numDependents; //current variable takes the place of next employee
                serat->nextEmployee->numDependents = tempNumDependents; //next employee takes the place of current employee

                tempDependents = serat->dependents; //temp variables takes position of current employee
                serat->dependents = serat->nextEmployee->dependents; //current variable takes the place of next employee
                serat->nextEmployee->dependents = tempDependents; //next employee takes the place of current employee

                swap = 1; //swap equals 1
            }
            
            serat = serat->nextEmployee; //goes to next employee
        }

    }while(swap != 0); //while swap doesn't equal 0
    
    printAll(headLL); //prints the sorted employees
}