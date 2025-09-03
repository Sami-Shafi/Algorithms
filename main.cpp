#include <bits/stdc++.h>
using namespace std;

// There are n cities and m roads between them. Your task is to process q queries where you have to determine the length of the shortest route between two given cities.
// Input
// The first input line has three integers n, m and q: the number of cities, roads, and queries.
// Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. All roads are two-way roads.
// Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between cities a and b.
// Output
// Print the length of the shortest route for each query. If there is no route, print -1 instead.

// Example
// Input:
// 4 3 5
// 1 2 5
// 1 3 9
// 2 3 3
// 1 2
// 2 1
// 1 3
// 1 4
// 3 2

// Output:
// 5
// 5
// 8
// -1
// 3

int n,m,q;
vector<vector<long long int>> adj_mat;

void floydHarshall() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            if (adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX)
                    adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
}


int main() {

    cin >> n >> m >> q;
    adj_mat.assign(n+5, vector<long long int>(n+5, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(i!=j) {
                adj_mat[i][j] = LLONG_MAX;
            }

    while (m--)
    {
        long long int a,b,c;
        cin >> a >> b >> c;

        int minWeight = min(adj_mat[a][b], c);
        adj_mat[a][b] = minWeight;
        adj_mat[b][a] = minWeight;
    }
    
    floydHarshall();

    while (q--)
    {
        long long int src, target;
        cin >> src >> target;

        if(adj_mat[src][target] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[src][target] << endl;
    }

    return 0;
}