#include<stdio.h>
#include<string.h>


int main(){
    char name[100];
    int id;
    float salary;
    int total_days;
    
    
    //read employee details
    printf("enter the id\n");
    scanf("%d",&id);
    printf("enter the name\n");
    scanf("%s",name);
    printf("enter the salary \n");
    scanf("%f",&salary);
    printf("enter the number of days \n");
    scanf("%d",&total_days);
    
    //process payroll
    float bonus=0.0f;
    float gross_salary=0.0f;
    char category[50]="good";
    
    //calculate bonus
    if (total_days>25){
        bonus=(salary/100.0f)*5.0f;
    
    }
    else if (total_days<10){
        bonus=(-1.0f*(salary/100.0f)*50.0f);
    
    }else{
        bonus=0;
    }

    
    //final salary
    gross_salary=(salary+bonus);
    
    //categorize employee
    if (total_days>25){
        strcpy(category,"excellent");
    }
    else if(total_days<15) {
        strcpy(category,"need improvement ");
    }
    
    //display payroll details
    printf("Id:%d\n",id);
    printf("name:%s\n",name);
    printf("basic salary:%.2f\n",salary);
    if (bonus>0){
        printf("bonus:%.2f\n",bonus);
    }
    
    printf("employee performace category:%s\n",category);
    printf("final salary :%f",gross_salary);
    return 0;
    
}
