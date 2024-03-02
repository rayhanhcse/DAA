#include <stdio.h>
#define INFINITY 999
void dijkstra_f(int nodes, int src_node, int adj_mat[20][20], int short_dist[]) {
 int i, select_node, count, currentWeight, minWeight;
 int visited[20];
 for (i = 1; i <= nodes; i++) {
 visited[i] = 0;
 short_dist[i] = adj_mat[src_node][i];
 }
 visited[src_node] = 1;
 count = 2;
 while (count <= nodes) {
 minWeight = INFINITY;
 for (i = 1; i <= nodes; i++) {
 if (short_dist[i] < minWeight && !visited[i]) {
 minWeight = short_dist[i];
 select_node = i;
 }
 }
 visited[select_node] = 1;
 count++;
 for (i = 1; i <= nodes; i++) {
if ((short_dist[select_node] + adj_mat[select_node][i] < short_dist[i]) && 
!visited[i]) {
 short_dist[i] = short_dist[select_node] + adj_mat[select_node][i];
 }
 }
 }
}
int main() {
 int nodes, src_node, i, j, adj_mat[20][20], short_dist[20];
 printf("Enter the number of nodes: ");
 scanf("%d", &nodes);
 printf("\nEnter the adjacency matrix:\n");
 for (i = 1; i <= nodes; i++) {
 for (j = 1; j <= nodes; j++) {
 scanf("%d", &adj_mat[i][j]);
 if (adj_mat[i][j] == 0)
 adj_mat[i][j] = INFINITY;
 }
 }
 printf("\nEnter the source node: ");
 scanf("%d", &src_node);
 dijkstra_f(nodes, src_node, adj_mat, short_dist);
 printf("\nShortest paths:\n");
 for (i = 1; i <= nodes; i++) {
 if (i != src_node) {
 printf("%d -> %d, cost = %d\n", src_node, i, short_dist[i]);
 }
 }
 return 0;
}
