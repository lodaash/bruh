#include<stdio.h> 
#include<math.h> 

int board[20],count;

void print(int n) {
  int i, j;
  printf("\n\nSolution %d:\n\n", ++count);
  for (i = 1; i <= n; ++i) printf("\t%d", i);
  for (i = 1; i <= n; ++i) {
    printf("\n\n%d", i);
    for (j = 1; j <= n; ++j) {
      if (board[i] == j) printf("\tQ");
      else
        printf("\t-");
    }
  }
}
int place(int row, int column) {
  int i;
  for (i = 1; i <= row - 1; ++i) {
    if (board[i] == column) return 0; // If there is already a queen in the same column, return 0 (false).
    else if (abs(board[i] - column) == abs(i - row)) return 0; //diagonal position
  }
  return 1;
}
void queen(int row, int n) {
  int column;
  for (column = 1; column <= n; ++column) {
    if (place(row, column)) {
      board[row] = column;  //placing queen at current posn
      if (row == n) print(n);
      else
        queen(row + 1, n);  // Recursively call queen() to place the next queen in the next row.
    }
  }
}
int main() {
  int n, i, j;
  printf("Enter number of Queens:");
  scanf("%d", & n);
  queen(1, n);
  return 0;
}
