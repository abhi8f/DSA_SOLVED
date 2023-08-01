// TC: O(2^(r - l))
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int rec(int l, int r, vector<int>& nums) {
    if (r-l<2) return 0;
    int ans = INT_MIN;
    for (int i = l + 1; i < r; i++) {
        ans = max(
            ans,
            nums[i] * (l == -1 ? 1 : nums[l]) * (r == nums.size() ? 1 : nums[r]) +
                rec(l, i, nums) + rec(i, r, nums));
    }
    return ans;
}

class Solution {
   public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        return rec(-1,nums.size(),nums);
    }
};

int main() {
    return 0;
}