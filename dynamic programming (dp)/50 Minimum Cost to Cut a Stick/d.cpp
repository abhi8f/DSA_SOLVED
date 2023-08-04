// TC: O(n*n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << x << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;



class Solution {
   public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int nn=cuts.size();
        vector<vector<int>> dp(nn,vector<int>(nn,0));
        for(int i=nn-3;i>=0;i--){
            for(int j=i+2;j<nn;j++){
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    ans=min(
                        ans,
                        cuts[j]-cuts[i] + dp[i][k] + dp[k][j]
                    );
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][nn-1];
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
    // vector<int> ac={1,2,5};
    // cout<<s.minCost(6,ac)<<endl;
    return 0;
}