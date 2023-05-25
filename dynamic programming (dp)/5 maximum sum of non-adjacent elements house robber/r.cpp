// TC: O(2^n)
// SC: O(n)
#include <bits/stdc++.h>
using namespace std;

int r(vector<int> &nums, int selectIndex, int currentIndex) {
    if (currentIndex == nums.size() - 1) {
        if (selectIndex == currentIndex - 1)
            return 0;
        else
            return nums[currentIndex];
    }
    if (selectIndex == currentIndex - 1) {
        return r(nums, selectIndex, currentIndex + 1);
    }
    return max(nums[currentIndex] + r(nums, currentIndex, currentIndex + 1),
               r(nums, selectIndex, currentIndex + 1));
}

int r2(int i, vector<int> &nums) {
    if (i == 0) return nums[0];
    if (i < 0) return 0;
    return max(nums[i] + r2(i - 2, nums), r2(i - 1, nums));
}

int maximumNonAdjacentSum(vector<int> &nums) {
    // return r(nums, -2, 0);
    return r2(nums.size() - 1, nums);
}

int main() {
    // 1 2 3 1 3 5 8 1 9
    vector<int> v = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    cout << maximumNonAdjacentSum(v) << endl;
    return 0;
}