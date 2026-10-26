#include <stdio.h>
#include <stdlib.h>

struct node { int data; struct node *next; };

int len(struct node *H) {
    int i = 0;
    struct node *curr = H->next;
    while (curr != NULL) { i++; curr = curr->next; }
    return i;
}

void create(struct node *H) {
    struct node *temp = H, *curr;
    char choice;
    do {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: "); scanf("%d", &curr->data);
        curr->next = NULL; temp->next = curr; temp = curr;
        printf("Continue? (y/n): "); scanf(" %c", &choice);
    } while (choice == 'y');
}

void display(struct node *H) {
    if (H->next == NULL) printf("list is empty\n");
    else {
        struct node *curr = H->next;
        while (curr != NULL) { printf("%d -> ", curr->data); curr = curr->next; }
        printf("NULL\n");
    }
}

void Insertbypos(struct node *H) {
    int i = 1, pos, k = len(H);
    struct node *curr = H;
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    printf("Data and Pos: "); scanf("%d %d", &nnode->data, &pos);
    if (pos > k + 1) printf("Data can't be inserted\n");
    else {
        while (curr != NULL && i < pos) { i++; curr = curr->next; }
        nnode->next = curr->next; curr->next = nnode;
    }
}

void delpos(struct node *H) {
    struct node *prev = H, *curr = H->next, *temp;
    int ctr = 1, pos, k = len(H);
    printf("Pos to delete: "); scanf("%d", &pos);
    if (k < pos) printf("Data can't be deleted\n");
    else {
        while (ctr < pos && curr != NULL) { ctr++; prev = curr; curr = curr->next; }
        temp = curr; prev->next = curr->next; curr->next = NULL; free(temp);
    }
}

void reverse(struct node *H) {
    struct node *prev = NULL, *curr = H->next, *future;
    while (curr != NULL) { future = curr->next; curr->next = prev; prev = curr; curr = future; }
    H->next = prev;
}

void sort(struct node *H) {
    int l = len(H);
    struct node *prev, *curr, *temp;
    for (int i = 1; i <= l - 1; i++) {
        prev = H; curr = H->next;
        for (int j = 0; j < l - i; j++) {
            temp = curr->next;
            if (curr->data > temp->data) {
                prev->next = temp; curr->next = temp->next; temp->next = curr; prev = temp;
            } else { prev = curr; curr = curr->next; }
        }
    }
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    int choice;
    do {
        printf("\n1. Create\n2. Display\n3. Length\n4. Insert by Pos\n5. Delete by Pos\n6. Reverse\n7. Sort\n8. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(head); break;
            case 2: display(head); break;
            case 3: printf("Length: %d\n", len(head)); break;
            case 4: Insertbypos(head); break;
            case 5: delpos(head); break;
            case 6: reverse(head); break;
            case 7: sort(head); break;
        }
    } while (choice != 8);
    return 0;
}
