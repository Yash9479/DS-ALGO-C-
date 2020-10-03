#include <bits/stdc++.h>
using namespace std;


int n, m;
vector <bool> vis;
vector <vector <int>> g;

bool DFS(int node, int p)
{
    vis[node] = 1;

    for (int &x: g[node])
    {
        if (!vis[x])
        {
            // unvisited, but there is a cycle
            if (DFS(x, node)) return 1;
        }
        else
        {
            // visited and isn't node's parent
            if (x != p) return 1;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);


    cin >> n >> m;
    g.resize(n);
    vis.resize(n);

    while (m)
    {
        --m;
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool cycle = 0;

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (!vis[t1]) cycle |= DFS(t1, -1);
        if (cycle) break;
    }

    cout << cycle << '\n';



    return 0;
}