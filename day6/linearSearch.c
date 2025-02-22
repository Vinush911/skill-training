#include<stdio.h>

int searchLinear(float* salary ,int size,float searchSalary);
int searchBinary(float* salary ,int size,float searchSalary);

int main(){
    float salary[]={20.0f,10.0f,13.0f,15.0f,12.0f};
    int salaryCount=5;
    float searchSalary=12.0f;
    int index =searchLinear(salary,salaryCount,searchSalary);
    printf("%.2f found at %d\n",searchSalary,  index);
    return 0;
}

int searchLinear(float* salary ,int size,float searchSalary){
    for (int i=0;i<size;i++){
        if(salary[i]==searchSalary){
            return i;
        }
    }
    return -1;
}
