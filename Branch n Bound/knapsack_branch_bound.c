#include <stdio.h>
#include <stdlib.h>

#define N 4

int included[N] = {0};
int profit[N] = {50, 49, 36, 20};
int weight[N] = {5, 7, 6, 4};
int cap = 11;
int maxprofit = 0;
int upperbound(int level, int w, int p)
{
    int bound = p;
    int newcap = cap - w;
    while (level < N && newcap > 0)
    {
        if (newcap >= weight[level])
        {
            newcap -= weight[level];
            bound += profit[level];
        }
        else
        {
            bound += newcap * ((float)profit[level] / weight[level]);
            newcap = 0;
        }
        level++;
    }
    return bound;
}

int feasible(int level, int w, int p)
{
    if (w > cap)
    {
        return 0;
    }
    if (level > N)
    {
        return 0;
    }
    return upperbound(level, w, p) >= maxprofit;
}

void knap(int level, int w, int p)
{
    
    if(level==4 && feasible(level, w, p)){
        printf("items included: ");
        for (int i = 0; i < N; i++)
    {
        if (included[i])
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
    }
    else if (feasible(level, w, p))
    
    {
        if (p > maxprofit)
        {
            maxprofit = p;
        }
        included[level] = 1;
        knap(level + 1, w + weight[level], p + profit[level]);
        included[level] = 0;
        knap(level + 1, w, p);
    }
    
}
int main()
{
    knap(0, 0, 0);
    printf("Maximum profit: %d\n", maxprofit);
    return 0;
}