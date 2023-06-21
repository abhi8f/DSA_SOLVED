// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

// using 1 index
int r(int i, int l, vector<int> &price) {
    if (i==0) return 0;
    return max(r(i-1, l, price), l>=i?price[i-1]+r(i, l-i, price):0);
}

int cutRod(vector<int> &price, int n) {
    return r(n, n, price);
}

int main() {
    int n=2;
    vector<int> price = {1, 20};
    cout << cutRod(price, n) << endl;
    return 0;
}