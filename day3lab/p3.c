#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 1000


int isPalindrome(char str[]);

int main() {
    char str[MAX_LENGTH];

    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    
    str[strcspn(str, "\n")] = 0;

    
    if (isPalindrome(str)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}


int isPalindrome(char str[]) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        if (tolower(str[left]) != tolower(str[right])) {
            return 0; 
        }
        left++;
        right--;
    }

    return 1;
}
