#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
void enqueue();
void dequeue();
void display();

struct node *temp, *newnode;
struct node *front = NULL, *rear = NULL;
void enqueue()
{
    newnode = malloc(sizeof(struct node));
    printf("Enter value to enqueue:");
    scanf("%d", &newnode->data);
    if (rear == NULL && front==NULL) {
        rear = newnode;
        newnode->next = NULL;
    } else {
        temp=rear;
        while(temp->next!=NULL)
        {
        temp=temp->next;
        }
        temp->next=newnode;
        newnode->next = NULL;
       
    }
}
void dequeue() {
    if (front == NULL) {
        printf("List is empty");
    } else {
        temp = front;
        front = front->next;  
        free(temp);
        printf("First node is deleted.\n");
    }
}
void display() {
    int i = 1;

    temp = front;
    printf("Address of head: %p",rear);

    if (front == NULL) {
        printf("List is empty");
    } else {
        printf("The linked list is :\n");
        while (temp != NULL) {
            printf("Node %d: Data: %d  Address: %p  Next Address: %p\n", i, temp->data, temp, temp->next);
            temp = temp->next;
            i++;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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
