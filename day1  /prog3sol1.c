#include <stdio.h>
#include<string.h>
int main() {
    char vehicleType[10];
    int distance;
    float baseCharge, discount = 0, totalTax;

    printf("Enter Vehicle Type (Car/Truck/Bus): ");
    scanf("%s", vehicleType);

    printf("Enter Distance Traveled: ");
    scanf("%d", &distance);

    if (strcmp(vehicleType, "Car") == 0) {
        baseCharge = distance * 5;
    } else if (strcmp(vehicleType, "Truck") == 0) {
        baseCharge = distance * 10;
        if (distance > 500) {
            discount = baseCharge * 0.10;
        }
    } else if (strcmp(vehicleType, "Bus") == 0) {
        baseCharge = distance * 8;
        if (distance > 300) {
            discount = baseCharge * 0.05;
        }
    } else {
        printf("Invalid vehicle type.\n");
        return 1;
    }

    totalTax = baseCharge - discount;

    printf("Vehicle Type: %s\n", vehicleType);
    printf("Distance Traveled: %d km\n", distance);
    printf("Base Charge: ₹%.2f\n", baseCharge);
    printf("Discount: ₹%.2f\n", discount);
    printf("Total Toll Tax: ₹%.2f\n", totalTax);

    return 0;
}
