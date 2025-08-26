#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int cnt, n, m;
    vector<vector<bool>> vis1;
    vector<vector<bool>> vis2;
    vector<pair<int,int>> mv = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool match = true;

    bool valid(int i, int j) {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }

    void dfs(int si, int sj, vector<vector<int>>& grid) {
        vis1[si][sj] = true;

        for(pair mvPair : mv) {
            int ci = si + mvPair.first;
            int cj = sj + mvPair.second;

            if (valid(ci, cj) && grid[ci][cj] == 1 && !vis1[ci][cj])
                dfs(ci, cj, grid);
        }
    }

    void dfsSub(int si, int sj, vector<vector<int>>& grid) {
        vis2[si][sj] = true;

        if(!vis1[si][sj]) {
            match = false;
        }

        for(pair mvPair : mv) {
            int ci = si + mvPair.first;
            int cj = sj + mvPair.second;

            if (valid(ci, cj) && grid[ci][cj] == 1 && !vis2[ci][cj]){
                dfsSub(ci, cj, grid);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        cnt = 0;
        n = grid1.size();
        m = grid1[0].size();
        vis1.assign(n, vector<bool>(m, false));
        vis2.assign(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis1[i][j] && grid1[i][j] == 1)
                    dfs(i, j, grid1);
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis2[i][j] && grid2[i][j] == 1)
                {
                    match = true;
                    dfsSub(i, j, grid2);
                    if(match) cnt++;
                }

        return cnt;
    }
};