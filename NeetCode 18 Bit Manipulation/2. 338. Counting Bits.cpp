class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int m = 0; m <= n; m++) {
            int num = m;
            int res = 0;
            while (num) {
                res += num%2;
                num = num>>1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
