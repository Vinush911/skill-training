#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int countPatternOccurrences(char dna[], char pattern[]) {
    int count = 0;
    int dnaLen = strlen(dna);
    int patternLen = strlen(pattern);
    
    for (int i = 0; i <= dnaLen - patternLen; i++) {
        if (strncmp(&dna[i], pattern, patternLen) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    char dna[MAX_LENGTH], pattern[MAX_LENGTH];
    
    printf("Enter DNA Sequence: ");
    scanf("%s", dna);
    
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    
    int occurrences = countPatternOccurrences(dna, pattern);
    printf("Pattern found %d time(s) in the DNA sequence.\n", occurrences);
    
    return 0;
}
