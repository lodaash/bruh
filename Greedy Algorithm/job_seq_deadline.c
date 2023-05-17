#include<stdio.h>

#include<stdlib.h>

#include<stdbool.h>

struct items {

  int index;
  int deadline;
  int profit;
};
void main() {

  int n;
  printf("Enter number of jobs: ");
  scanf("%d", & n);
  int sched[n];
  struct items job[n];
  struct items temp;
  for (int i = 0; i < n; i++) {

    job[i].index = i + 1;

    printf("Enter deadline and profit: ");
    scanf("%d %d", & job[i].deadline, & job[i].profit);
  }

  for (int i = 0; i < n - 1; i++) {

    for (int j = 0; j < n - i - 1; j++) {

      if (job[j].profit < job[j + 1].profit) {
        temp = job[j];
        job[j] = job[j + 1];
        job[j + 1] = temp;

      }
    }
  }
  printf(" The index in which job will be executed is");
  for (int i = 0; i < n; i++) {
    printf("%d ", job[i].index);
  }
  printf("\n");

  int mdead = 0;
  for (int i = 0; i < n; i++) {
    if (job[i].deadline > mdead) {

      mdead = job[i].deadline;
    }
  }

  printf("Max deadline is: %d", mdead);
  printf("\n");

  for (int i = 0; i < n; i++) {
    int j = 1;

    while (job[i].deadline - j >= 0) {   //This condition ensures that the loop does not go beyond the deadline
      if (sched[job[i].deadline - j] == 0) {  //if slot is available
        sched[job[i].deadline - j] = job[i].index;  //assigns to current job
        break;
      }
      j++;
    }
  }
  printf("Jobs are :");
  for (int i = 0; i < mdead; i++) {
    printf("%d ", sched[i]);
  }

}