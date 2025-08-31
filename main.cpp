#include <bits/stdc++.h>
using namespace std;

// Rezia is trapped in a 2D maze of NxM size, starting at position R, and her goal is to reach the exit marked by D. The maze contains blocks represented by #, and she can only traverse through cells marked with dots (.). As she need to escape as early as possible, we need to determine the path she will follow.

// Place an X in each cell representing Rezia's route to exit the maze. If there is no viable path for her to exit, leave the maze unchanged.

// Note: Rezia can move in four directions – right, left, up, and down. It is crucial to adhere to the specified order: attempting right first, then left, followed by up, and finally down.

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> mv = {{0,1}, {0,-1}, {-1,0}, {1,0}};
vector<vector<pair<int,int>>> parent;
int n, m;
int si,sj,di,dj;

bool valid(int i, int j) {
    return !(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '#');
}

void shortestDis(int si, int sj, int di, int dj) {
    if(!valid(si, sj) || !valid(di, dj)) return;
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    bool found = false;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int p_i = par.first;
        int p_j = par.second;

        if (p_i == di && p_j == dj){
            found = true;
            break;
        }

        for (auto mvPair : mv)
        {
            int ci = p_i + mvPair.first;
            int cj = p_j + mvPair.second;

            if(valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {p_i, p_j};
            }
        }
    }

    if(!found) return;
    int xi = di, xj = dj;
    while (grid[xi][xj] != 'R')
    {
        int par_i = parent[xi][xj].first;
        int par_j = parent[xi][xj].second;

        if(par_i == -1 || par_j == -1) break;
        if(grid[xi][xj] != 'R' && grid[xi][xj] != 'D')
            grid[xi][xj] = 'X';

        xi = par_i;
        xj = par_j;
    }
    

}

int main() {
    cin >> n >> m;
    grid.assign(n, vector<char>(m, '.'));
    vis.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            {
                char ourChar;
                cin >> ourChar;
                grid[i][j] = ourChar;

                if(ourChar == 'R'){
                    si = i;
                    sj = j;
                }else if(ourChar == 'D'){
                    di = i;
                    dj = j;
                }
            }

    shortestDis(si, sj, di, dj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j];
        cout << endl;
    }
    
    return 0;
}