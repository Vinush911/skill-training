#include<stdio.h>
void read_details(float* p_salary,int* p_score,int *p_expirience){
    printf("enter salary\n");
    scanf("%f",p_salary);
    
    printf("enter score\n");
    scanf("%d",p_score);
    
    printf("enter expirience\n");
    scanf("%d",p_expirience);
}

int is_eligible(float salary,int score,int expirience){
        return ((salary>=30000)&&(score>=750)&&(expirience>=2));
}
void dotask(){
    float salary;
    int score;
    int expirience;
    read_details(&salary,&score,&expirience);
    if(is_eligible(salary,score,expirience)){
        printf("loan approved ");
    }
    else{
        printf("loan not approved ");
    }
}

int main(){
    int choice;
    do{
        dotask();
        
        printf("\ndo you want to continue?");
        scanf("%d",&choice);
    }while(choice==1);
    return 0;
}
