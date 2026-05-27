#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack_DP(int n, int M, int W[], int P[], int U[]) {
    int table[n + 1][M + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (W[i - 1] <= j)
                table[i][j] = max(table[i - 1][j],
                                  P[i - 1] + table[i - 1][j - W[i - 1]]);
            else
                table[i][j] = table[i - 1][j];
        }
    }

    int j = M;
    for (int i = n; i > 0; i--) {
        if (table[i][j] != table[i - 1][j]) {
            U[i - 1] = 1;
            j -= W[i - 1];
        } else {
            U[i - 1] = 0;
        }
    }

    return table[n][M];
}

int main() {
    int n, M;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &M);

    int W[n], P[n], U[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &W[i]);

        printf("Enter profit of item %d: ", i + 1);
        scanf("%d", &P[i]);

        U[i] = 0;
    }

    int res = knapsack_DP(n, M, W, P, U);

    printf("Max profit = %d\n", res);

    printf("Selected items (1 = included): ");
    for (int i = 0; i < n; i++)
        printf("%d ", U[i]);

    return 0;
}

