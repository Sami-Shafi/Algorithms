#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<int> parent;
bool cycle;

void bfs(int src) {
    queue<int> q;
    vis[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int fr = q.front();
        q.pop();

        for (int child : adj_list[fr]) {
            if(vis[child] && parent[fr] != child) cycle = true;

            if(!vis[child]) {
                q.push(child);
                vis[child] = true;
                parent[child] = fr;
            }
        }
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
            bfs(i);

    cout << (cycle ? "Cycle Detected!" : "No Cycle!") << endl;
    
    return 0;
}