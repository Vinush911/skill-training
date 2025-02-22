#include<stdio.h>

int searchBinary(float* salary ,int size,float searchSalary);

int main(){
    float salary[]={10.0f,12.0f,13.0f,15.0f,20.0f};
    int salaryCount=5;
    float searchSalary=12.0f;
    int index =searchBinary(salary,salaryCount,searchSalary);
    printf("%.2f found at %d\n",searchSalary,  index);
    return 0;
}

int searchBinary(float* salary ,int size,float searchSalary){
    int left =0,right=size-1;
    while (left<=right){
        int mid=(left+right)/2;
        if(salary[mid]==searchSalary){
            return mid;
        }
        else if(searchSalary<=salary[mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
    
}
