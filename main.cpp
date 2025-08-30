#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<int>> level;
vector<pair<int,int>> mv = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=m || grid[i][j] == '-') return false;
    return true;
}

void sameComp(int si, int sj, int di, int dj) {
    if(!valid(si, sj) || !valid(di, dj)) return;
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (int i = 0; i < mv.size(); i++)
        {
            int ci = par.first + mv[i].first;
            int cj = par.second + mv[i].second;

            if(valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
        
    }
}

int main() {
    
    cin >> n >> m;
    grid.assign(n, vector<char>(m, ' '));
    vis.assign(n, vector<bool>(m, false));
    level.assign(n, vector<int>(m, -1));
    int si,sj,di,dj;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            {
                char ourChar;
                cin >> ourChar;
                grid[i][j] = ourChar;
            }

    cin >> si >> sj >> di >> dj;
    sameComp(si, sj, di, dj);

    if(level[di][dj] == -1){
        cout << "NO";
    }else {
        cout << "YES";
    }

    return 0;
}