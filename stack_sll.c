#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    printf("Enter data to push: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
    printf("Pushed %d onto the stack.\n", newnode->data);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty (Underflow).\n");
    } else {
        struct node *temp = top;
        printf("Popped element: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display() {
    struct node *temp = top;
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        while (temp != NULL) {
            printf("| %d |\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
