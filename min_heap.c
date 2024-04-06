#include <stdio.h>

int arr[10];
int size = 0;

void insert(int arr[], int d);
void printArray(int arr[], int n);
void heapify(int arr[], int size, int i);

int main()
{
    insert(arr, 0);
    insert(arr, 3);
    insert(arr, 1);
    insert(arr, 6);
    insert(arr, 5);

    printf("Before sorting, the array elements are:\n");
    printArray(arr, size);
    printf("\n");

    // Sort the array using heap sort
    int i;

    // Build a min heap by calling heapify for each non-leaf node in the array
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    // Perform heap sort by repeatedly swapping the root element with the last element,
    // reducing the size of the heap, and heapifying the reduced heap
    for (i = size - 1; i >= 0; i--)
    {
        // Swap the root (minimum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }

    printf("After sorting, the array elements are:\n");
    printArray(arr, size);
    printf("\n");

    return 0;
}

// Function to insert an element into the array
void insert(int arr[], int d)
{
    int i;
    if (size >= 10)
    {
        printf("Array is full, cannot insert more elements.\n");
        return;
    }

    arr[size] = d;
    size++;

    // Heapify the array after insertion
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

// Function to heapify the array
void heapify(int arr[], int size, int i)
{
    int m = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Find the smallest element among the current node and its children
    if (left < size && arr[left] < arr[m])
    {
        m = left;
    }

    if (right < size && arr[right] < arr[m])
    {
        m = right;
    }

    // If the smallest element is not the current node, swap them and heapify the affected subtree
    if (m != i)
    {
        int temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;

        heapify(arr, size, m);
    }
}

// Function to print the array elements
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
}

