# Program 3

## Data Structures

### struct node
Each node contains:
- `data` - the integer value
- `next` - pointer to the next node

## Functions

### insert(struct node** head, int data)
Creates a new node and adds it at the beginning of the list. The new node becomes the head.

### reversetraversal(struct node* head)
Recursively traverses the list in reverse. It keeps calling itself until it reaches the end, then prints values as it returns back through the recursion stack.

### display(struct node* head)
Normal forward traversal - walks through the list from head to tail and prints each value.

## Main Method

Asks how many elements you want, reads those values, and builds the linked list. Then it shows the list in both forward and reverse order. Since input gets inserted at the beginning each time, the list ends up in reverse order compared to how you entered the numbers. The reverse traversal shows them in the original input order.

## Sample Output

```
how many elements? 5
enter 5 elements:
10
20
30
40
50

forward traversal: 50 40 30 20 10 
reverse traversal: 10 20 30 40 50
```