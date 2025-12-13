#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *head2 = NULL;  // For second list (used in concatenation)

// ------------------- Create List ----------------------
void createList(int n) {
    struct Node *newNode, *temp;
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
    }

    printf("\nLinked list created successfully.\n");
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
void sortList() {
    struct Node *i, *j;
    int temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
    printf("Sorted List: ");
    displayList(head);
}
void reverseList() {
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;

    printf("List reversed successfully.\n");
    printf("Reversed List: ");
    displayList(head);
}
void createSecondList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head2 == NULL) {
            head2 = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    printf("Second list created.\n");
}
void concatenate() {
    if (head == NULL) {
        head = head2;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = head2;
    }
    printf("Lists concatenated successfully.\n");
    printf("\nConcatenated List: ");
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Create Linked List\n");
        printf("2. Display List\n");
        printf("3. Sort List\n");
        printf("4. Reverse List\n");
        printf("5. Create Second List\n");
        printf("6. Concatenate with Second List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;

            case 3:
                sortList();
                break;

            case 4:
                reverseList();
                break;

            case 5:
                printf("Enter number of nodes for second list: ");
                scanf("%d", &n);
                createSecondList(n);
                break;

            case 6:
                concatenate();
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
