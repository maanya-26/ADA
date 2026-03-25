#include <stdio.h>
#define MAX 100
#define INF 99999

int main() {
    int n, cost[MAX][MAX], visited[MAX] = {0};
    int i, j, ne = 0;
    int min, mincost = 0;
    int a, b;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(ne < n - 1) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", a, b, min);
        mincost += min;
        visited[b] = 1;
        ne++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
