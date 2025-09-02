#include <bits/stdc++.h>
using namespace std;

int n,m, q;
vector<vector<pair<int, int>>> adj_list;
vector<int> weightArr;


void setUpWeightArr() {
    for (int i = 0; i < n; i++)
    {
        weightArr[i] = INT_MAX;
    }
    weightArr[0] = 0;
}

void printWeightArr() {
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << weightArr[i] << endl;
    }
}

void dijkstra(int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    weightArr[src] = 0;

    while (!pq.empty()) 
    {
        pair<int,int> par = pq.top();
        int p_weight = par.first;
        int p_node = par.second;

        for (auto childPair : adj_list[p_node])
        {
            int c_weight = par.first;
            int c_node = par.second;

            int latest_weight = p_weight+c_weight;
            if(latest_weight < weightArr[c_node]) {
                weightArr[c_node] = latest_weight;
                pq.push({weightArr[c_weight], c_node});
            }
        }
        
    }
    
}

int main() {

    cin >> n >> m >> q;
    int e = m;
    adj_list.resize(n);
    weightArr.resize(n);

    while (e--)
    {
        int a,b,c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    while (q--)
    {
        setUpWeightArr();
        int src, target;
        cin >> src >> target;
        dijkstra(src);
        cout << "src: " << src << " | Target: " << target << " | Weight: " << weightArr[target] << endl;
    }
    

    return 0;
}