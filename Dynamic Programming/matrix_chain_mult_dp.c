#include<stdio.h> 
#include <limits.h> 
int ans[20][20]; 
void getAns(int p[], int n)
{
  int i, j, k, len, q;
  for (i = 0; i < n; i++)
    {
      ans[i][i] = 0;
    }
  for (len = 2; len <= n; len++)
    {
      for (i = 0; i < n - len + 1; i++)
    {
      j = i + len - 1;
      ans[i][j] = INT_MAX;
      for (k = i; k <= j - 1; k++)
        {
          q = ans[i][k] + ans[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
          if (q < ans[i][j])
        ans[i][j] = q;
        }
    }
    }
  printf ("\nThe matrix after multiplication is:\n");
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
    {
      printf ("%d", ans[i][j]);
      printf ("\t");
    }
      printf ("\n");
    }
} 
void main ()
{
  int num;
  printf ("Enter the number of orders to be entered:\n");
  scanf ("%d", &num);
  int arr[num];
  printf ("Enter the order of the matrices:\n");
  for (int i = 0; i < num; i++)
    {
      scanf ("%d", &arr[i]);
    }
  getAns (arr, num - 1);
}

