# Program 2: Infix to Postfix Conversion and Evaluation

## Data Structures

Two different stacks are used:
- Character stack (global) - for converting infix to postfix
- Integer stack (local to evaluate function) - for calculating the result

## Functions

### push(char c)
Adds an operator to the stack during conversion.

### pop()
Removes and returns the top operator from the stack.

### peek()
Returns the top operator without removing it. Useful for checking precedence.

### precedence(char op)
Returns the precedence level for operators. Multiplication and division get priority 2, addition and subtraction get priority 1.

### infixtopostfix(char* infix, char* postfix)
Converts an infix expression to postfix notation. The algorithm scans left to right - operands go straight to output, operators get pushed to the stack based on their precedence. Parentheses are handled by keeping operators on the stack until the closing parenthesis is found.

### evaluate(char* postfix)
Evaluates a postfix expression and returns the result. It uses a stack to store intermediate values. When it sees a number, it pushes it. When it sees an operator, it pops two numbers, performs the operation, and pushes the result back.

## Main Method

The program prompts for an infix expression, converts it to postfix, and displays the result. It then asks if you want to evaluate it (only works with single-digit numbers). If you choose yes, it calculates and shows the final result.

## Sample Output

```
enter infix expression: 3+5*2
postfix: 352*+
evaluate? (use single digits only) (y/n): y
result: 13

enter infix expression: (2+3)*4
postfix: 23+4*
evaluate? (use single digits only) (y/n): y
result: 20
```