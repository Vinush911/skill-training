#include<stdio.h>
struct student{
    char Name[30];
    int Marks;
};

typedef struct student s;
void readStudent( s student[],int length){
    for (int i=0;i<length;i++){
        printf("student %d Name:",i+1);
        scanf("%s",student[i].Name);
        printf("student Marks:");
        scanf("%d",&student[i].Marks);
    }
}

void printStudent(s student[],int length){
    printf("student recodes:");
    for (int i=0;i<length;i++){
        printf("%s - %d\n",student[i].Name,student[i].Marks);
    }
}

int main(){

    s student[100];
    int studentCount;

    printf("enter the number of students:");
    scanf("%d",&studentCount);
    readStudent(student,studentCount);
    printStudent(student,studentCount);
    

    return 0;
}
