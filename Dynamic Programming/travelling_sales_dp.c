#include<stdio.h>

#include<conio.h>

int a[10][10], visited[10], n, cost = 0;

void get() {

  int i, j;

  printf("Enter No. of Cities: ");

  scanf("%d", & n);

  printf("\nEnter Cost Matrix\n");

  for (i = 0; i < n; i++) {

    printf("\nEnter Elements of Row # : %d\n", i + 1);

    for (j = 0; j < n; j++)

      scanf("%d", & a[i][j]);

    visited[i] = 0;

  }

  printf("\n\nThe cost list is:\n\n");

  for (i = 0; i < n; i++) {

    printf("\n\n");

    for (j = 0; j < n; j++)

      printf("\t%d", a[i][j]);

  }

}

void mincost(int city) {

  int i, ncity;

  visited[city] = 1;  //marking current city as visited

  printf("%d -->", city + 1);

  ncity = least(city);  //Finds the next city to visit based on the current city.

  if (ncity == 999)
  // if (ncity == 999): Checks if there is no feasible next city to visit.
// If so, it means that all cities have been visited, and we need to return to the starting city. Therefore, set ncity to 0.
  {

    ncity = 0;

    printf("%d", ncity + 1);  //Prints the starting city as the last city in the path

    cost += a[city][ncity]; // Adds the cost of returning to the starting city to the total cost.

    return;

  }

  mincost(ncity);

}

int least(int c) { //finds the next nearest city to visit
//nc -index of next city
  int i, nc = 999;

  int min = 999, kmin;

  for (i = 0; i < n; i++) {

    if ((a[c][i] != 0) && (visited[i] == 0)) //Checks if the cost between the current city and the next city is not zero and if the next city is not visited yet.

      if (a[c][i] < min) // If the cost between the current city and the next city is less than the current minimum cost

    {

      min = a[i][0] + a[c][i];

      kmin = a[c][i];

      nc = i;

    }
    

  }

  if (min != 999) //Checks if a feasible next city was found.

    cost += kmin;

  return nc;

}

void put() {

  printf("\n\nMinimum cost:");

  printf("%d", cost);

}

void main() {

  get();

  printf("\n\nThe Path is:\n\n");

  mincost(0); //starting from city zero

  put();

}






