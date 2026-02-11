#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

void infixtopostfix(char* infix, char* postfix) {
    int j = 0;
    top = -1;
    for(int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];
        if(ch == ' ')
            continue;
        if(isalnum(ch))
            postfix[j++] = ch;
        else if(ch == '(')
            push(ch);
        else if(ch == ')') {
            while(top >= 0 && peek() != '(')
                postfix[j++] = pop();
            pop();
        }
        else {
            while(top >= 0 && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }
    while(top >= 0)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int evaluate(char* postfix) {
    int stack[MAX];
    int top = -1;
    for(int i = 0; i < strlen(postfix); i++) {
        char ch = postfix[i];
        if(isdigit(ch))
            stack[++top] = ch - '0';
        else {
            int b = stack[top--];
            int a = stack[top--];
            int result;
            
            switch(ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            stack[++top] = result;
        }
    }
    return stack[top];
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = 0;
    infixtopostfix(infix, postfix);
    printf("postfix: %s\n", postfix);
    printf("evaluate? (use single digits only) (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y') {
        int result = evaluate(postfix);
        printf("result: %d\n", result);
    }
    return 0;
}
