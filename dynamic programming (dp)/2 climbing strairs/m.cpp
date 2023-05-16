// TC: O(n)
// SC: O(n) + O(n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int m(int n, vector<int> &mv) {
    if (mv[n] != -1) return mv[n];
    if (n <= 2) return n;
    return mv[n] = m(n - 1, mv) + m(n - 2, mv);
}

int main() {
    int n;
    cin >> n;
    vector<int> mv(n + 1, -1);
    cout << m(n, mv) << endl;
    return 0;
}