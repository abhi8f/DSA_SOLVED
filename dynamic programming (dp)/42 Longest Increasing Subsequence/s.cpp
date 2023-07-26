// TC: O(n*n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> cur(n + 1, 0);
        for (int i = n-1; i >= 0; i--) 
            for (int j = i - 1; j >= -1; j--) 
                cur[j+1] = max(
                    cur[j + 1], 
                    (j==-1 || nums[i] > nums[j]) ? 1 + cur[i + 1] : 0);
        
        return cur[-1+1];
    }
};


int main() {
    return 0;
}