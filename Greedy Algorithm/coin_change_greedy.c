#include <stdio.h>

// Function to find the minimum number of coins needed for change using a greedy algorithm
void coinChange(int coins[], int numCoins, int amount) {
    int count = 0;
    int coinCount[numCoins]; // Array to store the count of each coin used

    // Start with the highest denomination coin
    for (int i = numCoins - 1; i >= 0; i--) {
        coinCount[i] = 0; // Initialize coin count for each denomination

        // Find the maximum number of coins of the current denomination that can be used
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            coinCount[i]++;
        }
    }

    // Check if exact change was possible
    if (amount != 0) {
        printf("Exact change not possible.\n");
    } else {
        printf("Minimum number of coins: %d\n", count);
        printf("Coins used:\n");
        for (int i = 0; i < numCoins; i++) {
            if (coinCount[i] > 0) {
                printf("%d coin(s) of denomination %d\n", coinCount[i], coins[i]);
            }
        }
    }
}

// Test the code
int main() {
    int numCoins;

    printf("Enter the number of coin denominations: ");
    scanf("%d", &numCoins);

    int coins[numCoins];

    printf("Enter the coin denominations:\n");
    for (int i = 0; i < numCoins; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    coinChange(coins, numCoins, amount);

    return 0;
}
