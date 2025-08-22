#include <bits/stdc++.h>
using namespace std;

// You are given an NXM sized 2D matrix that represents a map of a building. Each cell represents a wall or a room. The connected rooms are called apartments. Your task is to count the number of apartments in that building. You can walk left, right, up, and down through the room cells. You can't pass through walls.

// Input Format
// The first input line has two integers N and M: the height and width of the map.
// Then there are N lines of M characters describing the map. Each character is either .(room) or #(wall).

// Output Format
// Output the number of apartments

// Sample Input 0
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########

// Sample Output 0
// 3

// Sample Input 1
// 6 8
// .#.#####
// .#.###..
// #..#...#
// #.##....
// ..##.###
// #.#.##.#

// Sample Output 1
// 5

char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> mv = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j) {
    if (i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}

void dfs(int si, int sj) {
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + mv[i].first;
        int cj = sj + mv[i].second;
        
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
    
}

int main() {
    
    cin >> n >> m;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int apartments = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '.') {
                apartments++;
                dfs(i, j);
            }
        }
    }

    cout << apartments << endl;

    // memset(level, -1, sizeof(level));
    // cout << si << " " << sj << " |" << " " << di << " " << dj;

    return 0;
}