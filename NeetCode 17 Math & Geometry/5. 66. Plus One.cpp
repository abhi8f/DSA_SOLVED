class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int carry = 1;

        while((i >= 0) && (carry != 0)) {
            int val = digits[i] + carry;
            int digit = val % 10;
            digits[i] = digit;
            carry = val/10;
            i--;
        }
        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
