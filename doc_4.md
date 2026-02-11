# Program 4

## Data Structures

### struct node
Each node has three parts:
- `data` - integer value
- `next` - pointer to the next node
- `prev` - pointer to the previous node

Having links in both directions makes insertion and deletion more efficient.

## Functions

### createnode(int data)
Allocates memory for a new node, sets the data, and initializes both pointers to NULL.

### insertafter(struct node* prevnode, int data)
Inserts a new node right after the given node. It updates four pointers - the new node's next and prev, the previous node's next, and the following node's prev (if it exists).

### deletenode(struct node** head, struct node* del)
Removes a node from the list. It connects the surrounding nodes to each other, then frees the deleted node's memory. Handles edge cases like deleting the head or the last node.

### display(struct node* head)
Walks through the list and prints each value.

### findnode(struct node* head, int data)
Helper function that searches for a node with a specific value. Returns the node pointer if found, NULL otherwise.

## Main Method

Creates a sample list with values 10, 20, and 30. Then demonstrates:
- Inserting 25 after the node containing 20
- Deleting the node with value 20
- Inserting 15 after the node containing 10

## Sample Output

```
initial list: 10 20 30 

insert 25 after 20
list: 10 20 25 30 

delete node with value 20
list: 10 25 30 

insert 15 after 10
list: 10 15 25 30
```