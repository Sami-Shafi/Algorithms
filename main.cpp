#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll memArr[1005];
ll fibo(ll n) {
    if (n < 2) return n;
    if(memArr[n] != -1) return memArr[n];
    return memArr[n] = fibo(n-1) + fibo(n-2);
}

int main() {
    memset(memArr, -1, sizeof(memArr));
    ll n;
    cin >> n;
    cout << fibo(n) << endl;

    return 0;
}
