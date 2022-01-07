#include "bits/stdc++.h"
using namespace std;

#define int long long
const int INF = 1e17;

void bellmanFord(int v, int n, vector<vector<int>> &edges)
{

    // for (auto &edge : edges)
    // {
    //     cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    // }
    // cout << endl;

    vector<int> traceback(v + 1);
    vector<int> dist(v + 1, 0);
    // dist[1] = 0;

    int x = -1;
    for (int i = 0; i <= n; i++)
    {
        x = -1;
        for (auto &edge : edges)
        {
            if (dist[edge[0]] + edge[2] < dist[edge[1]])
            {
                dist[edge[1]] = dist[edge[0]] + edge[2];
                traceback[edge[1]] = edge[0];
                x = traceback[edge[1]];
            }
        }
    }

    // for (int i : traceback)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    if (x == -1)
    {
        cout << "NO";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        x = traceback[x];
    }

    vector<int> ans;

    for (int v = x;; v = traceback[v])
    {
        ans.push_back(v);
        if (v == x and ans.size() != 1)
        {
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << "YES\n";
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return;
}

signed main()
{
    int v, n;
    cin >> v >> n;
    vector<vector<int>> edges(n);

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }

    bellmanFord(v, n, edges);
}
