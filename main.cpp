#include <bits/stdc++.h>
using namespace std;

int n,e;

class Edge
{
    public:
        int a,b,c;
        Edge(int a, int b, int c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

vector<Edge> edge_list;
vector<int> weightArr;

void setUpWeightArr() {
    for (int i = 0; i < n; i++)
    {
        weightArr[i] = INT_MAX;
    }
    weightArr[0] = 0;
}

void bellmanFord() {
    
    setUpWeightArr();

    for (int i = 0; i < n-1; i++)
    {
        for (auto edge : edge_list)
        {
            int a,b,c;
            a = edge.a;
            b = edge.b;
            c = edge.c;

            if(weightArr[a] == INT_MAX) continue;

            int latestWeight = weightArr[a]+c;
            if(latestWeight < weightArr[b])
                weightArr[b] = latestWeight;
        }
    }
}

int main() {

    cin >> n >> e;
    weightArr.resize(n);
    edge_list.resize(e, Edge(0,0,0));

    while (e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }

    bellmanFord();
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << weightArr[i] << endl;
    }

    return 0;
}