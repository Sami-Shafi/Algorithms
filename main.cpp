#include <bits/stdc++.h>
using namespace std;

int n,e;
vector<int> leads;
vector<int> group_size;

// You will be given an undirected graph where there will be N nodes and E edges. You need to tell the number of edges that can create a cycle in the graph. Note: Duplicate edges as input can not be possible. The value of nodes are from 1 to N.

// Input Format
// First line will contain N and E.
// Next lines will contain A and B which means there is a edge between A and B.

int find (int node)
{
    if(leads[node] == -1)
        return node;

    leads[node] = find(leads[node]);
    return leads[node];
}

void dsu_union(int lead1, int lead2) {
    if(group_size[lead1] >= group_size[lead2]) {
        leads[lead2] = lead1;
        group_size[lead1]+=group_size[lead2];
    }else {
        leads[lead1] = lead2;
        group_size[lead2]+=group_size[lead1];
    }
}

int main() {
    
    cin >> n >> e;
    leads.assign(n+5, -1);
    group_size.assign(n+5, 1);

    int cycle = 0;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        int lead1 = find(a);
        int lead2 = find(b);
        if(lead1 == lead2)
            cycle++;
        else
            dsu_union(lead1, lead2);
    }

    cout << cycle << endl;

    return 0;
}
