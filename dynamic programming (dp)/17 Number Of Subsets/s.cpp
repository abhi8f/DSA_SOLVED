// TC: O(n*tar)
// SC: O(2tar) = O(tar)
#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int>& num, int tar) {
    int n = num.size();
    vector<int> pre(tar + 1, 0), cur(tar + 1, 0);
    int i = 0, zc = 0;
    while (i < n && num[i] == 0) zc++, i++;
    if (i < n) pre[0] = 1;
    if (i < n && num[i] <= tar) pre[num[i]] = 1;
    i++;
    for (; i < n; i++) {
        for (int j = 0; j <= tar; j++)
            cur[j] = pre[j] + (j >= num[i] ? pre[j - num[i]] : 0);
        pre = cur;
    }
    return pre[tar] * pow(2, zc);
}

int main() {
    /*
    3 1
    1 0 1
    */
    int tar = 3;
    vector<int> num{1, 2, 2, 3};
    cout << findWays(num, tar) << endl;
    return 0;
}