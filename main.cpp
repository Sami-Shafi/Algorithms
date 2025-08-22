#include <bits/stdc++.h>
using namespace std;

// You will be given an undirected graph as input. Then you will be given Q queries. For each query you will be given a node X. You need to print the nodes that are connected with X in descending order.

// Note: If there is no node connected to X, then print -1.

// Input Format
// The first line will contain N and E, the number of nodes and the number of edges, respectively. The values of the nodes range from 0 to N-1.
// Next E lines will contain two node values which means there is a connection between first node and second node.
// The next line will contain Q.
// The following Q lines will each contain X.

// Output Format
// Output the nodes that are connected with  in descending order.

int main() {
    
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[n];        

    while (e--)
    {
        int i, j;
        cin >> i >> j;

        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
    }


    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";

    //     for (int x : adj_list[i])
    //         cout << x << " ";
    //     cout << endl;
    // }

    int q;
    cin >> q;
        
    while (q--)
    {
        int x;
        cin >> x;

        vector<int> targetVector(adj_list[x]);
        if(targetVector.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        sort(targetVector.begin(), targetVector.end(), greater<int>());
        for(int ans : targetVector)
            cout << ans << " ";
        cout << endl;
    }
    
    
    return 0;
}