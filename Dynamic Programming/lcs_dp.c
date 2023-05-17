#include<stdio.h>

#include<string.h>

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

void print(int i, int j) {
  if (i == 0 || j == 0)
    return;
  if (b[i][j] == 'c') {
    print(i - 1, j - 1);
    printf("%c", x[i - 1]);
  } else if (b[i][j] == 'u')
    print(i - 1, j);
  else
    print(i, j - 1);
}

void lcs() {
  m = strlen(x);
  n = strlen(y);
  for (i = 0; i <= m; i++)
    c[i][0] = 0;
  for (i = 0; i <= n; i++)
    c[0][i] = 0;

  //c, u and l denotes cross, upward and downward directions respectively
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++) {
      // If the characters at positions (i-1) and (j-1) in strings x and y are equal, then the value in cell (i, j) is updated to the value in cell (i-1, j-1) incremented by 1. The direction of the LCS at this cell is set to 'c' (cross).
      // If the value in cell (i-1, j) is greater than or equal to the value in cell (i, j-1), then the value in cell (i, j) is updated to the value in cell (i-1, j), and the direction of the LCS at this cell is set to 'u' (upward).
      // Otherwise, the value in cell (i, j) is updated to the value in cell (i, j-1), and the direction of the LCS at this cell is set to 'l' (leftward).
      if (x[i - 1] == y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
        b[i][j] = 'c';
      } else if (c[i - 1][j] >= c[i][j - 1]) {
        c[i][j] = c[i - 1][j];
        b[i][j] = 'u';
      } else {
        c[i][j] = c[i][j - 1];
        b[i][j] = 'l';
      }
    }
}
int main() {
  printf("Enter 1st sequence:");
  scanf("%s", x);
  printf("Enter 2nd sequence:");
  scanf("%s", y);
  printf("\nThe Longest Common Subsequence is ");
  lcs();
  print(m, n);
  return 0;
}