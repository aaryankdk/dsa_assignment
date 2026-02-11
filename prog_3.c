#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}

void reversetraversal(struct node* head) {
    if(head == NULL)
        return;
    reversetraversal(head->next);
    printf("%d ", head->data);
}

void display(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    int n, value;
    printf("how many elements? ");
    scanf("%d", &n);
    printf("enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&head, value);
    }
    printf("\nforward traversal: ");
    display(head);
    printf("reverse traversal: ");
    reversetraversal(head);
    printf("\n");
    return 0;
}