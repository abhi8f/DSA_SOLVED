class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = (num.size() - 1); i >= 0; i--) {
            int x = num[i] - (int)('0');

            if (x % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};
