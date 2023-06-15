// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int tar, vector<int>& num) {
    if (i < 0) return tar == 0 ? 1 : 0;
    return (tar >= num[i] ? r(i - 1, tar - num[i], num) : 0) + r(i - 1, tar, num);
}

int findWays(vector<int>& num, int tar) {
    return r(num.size() - 1, tar, num);
}

int main() {
    /*
    3 1
    1 0 1
    */
    int tar = 1;
    vector<int> num{0, 0 , 0, 1};
    cout << findWays(num, tar) << endl;
    return 0;
}