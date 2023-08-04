// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

#define d(x) cout << #x << ": " << (x) << endl;
int h = 1;
#define h() cout << "h " << h++ << endl;

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(nums[n - 1]);
        ans[n-1]=-1;
        int i;
        for (int j = 2*n - 2; j >= 0; j--) {
            i=j%n;
            while (!s.empty() && nums[i] >= s.top()) s.pop();
            if (!s.empty()) ans[i] = s.top();
            else ans[i] = -1;
            s.push(nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {1,2,1};
    arr = s.nextGreaterElements(arr);
    cout << endl;
    for (int i : arr) cout << i << " ";
    cout << endl;
    return 0;
}