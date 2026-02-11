# Program 1

## Data Structures

The program uses a character array to implement a stack with a maximum capacity of 100 elements. The `top` variable tracks the current position in the stack and is initialized to -1 to represent an empty stack.

## Function

**push(char c)**  
Adds a character to the top of the stack if space is available.

**pop()**  
Removes and returns the character at the top of the stack. Returns a null character if the stack is empty.

**match(char a, char b)**  
Compares two brackets to determine if they form a valid matching pair: `()`, `[]`, or `{}`. Returns 1 for a match, 0 otherwise.

**check(char *expr)**  
The main validation function that processes the expression character by character. Opening brackets are pushed onto the stack. When a closing bracket is encountered, the function pops from the stack and verifies the match. Returns 1 if the expression is balanced, 0 if not.

## Main Method

The main function tests three different mathematical expressions as specified in the assignment. For each expression, it:
- Prints the expression being tested
- Resets the stack to empty state
- Calls the check function
- Displays whether the expression is balanced

## Sample Output

```
testing expressions:

expression: a + (b - c) * (d
result: not balanced

expression: m + [a - b * (c + d * {m)]
result: not balanced

expression: a + (b - c)
result: balanced
```
