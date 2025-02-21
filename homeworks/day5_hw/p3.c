#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char urls[MAX][100];
    int top;
} Stack;

void push(Stack *s, const char *url) {
    if (s->top < MAX - 1) {
        strcpy(s->urls[++s->top], url);
    }
}

char* pop(Stack *s) {
    if (s->top >= 0) {
        return s->urls[s->top--];
    }
    return NULL;
}

char* peek(Stack *s) {
    if (s->top >= 0) {
        return s->urls[s->top];
    }
    return NULL;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main() {
    Stack backStack = {.top = -1}, forwardStack = {.top = -1};
    char current[100] = "";

    // Visiting pages
    strcpy(current, "google.com");
    printf("Visited: %s\n", current);
    push(&backStack, current);
    
    strcpy(current, "github.com");
    printf("Visited: %s\n", current);
    push(&backStack, current);
    
    strcpy(current, "stackoverflow.com");
    printf("Visited: %s\n", current);
    push(&backStack, current);
    
    // Go Back
    if (!isEmpty(&backStack)) {
        push(&forwardStack, pop(&backStack));
        strcpy(current, peek(&backStack));
        printf("\nAction: Go Back\nCurrent Page: %s\n", current);
    }
    
    // Go Forward
    if (!isEmpty(&forwardStack)) {
        push(&backStack, pop(&forwardStack));
        strcpy(current, peek(&backStack));
        printf("\nAction: Go Forward\nCurrent Page: %s\n", current);
    }

    return 0;
}
