// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

// TC: O(n*n)
// SC: O(n*n*2) for first, O(n) for second
#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &arr) {
    int n=arr.size();
    vector<int> dp(n,1), count(n,1);
    
    int maxv=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++) 
            if (arr[j]<arr[i] && dp[i]<dp[j]+1) count[i]=count[j], dp[i] = dp[j]+1;
            else if (arr[j]<arr[i] && dp[i]==dp[j]+1) count[i]+=count[j];
        maxv=max(maxv,dp[i]);
        
    }
    int ans=0;
    for(int i=0;i<n;i++) ans+=dp[i]==maxv?count[i]:0;
    return ans;
}

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1), count(n,1);
        
        int maxv=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++) 
                if (nums[j]<nums[i] && dp[i]<dp[j]+1) count[i]=count[j], dp[i] = dp[j]+1;
                else if (nums[j]<nums[i] && dp[i]==dp[j]+1) count[i]+=count[j];
            maxv=max(maxv,dp[i]);
            
        }
        int ans=0;
        for(int i=0;i<n;i++) ans+=dp[i]==maxv?count[i]:0;
        return ans;
    }
};

int main() {
    vector<int> v = {15, 22, 12, 7, 13, 15 };
    cout << endl<< findNumberOfLIS(v)<< endl;
    return 0;
}