#include <stdio.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int item)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = item;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;

    return queue[front++];
}

int main()
{
    int n, i, j;
    int adj[MAX][MAX];
    int indegree[MAX] = {0};
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    while(front <= rear)
    {
        int vertex = dequeue();
        printf("%d ", vertex);
        count++;

        for(i = 0; i < n; i++)
        {
            if(adj[vertex][i] == 1)
            {
                indegree[i]--;

                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if(count != n)
    {
        printf("\nGraph contains a cycle. Topological ordering not possible.\n");
    }

    return 0;
}
