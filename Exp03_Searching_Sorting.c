#include <stdio.h>

int seqsearch(int a[], int n, int key) {
    int pos = -1, flag = 0;
    for (int i = 0; i < n; i++) {
        if (key == a[i]) { pos = i; flag = 1; break; }
    }
    if (flag == 1) return pos;
    else return -1;
}

int binary_search_iterative(int a[], int low, int high, int key) {
    int flag = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return 1;
        else if (key < a[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

int binary_search_recursive(int a[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (key < a[mid]) return binary_search_recursive(a, low, mid - 1, key);
        else return binary_search_recursive(a, mid + 1, high, key);
    }
    return -1;
}

void selectionsort(int a[], int n) {
    for (int i = 0; i <= n - 2; i++) {
        int minpos = i;
        for (int j = i + 1; j <= n - 1; j++) if (a[j] < a[minpos]) minpos = j;
        if (minpos != i) { int temp = a[i]; a[i] = a[minpos]; a[minpos] = temp; }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j = j - 1; }
        arr[j + 1] = key;
    }
}

void shell_sort(int A[], int n) {
    int gap = n / 2;
    do {
        int swapped = 0;
        do {
            swapped = 0;
            for (int i = 0; i < n - gap; i++) {
                if (A[i] > A[i + gap]) {
                    int temp = A[i]; A[i] = A[i + gap]; A[i + gap] = temp;
                    swapped = 1;
                }
            }
        } while (swapped == 1);
    } while ((gap = gap / 2) >= 1);
}

int main() {
    int arr[100], n, choice, key, res;
    printf("Number of students: "); scanf("%d", &n);
    printf("Enter records: "); for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    do {
        printf("\n1. Linear Search\n2. Binary Search(Iter)\n3. Binary Search(Rec)\n4. Selection Sort\n5. Insertion Sort\n6. Shell Sort\n7. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Key: "); scanf("%d", &key); res = seqsearch(arr, n, key); printf(res != -1 ? "Found\n" : "Not Found\n"); break;
            case 2: printf("Key: "); scanf("%d", &key); printf(binary_search_iterative(arr, 0, n-1, key) ? "Found\n" : "Not Found\n"); break;
            case 3: printf("Key: "); scanf("%d", &key); res = binary_search_recursive(arr, 0, n-1, key); printf(res != -1 ? "Found\n" : "Not Found\n"); break;
            case 4: selectionsort(arr, n); printf("Sorted\n"); break;
            case 5: insertionSort(arr, n); printf("Sorted\n"); break;
            case 6: shell_sort(arr, n); printf("Sorted\n"); break;
        }
    } while(choice != 7);
    return 0;
}
