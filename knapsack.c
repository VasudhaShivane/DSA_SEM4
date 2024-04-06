#include <stdio.h>
#define n 5

float capacity = 12;

void BasedProfit(float p[], float w[], float x[]);

int main() {
    float profit[n], weight[n], x[n];
    int i, j;

    // Read profit and weight for each item
    for (i = 0; i < n; i++) {
        printf("Enter profit: ");
        scanf("%f", &profit[i]);
        printf("Enter weight: ");
        scanf("%f", &weight[i]);
    }

    // Initialize array x
    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Call BasedProfit function
    BasedProfit(profit, weight, x);

    return 0;
}

void BasedProfit(float p[], float w[], float x[]) {
    float temp, W = 0, tp = 0;
    int i, j;

    // Sort items based on profit-to-weight ratio in descending order
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((p[j] / w[j]) < (p[j + 1] / w[j + 1])) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }

    i = 0;
    // Fill the knapsack while considering capacity constraint
    while (W <= capacity && i < n) {
        if (W + w[i] <= capacity) {
            x[i] = 1;
            W = W + w[i];
            i++;
        } else {
            x[i] = (capacity - W) / w[i];
            break;
        }
    }

    // Calculate total profit
    for (i = 0; i < n; i++) {
        tp = tp + p[i] * x[i];
    }

    // Print the maximum achievable profit
    printf("Profit is: %.2f\n", tp);
}

