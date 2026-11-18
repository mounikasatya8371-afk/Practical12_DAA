#include <stdio.h>

#define INF 99999
#define N 4

int tsp(int graph[N][N], int mask, int pos)
{
    if(mask == (1 << N) - 1)
        return graph[pos][0];

    int ans = INF;

    for(int city = 0; city < N; city++)
    {
        if((mask & (1 << city)) == 0)
        {
            int cost = graph[pos][city] +
                       tsp(graph, mask | (1 << city), city);

            if(cost < ans)
                ans = cost;
        }
    }

    return ans;
}

int main()
{
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    printf("Minimum cost = %d\n",
           tsp(graph, 1, 0));

    return 0;
}
