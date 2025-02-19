#include <stdio.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct {
    char name[50];
    int age;
    char destination[50];
} Passenger;

void sortPassengers(Passenger passengers[], int n) {
    Passenger temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(passengers[j].destination, passengers[j + 1].destination) > 0) {
                temp = passengers[j];
                passengers[j] = passengers[j + 1];
                passengers[j + 1] = temp;
            }
        }
    }
}

void searchByDestination(Passenger passengers[], int n, char searchDest[]) {
    int found = 0;
    printf("Passengers traveling to %s:\n", searchDest);
    for (int i = 0; i < n; i++) {
        if (strcmp(passengers[i].destination, searchDest) == 0) {
            printf("%s\n", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found traveling to %s.\n", searchDest);
    }
}

int main() {
    int n;
    printf("Enter number of passengers: ");
    scanf("%d", &n);
    getchar(); // Clear newline from buffer

    Passenger passengers[MAX_PASSENGERS];
    
    for (int i = 0; i < n; i++) {
        printf("Passenger %d (Name, Age, Destination): ", i + 1);
        scanf("%[^,], %d, %[^\n]", passengers[i].name, &passengers[i].age, passengers[i].destination);
        getchar(); // Clear newline from buffer
    }
    
    sortPassengers(passengers, n);
    
    printf("\nSorted List (by destination):\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", passengers[i].name, passengers[i].destination);
    }
    
    char searchDest[50];
    printf("\nEnter destination to search: ");
    scanf("%s", searchDest);
    
    searchByDestination(passengers, n, searchDest);
    
    return 0;
}
