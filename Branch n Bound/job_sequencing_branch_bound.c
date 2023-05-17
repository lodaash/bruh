#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

int n = 4; 
// p, d, and w are arrays representing the processing time, deadline, and weight of each job, respectively.
int p[N] = {1, 2, 1, 1};
int d[N] = {1, 3, 2, 1};
int w[N] = {5, 10, 6, 3}; 
int s[N]; //start n finish time for each job
int f[N]; 
int upperbound = INT_MAX;
int best_time;  //represents the minimum cost/time taken for the schedule.
int best_included[N];  //array that stores whether a job is included in the optimal schedule or not.


//The calcost function calculates the cost of including a particular job in the schedule based on the weight of the jobs that are not included.
int calcost(int job, int included[N]){   //included array to check whether job is included or not in schedule
    included[job]=1;  //indicating that the job is included in the schedule.
    int cost = 0;
    
    for (int i = 0; i <= job; i++){

        //If the job is not included, it adds its weight (w[i]) to the cost variable.
        if (included[i] == 0){
            cost += w[i];
        }
    }
    return cost;
}
//The calupperbound function calculates the upper bound of the cost for the remaining jobs that are not included in the schedule.
int calupperbound(int included[N]){
    
    int cost = 0;
    
    for (int i = 0; i < N; i++){
        if (included[i] == 0){
            cost += w[i];
        }
    }
    
    return cost;
}

//depth: depth of recursion
void solve(int job, int depth, int included[N], int cost)
{

    //Branching Condition:
    for (int i = job+1; i < N; i++){
// If the job is not included, it performs the following steps:
// It calculates the start time s[i] of the job based on the finish time of the previous job.
// If job is 0 (the first job), the start time is set to 0.
// Otherwise, the start time is set to the finish time of the previous job (f[job-1]).

        if (included[i] == 0){
            if (job == 0){
                s[i] = 0;
            } else {
                s[i] = f[job-1];
            }
            
            f[i] = s[i] + p[i]; // finsih time= start time+ processing time


//DEPICTS BOUNDING CONDITION
            if (f[i] <= d[i] ){ // finish<=deadline
               // printf("%d %d \n",calcost(i,included),upperbound);
                int cost1=calcost(i,included);
                if(cost1<upperbound){   //if cost of inlcuding<upperbound
                included[i]=1;   //updates the included array to mark the job as included.
                upperbound=calupperbound(included);
                best_time = upperbound;
            for (int i = 0; i < N; i++){
                best_included[i] = included[i];  //copies the included array to the best_included array to keep track of the jobs included in the optimal schedule.
            }
                solve(i, depth+1, included, cost1);   //recursive call to next job
                included[i] = 0;
                }
            }
            included[i] = 0;
        }
    }
}

int main()
{
    best_time =INT_MAX;
    int included[N] = {0};
    solve(0, 0, included, 0);

    printf("Minimum cost: %d\n", best_time);
    printf("Jobs included: ");
    for (int i = 0; i < N; i++) {
        if (best_included[i] == 1) {
            printf("%d ", i+1);
        }
    }
    printf("\n");

    printf("Path taken: ");
    int current_time = 0;
    for (int i = 0; i < N; i++) {
        if (best_included[i] == 1) {
            printf("%d ", i+1);
            current_time += p[i];
        }
    }
    printf("\n");

    return 0;
}
