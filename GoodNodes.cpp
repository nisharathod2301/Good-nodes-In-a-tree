#include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

int findgn(const vector<int>& v, int len, int i, int max) {
    if (i >= len)
        return 0;

    int lc = 2 * i + 1;
    int rc = 2 * i + 2;
    int sum = 0;

    if (v[i] >= max) {
        sum++; // Count the current node as good
        max = v[i];
    }

    if (lc < len) {
        sum += findgn(v, len, lc, max);
    }

    if (rc < len) {
        sum += findgn(v, len, rc, max);
    }

    return sum; // Return the sum after recursive calls
}

int main() {
    vector<int> v;
    string t;
    int len = 0;
    cout << "Enter values: ";
    while (1) {
        int node;
        cin >> t;
        if (t == "-1")
            break;
        len++;
        if (t == "null")
            node = INT_MIN;
        else
            node = stoi(t);
        v.push_back(node);
    }
    cout << findgn(v, len, 0, v[0]) << endl;
    return 0;
}
