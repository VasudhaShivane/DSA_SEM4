#include <stdio.h>

// Function prototypes
void Merge(int arr[], int beg, int mid, int end);
void Merge_sort(int arr[], int beg, int end);

int main() {
    int i, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter array elements: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    Merge_sort(arr, 0, size - 1);

    printf("Sorted array is: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void Merge_sort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = (beg + end) / 2;
        // Recursive calls to divide the array
        Merge_sort(arr, beg, mid);
        Merge_sort(arr, mid + 1, end);
        // Merge the divided arrays
        Merge(arr, beg, mid, end);
    }
}

void Merge(int arr[], int beg, int mid, int end) {
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int left[n1], right[n2];

    // Copy elements to temporary left and right arrays
    for (i = 0; i < n1; i++) {
        left[i] = arr[beg + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    i = 0; // Initial index of the left subarray
    j = 0; // Initial index of the right subarray
    k = beg; // Initial index of the merged subarray

    // Merge the two subarrays in ascending order
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left subarray, if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right subarray, if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

