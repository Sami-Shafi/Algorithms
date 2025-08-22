#include <bits/stdc++.h>
using namespace std;

char grid[105][105];
bool vis[105][105];
vector<pair<int,int>> mv = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}

void bfs(int si, int sj){
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> fr = q.front();
        q.pop();

        cout << fr.first << " " << fr.second << endl;

        for (int i = 0; i < 4; i++)
        {
            int childRow = fr.first + mv[i].first;
            int childCol = fr.second + mv[i].second;

            if(valid(childRow, childCol) && !vis[childRow][childCol])
                {
                    q.push({childRow, childCol});
                    vis[childRow][childCol] = true;
                }
        }
        
    }
    
}

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    
    // print
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << grid[i][j] << " ";
    //     cout << endl;
    // }
    
    int srcRow, srcCol;
    cin >> srcRow >> srcCol;

    memset(vis, false, sizeof(vis));
    bfs(srcRow, srcCol);
    
    return 0;
}