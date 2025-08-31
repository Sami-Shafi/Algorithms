#include <bits/stdc++.h>
using namespace std;

// You will be given a chessboard of NxM size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell K(Ki and Kj), and the queen's cell Q(Qi and Qj). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move. A knight move in 8 directions. Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print -1.

// First line will contain T, the number of test cases.
// First line of each test case will contain N and M.
// Second line of each test case will contain Ki and Kj.
// Third line of each test case will contain Qi and Qj.

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<int>> level;
vector<pair<int,int>> mv = {{-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}};
int n, m;
int si,sj,di,dj;

bool valid(int i, int j) {
    return !(i<0 || i>=n || j<0 || j>=m);
}

int shortestDis(int si, int sj, int di, int dj) {
    if(!valid(si, sj) || !valid(di, dj)) return -1;
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int p_i = par.first;
        int p_j = par.second;

        if(p_i == di && p_j == dj) return level[p_i][p_j];

        for (auto mvPair : mv)
        {
            int ci = p_i + mvPair.first;
            int cj = p_j + mvPair.second;

            if(valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
        
    }
    return -1;
}

int main() {

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;
        grid.assign(n, vector<char>(m, '.'));
        vis.assign(n, vector<bool>(m, false));
        level.assign(n, vector<int>(m, -1));

        cin >> si >> sj >> di >> dj;
        if(si == di && sj == dj) {
            cout << 0 << endl;
            continue;
        }
        cout << shortestDis(si, sj, di, dj) << endl;
    }
    
    return 0;
}