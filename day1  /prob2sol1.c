#include <stdio.h>

int main() {
    char customerName[100];
    int customerID;
    int unitsConsumed;
    float baseBill = 100.0; // Fixed charge
    float surcharge = 0.0;
    float totalBill;

    printf("Enter Customer Name: ");
    scanf(" %[^\n]s", customerName); // Read with spaces
    printf("Enter Customer ID: ");
    scanf("%d", &customerID);
    printf("Enter Total Units Consumed: ");
    scanf("%d", &unitsConsumed);

    if (unitsConsumed <= 100) {
        baseBill += unitsConsumed * 5.0;
    } else if (unitsConsumed <= 300) {
        baseBill += 100 * 5.0 + (unitsConsumed - 100) * 7.0;
    } else {
        baseBill += 100 * 5.0 + 200 * 7.0 + (unitsConsumed - 300) * 10.0;
    }

    if (baseBill > 1000.0) {
        surcharge = baseBill * 0.05;
        totalBill = baseBill + surcharge;
    } else {
        totalBill = baseBill;
    }

    printf("\nCustomer Name: %s\n", customerName);
    printf("Customer ID: %d\n", customerID);
    printf("Units Consumed: %d\n", unitsConsumed);
    printf("Base Bill: ₹%.1f\n", baseBill);
    printf("Surcharge: ₹%.1f\n", surcharge);
    printf("Total Bill: ₹%.1f\n", totalBill);

    return 0;
}
