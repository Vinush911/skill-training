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
        printf("enter employee[%d] details:\n id \n name \n salary \n dept \n",i+1);
        scanf("%d%s%f%s",&emp[i].id,emp[i].name,&emp[i].salary,emp[i].dept);

    }
}

void displayEmployee(Employee emp[],int n){
    printf("employees \tID\tNAME\tSALARY\t\tDEPT\n");
    printf("****************************************************\n");
    for (int i=0;i<n;i++){

        printf("employee %d\t",i+1);
        
        printf("%d\t%s\t%.2f\t%s\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].dept);
    }
}

Employee findHighestSalary(Employee emp[],int n){
    Employee MAX;
    for (int i=0;i<n;i++){
        if(emp[i].salary>emp[i+1].salary){
                MAX=emp[i];
                
        }
        return MAX;
    }
}

void saveEmployee(Employee emp[],int n){
    FILE *file=fopen("employee.txt","w");
    if (file==NULL){
        printf("cannot create file.\n");
        return;
    }
    for (int i=0;i<n;i++){
        fprintf(file, "%d %s %f %s\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].dept);
    }
    fclose(file);
}

void loadEmployee(Employee emp[],int n){
    FILE *file=fopen("employee.txt","r");
    if (file==NULL){
        printf("cannot create file.\n");
        return;
    }
    for (int i=0;i<n;i++){
        fscanf(file," %d %s %f %s\n",&emp[i].id,emp[i].name,&emp[i].salary,emp[i].dept);
    }
    fclose(file);
}

int main(){
    int employeeCount;
    Employee emp[1000];
    printf("enter the employee count:");
    scanf("%d",&employeeCount);
    
    
    readEmployee(emp,employeeCount);
    saveEmployee(emp,employeeCount);
    loadEmployee(emp,employeeCount);
    displayEmployee(emp,employeeCount);

    Employee highestSalariedEmployee=findHighestSalary(emp,employeeCount);
    printf("highest salaried employee is: %s %f [%s] \n",highestSalariedEmployee.name,highestSalariedEmployee.salary,highestSalariedEmployee.dept);
    

    return 0;
}
