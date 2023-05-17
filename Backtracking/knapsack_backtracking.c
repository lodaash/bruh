#include <stdio.h>

#define max 100

int weight[max];
int value[max];
int n, max_weight, max_value;

int best_answer[max], answer[max];

void print() {
    int i;
    printf("Max profit: %d\n", max_value);
    printf("Solution vector:\n");
    for (i = 1; i <= n; i++)
        printf("%d ", best_answer[i]);
    printf("\n");
}
// level represents the current level of the search tree
void DFS(int level, int current_weight, int current_value) {
    if (level >= n + 1) {
        if (current_value > max_value) {  //If the level exceeds the total number of items (n + 1), it means all items have been considered. In this case, it checks if the current_value is greater than the max_value found so far. If it is, it updates the max_value and stores the selected items in the best_answer array.
            int i;
            max_value = current_value;
            for (i = 1; i <= n; i++)
                best_answer[i] = answer[i];
        }
    } else {
        if (current_weight >= weight[level + 1]) {  //curr wt>=wt of next item, If it is, it means the next item can be included in the knapsack.
            current_weight = current_weight - weight[level + 1];
            current_value = current_value + value[level + 1];
            answer[level + 1] = 1; //answer[level + 1] to 1 to indicate that the item has been selected.
            DFS(level + 1, current_weight, current_value);
            answer[level + 1] = 0;
            current_weight = current_weight + weight[level + 1];
            current_value = current_value - value[level + 1];
        }
        DFS(level + 1, current_weight, current_value);
    }
}

void init() {
    int i;
    max_value = 0;
    for (i = 1; i <= n; i++)
        answer[i] = 0;
}

int main() {
    int i;
    printf("Enter the number of items and max weight:\n");
    while (scanf("%d%d", &n, &max_weight) != EOF) {
        printf("Enter weight of items:\n");
        for (i = 1; i <= n; i++)
            scanf("%d", &weight[i]);
        printf("Enter value of items:\n");
        for (i = 1; i <= n; i++)
            scanf("%d", &value[i]);

        init();

        DFS(0, max_weight, 0);

        print();
    }
    return 0;
}
