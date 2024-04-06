#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define n 6

int A[n][n]; // Adjacency matrix representing the graph
int visited[n]; // Array to track visited vertices

// Depth First Search (DFS) function
void DFS(int v) {
    int i;
    visited[v] = 1; // Mark the current vertex as visited
    for (i = 0; i < n; i++) {
        if (A[v][i] == 1 && !visited[i]) { // Visit adjacent unvisited vertices
            printf("\nThe edge is [%d][%d]", v, i);
            DFS(i); // Recursively call DFS for the adjacent vertex
        }
    }
}

// Breadth First Search (BFS) function
void BFS(int v) {
    int q[10], f = -1, r = -1; // Queue for BFS traversal
    int i;
    visited[v] = 1; // Mark the current vertex as visited
    printf("%d\t", v); // Print the visited vertex
    for (i = 0; i < n; i++) {
        if (A[v][i] == 1 && !visited[i]) { // Visit adjacent unvisited vertices
            q[++r] = i; // Enqueue the adjacent vertex
            visited[i] = 1; // Mark the adjacent vertex as visited
        }
    }
    if (f <= r) {
        BFS(q[++f]); // Continue BFS with the next vertex in the queue
    }
}

int main() {
    int choice, v, i, j;
    for (i = 0; i < n; i++) {
        visited[i] = 0; // Initialize visited array to all zeros
    }
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]); // Read the adjacency matrix from user input
        }
    }
    while (1) {
        printf("\n********** MENU **********\n");
        printf("1. Depth First Search (DFS)\n");
        printf("2. Breadth First Search (BFS)\n");
        printf("3. Exit\n");
        printf("***************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user choice from the menu

        switch (choice) {
            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &v); // Read the starting vertex for DFS
                printf("DFS traversal:\n");
                DFS(v); // Perform DFS traversal from the starting vertex
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &v); // Read the starting vertex for BFS
                printf("BFS traversal:\n");
                BFS(v); // Perform BFS traversal from the starting vertex
                break;
            case 3:
                exit(0); // Exit the program
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

