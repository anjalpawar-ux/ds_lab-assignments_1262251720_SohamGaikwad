#include <stdio.h>
#define size 100

int front = -1;
int rear = -1;

int isfull() { if (rear == size - 1) return 1; return 0; }
int isempty() { if (rear == front) return 1; return 0; }

void AddQ(int q[], int elem) {
    if (isfull()) printf("Queue is full\n");
    else { rear = rear + 1; q[rear] = elem; }
}

int DelQ(int q[]) {
    int elem;
    if (isempty()) { printf("Queue is empty\n"); return -1; }
    else { front = front + 1; elem = q[front]; return elem; }
}

int main() {
    int q[size], choice, elem, val;
    do {
        printf("\n1. Add Print Job\n2. Process Print Job\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Job ID: "); scanf("%d", &elem); AddQ(q, elem); break;
            case 2: val = DelQ(q); if (val != -1) printf("Processed ID: %d\n", val); break;
        }
    } while (choice != 3);
    return 0;
}
