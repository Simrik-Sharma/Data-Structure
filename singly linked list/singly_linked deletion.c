#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList(int n) {
    struct Node *newNode, *temp = NULL;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    } // ← Missing brace added
} // ← Function closing brace added

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end.\n");
}

void insertAtPosition(int data, int pos) {
    int i;
    struct Node *newNode, *temp = head;

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", pos);
    }
}

void displayList() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteatfirst() {
    struct Node *temp;
    if (head == NULL) {
        printf("The list is empty. Nothing to delete\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteatlast() {
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("The list is empty. Nothing to delete\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted element: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void deleteatspecific(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("The list is empty. Nothing to delete\n");
        return;
    }
    if (head->data == value) {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list\n", value);
        return;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

int main() {
    int choice, n, data, pos, value;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Any Position\n");
        printf("4. Insert at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete Specific Element\n");
        printf("7. Delete at End\n");
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
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;

            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 5:
                deleteatfirst();
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteatspecific(value);
                break;

            case 7:
                deleteatlast();
                break;

            case 8:
                displayList();
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
