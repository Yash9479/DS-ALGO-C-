#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);


    int n, m;
    cin >> n >> m;
    vector <vector <int>> g(n);

    for (int i = 0; i < n; ++i)
    {
	// initialization
        g[i].assign(n, 10000000LL);
        g[i][i] = 0;
    }

    while (m)
    {
        --m;
        int a, b, c;
        cin >> a >> b >> c; // edge 1, edge 2, cost
        if (c < g[a][b]) g[a][b] = g[b][a] = c;
    }

    // Floyd-Warshall's algo
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (g[j][k] > g[j][i]+g[i][k])
                    g[j][k] = g[j][i]+g[i][k];
            }
        }
    }

    // prints lengths of the shortest path from i to j
    for (int i = 0; i < n; ++i)
    {
        cout << i << ":  ";

        for (int j = 0; j < n; ++j)
            cout << g[i][j] << ' ';

        cout << '\n';
    }


    return 0;
}