#include <bits/stdc++.h>
using namespace std;
#define maxSize 1000
#define INF INT_MAX

vector<pair<int, int>> adj[maxSize]; // Each pair stores (neighbor, weight)
int dist[maxSize];                   // Stores the shortest distance from the source
int parent[maxSize];                 // Stores the parent of each node in the shortest path

void Dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue
    fill(dist, dist + maxSize, INF);                                                    // Initialize distances with INF
    dist[src] = 0;
    parent[src] = src;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        // Iterate over all neighbors of node u
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, e, src, dest;
    cout << "Enter the number of nodes and edges:" << endl;
    cin >> n >> e;

    cout << "Enter the edges (node1 node2 weight):" << endl;
    for (int i = 0; i < e; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w); // Remove this line if the graph is directed
    }

    cout << "Enter the starting node and the destination node:" << endl;
    cin >> src >> dest;

    Dijkstra(src);

    cout << "The shortest distance to the destination node " << dest << " is " << dist[dest] << endl;

    cout << "The path from the destination to the source is:" << endl;
    int now = dest;
    stack<int> path;
    while (now != src)
    {
        path.push(now);
        now = parent[now];
    }
    path.push(src);

    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;

    return 0;
}
