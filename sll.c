#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtFirst();
void insertAtEnd(); 
void insertAtPosition();  
void deleteAtFirst();
void deleteAtLast();
void deleteAtPosition(); 
void display();

struct node *temp, *newnode, *prevnode;

int main() {
    int ch;

    while (1) {
        printf("---Menu---\n");
        printf("1.Insert at first\n");
        printf("2.Insert at end\n");
        printf("3.Insert at position\n");
        printf("4.Delete at first\n");
        printf("5.Delete at last\n");
        printf("6.Delete at position\n");
        printf("7.Display\n");
        printf("8.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertAtFirst();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition(); 
                break;
            case 4:
                deleteAtFirst();
                break;
            case 5:
                deleteAtLast();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                display();
                break;
            case 8:  
                printf("Exiting.....\n");
                exit(0);
            default:
                printf("Invalid choice.");
        }
    }

    return 0;
}

void insertAtFirst() {
    newnode = malloc(sizeof(struct node));
    printf("Enter value to insert at first:");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void insertAtEnd() {
    newnode = malloc(sizeof(struct node));
    printf("Enter value to insert at first:");
    scanf("%d", &newnode->data);
    if (head == NULL) {
        head = newnode;
        newnode->next = NULL;
    } else {
        temp=head;
     while(temp->next!=NULL)
     {
        temp=temp->next;
     }
     temp->next=newnode;
     newnode->next=NULL;
    }

}

void insertAtPosition() {
    int pos, count;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    printf("Enter the position to insert at (starting from 1): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position. Position must be >= 1\n");
        free(newNode);
        return;
    }

    // Inserting at the first position
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        temp = head;
        count = 1; // Position tracking starts from 1
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            printf("Position out of range\n");
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}



void deleteAtFirst() {
    if (head == NULL) {
        printf("List is empty");
    } else {
        temp = head;
        head = head->next;  
        free(temp);
        printf("First node is deleted.\n");
    }
}

void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty");
    } else {
        temp = head;
        if (head->next == NULL) {
            head = NULL;
            free(temp);
        } else {
            while (temp->next != NULL) {  
                prevnode = temp;
                temp = temp->next;       
            }
            prevnode->next = NULL;
            free(temp);
        }
        printf("Last node is deleted.\n");
    }
}

void deleteAtPosition() {
    int pos, count;
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the position to delete from (starting from 1): ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position. Position must be >= 1\n");
        return;
    }

    // Deleting the first node
    if (pos == 1) {
        temp = head;
        head = head->next;
        printf("Deleted node value: %d\n", temp->data);
        free(temp);
    } else {
        temp = head;
        count = 1;

        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range\n");
        } else {
            prev = temp->next;
            temp->next = prev->next;
            printf("Deleted node value: %d\n", prev->data);
            free(prev);
        }
    }
}

void display() {
    int i = 1;

    temp = head;
    printf("Address of head: %p", head);

    if (head == NULL) {
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
