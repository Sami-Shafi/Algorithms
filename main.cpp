#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        cout << f << " ";

        for (int child : adj_list[f])
        {
            if(vis[child] != false)
                continue;
            
            q.push(child);
            vis[child] = true;
        }
        
    }
    
}

int main() {
    
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs(0);
    
    return 0;
}