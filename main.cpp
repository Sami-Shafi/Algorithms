#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj_mat;

bool valid(int num) {
    return !(num >= INT_MAX);
}

void floydHarshall() {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int altPath = adj_mat[i][k] + adj_mat[k][j];
                int mainPath = adj_mat[i][j];
                if(valid(adj_mat[i][k]) && valid(adj_mat[k][j]) &&  altPath < mainPath)
                    adj_mat[i][j] = altPath;
            }
}


int main() {

    cin >> n >> m;
    int e = m;
    adj_mat.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(i!=j)
                adj_mat[i][j] = INT_MAX;

    while (e--)
    {
        int a,b,c;
        cin >> a >> b >> c;

        adj_mat[a][b] = c;
        // for undirected
        // adj_mat[b][a] = c;
    }
    
    floydHarshall();

    bool cycle = false;
    for (int i = 0; i < n; i++)
        if(adj_mat[i][i] < 0)
            cycle = true;
    
    if(!cycle) {
        // print matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                if(adj_mat[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << adj_mat[i][j] << "   ";
        
            cout << endl;
        }
    }else 
        cout << "Negative-Weighted Cycle Detected!";


    return 0;
}