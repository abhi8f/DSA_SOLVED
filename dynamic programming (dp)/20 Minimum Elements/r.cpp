// TC: O((target/num[i])^n))
// SC: O(target)
#include <bits/stdc++.h>
using namespace std;

int r(int i, int x,vector<int> &num) {
    if (x==0) return 0;
    if (i < 0) return 1e8;

    int ans = r(i - 1, x, num);
    for (int m = 1; m <= x / num[i]; m++) {
        ans = min(ans, r(i - 1, x - m * num[i], num) + m);
    }
    return ans;
}

int minimumElements(vector<int> &num, int x) {
    vector<vector<int>> mv(num.size(), vector<int>(x + 1, -1));
    int ans=r(num.size() - 1, x, num);
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