#include <bits/stdc++.h>
using namespace std;
int leads[1005];
int group_size[1005];

// loop
// int find (int node)
// {
//     while (leads[node] != -1)
//     {
//         node = leads[node];
//     }
//     return node;
// }

// recursion
int find (int node)
{
    if(leads[node] == -1)
        return node;

    int newleads = find(leads[node]);
    leads[node] = newleads;
    return newleads;
}

void dsu_union(int node1, int node2) {
    int lead1 = find(node1);
    int lead2 = find(node2);

    if(group_size[lead1] >= group_size[lead2]) {
        leads[lead2] = lead1;
        group_size[lead1]+=group_size[lead2];
    }else {
        leads[lead1] = lead2;
        group_size[lead2]+=group_size[lead1];
    }
}

int main() {
    memset(leads, -1, sizeof(leads));
    memset(group_size, 1, sizeof(group_size));
    
    int n, e;
    cin >> n >> e;
    bool cycle = false;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        if(find(a) == find(b))
            cycle = true;
        else
            dsu_union(a, b);
    }
    if(cycle)
        cout << "Cycle Detected!" << endl;

    return 0;
}