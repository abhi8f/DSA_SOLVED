// TC: O(n*n)
// SC: O(n*n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(INT_MAX);
        int n = nums.size();
        vector<int> cur(n, 0);
        for (int j = 1; j < n; j++) cur[j] = nums[0] < nums[j] ? 1 : 0;

        for (int i = 1; i < n - 1; i++)
            for (int j = n - 1; j >= i + 1; j--)
                cur[j] = max(cur[j], nums[i] < nums[j] ? 1 + cur[i] : 0);
        return cur[n - 1];
    }
};


int main() {
    return 0;
}