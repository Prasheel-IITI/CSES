#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define int long long
 
const int M = 1e17;
 
struct Pos
{
    int pos;
    bool used;
    int cost;
};
 
struct Compare
{
    bool operator()(const Pos &a, Pos &b)
    {
        return a.cost > b.cost;
    }
};
 
signed main()
{
    int n, m;
    cin >> n >> m;
 
    vector<vector<pair<int, int>>> Adj(n + 1);
 
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        Adj[x].push_back({y, z});
    }
 
    priority_queue<Pos, vector<Pos>, Compare> Q;
 
    vector<vector<int>> Price(n + 1, vector<int>(2, M));
 
    Price[1][0] = 0;
    Price[1][1] = 0;
 
    Q.push(Pos{1, 0, 0});
 
    while (!Q.empty())
    {
        Pos P = Q.top();
        Q.pop();
 
        if (P.cost != Price[P.pos][P.used])
        {
            continue;
        }
 
        if (P.pos == n)
        {
            break;
        }
 
        for (pair<int, int> I : Adj[P.pos])
        {
            if (!P.used)
            {
                int wt = P.cost + I.second / 2;
                if (wt < Price[I.first][1])
                {
                    Price[I.first][1] = wt;
                    Q.push({I.first, 1, wt});
                }
            }
            int wt = P.cost + I.second;
            if (wt < Price[I.first][P.used])
            {
                Price[I.first][P.used] = wt;
                Q.push({I.first, P.used, wt});
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << Price[i][0] << " " << Price[i][1] << endl;
    // }
    // cout << endl;
    cout << Price[n][1] << endl;
}
