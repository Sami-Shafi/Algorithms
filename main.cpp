#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<int> parent;
bool cycle;

void dfs(int src) {
    vis[src] = true;
    
    for (int child : adj_list[src])
    {
        if(!vis[child]) {
            parent[child] = src;
            dfs(child);
        }else if (parent[src] != child) cycle = true;
    }
    
}

int main ()
{
    int n, e;
    cin >> n >> e;
    adj_list.assign(n, {});
    vis.assign(n, false);
    parent.assign(n, -1);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);

        // do not include for directed
        adj_list[b].push_back(a);
    }

    cycle = false;
    for (int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i);

    cout << (cycle ? "Cycle Detected!" : "No Cycle!") << endl;
    
    return 0;
}