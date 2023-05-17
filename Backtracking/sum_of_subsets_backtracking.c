#include <stdio.h> 
int sum; 
int num[20]; 
int sol[20];

void sumofsubs(int i, int M) {  //This function recursively finds the subsets with the desired sum.
  if (sum == M) {  //current sum equals desired sum
    for (int j = 0; j < i; j++) {
      if (sol[j] == 1) {  //if the element at index j is included in the subset (sol[j] = 1), print the corresponding number.
        printf("%d ", num[j]);
      }
    }
    printf("\n");
  } else if (feas(i, M)) {   //If the current sum doesn't equal the desired sum but it is feasible to continue exploring the subsets:
    sol[i] = 1;  //include current number in subset
    sum += num[i];
    sumofsubs(i + 1, M);
    sol[i] = 0;  //Exclude the current number from the subset.
    sum -= num[i];
    sumofsubs(i + 1, M);
  }
}
int feas(int i, int M) {   //This function checks if it is feasible to continue exploring subsets.
  if (sum > M) {
    return 0;  //not feasible
  }
  if (i == 6 && sum < M) {
    return 0;
  }
  return 1;
}
void main() {
  int n, val;
  printf("Enter the number of Subsets: ");
  scanf("%d", &n);
  printf("Enter the values: ");
  for (int i = 0; i < n; i++) {
    sol[i] = 0;
    scanf("%d", & num[i]);
  }
  printf("Enter the value of sum: ");
  scanf("%d", & val);
  int len = 0;
  printf("The solutions are as follows: \n");
  sumofsubs(len, val);
}
