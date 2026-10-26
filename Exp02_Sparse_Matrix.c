#include <stdio.h>

void displaySparse(int matrix[20][3]) {
    int t = matrix[0][2];
    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= t; i++) printf("%d\t%d\t%d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
}

void compact(int A[20][20], int m, int n, int B[20][3]) {
    B[0][0] = m; B[0][1] = n;
    int k = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) { B[k][0] = i; B[k][1] = j; B[k][2] = A[i][j]; k++; }
        }
    }
    B[0][2] = k - 1;
}

void Transpose(int A[20][3], int B[20][3]) {
    int m = A[0][0], n = A[0][1], t = A[0][2];
    B[0][0] = n; B[0][1] = m; B[0][2] = t;
    if (t <= 0) return;
    int q = 1;
    for (int col = 0; col < n; col++) {
        for (int p = 1; p <= t; p++) {
            if (A[p][1] == col) { B[q][0] = A[p][1]; B[q][1] = A[p][0]; B[q][2] = A[p][2]; q++; }
        }
    }
}

void FAST_TRANSPOSE(int A[20][3], int B[20][3]) {
    int S[20], T[20], m = A[0][0], n = A[0][1], t = A[0][2];
    B[0][0] = n; B[0][1] = m; B[0][2] = t;
    if (t <= 0) return;
    for (int i = 0; i < n; i++) S[i] = 0;
    for (int i = 1; i <= t; i++) S[A[i][1]] = S[A[i][1]] + 1;
    T[0] = 1;
    for (int i = 1; i < n; i++) T[i] = T[i - 1] + S[i - 1];
    for (int i = 1; i <= t; i++) {
        int j = A[i][1];
        B[T[j]][0] = A[i][1]; B[T[j]][1] = A[i][0]; B[T[j]][2] = A[i][2];
        T[j] = T[j] + 1;
    }
}

int main() {
    int A[20][20], sparse[20][3], trans[20][3], ftrans[20][3], m, n, choice;
    printf("Rows and cols: "); scanf("%d %d", &m, &n);
    printf("Elements:\n");
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);

    compact(A, m, n, sparse);

    do {
        printf("\n1. Display Compact\n2. Simple Transpose\n3. Fast Transpose\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: displaySparse(sparse); break;
            case 2: Transpose(sparse, trans); displaySparse(trans); break;
            case 3: FAST_TRANSPOSE(sparse, ftrans); displaySparse(ftrans); break;
        }
    } while (choice != 4);
    return 0;
}
