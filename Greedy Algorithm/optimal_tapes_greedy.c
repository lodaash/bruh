#include <stdio.h>

void optimal(int l[], int n) {
    int temp, sum;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (l[j] < l[i]) {
                temp = l[j];
                l[j] = l[i];
                l[i] = temp;
            }
        }
    }

    printf("The optimal sequence is\n");
    for (int i = 0; i < n; i++) {
        printf(" %d ", l[i]);
    }

    double MRT = 0;
    sum = 0; // Initialize sum

    for (int i = 0; i < n; i++) {
        sum += l[i]; // Accumulate sum
        MRT += sum;
    }
    MRT /= n;

    printf("\nThe MRT is %.2f", MRT);
}

int main() {
    int size;

    printf("Enter the number of Tapes: ");
    scanf("%d", &size);

    int l[size];

    for (int i = 0; i < size; i++) {
        printf("Tape %d: ", i + 1);
        scanf("%d", &l[i]);
    }

    optimal(l, size);

    return 0;
}
