#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj_list;
    vector<bool> vis;

    void dfs(int src) {
        vis[src] = true;
        for (int ch : adj_list[src])
            if(!vis[ch])
                dfs(ch);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj_list.assign(n, {});
        vis.assign(n, false);
        for (int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        dfs(source);
        return vis[destination];
    }
};