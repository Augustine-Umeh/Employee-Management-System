#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 25

/* definition of an employee record*/
struct employee
{
   char fname[MAX_LENGTH];
   char lname[MAX_LENGTH];
   int empId;              // this is auto-generated by the program
   int numDependents;
   char  ** dependents;    // this array is dynamically allocated
   struct employee * nextEmployee;          
};

typedef struct employee a3Emp;

//function prototypes
void recruitEmployee (struct employee ** headLL);
void printAll (struct employee * headLL);
void printOne (struct employee * headLL, int whichOne);
int lookOnId (struct employee * headLL, int whichEmpId);
int lookOnFullName (struct employee * headLL, char whichName [100]);
void loadEmpData (struct employee ** headLL, char fileName [MAX_LENGTH]);
int countEmployees (a3Emp * headLL);
void sortEmployeesId (struct employee * headLL);
void fireAll(a3Emp ** headLL);
void fireOne (a3Emp ** headLL, int whichOne);