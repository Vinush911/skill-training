#include <stdio.h>

int main() {
    int numProducts, weight, acceptedCount = 0, rejectedCount = 0;

    printf("Enter number of products: ");
    scanf("%d", &numProducts);

    printf("Enter weights (in grams): ");
    for (int i = 0; i < numProducts; i++) {
        scanf("%d", &weight);
        if (weight >= 950 && weight <= 1050) {
            acceptedCount++;
        } else {
            rejectedCount++;
        }
    }

    printf("Accepted Products: %d\n", acceptedCount);
    printf("Rejected Products: %d\n", rejectedCount);

    return 0;
}
