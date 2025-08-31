#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
// vector<vector<int>> level;
vector<pair<int,int>> mv = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
int n, m, cnt = 0, minArea = INT_MAX;

bool valid(int i, int j) {
    return !(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '-');
}

void dfs(int si, int sj, vector<vector<char>>& grid) {
    cnt++;
    vis[si][sj] = true;

    for(auto mvPair : mv) {
        int ci = si + mvPair.first;
        int cj = sj + mvPair.second;

        if (valid(ci, cj) && !vis[ci][cj]) {
            dfs(ci, cj, grid);
        }
    }
}

int main() {
    
    cin >> n >> m;
    grid.assign(n, vector<char>(m, ' '));
    vis.assign(n, vector<bool>(m, false));
    // level.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            {
                char ourChar;
                cin >> ourChar;
                grid[i][j] = ourChar;
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(grid[i][j] == '.' && !vis[i][j]) {
                dfs(i, j, grid);
                if(cnt < minArea)
                    minArea = cnt;
                cnt = 0;
            }

    if(minArea==INT_MAX)
        cout << -1;
    else 
        cout << minArea;
    
    return 0;
}