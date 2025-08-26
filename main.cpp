#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt, n, m;
    vector<vector<bool>> vis;
    vector<pair<int,int>> mv = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    bool valid(int i, int j) {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }

    void dfs(int si, int sj, vector<vector<char>>& grid) {
        vis[si][sj] = true;

        for(pair mvPair : mv) {
            int ci = si + mvPair.first;
            int cj = sj + mvPair.second;

            if (valid(ci, cj) && grid[ci][cj] == '1' && !vis[ci][cj])
                {
                    dfs(ci, cj, grid);
                }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        cnt = 0;
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && grid[i][j] == '1')
                    {
                        cnt++;
                        dfs(i, j, grid);
                    }

        return cnt;
    }
};