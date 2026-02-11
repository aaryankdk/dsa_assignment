#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if(top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if(top >= 0)
        return stack[top--];
    return '\0';
}

// checks if opening and closing brackets match
int match(char a, char b) {
    if(a == '(' && b == ')') return 1;
    if(a == '[' && b == ']') return 1;
    if(a == '{' && b == '}') return 1;
    return 0;
}

int check(char *expr) {
    int i;
    char c;
    for(i = 0; i < strlen(expr); i++) {
        c = expr[i];
        // push opening brackets to stack
        if(c == '(' || c == '[' || c == '{')
            push(c);
        // checks if closing brackets match
        else if(c == ')' || c == ']' || c == '}') {
            if(top == -1)
                return 0;
            if(!match(pop(), c))
                return 0;
        }
    }
    // balanced if stack is empty at the end
    return top == -1;
}

int main() {
    char expr1[] = "a + (b - c) * (d";
    char expr2[] = "m + [a - b * (c + d * {m)]";
    char expr3[] = "a + (b - c)";
    printf("testing expressions:\n\n");
    printf("expression: %s\n", expr1);
    top = -1;
    if(check(expr1))
        printf("result: balanced\n\n");
    else
        printf("result: not balanced\n\n");
    printf("expression: %s\n", expr2);
    top = -1;
    if(check(expr2))
        printf("result: balanced\n\n");
    else
        printf("result: not balanced\n\n");
    printf("expression: %s\n", expr3);
    top = -1;
    if(check(expr3))
        printf("result: balanced\n\n");
    else
        printf("result: not balanced\n\n");
    return 0;
}