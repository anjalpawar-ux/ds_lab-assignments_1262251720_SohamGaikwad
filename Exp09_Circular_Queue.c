#include <stdio.h>
#define n 5

int front = 0;
int rear = 0;
int Q[n];

void AddCQ(int elem) {
    if ((rear + 1) % n == front) printf("queue full\n");
    else { rear = (rear + 1) % n; Q[rear] = elem; }
}

int DelCQ() {
    int elem;
    if (front == rear) { printf("queue empty\n"); return -1; }
    else { front = (front + 1) % n; elem = Q[front]; return elem; }
}

void displayCQ() {
    if (front == rear) printf("queue empty\n");
    else {
        int i = (front + 1) % n;
        printf("Pending Jobs: ");
        while (i != (rear + 1) % n) { printf("%d ", Q[i]); i = (i + 1) % n; }
        printf("\n");
    }
}

int main() {
    int choice, elem, val;
    do {
        printf("\n1. Add Job (CQ)\n2. Process Job (CQ)\n3. Display CQ\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Job ID: "); scanf("%d", &elem); AddCQ(elem); break;
            case 2: val = DelCQ(); if(val != -1) printf("Processed ID: %d\n", val); break;
            case 3: displayCQ(); break;
        }
    } while (choice != 4);
    return 0;
}
