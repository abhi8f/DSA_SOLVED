class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> monotonicDec;
        int n = nums.size();
        vector<int> ans(n - k + 1);

        for(int i = 0; i < k; i++) {
            while (!monotonicDec.empty() && (nums[monotonicDec.back()] < nums[i])) {
                monotonicDec.pop_back();
            }
            monotonicDec.push_back(i);
        }
        ans[0] = nums[monotonicDec.front()];

        int pre = 0;
        int post = k;

        while (post < n) {
            while (!monotonicDec.empty() && (monotonicDec.front() <= pre)) {
                monotonicDec.pop_front();
            }

            while (!monotonicDec.empty() && (nums[monotonicDec.back()] < nums[post])) {
                monotonicDec.pop_back();
            }
            monotonicDec.push_back(post);
            ans[pre + 1] = nums[monotonicDec.front()];
            pre++;
            post++;
        }
        return ans;
    }
};
