#include<stdio.h>
#include <string.h>

int main() {
    int vehiclecount;
    char vehicletype[10];

    printf("Enter vehicle number:");
    scanf("%d", &vehiclecount);

    float collection= 0;



    for(int I = 1; I <= vehiclecount; I++) {
        printf("Enter vehicle type:");
        scanf("%s", vehicletype);   
        if(strcmp(vehicletype,"car")==0) {
             collection+=50;           
        }
        else if(strcmp(vehicletype,"truck")==0) {
            collection+=100;           
       }
       else if(strcmp(vehicletype,"bike")==0) {
        collection+=20;           
   }
   else{
       printf("entered invalid vehickle name !!!");
   }
    }
    printf("the toll collection:%.0f",collection);

    return 0;
}
