#include <stdio.h>
#include <stdlib.h>

typedef struct pnode { int coef, exp; struct pnode *next; } pnode;
typedef struct poly { pnode *h; } poly;

pnode* getnode() { return (pnode*)malloc(sizeof(pnode)); }

void insert(pnode *head, pnode *newnode) {
    pnode *p = head->next, *prev = head;
    while (p != head && p->exp > newnode->exp) { prev = p; p = p->next; }
    if (p->exp == newnode->exp) {
        p->coef += newnode->coef;
        if (p->coef == 0) { prev->next = p->next; p->next = NULL; free(p); }
        free(newnode);
    } else { newnode->next = p; prev->next = newnode; }
}

pnode* create() {
    pnode *head = getnode();
    head->next = head; head->exp = 999;
    int n; printf("No of terms: "); scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        pnode *newnode = getnode();
        printf("Coef Exp: "); scanf("%d %d", &newnode->coef, &newnode->exp);
        insert(head, newnode);
    }
    head->exp = -1; head->next = head;
    return head;
}

void display(pnode *head) {
    pnode *p = head->next;
    while (1) {
        printf("%dx^%d ", p->coef, p->exp); p = p->next;
        if (p == head) break;
        if (p->coef > 0) printf("+");
    }
    printf("\n");
}

void add_poly(poly p1, poly p2, poly *res) {
    pnode *t1 = p1.h->next, *t2 = p2.h->next, *t3 = res->h;
    while (t1->exp != -1 || t2->exp != -1) {
        pnode *curr = getnode();
        if (t1->exp == t2->exp) {
            curr->exp = t1->exp; curr->coef = t1->coef + t2->coef;
            t3->next = curr; curr->next = res->h; t3 = curr; t1 = t1->next; t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            curr->exp = t1->exp; curr->coef = t1->coef;
            t3->next = curr; curr->next = res->h; t3 = curr; t1 = t1->next;
        } else {
            curr->exp = t2->exp; curr->coef = t2->coef;
            t3->next = curr; curr->next = res->h; t3 = curr; t2 = t2->next;
        }
    }
}

int main() {
    poly p1, p2, p3; p1.h = NULL; p2.h = NULL; p3.h = getnode(); p3.h->exp = -1; p3.h->next = p3.h;
    printf("Poly 1:\n"); p1.h = create(); 
    pnode *temp1 = p1.h; while(temp1->next != p1.h && temp1->next != NULL) temp1 = temp1->next; temp1->next = p1.h;
    printf("Poly 2:\n"); p2.h = create();
    pnode *temp2 = p2.h; while(temp2->next != p2.h && temp2->next != NULL) temp2 = temp2->next; temp2->next = p2.h;
    printf("Add Poly 1 & 2:\n"); add_poly(p1, p2, &p3); display(p3.h);
    return 0;
}
