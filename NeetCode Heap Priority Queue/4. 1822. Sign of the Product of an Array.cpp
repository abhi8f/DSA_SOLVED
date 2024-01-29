class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = true;
        for(int& x: nums) {
            if (x == 0) return 0;
            if (x < 0) sign = !sign;
        }
        if (sign) return 1;
        return -1;
    }
};
