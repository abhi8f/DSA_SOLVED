class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int cur = 0;
        for(char& c: s) {
            if (c == '(') {
                cur++;
            } else {
                cur--;
                if (cur < 0) {
                    ans -= cur;
                    cur = 0;
                }
            }
        }
        return ans + cur;
    }
};
