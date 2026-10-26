#include <stdio.h>

void displayMatrix(int mat[20][20], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int Mat1[20][20], int Mat2[20][20], int R1, int R2, int C1, int C2) {
    int s[20][20], i, j;
    if ((R1 == R2) && (C1 == C2)) {
        printf("Addition:\n");
        for (i = 0; i < R1; i++) {
            for (j = 0; j < C1; j++) s[i][j] = Mat1[i][j] + Mat2[i][j];
        }
        displayMatrix(s, R1, C1);
    } else printf("Matrices cannot be added\n");
}

void subMatrix(int Mat1[20][20], int Mat2[20][20], int R1, int R2, int C1, int C2) {
    int m[20][20], i, j;
    if ((R1 == R2) && (C1 == C2)) {
        printf("Subtraction:\n");
        for (i = 0; i < R1; i++) {
            for (j = 0; j < C1; j++) m[i][j] = Mat1[i][j] - Mat2[i][j];
        }
        displayMatrix(m, R1, C1);
    } else printf("Matrices cannot be subtracted\n");
}

void transpose(int mat[20][20], int r, int c) {
    int i, j, t[20][20];
    printf("Transpose:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) t[i][j] = mat[j][i];
    }
    displayMatrix(t, c, r);
}

void multiMatrix(int Mat1[20][20], int Mat2[20][20], int R1, int R2, int C1, int C2) {
    if (C1 == R2) {
        int sum, mul[20][20], i, j, k;
        printf("Multiplication:\n");
        for (i = 0; i < R1; i++) {
            for (j = 0; j < C2; j++) {
                sum = 0;
                for (k = 0; k < R2; k++) sum = sum + Mat1[i][k] * Mat2[k][j];
                mul[i][j] = sum;
            }
        }
        displayMatrix(mul, R1, C2);
    } else printf("Matrices cannot be multiplied\n");
}

int main() {
    int Mat1[20][20], Mat2[20][20], R1, C1, R2, C2, choice, i, j;
    printf("Enter rows and cols for Matrix 1: ");
    scanf("%d %d", &R1, &C1);
    printf("Enter elements of Matrix 1:\n");
    for (i = 0; i < R1; i++) for (j = 0; j < C1; j++) scanf("%d", &Mat1[i][j]);

    printf("Enter rows and cols for Matrix 2: ");
    scanf("%d %d", &R2, &C2);
    printf("Enter elements of Matrix 2:\n");
    for (i = 0; i < R2; i++) for (j = 0; j < C2; j++) scanf("%d", &Mat2[i][j]);

    do {
        printf("\n--- Matrix Menu ---\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addMatrix(Mat1, Mat2, R1, R2, C1, C2); break;
            case 2: subMatrix(Mat1, Mat2, R1, R2, C1, C2); break;
            case 3: multiMatrix(Mat1, Mat2, R1, R2, C1, C2); break;
            case 4: 
                printf("Mat1 Transpose:\n"); transpose(Mat1, R1, C1);
                printf("Mat2 Transpose:\n"); transpose(Mat2, R2, C2); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}
