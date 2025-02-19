
#include <stdio.h>

void displayages(int *ages,int n,int i){
    if (i==n){
        return;
    }
    printf("%d ",ages[i]);
    displayages(ages,n,++i);

}
void displaybackward(int*ages,int n ,int i){
    if (i>=n)
        return;
    displaybackward(ages,n,i+1);
    printf("%d ",ages[i]);
}

int main() {

    int ages[10]={45,42,14,20,70};
    displayages(ages,5,0);
    printf("\n");
    displaybackward(ages,5,0);
    return 0;
}
