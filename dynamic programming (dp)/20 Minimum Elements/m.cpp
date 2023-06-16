// TC: O(n*target)
// SC: O(target) + O(n*target) = O(n*target)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int x,vector<int> &num, vector<vector<int>> &mv) {
    if (x==0) return 0;
    if (i < 0) return 1e8;
    if (mv[i][x] != -1) return mv[i][x];

    int ans = r(i - 1, x, num, mv);
    for (int m = 1; m <= x / num[i]; m++) {
        ans = min(ans, r(i - 1, x - m * num[i], num, mv) + m);
    }
    return mv[i][x] = ans;
}

int minimumElements(vector<int> &num, int x) {
    vector<vector<int>> mv(num.size(), vector<int>(x + 1, -1));
    int ans=r(num.size() - 1, x, num, mv);
    return ans==1e8?-1:ans;
}

int main() {
    /*
4 10
4 1 2 6 

    */
   int n=4, x=10;
    vector<int> num={4, 1, 2, 6};
    cout<<minimumElements(num, x);
    return 0;
}