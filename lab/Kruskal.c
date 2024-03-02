#include<stdio.h>
#include<stdlib.h>

#define INF 999

int i, j, vrtx1, vrtx2, u, v, n_vrtx, edge_cnt = 0;
int min_wght, t_min_cost = 0, adj_mat[9][9], parent[9];

int findSet_f(int);
int unionSet_f(int, int);

int main() {
    printf("\nKruskal's Algorithm Implementation\n\n");
    printf("\nEnter the number of vertices\n");
    scanf("%d", &n_vrtx);
    printf("\nEnter the cost adjacency matrix\n");
    for (i = 0; i < n_vrtx; i++) {
        for (j = 0; j < n_vrtx; j++) {
            scanf("%d", &adj_mat[i][j]);
            if (adj_mat[i][j] == 0)
                adj_mat[i][j] = INF;
        }
    }
    printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
    while (edge_cnt < n_vrtx - 1) {
        for (i = 0, min_wght = INF; i < n_vrtx; i++) {
            for (j = 0; j < n_vrtx; j++) {
                if (adj_mat[i][j] < min_wght) {
                    min_wght = adj_mat[i][j];
                    vrtx1 = u = i;
                    vrtx2 = v = j;
                }
            }
        }
        u = findSet_f(u);
        v = findSet_f(v);
        if (unionSet_f(u, v)) {
            printf("\n%d edge (%d,%d) = %d\n", ++edge_cnt, vrtx1 + 1, vrtx2 + 1, min_wght);
            t_min_cost += min_wght;
        }
        adj_mat[vrtx1][vrtx2] = adj_mat[vrtx2][vrtx1] = INF;
    }
    printf("\n\tTotal Minimum Cost = %d\n", t_min_cost);
    return 0;
}

int findSet_f(int vertex) {
    while (parent[vertex])
        vertex = parent[vertex];
    return vertex;
}

int unionSet_f(int vrtx1, int vrtx2) {
    if (vrtx1 != vrtx2) {
        parent[vrtx2] = vrtx1;
        return 1;
    }
    return 0;
}
