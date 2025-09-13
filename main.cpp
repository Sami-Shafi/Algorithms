#include <bits/stdc++.h>
using namespace std;

// The Tetranacci sequence is an extension of the well-known Fibonacci sequence, incorporating four previous terms instead of two.

// The Tetranacci sequence Tn is defined as follows:
// T0 = 0, T1 = 1, T2 = 1,T3 = 2
// For n >= 4, Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4
// Given an integer 𝑛, return the value of Tn

// Note : You must solve this problem using Recursion. (Top Down)

// Input Format
// A single integer n representing the position in the Tetranacci sequence.

int memArr[1005];
int tetra(int n) {
    if(memArr[n] != -1) return memArr[n];
    return memArr[n] = tetra(n-1) + tetra(n-2) + tetra(n-3) + tetra(n-4);
}

int main() {
    memset(memArr, -1, sizeof(memArr));
    memArr[0] = 0;
    memArr[1] = 1;
    memArr[2] = 1;
    memArr[3] = 2;
    int n;
    cin >> n;
    cout << tetra(n) << endl;

    return 0;
}