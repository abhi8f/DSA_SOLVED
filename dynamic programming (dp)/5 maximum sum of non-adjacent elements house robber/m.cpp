// TC: O(n)
// SC: O(n) + O(n) = O(n)
#include <bits/stdc++.h>
using namespace std;

int m(vector<int> &nums, int selectIndex, int currentIndex, vector<vector<int>> &mv) {
    if (currentIndex == nums.size() - 1) {
        if (selectIndex == currentIndex - 1)
            return 0;
        else
            return nums[currentIndex];
    }
    if (selectIndex == currentIndex - 1) {
        if (mv[currentIndex][0] != -1) return mv[currentIndex][0];
        return mv[currentIndex][0] = m(nums, selectIndex, currentIndex + 1, mv);
    }
    if (mv[currentIndex][1] != -1) return mv[currentIndex][1];
    return mv[currentIndex][1] =
               max(nums[currentIndex] + m(nums, currentIndex, currentIndex + 1, mv),
                   m(nums, selectIndex, currentIndex + 1, mv));
}

int m2(int i, vector<int> &nums, vector<int> &mv) {
    if (i == 0) return nums[0];
    if (i < 0) return 0;
    if (mv[i] != -1) return mv[i];
    return mv[i] = max(nums[i] + m2(i - 2, nums, mv), m2(i - 1, nums, mv));
}

int maximumNonAdjacentSum(vector<int> &nums) {
    // vector<vector<int>> mv(nums.size(), vector<int>(2, -1));
    // return m(nums, -2, 0, mv);
    vector<int> mv(nums.size(), -1);
    return m2(nums.size() - 1, nums, mv);
}

int main() {
    // 1 2 3 1 3 5 8 1 9
    // vector<int> v = {1, 2, 3, 1, 3, 5, 8, 1, 9};/
    vector<int> v={1,2,3,5,4};
    cout << maximumNonAdjacentSum(v) << endl;
    return 0;
}