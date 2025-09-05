#include <bits/stdc++.h>
using namespace std;

// You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and W which means there is a connection from A to B only and for which you need to give W cost. The value of nodes could be from 1 to N.

// You will be given a source node S. Then you will be given a test case T, for each test case you will be given a destination node D. You need to tell the minimum cost from source node to destination. If there is no possible path from S to D then print Not Possible.

// Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - "Negative Cycle Detected".

// Input Format

// First line will contain N and E.
// Next E lines will contain A, B and W.
// Next line will contain source node S.
// Next line will contain T, the number of test cases.
// For each test case, you will get D.

int n,e;

class Edge {
    public:
        int a, b, w;
        Edge (int a, int b, int w) {
            this->a = a;
            this->b = b;
            this->w = w;
        }
};

vector<Edge> edge_list;
vector<long long> cost;

bool negCycle = false, cycleDone = false;

void bellmanLoop() {
    for (auto edge : edge_list)
    {
        int a,b,w;
        a = edge.a;
        b = edge.b;
        w = edge.w;

        if(cost[a] == LLONG_MAX) continue;
        if(cost[a]+w < cost[b])
            if(!cycleDone)
                cost[b] = cost[a]+w;
            else{
                negCycle = true;
                break;
            }
    }
}

void bellmanFord() {
    for (int i = 1; i <= n-1; i++)
    {
        bellmanLoop();
    }
    cycleDone = true;
}

int main() {
    
    cin >> n >> e;
    cost.assign(n+5, LLONG_MAX);

    while (e--)
    {
        int a,b,w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a,b,w));
    }

    int src, t;
    cin >> src >> t;
    cost[src] = 0;

    bellmanFord();

    bellmanLoop();
    if(negCycle) {
        cout << "Negative Cycle Detected";
        return 0;
    }

    while (t--)
    {
        int d;
        cin >> d;
        if(cost[d] != LLONG_MAX)
            cout << cost[d] << endl;
        else
            cout << "Not Possible" << endl;
    }
    

    return 0;
}