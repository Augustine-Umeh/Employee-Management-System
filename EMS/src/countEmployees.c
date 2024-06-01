#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL){

    //declare variables
    a3Emp * serat = headLL;
    int pos = 0;

    //goes through the loop if not NULL
    while(serat != NULL){

        serat = serat->nextEmployee; //goes to the next employee
        pos++; //counts how many employee
    }

    return pos; //returns the number of employeees
}