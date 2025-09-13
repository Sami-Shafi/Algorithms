#include<bits/stdc++.h>
using namespace std;

vector<int> val;
vector<int> weight;

int knapsack(int idx, int weight_cap) {
    if(idx < 0 || weight_cap == 0)
        return 0;

    int opt1 = knapsack(idx-1, weight_cap-weight[idx]) + val[idx];
    int opt2 = knapsack(idx-1, weight_cap);
    if(weight[idx] <= weight_cap)
        return max(opt1, opt2);
    else
        return opt2;
}

int main ()
{
    int n, weight_cap;
    cin >> n;
    val.resize(n);
    weight.resize(n);

    for (int i = 0; i < n; i++)
        cin >> val[i];
    
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> weight_cap;
    cout << knapsack(n-1, weight_cap) << endl;
    
    return 0;
}