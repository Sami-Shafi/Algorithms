#include <bits/stdc++.h>
using namespace std;

int sum(int n) {
    if (n < 1) return 0;
    return sum(n-1) + n;
}

int main() {

    int n;
    cout << "Input Number to get sum till 1" << endl;
    cin >> n;
    cout << sum(n) << endl;

    return 0;
}
