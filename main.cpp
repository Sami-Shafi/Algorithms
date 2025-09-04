#include <bits/stdc++.h>
using namespace std;
int leads[1005];

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

int main() {
    memset(leads, -1, sizeof(leads));
    leads[0] = 1;
    leads[1] = -1;
    leads[2] = 7;
    leads[3] = 1;
    leads[4] = 5;
    leads[5] = 3;

    cout << find(4) << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << i << " -> " << leads[i] << endl;
    }
    

    return 0;
}