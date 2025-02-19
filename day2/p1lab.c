#include <stdio.h>
#include <string.h>

float calculateBill(char wardType, int days) {
    float dailyRate;
    float totalBillBeforeDiscount;
    float discount;
    float finalBill;

    switch (wardType) {
        case 'G':
        case 'g':
            dailyRate = 1000.0; 
            break;
        case 'S':
        case 's':
            dailyRate = 2000.0; 
            break;
        case 'P':
        case 'p':
            dailyRate = 5000.0; 
            break;
        default:
            printf("Invalid Ward Type.\n");
            return -1.0;
    }

    totalBillBeforeDiscount = dailyRate ;

    if (days > 7) {
        discount = totalBillBeforeDiscount * 0.05;
    } else {
        discount = 0.0;
    }

    finalBill = totalBillBeforeDiscount - discount;

    printf("Total Bill Before Discount: ₹%.2f\n", totalBillBeforeDiscount);
    printf("Discount Applied: ₹%.2f\n", discount);
    printf("Final Bill Amount: ₹%.2f\n", finalBill);

    return finalBill;
}

int main() {
    char patientName[100];
    char wardType;
    int days;

    printf("Enter Patient Name: ");
    scanf("%s",patientName);

    printf("Enter Ward Type (G/S/P): ");
    scanf(" %c", &wardType);

    printf("Enter Number of Days: ");
    scanf("%d", &days);

    printf("Patient Name: %s\n", patientName);

    calculateBill(wardType, days);

    return 0;
}
