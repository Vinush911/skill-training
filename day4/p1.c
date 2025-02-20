#include<stdio.h>


struct Employee_t{
    int id;
    char name[20];
    float salary;
    char dept[30];
};

typedef struct Employee_t Employee;

void readEmployee(Employee emp[],int n){
    for (int i=0;i<n;i++){
        printf("enter the - id name salary dept:");
        scanf("%d%s%f%s",&emp[i].id,emp[i].name,&emp[i].salary,emp[i].dept);

    }
}

void displayEmployee(Employee emp[],int n){

    for (int i=0;i<n;i++){
        printf("employee %d details:",i+1);
        
        printf("ID:%d\nNAME:%s\nSALARY:%.2f\nDEPT:%s\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].dept);
    }
}

Employee findHighestSalary(Employee emp[],int n){
    Employee MAX[1000];
    for (int i=0;i<n;i++){
        if(emp[i].salary>emp[i+1].salary){
                MAX[i]=emp[i];
                
        }
        return MAX[i];
    }
}

int main(){
    int employeeCount;
    Employee emp[1000];
    printf("enter the employee count:");
    scanf("%d",&employeeCount);
    
    
    readEmployee(emp,employeeCount);

    displayEmployee(emp,employeeCount);

    Employee highestSalariedEmployee=findHighestSalary(emp,employeeCount);

    printf("highest salaried employee is: %s, %.2f (%s)\n",highestSalariedEmployee.name,highestSalariedEmployee.salary,highestSalariedEmployee.dept);

    return 0;
}
