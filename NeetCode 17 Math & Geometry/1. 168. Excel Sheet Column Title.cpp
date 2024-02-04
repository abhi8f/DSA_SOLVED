class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber) {
            int rem = (columnNumber - 1)%26;
            columnNumber = (columnNumber - 1)/26;
            ans += char(int('A') + rem);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
