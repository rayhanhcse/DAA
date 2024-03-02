#include<stdio.h>
int visited[10]={},adj[10][10],V,start;
void BFS(int start)
{
 int queue[10],rear = -1, front = -1;
 for(int i=0; i<V; i++)
 {
 visited[i] = 0;
 }
 queue[++rear] = start;
 ++front;
 visited[start] =1;
 while(rear >= front)
 {
 start = queue[front++];
 printf("%d ",start);
 for(int i = 0; i < V; i++)
 {
 if(adj[start][i] && visited[i] == 0)
 {
 queue[++rear] = i;
 visited[i] =1;
 }
 }
 }
}
void DFS(int start)
{
 int stack[10],top=-1;
 for(int i = 0; i < V; i++)
 {
 visited[i] =0;
 }
 stack[++top] = start;
 visited[start] = 1;
 while(top != -1)
 {
 start = stack[top--];
 printf("%d ",start);
 for(int i = 0; i < V; i++)
 {
 if(adj[start][i] && visited[i] ==0)
 {
 stack[++top] = i;
 visited[i] = 1;
 }
 }
 }
}
void main()
{
 printf("Enter the number of vertices:");
 scanf("%d",&V);
 printf("\nEnter graph data in matrix form:\n");
 for( int i=0;i<V;i++)
 {
 for(int j=0;j<V;j++)
 {
 scanf("%d",&adj[i][j]);
 }
 }
 printf("\nEnter the starting vertex:");
 scanf("%d",&start);
 printf("\nBFS for this graph is:\n");
 BFS(start);
 printf("\n\nDFS for this graph is:\n");
 DFS(start);
 printf("\n");
}