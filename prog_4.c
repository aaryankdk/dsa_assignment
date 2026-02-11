#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertafter(struct node* prevnode, int data) {
    if(prevnode == NULL) {
        printf("previous node cannot be null\n");
        return;
    }
    struct node* newnode = createnode(data);
    newnode->next = prevnode->next;
    newnode->prev = prevnode;
    prevnode->next = newnode;
    if(newnode->next != NULL)
        newnode->next->prev = newnode;
}

void deletenode(struct node** head, struct node* del) {
    if(*head == NULL || del == NULL)
        return;
    if(*head == del)
        *head = del->next;
    if(del->next != NULL)
        del->next->prev = del->prev;
    if(del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}

void display(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* findnode(struct node* head, int data) {
    struct node* temp = head;
    while(temp != NULL) {
        if(temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main() {
    struct node* head = createnode(10);
    head->next = createnode(20);
    head->next->prev = head;
    head->next->next = createnode(30);
    head->next->next->prev = head->next;
    printf("initial list: ");
    display(head);
    printf("\ninsert 25 after 20\n");
    struct node* node20 = findnode(head, 20);
    insertafter(node20, 25);
    printf("list: ");
    display(head);
    printf("\ndelete node with value 20\n");
    node20 = findnode(head, 20);
    deletenode(&head, node20);
    printf("list: ");
    display(head);
    printf("\ninsert 15 after 10\n");
    struct node* node10 = findnode(head, 10);
    insertafter(node10, 15);
    printf("list: ");
    display(head);
    return 0;
}