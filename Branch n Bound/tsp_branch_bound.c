
//another method:

#include <stdio.h>
#include <stdbool.h>

#define N 5 // Number of cities

int minCost = 9999;  // Variable to store the minimum cost
int finalPath[N + 1];   // Final solution path

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// The function calculateCost calculates the total cost of a given path based on the cost matrix. It iterates over the path array and sums up the corresponding costs from the cost matrix.
int calculateCost(int path[], int costMatrix[][N]) {
    int cost = 0;
    for (int i = 0; i < N - 1; i++) {
        cost += costMatrix[path[i]][path[i + 1]];
    }
    return cost;
}

void TSPBranchAndBound(int currentCity, int path[], bool visited[], int costMatrix[][N], int level) {
    if (level == N) {
        // Check if there is an edge from the last visited city to the starting city
        if (costMatrix[currentCity][path[0]] != 0) {
            int currentCost = calculateCost(path, costMatrix) + costMatrix[currentCity][path[0]];

            if (currentCost < minCost) {
                minCost = currentCost;
                for (int i = 0; i < N; i++) {
                    finalPath[i] = path[i];
                }
                finalPath[N] = path[0];
            }
        }
        return;
    }
// In the recursive case, the function iterates over all unvisited cities from the current city and checks if there is an edge between them. If an unvisited city with a valid edge is found, it marks that city as visited, adds it to the path, and recursively calls TSPBranchAndBound with the updated parameters.
    for (int i = 0; i < N; i++) {
        if (!visited[i] && costMatrix[currentCity][i] != 0) {
            visited[i] = true;
            path[level] = i;

            TSPBranchAndBound(i, path, visited, costMatrix, level + 1);

            visited[i] = false;  //marks current city as univisted
            path[level] = -1;  //removes it from path
        }
    }
}

void printPath() {
    printf("Optimal Path: ");
    for (int i = 0; i <= N; i++) {
        printf("%d ", finalPath[i] + 1);
    }
    printf("\nMinimum Cost: %d\n", minCost);
}

int main() {
  int costMatrix[N][N] = {
    {0, 1, 0, 5, 4},
    {1, 0, 4, 3, 6},
    {0, 4, 0, 2, 0},
    {5, 3, 2, 0, 7},
    {4, 6, 0, 7, 0}
};

    int path[N];  //keeps track of current path being explored
    bool visited[N]; //keeps track of which cities have been visited
    path[0] = 0;
    visited[0] = true;
    for (int i = 1; i < N; i++) {
        path[i] = -1;
        visited[i] = false;
    }

    TSPBranchAndBound(0, path, visited, costMatrix, 1);

    printPath();

    return 0;
}