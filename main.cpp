#include<bits/stdc++.h>
using namespace std;

vector<int> val;
vector<int> weight;
vector<vector<int>> dp;

int knapsack(int idx, int weight_cap) {
    if(idx < 0 || weight_cap <= 0)
        return 0;

    if(dp[idx][weight_cap] != -1)
        return dp[idx][weight_cap];
    
    int opt1 = 0;
    if(weight[idx] <= weight_cap)
        opt1 = knapsack(idx-1, weight_cap-weight[idx]) + val[idx];

    int opt2 = knapsack(idx-1, weight_cap);
    
    return dp[idx][weight_cap] = max(opt1, opt2);
}

int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, weight_cap;
        cin >> n >> weight_cap;
        val.assign(n, 0);
        weight.assign(n, 0);
        dp.assign(n, vector<int>(weight_cap+5, -1));

        for (int i = 0; i < n; i++)
            cin >> weight[i];
        
        for (int i = 0; i < n; i++)
            cin >> val[i];
        
        cout << knapsack(n-1, weight_cap) << endl;
    }
    
    return 0;
}