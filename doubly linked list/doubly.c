#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL, *tail = NULL;
void createList(int n) {
    int i, data;
    struct Node *newNode;

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}
void insertAtFront(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = tail;
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtPosition(int data, int pos) {
    int i;
    struct Node *newNode, *temp = head;
    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertAtFront(data);
        return;
    }
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        insertAtEnd(data);
        return;
    }
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;

    if (newNode->next == NULL)
        tail = newNode;
}
void deleteAtFront() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;
    free(temp);
}
void deleteAtEnd() {
    struct Node *temp;
    if (tail == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = tail;
    tail = tail->prev;
    if (tail != NULL)
        tail->next = NULL;
    else
        head = NULL;
    free(temp);
}
void deleteByValue(int value) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }
    if (temp == head)
        deleteAtFront();
    else if (temp == tail)
        deleteAtEnd();
    else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}
void displayList() {
    struct Node *temp = head;

    printf("\nList: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, n, data, pos, value;
    while (1) {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Front\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Delete at Front\n");
        printf("6. Delete at End\n");
        printf("7. Delete by Value\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteAtFront();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 8:
                displayList();
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
