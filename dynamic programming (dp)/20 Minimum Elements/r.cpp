// TC: O((target/num[i])^n))
// SC: O(target)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int x, vector<int> &num) {
    if (x == 0) return 0;
    if (i < 0) return 1e8;
    return min(r(i - 1, x, num), x >= num[i] ? r(i, x - num[i], num) + 1 : (int)1e8);
}

int minimumElements(vector<int> &num, int x) {
    int ans = r(num.size() - 1, x, num);
    return ans == 1e8 ? -1 : ans;
}

int main() {
    /*
3 7
1 2 3

    */
    int n = 3, x = 7;
    vector<int> num = {1, 2, 3};
    cout << minimumElements(num, x);
    return 0;
}