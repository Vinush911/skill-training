#include <stdio.h>

#define MAX_MATCHES 100

void findScores(int scores[], int n, int *highest, int *lowest, float *average) {
    *highest = scores[0];
    *lowest = scores[0];
    int sum = scores[0];
    
    for (int i = 1; i < n; i++) {
        if (scores[i] > *highest) {
            *highest = scores[i];
        }
        if (scores[i] < *lowest) {
            *lowest = scores[i];
        }
        sum += scores[i];
    }
    
    *average = (float)sum / n;
}

int main() {
    int n, scores[MAX_MATCHES];
    
    printf("Enter number of matches: ");
    scanf("%d", &n);
    
    printf("Enter scores of %d matches: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }
    
    int highest, lowest;
    float average;
    findScores(scores, n, &highest, &lowest, &average);
    
    printf("\nHighest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
    printf("Average Score: %.2f\n", average);
    
    return 0;
}
