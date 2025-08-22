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

void dfs(int si, int sj){
    // cout << "Parent Index: ";
    cout << si << " " << sj << endl;
    // cout << "-----------" << endl;
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int childRow, childCol;
        childRow = si + mv[i].first;
        childCol = sj + mv[i].second;
        // cout << "Child Index: " << childRow << " " << childCol << endl;
        if(valid(childRow, childCol) && !vis[childRow][childCol])
            dfs(childRow, childCol);
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
    dfs(srcRow, srcCol);
    
    return 0;
}