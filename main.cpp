#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> adj_list;
vector<int> weightArr;

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({src, 0});
    weightArr[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();

        int p_weight = par.first;
        int p_node = par.second;

        for (auto child : adj_list[p_node])
        {
            int c_node = child.first;
            int c_weight = child.second;

            int latest_weight = p_weight+c_weight;
            if(latest_weight < weightArr[c_node])
            {
                weightArr[c_node] = latest_weight;
                pq.push({weightArr[c_node], c_node});
            }
        }
        
    }
    
}

int main ()
{
    int n, e;
    cin >> n >> e;
    
    adj_list.resize(n);
    weightArr.assign(n, INT_MAX);
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        cout << weightArr[i] << endl;
    }
    
    return 0;
}