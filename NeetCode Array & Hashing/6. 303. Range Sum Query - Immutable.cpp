class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int& x: nums) {
            sum += x;
            prefixSum.emplace_back(sum);
        }
    }

    int sumRange(int left, int right) {
        int r = prefixSum[right];
        int l = 0;
        if (left > 0) {
            l = prefixSum[left - 1];
        }
        return r - l;
    }
};
