#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

// Function prototypes
void calculateTotalMarks(int marks[][MAX_SUBJECTS], int n, int totalMarks[]);
void sortStudents(int totalMarks[], int n);

int main() {
    int n, m;
    int marks[MAX_STUDENTS][MAX_SUBJECTS];
    int totalMarks[MAX_STUDENTS];

    // Read number of students and subjects
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter number of subjects: ");
    scanf("%d", &m);

    // Read marks for each student
    for (int i = 0; i < n; i++) {
        printf("Enter marks for Student %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    // Calculate total marks for each student
    calculateTotalMarks(marks, n, totalMarks);

    // Sort students based on total marks
    sortStudents(totalMarks, n);

    // Display total marks for each student in sorted order
    printf("\nSorted Total Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Total Marks = %d\n", i + 1, totalMarks[i]);
    }

    return 0;
}

// Function to calculate total marks for each student
void calculateTotalMarks(int marks[][MAX_SUBJECTS], int n, int totalMarks[]) {
    for (int i = 0; i < n; i++) {
        totalMarks[i] = 0; // Initialize total marks for the student
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            totalMarks[i] += marks[i][j];
        }
    }
}

// Function to sort students based on total marks in descending order
void sortStudents(int totalMarks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (totalMarks[j] < totalMarks[j + 1]) {
                // Swap total marks
                int temp = totalMarks[j];
                totalMarks[j] = totalMarks[j + 1];
                totalMarks[j + 1] = temp;
            }
        }
    }
}
