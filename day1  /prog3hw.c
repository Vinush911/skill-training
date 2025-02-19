
#include <stdio.h>
#include <string.h>

int main() {
    int method, bank;
    char cardNumber[17];
    char upiID[50];
    
    // Prompt the user to select a payment method
    printf("Select Payment Method (1-3):\n");
    printf("1. Credit/Debit Card\n2. UPI\n3. Net Banking\n");
    scanf("%d", &method);
    
    switch (method) {
        case 1:
            printf("Enter your 16-digit card number: ");
            scanf("%16s", cardNumber);
            if (strlen(cardNumber) == 16) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
        
        case 2:
            printf("Enter your UPI ID: ");
            scanf("%s", upiID);
            if (strchr(upiID, '@') != NULL) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
        
        case 3:
            printf("Select your bank:\n1. SBI\n2. HDFC\n");
            scanf("%d", &bank);
            if (bank == 1 || bank == 2) {
                printf("Payment Successful!\n");
            } else {
                printf("Transaction Failed. Please try again.\n");
            }
            break;
        
        default:
            printf("Invalid payment method. Please try again.\n");
    }
    
    return 0;
}
