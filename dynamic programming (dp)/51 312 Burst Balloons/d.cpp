// TC: O(n*n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;
#define d(x) cout<<#x<<": "<<x<<endl;
int h=1;
#define h() cout<<"h "<<h++<<endl;

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=n-2;i>=-1;i--){
            for(int j=i+2;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    // d(i);d(j);d(k);
                    dp[i+1][j]=max(
                        dp[i+1][j],
                        nums[k] * (i == -1 ? 1 : nums[i]) * (j == n ? 1 : nums[j]) + dp[i+1][k] + dp[k+1][j]
                    );
                }
            }
        }
        return dp[-1+1][n];
    }
};

int main() {
    Solution s;
    vector<int> v={1,5};
    cout<<endl<<s.maxCoins(v)<<endl;
    return 0;
}