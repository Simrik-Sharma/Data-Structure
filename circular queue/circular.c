#include <stdio.h>
#define N 5

int deque[N];
int front = -1;
int rear = -1;

void enqueuefront(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[front] = x;
    } else if (front == 0) {
        front = N - 1;
        deque[front] = x;
    } else {
        front--;
        deque[front] = x;
    }
}

void enqueuerear(int x) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        deque[rear] = x;
    } else if (rear == N - 1) {
        rear = 0;
        deque[rear] = x;
    } else {
        rear++;
        deque[rear] = x;
    }
}

void dequeuefront() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Deleted element = %d\n", deque[front]);
        front = rear = -1;
    } else if (front == N - 1) {
        printf("Deleted element = %d\n", deque[front]);
        front = 0;
    } else {
        printf("Deleted element = %d\n", deque[front]);
        front++;
    }
}

void dequeuerear() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Deleted element = %d\n", deque[rear]);
        front = rear = -1;
    } else if (rear == 0) {
        printf("Deleted element = %d\n", deque[rear]);
        rear = N - 1;
    } else {
        printf("Deleted element = %d\n", deque[rear]);
        rear--;
    }
}

void displayFrontToRear() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements from front to rear: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % N;
    }
    printf("\n");
}

void displayRearToFront() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements from rear to front: ");
    int i = rear;
    while (1) {
        printf("%d ", deque[i]);
        if (i == front)
            break;
        i = (i - 1 + N) % N;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nChoose the operation you want to operate:\n");
        printf("1. Insert from front\n");
        printf("2. Insert from rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display front to rear\n");
        printf("6. Display rear to front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int x;
                printf("Enter the element to insert from front: ");
                scanf("%d", &x);
                enqueuefront(x);
                break;
            }
            case 2: {
                int x;
                printf("Enter the element to insert from rear: ");
                scanf("%d", &x);
                enqueuerear(x);
                break;
            }
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                displayFrontToRear();
                break;
            case 6:
                displayRearToFront();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
