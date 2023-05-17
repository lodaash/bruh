#include<stdio.h>
#include<conio.h>
// a and b represent the nodes of an edge, while u and v are temporary variables used for comparisons.
// n represents the number of nodes in the graph.
//ne is an edge counter, initialized as 1.
// min represents the minimum cost during each iteration.
// mincost stores the minimum cost of the MST.
// visited is an array to track visited nodes.
int a,b,u,v,n,i,j,ne=1;
int visited[10]= {0},min,mincost=0,cost[10][10];
void main() {
	
	printf("\n Enter the number of nodes:");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++) {
		scanf("%d",&cost[i][j]);
		if(cost[i][j]==0)
		    cost[i][j]=999;
	}
	visited[1]=1; //After the adjacency matrix is populated, the code initializes visited[1] as 1, marking the first node as visited
	printf("\n");

	//The while loop continues until ne reaches n, indicating that all nodes have been included in the MST.
	while(ne<n) {
		for (i=1,min=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		    if(cost[i][j]<min)
		     if(visited[i]!=0) {
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		//If either visited[u] or visited[v] is 0, it means that one of the nodes is not yet visited, and the code proceeds to include that edge in the MST.
		if(visited[u]==0 || visited[v]==0) {
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999; //The cost of the selected edge is set to 999 to exclude it from future considerations.
	}
	printf("\n Minimun cost=%d",mincost);
	
}