#include <stdio.h>
#include <stdbool.h>

#define V 4

void printSolution(char color[]);

bool isSafe(bool graph[V][V], char color[]) {
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] && color[j] == color[i]) {  //checks if there is an edge b/w them and also do they have same color, if yes return false
                return false;
            }
        }
    }
    return true;
}
//m - no of colors
//color - array to store colors
bool graphColoring(bool graph[V][V], int m, int i, char color[V]) {
    if (i == V) {  // means all vertices are coloured
        if (isSafe(graph, color)) {
            printSolution(color);
            return true;
        }
        return false;
    }

    for (int j = 0; j < m; j++) {
        color[i] = 'A' + j;
        if (graphColoring(graph, m, i + 1, color)) { //recursive call for next vertex
            return true;
        }
        color[i] = ' '; // in case of false, resets the color of current vertex
    }
    return false;
}

void printSolution(char color[]) {
    printf("Solution Exists: Following are the assigned colors\n");
    for (int i = 0; i < V; i++) {
        printf("  %c", color[i]);
    }
    printf("\n");
}

int main() {
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 }
    };
    int m = 3;

    char color[V];
    for (int i = 0; i < V; i++) {
        color[i] = ' ';
    }

    if (!graphColoring(graph, m, 0, color)) {
        printf("Solution does not exist\n");
    }

    return 0;
}
