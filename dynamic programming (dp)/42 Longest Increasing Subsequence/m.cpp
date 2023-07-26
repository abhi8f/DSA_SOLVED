// TC: O(n*n)
// SC: O(n) + O(n*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cur(n + 1, 0);
        for(int j=0;j<n;j++) cur[j]=nums[0] < nums[j]?1:0;
        cur[n]=1;
        for(int i=1;i<n;i++)
            for(int j=n;j>=i+1;j--)
                cur[j]=max(
                    cur[j],
                    (j == nums.size() || nums[i] < nums[j]) ? 1 + cur[i] : 0
                );
        
        return cur[n];
    }
};

int main() {
    return 0;
}