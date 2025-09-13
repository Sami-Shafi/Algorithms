#include <bits/stdc++.h>
using namespace std;


// You will be given a positive integer N. You will start from 1 and do some steps (possibly zero).

// In each step you can choose one of the following:
// Add 3 with the current value
// Multiply by 2 with the current value

// Can you tell if you can reach n by using any number of steps you want.

bool reacher(int n) {
    if(n < 1)
        return false;
    
    if(n == 1)
        return true;

    if(n % 2 == 0)
        return reacher(n/2);
    else
        return reacher(n-3);
}

int main() {

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if(reacher(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}