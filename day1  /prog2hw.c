#include <stdio.h>

int main() {
    int N;
    
    // Prompt the user to enter the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &N);
    
    // Print the right-angled triangle
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
