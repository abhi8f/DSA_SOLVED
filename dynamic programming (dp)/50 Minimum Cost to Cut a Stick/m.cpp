// TC: O(n*n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << x << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;

int r(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
    if (j-i<2) return 0;
    h();
    if (dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<j;k++){
        ans=min(
            ans,
            cuts[j]-cuts[i] + r(i,k,cuts,dp) + r(k,j,cuts,dp)
        );
    }
    return dp[i][j] = ans;
}


class Solution {
   public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int nn=cuts.size();
        vector<vector<int>> dp(nn,vector<int>(nn,-1));
        int val = r(0,nn-1,cuts,dp);
        return val;
    }
};

int main() {
    Solution s;
    vector<int> ac = {1, 3, 4, 5};
    cout << s.minCost(7, ac) << endl;
    // vector<int> ac={5,6,1,4,2};
    // cout<<s.minCost(9,ac)<<endl;
    // vector<int> ac={1,3};
    // cout<<s.minCost(5,ac)<<endl;
    return 0;
}