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
    
    dsu_union(1, 2);
    dsu_union(2, 0);
    dsu_union(3, 1);

    for (int i = 0; i < 6; i++)
        cout << i << " -> " << leads[i] << endl;

    return 0;
}