#include <bits/stdc++.h>
using namespace std;

// You are given an array H representing the heights of N vertical lines positioned at equally spaced intervals along a two-dimensional plane. The i-th line's height is represented by the integer H where 0 <= i < N and the height will be unique.

// You need to find the two lines, such that together with the x-axis forms a container that can hold the most water in term of height.

// Note: Print the left index first, then the right index.

// Input Format
// First line will contain T, the number of test cases.
// First line of each test case will contain N.
// Second line of each test case will contain the array H.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> heights(n);

        for (int i = 0; i < n; i++)
            cin >> heights[i];

        int highest = -1, secondHighest = -1;
        int lWallIndex = -1, rWallIndex = -1;

        for (int i = 0; i < n; i++) {
            if (heights[i] > highest) {
                secondHighest = highest; rWallIndex = lWallIndex;
                highest = heights[i]; lWallIndex = i;
            } else if (heights[i] > secondHighest) {
                secondHighest = heights[i];
                rWallIndex = i;
            }
        }

        if (lWallIndex > rWallIndex)
            swap(lWallIndex, rWallIndex);

        cout << lWallIndex << " " << rWallIndex << endl;
    }
    return 0;
}
