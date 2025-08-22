#include <bits/stdc++.h>
using namespace std;

// You are given an NXM sized 2D matrix that represents a map of a building. Each cell represents a wall, a floor or a room. You will be given two rooms A and B. You need to tell if you can go from room  to  by passing through the floors. You can walk left, right, up, and down through the floor cells. You can't pass through walls.

// Input Format
// The first input line has two integers N and M: the height and width of the map.
// Then there are N lines of M characters describing the map. Each character is .(floor), #(wall), A or B (rooms).

// Output Format
// Output YES if you can go from room  to , NO otherwise.

// Sample Input 0
// 5 8
// ########
// #.A#...#
// #.##.#B#
// #......#
// ########

// Sample Output 0
// YES

char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
vector<pair<int,int>> mv = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}

void reachabilityWithBFS(int si, int sj, int di, int dj) {
    if(!valid(si, sj)) return;
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> fr = q.front();
        q.pop();

        // cout << "Parent -> " << fr.first << " " << fr.second << endl;

        for (int i = 0; i < 4; i++)
        {
            int ci = fr.first + mv[i].first;
            int cj = fr.second + mv[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[fr.first][fr.second] + 1;
            }
        }
        
    }
    
    if(level[di][dj] == -1){
        cout << "NO";
    }else {
        cout << "YES";
    }
}

int main() {
    
    cin >> n >> m;
    int si,sj,di,dj;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            {
                char ourChar;
                cin >> ourChar;
                grid[i][j] = ourChar;
                if(ourChar == 'A'){
                    si = i;
                    sj = j;
                }else if(ourChar == 'B'){
                    di = i;
                    dj = j;
                }
            }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    reachabilityWithBFS(si, sj, di, dj);
    // cout << si << " " << sj << " |" << " " << di << " " << dj;

    return 0;
}