#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<vector<long long int>> adj_mat;

// You'll be given a graph of N nodes and E edges. For each edge, you'll be given A, B and W which means there is an edge from A to B only and which will cost W.

// Also, you'll be given Q queries, for each query you'll be given S and D, where S is the source and D is the destination. You need to print the minimum cost from S to D for each query. If there is no connection between S and D, print -1.

// Note: There can be multiple edges from one node to another. Make sure you handle this one.

// Input Format

// First line will contain N and E.
// Next E lines will contain A, B and W.
// After that you'll get Q.
// Next Q queries will contain S and D.

void floydWarshall () {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX)
                    adj_mat[i][j] = min(adj_mat[i][k]+adj_mat[k][j], adj_mat[i][j]);
    
}

int main() {
    
    cin >> n >> e;
    adj_mat.assign(n+5, vector<long long int>(n+5, LLONG_MAX));

    for (int i = 1; i <= n; i++)
        adj_mat[i][i] = 0;

    while (e--)
    {
        int a,b;
        long long int w;
        cin >> a >> b >> w;
        adj_mat[a][b] = min(adj_mat[a][b], w);
    }
    
    floydWarshall();

    int q;
    cin >> q;
    while (q--)
    {
        int s,d;
        cin >> s >> d;

        if(adj_mat[s][d] != LLONG_MAX)
            cout << adj_mat[s][d] << endl;
        else
            cout << -1 << endl;
    }
    

    return 0;
}
