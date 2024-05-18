#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define maxSize 1000

bool vis[maxSize];
vector<int> adj[maxSize];
stack<int> q;
int level[maxSize];
int parent[maxSize];

void DFS(int node)
{
    if (!vis[node])
    {
        level[node] = 0;
        parent[node] = node;
        vis[node] = true;
        q.push(node);
        cout << "\nThe bfs traversal is :\n"
             << endl;

        while (!q.empty())
        {
            int fr = q.front();
            cout << fr << " ";
            q.pop();

            for (int i = 0; i < adj[fr].size(); ++i)
            {
                int v = adj[fr][i];

                if (!vis[v])
                {
                    level[v] = level[fr] + 1;
                    parent[v] = fr;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    cout << endl
         << endl;
}

int main()
{
    int n, e, node;
    cout << "Enter the value of the total nodes and the total edges:" << endl;
    cin >> n >> e;

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int d;
    cout << "Enter the starting node and the destination node:\n"
         << endl;
    cin >> node >> d;

    DFS(node);

    cout << "The level of the destination node" << d << "is" << level[d] << endl;

    cout << "The backtracked path from the destination to the source is:" << endl;

    int now = d;
    cout << now << " ";
    while (now != node)
    {
        now = parent[now];
        cout << now << " ";
    }
    return 0;
}