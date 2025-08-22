#include <bits/stdc++.h>
using namespace std;

// Problem Statement
// You will be given a directed graph as input. Then you will receive Q queries. For each query, you will be given two nodes, A and B. You need to determine whether you can go from A to B directly without using any other nodes.

// Input Format
// The first line will contain N and E, the number of nodes and the number of edges, respectively. The values of the nodes range from 0 to N-1.
// Next E lines will contain two node values which means there is a connection from first node to second node.
// The next line will contain Q.
// The following Q lines will each contain A and B.

// Output Format
// For each query output YES if it is possible to go from A to B directly without using any other nodes, NO otherwise. Don't forget to put a new line after each query.

int main() {
    
    int n, e;
    cin >> n >> e;
    int mt[n][n];
    memset(mt, 0, sizeof(mt));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(i==j)
                mt[i][j]=1;
        

    while (e--)
    {
        int i, j;
        cin >> i >> j;

        mt[i][j] = 1;
    }


    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //             cout << mt[i][j] << " ";
    //     cout << endl;
    // }

    int q;
    cin >> q;
        
    while (q--)
    {
        int i, j;
        cin >> i >> j;

        if(mt[i][j] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    
    return 0;
}