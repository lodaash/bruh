#include<stdio.h>

#include<conio.h>

#define INFINITY 9999

#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode);

int main()

{

    

    int G[MAX][MAX],i,j,n,u;

    printf("Enter no. of vertices:");

    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:\n");

    for(i=0;i<n;i++)

    for(j=0;j<n;j++)

    scanf("%d",&G[i][j]);

    printf("\nEnter the starting node:");

    scanf("%d",&u);

    dijkstra(G,n,u);

    getch();

    return 0;

}

void dijkstra(int G[MAX][MAX],int n,int startnode)

{

    int cost[MAX][MAX],distance[MAX],pred[MAX];

    int visited[MAX],count,mindistance,nextnode,i,j;

    //pred[] stores the predecessor of each node

    //count gives the number of nodes seen so far

    //create the cost matrix

    for(i=0;i<n;i++)

    for(j=0;j<n;j++)

    { if(G[i][j]==0)

    cost[i][j]=INFINITY;

    else

    cost[i][j]=G[i][j];

    }

    //initialize pred[],distance[] and visited[]

    for(i=0;i<n;i++)

    {

    distance[i]=cost[startnode][i];

    pred[i]=startnode;

    visited[i]=0;

    }

    distance[startnode]=0;

    visited[startnode]=1;

    count=1;

    while(count<n-1)

    {

     mindistance=INFINITY;

    //nextnode gives the node at minimum distance

    for(i=0;i<n;i++)

    if(distance[i]<mindistance&&!visited[i])

    {

    mindistance=distance[i];

    nextnode=i;

    }

    //check if a better path exists through nextnode

    visited[nextnode]=1;

    for(i=0;i<n;i++)

    if(!visited[i])

    if(mindistance+cost[nextnode][i]<distance[i])

    {

     distance[i]=mindistance+cost[nextnode][i];

     pred[i]=nextnode;

    }

   count++;

    }

    //print the path and distance of each node

    for(i=0;i<n;i++)

    if(i!=startnode)

{

    printf("\nDistance of node%d=%d",i,distance[i]);

    printf("\nPath=%d",i);

    j=i;

    do

    {

      j=pred[j];

      printf("<-%d",j);

    }while(j!=startnode);

      }

}



// Djikstras - another method:

#include <stdio.h>
#include <limits.h>

#define V 9

int minDistance(int dist[], int sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t%d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (sptSet[v] == 0 && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}
