#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<bool> pathVis;
bool cycle;

void dfs(int src) {
    vis[src] = true;
    pathVis[src] = true;

    for (int child : adj_list[src])
    {
        if(!vis[child]) {
            pathVis[child] = true;
            vis[child] = true;
            dfs(child);
        }else if (pathVis[child]) cycle = true;
    }
    pathVis[src] = false;
}

int main ()
{
    int n, e;
    cin >> n >> e;
    adj_list.assign(n, {});
    vis.assign(n, false);
    pathVis.assign(n, false);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    cycle = false;
    for (int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i);

    cout << (cycle ? "Cycle Detected!" : "No Cycle!") << endl;
    
    return 0;
}