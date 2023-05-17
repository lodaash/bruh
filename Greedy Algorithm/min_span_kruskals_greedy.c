#include <stdio.h>

#include <stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;

int min, mincost = 0, cost[9][9], parent[9];

// find(int i): This function is used to find the root or representative element of the set to which the element i belongs. It takes an element i as input and iteratively follows the parent pointers until it reaches an element whose parent is 0 (indicating the root). It returns the root element.

// i: The element for which we want to find the root element.
// uni(int i, int j): This function is used to perform the union of two sets represented by their root elements i and j. It takes two root elements as input and merges the sets if they are not already the same. It returns a boolean value indicating whether a union operation was performed or not.

// i: The root element of the first set.
// j: The root element of the second set.
int find(int i) {

  while (parent[i])

    i = parent[i];

  return i;

}

int uni(int i, int j) {

  if (i != j)

  {

    parent[j] = i;

    return 1;

  }

  return 0;

}

void main() {

  printf("Enter the no. of vertices:\n");

  scanf("%d", & n);

  printf("\nEnter the cost adjacency matrix:\n");

  for (i = 1; i <= n; i++)

  {

    for (j = 1; j <= n; j++)

    {

      scanf("%d", & cost[i][j]);

      if (cost[i][j] == 0)

        cost[i][j] = 999;

    }

  }

  printf("The edges of Minimum Cost Spanning Tree are\n");

  while (ne < n)

  {

    for (i = 1, min = 999; i <= n; i++)

    {

      for (j = 1; j <= n; j++)

      {

        if (cost[i][j] < min)

        {

          min = cost[i][j];

          a = u = i;

          b = v = j;

        }

      }

    }

    u = find(u);

    v = find(v);

    if (uni(u, v))

    {

      printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);

      mincost += min;

    }

    cost[a][b] = cost[b][a] = 999;

  }

  printf("\nMinimum cost = %d\n", mincost);

}