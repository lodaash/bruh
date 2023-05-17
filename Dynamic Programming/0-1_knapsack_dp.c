#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxProfit(int W, int n, int wt[], int val[], int solution[]) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  //the maximum profit is set to 0 because there are no items to select or no capacity available.
            } else {
                int notTake = dp[i - 1][j];
                int take = -1000000000;


                // If the current item's weight (wt[i - 1]) is less than or equal to the current weight capacity (j), it calculates the maximum profit by selecting the item (take) or not selecting the item (notTake). The maximum profit is determined by comparing the sum of the current item's value and the maximum profit for the remaining weight (dp[i - 1][j - wt[i - 1]]) with the maximum profit obtained without selecting the current item (dp[i - 1][j]).
                if (j >= wt[i - 1]) {
                    take = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                }
                dp[i][j] = max(notTake, take);
            }
        }
    }

    // Constructing the solution vector
    int i = n, j = W; // It starts from the last row and last column 
    int index = 0;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {  //checking if maxm current profit differs from max profit withour current item
            solution[index++] = i; //if yes, curr item is selected and added to solution
            j -= wt[i - 1];  //subtraction of currrent wt from current wt capaacity
        }
        i--;
    }

    return dp[n][W];
}

int main() {
    int W = 50;
    int n = 3;
    int val[n];
    int wt[n];
    int solution[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    int maxProfitt = maxProfit(W, n, wt, val, solution);

    printf("Maximum Profit: %d\n", maxProfitt);
    printf("Solution Vector: ");
    for (int i = 0; i < maxProfitt; i++) {
        printf("%d ", solution[i]);
    }
    printf("\n");

    return 0;
}
